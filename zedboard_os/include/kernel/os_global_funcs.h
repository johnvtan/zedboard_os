#ifndef __OS_GLOBAL_FUNCS_H__
#define __OS_GLOBAL_FUNCS_H__

void timer_int_handler(void *param);
void task_wrapper(int (*task)(void*), void *param);

#endif
