#ifndef __BTN_SERVER_H__
#define __BTN_SERVER_H__

#include <app/hw/gpio.h>
#include <kernel/os.h>
#include <kernel/os_config.h>

#define CENTER_BTN 1
#define DOWN_BTN 2
#define LEFT_BTN 4
#define RIGHT_BTN 8
#define UP_BTN 16

enum btn_req {
    BTN_GET_STATE,
};

struct btn_msg_request {
    enum btn_req req;
};

struct btn_msg_reply {
    uint32_t state;
};

class BtnServer
{
public:
    BtnServer(void);
    ~BtnServer(void);
    void run(void);
private:
    void get_request(void);
    void send_reply(void);
    GPIOIn btns;
    int sender_tid;
    struct btn_msg_request request;
    struct btn_msg_reply reply;
};

int run_btn_server(void *param);
#endif
