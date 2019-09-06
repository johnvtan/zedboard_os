#include <kernel/interrupts.h>

InterruptController::InterruptController(void) {

}

InterruptController::~InterruptController(void) {

}

int InterruptController::init(void) {
    XScuGic_Config *config = XScuGic_LookupConfig(XPAR_SCUGIC_SINGLE_DEVICE_ID);
    if (config == NULL) {
        return -1;
    }

    int status = XScuGic_CfgInitialize(&interrupt_controller, config, config->CpuBaseAddress);
    if (status != XST_SUCCESS) {
        return -1;
    }
    Xil_ExceptionInit();
    return 0;
}

int InterruptController::register_interrupt(uint16_t interrupt_id, void (*handler)(void*), void *handler_param) {
    Xil_ExceptionRegisterHandler(XIL_EXCEPTION_ID_IRQ_INT,
                                 (Xil_ExceptionHandler)XScuGic_InterruptHandler,
                                 &interrupt_controller);
    int status = XScuGic_Connect(&interrupt_controller, interrupt_id, (Xil_ExceptionHandler)handler, handler_param);
    if (status != XST_SUCCESS) {
        return -1;
    }
    XScuGic_Enable(&interrupt_controller, interrupt_id);
    Xil_ExceptionEnable();
    return 0;
}
