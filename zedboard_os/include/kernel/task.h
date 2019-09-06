#ifndef __TASK_H__
#define __TASK_H__

#include <stdint.h>
#include <kernel/queue.h>
#include <kernel/os_config.h>

// Macros for return codes
#define ERR_MSG_TRUNCATED (-1)
#define ERR_TID_INVALID (-2)
#define ERR_NO_MORE_TIDS (-2)
#define ERR_SRR_INCOMPLETE (-3)
#define ERR_TASK_NOT_SEND_BLOCKED (-3)

enum task_state {
    TASK_READY,
    TASK_RUNNING,
    TASK_ZOMBIE,
    TASK_SEND_BLOCKED,
    TASK_RECEIVE_BLOCKED,
    TASK_EVENT_BLOCKED,
    TASK_ASLEEP,
};

struct task_context {
    uint32_t r[12]; // r0-r11; r12 is a scratch register, which we use to load/store cpsr
    uint32_t lr;
    uint32_t pc;
    uint32_t cpsr;
};

struct task_stack {
    uint32_t data[TASK_STACK_SIZE];
};

struct mailbox {
    void *msg;
    int msglen;
};

struct tcb_entry {
    uint32_t *stack_top;      // points to the highest unused memory location in the stack
    uint32_t tid;
    char name[TASK_NAME_SIZE];
    int priority;
    enum task_state state;
    struct mailbox outbox; 
    struct mailbox inbox;
    Queue<struct tcb_entry> receive_queue;
};

#endif
