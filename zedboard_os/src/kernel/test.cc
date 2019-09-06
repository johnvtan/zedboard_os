#include <kernel/test.h>

// needed for using OS services
extern myOS OS;

// A set of tasks used for testing the system

// This test continually computes an expression whose value is known at compile time
// This task should periodically be context switched into and if it fails, then we know 
// that the task context has been corrupted.
extern "C" void context_switch_test_set_reg_values(void);
extern "C" int context_switch_test_check_reg_values(void);
int context_switch_test(void *param) {
    (void)param;
    context_switch_test_set_reg_values();
    while (1) {
        if (context_switch_test_check_reg_values() != 0) {
            OS.panic("Context switch test failed!\n\r");
        } else {
            xil_printf("Context switch test passed\n\r");
        }
    }
}

