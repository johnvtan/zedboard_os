#ifndef __SNAKE_H__
#define __SNAKE_H__

#include <stdint.h>
#include <stddef.h>

#include <app/oled_server.h>
#include <app/btn_server.h>
#include <app/led_server.h>
#include <kernel/os.h>
#include <kernel/os_config.h>

#include "xil_printf.h"

#define MAX_SNAKE_LEN 8 

#define SNAKE_POS_TICKS 30 
#define SNAKE_SCREEN_TICKS 5
#define LED_TICKS 150

// each snake piece is 4 pixels by 4 pixels
#define SNAKE_PIECE_SIZE 4 

#define SNAKE_MAGIC 1337

#define MAX_X 128
#define MAX_Y 32

struct snake_piece
{
    int x;
    int y;
    int vx;
    int vy;
};

enum game_state
{
    GAME_RUNNING,
    GAME_WIN,
    GAME_LOSE,
};

class SnakeApp {
public:
    SnakeApp(void);
    ~SnakeApp(void);
    void run(void);
private:
    void clear_screen(void);
    void set_pixel(int x, int y);
    void clear_pixel(int x, int y);
    void flush_screen(void);
    void update_screen(void);
    void update_game(void);
    void update_leds(void);
    void process_btns(void);
    void set_led(int pin);
    void toggle_led(int pin);
    bool collision(struct snake_piece s1, struct snake_piece s2);
    uint32_t get_btn_state(void);

    int snake_len;
    struct snake_piece snake_pieces[MAX_SNAKE_LEN];
    struct snake_piece food;
    int vx;
    int vy;

    int lifetime; 
    enum game_state game_state;

    int led_server_tid;
    int btn_server_tid;
    int oled_server_tid;
};

int run_snake_app(void* param);
#endif
