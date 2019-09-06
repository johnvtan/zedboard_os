#ifndef __INTERRUPTS_H__
#define __INTERRUPTS_H__

#include "xparameters.h"
#include "xil_exception.h"
#include "xscugic.h"

class InterruptController
{
public:
    InterruptController(void);
    ~InterruptController(void);
    int init(void);
    int register_interrupt(uint16_t interrupt_id, void (*handler)(void*), void *handler_param);
private:
    XScuGic interrupt_controller;
};
#endif
