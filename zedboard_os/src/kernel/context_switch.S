.globl load_context
/*
This is still used for switching into the first user task
void load_context(uint32_t *task_sp)
    -param task should be in r0
*/
load_context:
    // dereference pointer to task state
    mov  sp, r0
    pop {r0-r11}
    //msr cpsr_c, r12

    pop {lr}

    // jump to new code
    //pop {pc}
    cpsie if // reenable interrupts
    rfeia sp! // this pops off pc and cpsr at the same time

.globl switch_to_task

/*
void switch_to_task(struct tcb_entry *curr, struct tcb_entry *next)
    curr should be in r0
    next should be in r1
*/
switch_to_task:
    mrs r12, cpsr
    push {r12}  // push cpsr
    push {lr}   // push LR into pc
    push {sp}   // push garbage
    // the following line was used to test the context switch test
    // add r4, r4, #1
    push {r0-r11}
    str sp, [r0] // store the stack pointer in curr tcb entry
    
    ldr sp, [r1] // load stack pointer from next tcb entry
    pop {r0-r11}
    pop {lr}

    cpsie if // reenable interrupts
    rfeia sp! // pops off pc and cpsr at the same time
    // shouldn't return
