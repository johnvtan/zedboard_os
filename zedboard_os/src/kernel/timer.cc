#include <kernel/timer.h>
#include <xil_printf.h>

Timer::Timer() {

}

Timer::~Timer() {

}

int Timer::init(void) {
    XScuTimer_Config *config_ptr = XScuTimer_LookupConfig(TIMER_DEVICE_ID);
    int status = XScuTimer_CfgInitialize(&timer, config_ptr, config_ptr->BaseAddr);
    if (status != XST_SUCCESS) {
        return -1;
    }
    
    status = XScuTimer_SelfTest(&timer);
    if (status != XST_SUCCESS) {
        return -1;
    }

    //uint8_t prescaler = XScuTimer_GetPrescaler(&timer);
    XScuTimer_EnableAutoReload(&timer);
    XScuTimer_LoadTimer(&timer, TIMER_MAX_VAL);
    return 0;
}

XScuTimer *Timer::get_instance_ptr(void) {
    return &timer;
}

uint32_t Timer::get_current_value(void) {
    return XScuTimer_GetCounterValue(&timer);
}

void Timer::enable_interrupt(void) {
    XScuTimer_EnableInterrupt(&timer);
}

void Timer::start(void) {
    XScuTimer_Start(&timer);
}
