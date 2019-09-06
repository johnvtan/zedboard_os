#ifndef __OLED_SERVER_H__
#define __OLED_SERVER_H__

#include <app/hw/oled.h>
#include <kernel/os.h>
#include <kernel/os_config.h>

#include <stdint.h>
#include <stddef.h>

enum oled_request
{
    OLED_SET_PIXEL,
    OLED_CLEAR_PIXEL,
    OLED_TOGGLE_PIXEL,
    OLED_SET_BOX,
    OLED_CLEAR_SCREEN,
    OLED_FLUSH
};

enum oled_reply
{
    OLED_ACK,
};

struct oled_msg_request
{
    enum oled_request req;
    int x;
    int y;
    int edge;
};

struct oled_msg_reply
{
    enum oled_reply rep;
};

class OledServer
{
public:
    OledServer(void);
    ~OledServer(void);
    void run(void);
private:
    struct oled_msg_request request;
    struct oled_msg_reply reply;
    int sender_tid;

    void send_reply(void);
    void get_request(void);
    OLED oled;
};

int run_oled_server(void *param);

#endif
