.globl context_switch_test_set_reg_values
context_switch_test_set_reg_values:
    mov r4, #42
    mov r5, #100
    mov r6, #0
    mov r7, #34
    mov r8, #255
    mov r9, #23
    mov r10, #144
    mov r11, #3
    bx lr

.globl context_switch_test_check_reg_values
context_switch_test_check_reg_values:
    cmp r4, #42
    bne test_fail
    cmp r5, #100
    bne test_fail
    cmp r6, #0
    bne test_fail
    cmp r7, #34
    bne test_fail
    cmp r8, #255
    bne test_fail
    cmp r9, #23
    bne test_fail
    cmp r10, #144
    bne test_fail
    cmp r11, #3
    bne test_fail
    mov r0, #0
    bx lr

test_fail:
    mov r1, #-1
    bx lr
