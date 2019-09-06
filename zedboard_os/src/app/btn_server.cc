#include <app/btn_server.h>

extern myOS OS;

int run_btn_server(void *param) {
    (void) param;
    BtnServer btn_server;
    btn_server.run();
    return 0;
}

BtnServer::BtnServer(void) : btns(BTN_GPIO_BASE_ADDR, GPIO_CH_1) {

}

BtnServer::~BtnServer(void) {

}

void BtnServer::run(void) {
    OS.signal_event(BTN_SERVER_INIT, 0);
    while (1) {
        sender_tid = -1;
        get_request();
        switch (request.req) {
            case BTN_GET_STATE:
                reply.state = btns.get_state(); 
                break;
            default:
                OS.panic("uhhhhh btns are broken\n\r");
                break;
        }
        send_reply();
    }
}

void BtnServer::get_request(void) {
    OS.receive(&sender_tid, &request, sizeof(struct btn_msg_request));
    if (sender_tid < 0 || sender_tid > MAX_NUM_TASKS) {
        OS.panic("btn server received request from invalid task\n\r");
    }
}

void BtnServer::send_reply(void) {
    OS.reply(sender_tid, &reply, sizeof(struct btn_msg_reply));
}
