#include <app/snake.h>

extern myOS OS;

int run_snake_app(void *param) {
    (void) param;
    SnakeApp snake_app;
    snake_app.run();
    return 0;
}

SnakeApp::SnakeApp(void) {
    game_state = GAME_RUNNING;

    // Initialize snake position and velocity
    snake_len = 1;
    snake_pieces[0].x = 64;
    snake_pieces[0].y = 16;

    vx = 1;
    vy = 0;
    lifetime = LED_TICKS;

    // Initialize food position
    food.x = 104;
    food.y = 16;

    // initialize servers
    oled_server_tid = OS.create(run_oled_server, NULL, MAX_USER_PRIO);
    OS.await_event(OLED_SERVER_INIT);

    led_server_tid = OS.create(run_led_server, NULL, MAX_USER_PRIO);
    OS.await_event(LED_SERVER_INIT);

    btn_server_tid = OS.create(run_btn_server, NULL, MAX_USER_PRIO);
    OS.await_event(BTN_SERVER_INIT);
}

SnakeApp::~SnakeApp(void) {

}

void SnakeApp::run(void) {
    uint64_t curr_time = OS.get_time();
    uint64_t last_screen_update = curr_time;
    uint64_t last_pos_update = curr_time;
    uint64_t last_led_update = curr_time;
    while (1) {
        OS.sleep(0);
        process_btns();
        curr_time = OS.get_time();
        if (game_state == GAME_RUNNING && curr_time > last_pos_update + SNAKE_POS_TICKS) {
            update_game();
            last_pos_update = curr_time;
        }
        if (curr_time > last_led_update + lifetime) {
            update_leds();
            last_led_update = curr_time;
        }
        if (curr_time > last_screen_update + SNAKE_SCREEN_TICKS) {
            clear_screen();
            update_screen();
            last_screen_update = curr_time;
        }
        if (game_state == GAME_WIN || game_state == GAME_LOSE) {
            xil_printf("Game over\n\r");
        }
    }
}

void SnakeApp::clear_screen(void) {
    struct oled_msg_request req;
    struct oled_msg_reply rp;
    req.req = OLED_CLEAR_SCREEN;
    OS.send(oled_server_tid, &req, sizeof(struct oled_msg_request), &rp, sizeof(struct oled_msg_reply));
    if (rp.rep != OLED_ACK) {
        OS.panic("not sure what happened when sending to oled");
    }
}

void SnakeApp::set_pixel(int x, int y) {
    struct oled_msg_request req;
    struct oled_msg_reply rp;
    req.req = OLED_SET_BOX;
    req.x = x;
    req.y = y;
    req.edge = SNAKE_PIECE_SIZE;
    OS.send(oled_server_tid, &req, sizeof(struct oled_msg_request), &rp, sizeof(struct oled_msg_reply));
    if (rp.rep != OLED_ACK) {
        OS.panic("not sure what happened when sending to oled");
    }
}

void SnakeApp::clear_pixel(int x, int y) {
    struct oled_msg_request req;
    struct oled_msg_reply rp;
    req.req = OLED_CLEAR_PIXEL;
    req.x = x;
    req.y = y;
    OS.send(oled_server_tid, &req, sizeof(struct oled_msg_request), &rp, sizeof(struct oled_msg_reply));
    if (rp.rep != OLED_ACK) {
        OS.panic("not sure what happened when sending to oled");
    }

}

void SnakeApp::update_screen(void) {
    if (game_state == GAME_LOSE) {
        clear_screen();
    } else if (game_state == GAME_WIN) {
        for (int i = 0; i < MAX_X; i++) {
            for (int j = 0; j < MAX_Y; j++) {
                set_pixel(i, j);
            }
        } 
    } else {
        for (int i = 0; i < snake_len; i++) {
            set_pixel(snake_pieces[i].x, snake_pieces[i].y);
        }

        set_pixel(food.x, food.y);
    }

    flush_screen();
}

void SnakeApp::flush_screen(void) {
    struct oled_msg_request req;
    struct oled_msg_reply rp;
    req.req = OLED_FLUSH;
    OS.send(oled_server_tid, &req, sizeof(struct oled_msg_request), &rp, sizeof(struct oled_msg_reply));
    if (rp.rep != OLED_ACK) {
        OS.panic("not sure what happened when sending to oled");
    }
}

void SnakeApp::update_game(void) {
    if (lifetime-- < 5) {
        game_state = GAME_LOSE;
        lifetime = LED_TICKS;
        for (int i = 0; i < 8; i++) {
            set_led(i);
        }
        return;
    }
    struct snake_piece next;
    // update snake pieces behind the head
    for (int i = snake_len-1; i > 0 ; i--) {
        next = snake_pieces[i-1];
        snake_pieces[i].x = next.x - (snake_pieces[i].vx * SNAKE_PIECE_SIZE);
        snake_pieces[i].y = next.y - (snake_pieces[i].vy * SNAKE_PIECE_SIZE);
        snake_pieces[i].vx = next.vx;
        snake_pieces[i].vy = next.vy;
    }

    struct snake_piece head = snake_pieces[0];
    head.x += vx * SNAKE_PIECE_SIZE;
    head.y += vy * SNAKE_PIECE_SIZE;
    head.vx = vx;
    head.vy = vy;

    if (head.x > MAX_X-1) {
        head.x = 0;
    } else if (head.x <= 0) {
        head.x = MAX_X-1;
    }

    if (head.y > MAX_Y-1) {
        head.y = 0;
    } else if (head.y <= 0) {
        head.y = MAX_Y-1;
    }

    // If snake runs into itself
    for (int i = 1; i < snake_len; i++) {
        if (head.x == snake_pieces[i].x && head.y == snake_pieces[i].y) {
            game_state = GAME_LOSE;
            return;
        }
    }

    // collision detection
    if (collision(head, food)) {
        // add new snake piece to the end
        struct snake_piece tail = snake_pieces[snake_len-1];

        // the new tail should spawn behind the old tail and move in the same direction
        snake_pieces[snake_len].x = tail.x - (tail.vx * 2 * SNAKE_PIECE_SIZE);
        snake_pieces[snake_len].y = tail.y - (tail.vy * 2 * SNAKE_PIECE_SIZE);
        snake_pieces[snake_len].vx = tail.vx;
        snake_pieces[snake_len].vy = tail.vy;
        snake_len += 1;
        lifetime = LED_TICKS;

        // spawn new food location
        food.x = (SNAKE_MAGIC + food.x) % MAX_X;
        food.y = (SNAKE_MAGIC + food.y) % MAX_Y;
    }

    snake_pieces[0] = head;
    // check win condition
    if (snake_len == MAX_SNAKE_LEN) {
        game_state = GAME_WIN;
    }
}

void SnakeApp::update_leds(void) {
    static int prev_snake_len = 1;

    if (game_state != GAME_RUNNING) {
        for (int i = 0; i < 8; i++) {
            toggle_led(i);
        }
    } else if (snake_len > prev_snake_len) {
        set_led(prev_snake_len-1);
        prev_snake_len += 1;
        toggle_led(prev_snake_len-1);
    } else {
        toggle_led(prev_snake_len-1);
    }
}

void SnakeApp::set_led(int pin) {
    struct led_msg_request req;
    struct led_msg_reply rp;
    req.req = LED_SET;
    req.pin = pin;
    OS.send(led_server_tid, &req, sizeof(struct led_msg_request), &rp, sizeof(struct led_msg_reply));
    if (rp.reply != LED_NOW_SET) {
        OS.panic("whaaaaaaaaaaaaat\n\r");
    }
}

void SnakeApp::toggle_led(int pin) {
    struct led_msg_request req;
    struct led_msg_reply rp;
    req.req = LED_TOGGLE;
    req.pin = pin;
    OS.send(led_server_tid, &req, sizeof(struct led_msg_request), &rp, sizeof(struct led_msg_reply));
}

void SnakeApp::process_btns(void) {
    uint32_t pressed_btns = get_btn_state();

    if (pressed_btns & RIGHT_BTN && vx != -1) {
        vx = 1;
        vy = 0;
    } else if (pressed_btns & LEFT_BTN && vx != 1) {
        vx = -1;
        vy = 0;
    }

    if (pressed_btns & UP_BTN && vy != 1) {
        vy = -1;
        vx = 0;
    } else if (pressed_btns & DOWN_BTN && vy != -1) {
        vy = 1;
        vx = 0;
    }
}

bool SnakeApp::collision(struct snake_piece s1, struct snake_piece s2) {
    int top1 = s1.y;
    int top2 = s2.y;
    int bottom1 = s1.y + SNAKE_PIECE_SIZE-1;
    int bottom2 = s2.y + SNAKE_PIECE_SIZE-1;
    int left1 = s1.x;
    int left2 = s2.x;
    int right1 = s1.x + SNAKE_PIECE_SIZE-1;
    int right2 = s2.x + SNAKE_PIECE_SIZE-1;

    if (top1 >= bottom2)
        return false;
    if (top2 >= bottom1)
        return false;
    if (left1 >= right2)
        return false;
    if (left2 >= right1)
        return false;

    return true;
}

uint32_t SnakeApp::get_btn_state(void) {
    struct btn_msg_request req;
    struct btn_msg_reply rp;
    req.req = BTN_GET_STATE;
    OS.send(btn_server_tid, &req, sizeof(struct btn_msg_request), &rp, sizeof(btn_msg_reply));
    return rp.state;
}
