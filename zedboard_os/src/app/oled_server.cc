#include <app/oled_server.h>

extern myOS OS;

int run_oled_server(void *param) {
    (void) param;
    OledServer oled_server;
    oled_server.run();
    return 0;
}

OledServer::OledServer(void) : oled() {

}

OledServer::~OledServer(void) {

}

void OledServer::run(void) {
    OS.signal_event(OLED_SERVER_INIT, 0);
    while (1) {
        get_request();
        switch(request.req) {
            case OLED_SET_PIXEL:
                oled.set_pixel(request.x, request.y);
                break;
            case OLED_CLEAR_PIXEL:
                oled.clear_pixel(request.x, request.y);
                break;
            case OLED_TOGGLE_PIXEL:
                oled.toggle_pixel(request.x, request.y);
                break;
            case OLED_SET_BOX:
                oled.set_box(request.x, request.y, request.edge);
                break;
            case OLED_CLEAR_SCREEN:
                oled.clear_screen();
                break;
            case OLED_FLUSH:
                oled.flush();
                break;
            default:
                OS.panic("OLED server received unknown request\n\r");
                break;
        }
        send_reply();
        sender_tid = -1;
    }
} 

void OledServer::get_request(void) {
    OS.receive(&sender_tid, (void*)&request, sizeof(struct oled_msg_request));
    if (sender_tid < 0 || sender_tid >= MAX_NUM_TASKS) {
        OS.panic("Received request from unknown task id\n\r");
    }
}

void OledServer::send_reply(void) {
    reply.rep = OLED_ACK;
    OS.reply(sender_tid, (void*)&reply, sizeof(struct oled_msg_reply));
}
