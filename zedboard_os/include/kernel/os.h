#ifndef __OS_H__
#define __OS_H__

#include <stdint.h>
#include <stddef.h>

#include "xil_printf.h"
#include "xparameters.h"

#include <kernel/interrupts.h>
#include <kernel/queue.h>
#include <kernel/task.h>
#include <kernel/timer.h>

#define ERR_INVALID_EVENT (-1)
#define ERR_CORRUPTED_DATA (-2)

struct event_return {
    int value;
    bool buffered;
};

class myOS
{
public:
    myOS();
    ~myOS();
    void init(int (*first_task)(void*), void (*schedule_callback)(void*), int first_task_prio);
    int create(int (*task)(void*), void *task_param, int priority);
    void panic(char *msg);
    void yield(void);
    void yield_from_interrupt(void);
    void exit(void);
    void register_as(char *name, int len);
    int who_is(char *name, int len);
    int send(int tid, void *msg, int msglen, void *reply, int rplen);
    int receive(int *tid, void *msg, int msglen);
    int reply(int tid, void *reply, int rplen);
    int await_event(int event);
    int signal_event(int event, int rv);
    uint64_t get_time(void);
    void sleep(uint64_t time);
    void wakeup(uint64_t time);
private:
    void reschedule(struct tcb_entry *task);
    struct tcb_entry *get_next_task(void);
    void init_tasks(int (*first_task)(void*), void* params, int first_task_prio);
    void start(void);

    /* OS tasks */
    static int system_task(void *param);
    static int clock_task(void *param);
    static int idle_task(void *param);
    static void clock_task_send_reply(int tid, uint64_t tick_count);

    Timer timer;
    InterruptController interrupt_controller;

    struct tcb_entry tcb_entries[MAX_NUM_TASKS];
    struct task_stack task_stacks[MAX_NUM_TASKS];

    struct tcb_entry *curr_running_task;

    PriorityQueue<struct tcb_entry, int> ready_queue;
    PriorityQueue<struct tcb_entry, uint64_t> sleep_queue;

    QueueNode<struct tcb_entry> event_queue_nodes[MAX_NUM_TASKS];
    Queue<struct tcb_entry> event_queues[NUM_EVENTS];

    QueueNode<struct tcb_entry> receive_queue_nodes[MAX_NUM_TASKS];

    struct event_return event_buffer[NUM_EVENTS];
};

#endif
