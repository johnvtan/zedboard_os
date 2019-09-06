#include <kernel/platform.h>
#include <kernel/os.h> 
#include <kernel/os_config.h>
#include <kernel/os_global_funcs.h>
#include <app/snake.h>

// global OS instance - needed by tasks to use services
myOS OS;

int main() {
    init_platform();
    OS.init(run_snake_app, (Xil_ExceptionHandler)timer_int_handler, MAX_USER_PRIO);
    cleanup_platform();
    return 0;
}
