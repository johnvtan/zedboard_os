#ifndef __CLOCK_TASK_H__
#define __CLOCK_TASK_H__

#include <stdint.h>
#include <stddef.h>
#include <kernel/os.h>
#include <kernel/os_config.h>

enum clock_message_request {
    CLOCK_MSG_INCREMENT_TICK,
    CLOCK_MSG_GET_TIME,
};

struct clock_request {
    enum clock_message_request request;
};

enum clock_message_reply {
    CLOCK_REPLY_ACK,
};

struct clock_reply {
    enum clock_message_reply ack;
    uint64_t time_ms; // in ms
};

#endif
