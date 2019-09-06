#include <kernel/os.h>
#include <kernel/os_global_funcs.h>
#include <kernel/clock_defs.h>
#include <assert.h>

extern "C" void load_context(uint32_t *task_sp);
extern "C" void switch_to_task(struct tcb_entry *curr_task, struct tcb_entry *next_task);

static inline void DISABLE_INTERRUPTS() {
    asm __volatile__("cpsid if"::);
}

static inline void ENABLE_INTERRUPTS() {
    asm __volatile__("cpsie if"::);
}

myOS::myOS() {

}

myOS::~myOS() {

}

void myOS::init(int (*first_task)(void*), void (*schedule_callback)(void*), int first_task_prio) {
    // only enable interrupts right before we start
    // initialize hardware
    DISABLE_INTERRUPTS();
    int rv = timer.init();
    if (rv != 0) {
        panic("timer init failed\n");
    }
    rv = interrupt_controller.init();
    if (rv != 0) {
        panic("interrupt controller init failed\n");
    }
    rv = interrupt_controller.register_interrupt(XPAR_SCUTIMER_INTR, schedule_callback, (void*)timer.get_instance_ptr());
    if (rv != 0) {
        panic("couldn't register timer interrupt\n");
    }

    timer.enable_interrupt();
    ENABLE_INTERRUPTS();

    // initialize with system task - system task should bring up all other OS tasks
    init_tasks(system_task, NULL, MAX_SYS_PRIO);

    // create first user task (after system task)
    create(first_task, NULL, first_task_prio);

    timer.start();
    start();
}

int myOS::create(int (*task)(void*), void *task_param, int priority) {
    int new_task_idx = -1;
    for (int i = 0; i < MAX_NUM_TASKS; i++) {
        if (tcb_entries[i].state == TASK_ZOMBIE) {
            new_task_idx = i;
            break;
        }
    }
    if (new_task_idx == -1) {
        return ERR_NO_MORE_TIDS;
    }

    // set priority in tcb
    tcb_entries[new_task_idx].priority = priority;

    struct task_context *context = (struct task_context*)tcb_entries[new_task_idx].stack_top;

    // put task code address in r0 (first param location)
    context->r[0] = (uint32_t)task;

    // put param in r1 (second parameter location)
    context->r[1] = (uint32_t)task_param;

    // set pc to call task_wrapper()
    context->pc = (uint32_t)task_wrapper;

    // save the cpsr
    asm("mov r4, %0"::"r"((uint32_t)&context->cpsr));
    asm("mrs r3, cpsr"::);
    asm("str r3, [r4]"::);

    // schedule the newly created task
    reschedule(&tcb_entries[new_task_idx]);
    return new_task_idx;
}

void myOS::panic(char *msg) {
    xil_printf("--------------------------KERNEL PANIC -------------------\n");
    xil_printf(msg);
    xil_printf("--------------------------KERNEL PANIC -------------------\n");
    while (1) {
    }
}

void myOS::yield(void) {
    DISABLE_INTERRUPTS();
    struct tcb_entry *prev = curr_running_task;

    // if a running task calls it, change state to TASK_READY and push it onto the ready_queue
    // otherwise assume that it's blocked and don't push onto ready_queue
    if (prev->state == TASK_RUNNING) {
        reschedule(prev);
    }

    // change to next task
    curr_running_task = ready_queue.pop();
    curr_running_task->state = TASK_RUNNING;

    // switch_to_task() re-enables interrupts
    switch_to_task(prev, curr_running_task);

}

void myOS::yield_from_interrupt(void) {
    DISABLE_INTERRUPTS();
	asm __volatile__("add sp, sp, #0x120");     // Adjust interrupt SP to point before registers were placed on the stack.

    // Change into system mode and store current SP into tcb_entries[curr_running_task].stack_top
    // Assumes that the IRQ handler has already saved the task's context on the task's stack.
    asm __volatile__("cps #0x1F"); // I'm in system mode now
    asm __volatile__("mov r0, %0"::"r"((uint32_t)curr_running_task));
    asm __volatile__("str sp, [r0]"::);

    struct tcb_entry *prev = curr_running_task;

    if (prev->state == TASK_RUNNING) {
        reschedule(prev);
    }

    // Round robin scheduling: push currently running task onto queue and pop the next one off the queue
    curr_running_task = ready_queue.pop();
    curr_running_task->state = TASK_RUNNING;

    if (curr_running_task == NULL) {
        xil_printf("uh oh curr task is NULL\n\r");
        while (1) {}
    }

    // load_context() re-enables interrupts
    load_context(curr_running_task->stack_top); 

}

void myOS::exit(void) {
    // presumably the task was running when this happened
    curr_running_task->state = TASK_ZOMBIE;
    curr_running_task = ready_queue.pop();
    if (curr_running_task == NULL) {
        xil_printf("oh no curr task is NULL\n\r");
        while (1) {}
    }
    curr_running_task->state = TASK_RUNNING;
    load_context(curr_running_task->stack_top);
}

int myOS::send(int tid, void *msg, int msglen, void *reply, int rplen) {
    if (tcb_entries[tid].state == TASK_ZOMBIE) {
        return ERR_TID_INVALID;
    }

    // push curr task onto receiver's receive_queue, which is a queue of all tasks trying
    // to send to the task
    struct tcb_entry *receiver = &tcb_entries[tid];
    receive_queue_nodes[curr_running_task->tid].node = curr_running_task;
    receiver->receive_queue.push(&receive_queue_nodes[curr_running_task->tid]);

    // if the receiver is blocked waiting for a message, change it to TASK_READY
    // and push it on the ready queue
    if (receiver->state == TASK_RECEIVE_BLOCKED) {
        reschedule(receiver);
    }

    // make the currently running task send blocked
    curr_running_task->state = TASK_SEND_BLOCKED;

    // put the message in the sending task's mailbox
    curr_running_task->outbox.msg = msg;
    curr_running_task->outbox.msglen = msglen;

    // set the inbox to point to the reply
    curr_running_task->inbox.msg = reply;
    curr_running_task->inbox.msglen = rplen;

    // stop executing 
    yield();

    // we should now have a valid message in our inbox
    // return size of message. we put a max length in there, but receive/reply might change that
    return curr_running_task->inbox.msglen;

}

int myOS::receive(int *tid, void *msg, int msglen) {
    if (curr_running_task->receive_queue.get_len() == 0) {
        // if no sender, block this task until it gets something
        curr_running_task->state = TASK_RECEIVE_BLOCKED;
        yield();
    }

    // if we get here, there should be a task on our receive_queue
    struct tcb_entry *sender = curr_running_task->receive_queue.pop();
    if (sender == NULL) {
        xil_printf("sender is NULL idk how so I'm panicking...\n");
        while (1) {}
    }

    // determine how much data can be copied while preventing overflow and copy the data
    int copy_length = msglen < sender->outbox.msglen ? msglen : sender->outbox.msglen;
    memcpy(msg, sender->outbox.msg, copy_length);

    // Set the tid and return the length of the msg or error code
    *tid = sender->tid;
    return copy_length <= msglen ? copy_length : ERR_MSG_TRUNCATED;
}

int myOS::reply(int tid, void *reply, int rplen) {
    struct tcb_entry *receiver = &tcb_entries[tid];
    if (receiver->state == TASK_ZOMBIE) {
        return ERR_TID_INVALID;
    }
    if (receiver->state != TASK_SEND_BLOCKED) {
        return ERR_TASK_NOT_SEND_BLOCKED;
    }

    // copy the message to the receiving task's inbox
    int copy_length = rplen > receiver->inbox.msglen ? receiver->inbox.msglen : rplen;
    memcpy(receiver->inbox.msg, reply, copy_length);

    // change receiver task state from TASK_SEND_BLOCKED to TASK_READY and schedule
    reschedule(receiver);

    // return -1 if message was truncated, 0 otherwise to indicate success
    return copy_length < rplen ? ERR_MSG_TRUNCATED : 0;

}

int myOS::await_event(int event) {
    if (event >= NUM_EVENTS) {
        return ERR_INVALID_EVENT;
    }
 
    // curr task yields for event
    if (!event_buffer[event].buffered) {
        curr_running_task->state = TASK_EVENT_BLOCKED;
        event_queue_nodes[curr_running_task->tid].node = curr_running_task;
        event_queues[event].push(&event_queue_nodes[curr_running_task->tid]);
        yield();
    }    

    // only one task can consume the buffered result
    event_buffer[event].buffered = false;

    // if we're here, then the event should have happened
    return event_buffer[event].value;

}

int myOS::signal_event(int event, int rv) {
    if (event >= NUM_EVENTS) {
        return ERR_INVALID_EVENT;
    }
 
    // put return value in event buffer
    event_buffer[event].value = rv;

    int num_tasks_waiting = event_queues[event].get_len();
    if (num_tasks_waiting == 0) {
        event_buffer[event].buffered = true; 
    } else {
        for (int i = 0; i < num_tasks_waiting; i++) {
            reschedule(event_queues[event].pop());
        }
        event_buffer[event].buffered = false;
    }
    return 0;
}

void myOS::reschedule(struct tcb_entry *task) {
    // if it's ready, assume that it's already on a queue
    if (task->state != TASK_READY) {
        task->state = TASK_READY;
        ready_queue.push(task, task->priority);
    }
}

struct tcb_entry *myOS::get_next_task(void) {
    return ready_queue.pop();
}

void myOS::init_tasks(int (*first_task)(void*), void* param, int first_task_prio) {
    print("Task init\n\r");
    int i = 0;
    for (i = 0; i < MAX_NUM_TASKS; i++) {
        // initialize with space at the top for initial context 
        tcb_entries[i].stack_top = &task_stacks[i].data[TASK_STACK_SIZE - 1] - sizeof(struct task_context); 

        // zero out state
        memset(tcb_entries[i].stack_top, 0, sizeof(struct task_context));

        // set some ID number to the task
        tcb_entries[i].tid = i;

        // set to ready state
        tcb_entries[i].state = TASK_ZOMBIE;

        // Initialize mailboxes
        tcb_entries[i].outbox.msg = NULL;
        tcb_entries[i].outbox.msglen = 0;

        tcb_entries[i].inbox.msg = NULL;
        tcb_entries[i].inbox.msglen = 0;
    }
    curr_running_task = NULL;
    create(first_task, param, first_task_prio);
}

void myOS::start(void) {
    curr_running_task = get_next_task();
    assert(curr_running_task != NULL);
    curr_running_task->state = TASK_RUNNING;
    load_context(curr_running_task->stack_top);
}

uint64_t myOS::get_time(void) {
    struct clock_request req;
    struct clock_reply rp;
    req.request = CLOCK_MSG_GET_TIME;
    send(2, (void*)&req, sizeof(struct clock_request), (void*)&rp, sizeof(struct clock_reply));
    if (rp.ack != CLOCK_REPLY_ACK) {
        panic("Get time failed\n\r");
    }
    return rp.time_ms;
}

void myOS::sleep(uint64_t time) {
    // put task on sleep queue and yield cpu
    uint64_t wakeup_time = time + get_time();
    curr_running_task->state = TASK_ASLEEP;
    sleep_queue.push(curr_running_task, wakeup_time);
    yield();
}

void myOS::wakeup(uint64_t time) {
    while (time >= sleep_queue.peek_prio() && sleep_queue.peek_prio() > 0) {
        reschedule(sleep_queue.pop());
    }
}

// Task implementations need an instance of the class?
extern myOS OS;

// Task implementations
int myOS::system_task(void *param) {
    int await_result = -1;

    struct clock_request send_msg;
    send_msg.request = CLOCK_MSG_INCREMENT_TICK;
    struct clock_reply reply;

    // bring up clock task
    int clock_task_tid = OS.create(clock_task, NULL, MAX_SYS_PRIO+1);

    // bring up idle task
    int idle_task_tid = OS.create(idle_task, NULL, MIN_SYS_PRIO);
    while (1) {
        await_result = OS.await_event(TIMER_EVENT);
        OS.send(clock_task_tid, (void*)&send_msg, sizeof(struct clock_request), (void*)&reply, sizeof(struct clock_reply));
        if (reply.ack != CLOCK_REPLY_ACK) {
            OS.panic("Received unknown response from clock server\n");
        }
    }

    return 0;
}

int myOS::idle_task(void *param) {
    (void) param;
    while (1) {
        asm("nop");
    }
    return 0;
}

int myOS::clock_task(void *param) {
    int receive_tid = -1;
    struct clock_request request;
    uint64_t tick_count = 0;
    while (1) {
        OS.receive(&receive_tid, (void*)&request, sizeof(struct clock_request));
        if (receive_tid < 0 || receive_tid >= MAX_NUM_TASKS) {
            OS.panic("Clock task received request from invalid TID\n\r");
        }
        switch(request.request) {
            case CLOCK_MSG_INCREMENT_TICK:
                ++tick_count;
                OS.wakeup(tick_count);
                // send to the system task so that it can run
                clock_task_send_reply(receive_tid, tick_count);
                break;
            case CLOCK_MSG_GET_TIME:
                clock_task_send_reply(receive_tid, tick_count);
                break;
            default:
                // do nothing for unknown request?
                break;
        }
    }
    return 0;
}

void myOS::clock_task_send_reply(int tid, uint64_t tick_count) {
    struct clock_reply reply;
    reply.ack = CLOCK_REPLY_ACK;

    // time comes back in ms
    reply.time_ms = tick_count;
    OS.reply(tid, (void*)&reply, sizeof(struct clock_reply));
}
