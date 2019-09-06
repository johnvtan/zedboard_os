#include <app/led_server.h>

extern myOS OS;

int run_led_server(void *param) {
    LEDServer led_server(LED_GPIO_BASE_ADDR);
    led_server.run();
    return 0;
} 

LEDServer::LEDServer(uint32_t base_addr) : leds(base_addr, GPIO_CH_1) {

}

LEDServer::~LEDServer(void) {

}

void LEDServer::run(void) {
    OS.signal_event(LED_SERVER_INIT, 0);
    struct led_msg_request request;    
    struct led_msg_reply reply;
    int tid = -1;
    while (1) {
        OS.receive(&tid, (void*)&request, sizeof(led_msg_request));
        if (request.pin > 8) {
            OS.panic("how many pins do you think i have\n\r");
        }
        switch(request.req) {
            case LED_SET:
                leds.set(request.pin);
                reply.reply = LED_NOW_SET;
                break;
            case LED_CLEAR:
                leds.clear(request.pin);
                reply.reply = LED_NOW_CLEAR;
                break;
            case LED_TOGGLE:
                leds.toggle(request.pin);
            case LED_CHECK_SET:
                // LED_TOGGLE should fall through to here
                reply.reply = leds.is_set(request.pin) ? LED_NOW_SET : LED_NOW_CLEAR;
                break;
            default:
                break;
        }
        OS.reply(tid, (void*)&reply, sizeof(led_msg_reply));
    }
}
