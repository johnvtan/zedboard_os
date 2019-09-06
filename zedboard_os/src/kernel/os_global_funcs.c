#include <kernel/os_global_funcs.h>
#include <kernel/os.h>
#include <kernel/interrupts.h>

#include <xil_printf.h>

extern myOS OS;

void timer_int_handler(void *param) {
    XScuTimer *timer = (XScuTimer *)param;
    XScuTimer_ClearInterruptStatus(timer);

    // signal that the timer event happened
    OS.signal_event(TIMER_EVENT, 0);

    // system task should have been rescheduled, so switch to that
    OS.yield_from_interrupt();
}

void task_wrapper(int (*task)(void*), void *param) {
    int rv = task(param);
    xil_printf("Got return value: %d\n\r", rv);
    OS.exit();
}
