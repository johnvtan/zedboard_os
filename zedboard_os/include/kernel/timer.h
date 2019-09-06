#ifndef __TIMER_H__
#define __TIMER_H__

#include <stdint.h>
#include "xscutimer.h"
#include "xparameters.h"

#define TIMER_DEVICE_ID XPAR_XSCUTIMER_0_DEVICE_ID
#define TIMER_MAX_VAL 999998  // each tick is 3 ms

class Timer
{
public:
    Timer();
    ~Timer();
    int init(void);
    uint32_t get_current_value(void);
    XScuTimer *get_instance_ptr(void);
    void enable_interrupt(void);
    void start(void);
private:
    XScuTimer timer;
};

#endif
