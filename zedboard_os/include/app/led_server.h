#ifndef _LED_SERVER_H__
#define _LED_SERVER_H__

#include <stdint.h>
#include <stddef.h>

#include <kernel/os.h>
#include <kernel/os_config.h>

#include <app/hw/gpio.h>

/** hardware server should be application specific and high level */

enum led_request {
   LED_SET,
   LED_CLEAR,
   LED_TOGGLE,
   LED_CHECK_SET,
};

enum led_reply {
    LED_NOW_SET,
    LED_NOW_CLEAR
};

struct led_msg_request {
    enum led_request req;
    uint32_t pin;
};

struct led_msg_reply {
    enum led_reply reply;
};

class LEDServer {
public:
    LEDServer(uint32_t base_addr);
    ~LEDServer(void);
    void run(void);
private:
    GPIOOut leds;
};

int run_led_server(void *param);
#endif
