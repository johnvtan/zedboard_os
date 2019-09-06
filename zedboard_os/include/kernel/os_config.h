#ifndef __OS_CONFIG_H__
#define __OS_CONFIG_H__

#define MAX_NUM_TASKS 32
#define TASK_STACK_SIZE 8192 
#define TASK_NAME_SIZE 16

#define MAX_SYS_PRIO 0
#define MAX_USER_PRIO 4
#define MIN_USER_PRIO 30
#define MIN_SYS_PRIO 31

#define TIMER_EVENT 0
#define LED_SERVER_INIT 1
#define OLED_SERVER_INIT 2
#define BTN_SERVER_INIT 3
#define NUM_EVENTS 4

#endif
