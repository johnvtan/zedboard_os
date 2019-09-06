#ifndef __OLED_H__
#define __OLED_H__

#include <app/hw/gpio.h>
#include <app/hw/spi.h>
#include <app/hw/oled_cmds.h>

#include <stdint.h>

#define OLED_WIDTH  SSD1306_LCDWIDTH 
#define OLED_HEIGHT SSD1306_LCDHEIGHT

#define OLED_PAGE_SIZE 8

#define OLED_ROWS (OLED_HEIGHT / OLED_PAGE_SIZE) 
#define OLED_COLS OLED_WIDTH 

#define OLED_CMD_DATA_PIN 0

class OLED
{
public:
    OLED(void);
    ~OLED(void);

    /*
     * Sets pixel in internal state. Doesn't get pushed until flush() called
     */
    int set_pixel(int x, int y);

    /*
     * Clears pixel in internal state. Doesn't get pushed until flush() called
     */
 
    int clear_pixel(int x, int y);

    /*
     * Toggles pixel in internal state. Doesn't get pushed until flush() is called
     */
    int toggle_pixel(int x, int y);

    void clear_screen(void);
    void set_box(int x, int y, int edge);

    /*
     * Pushes current screen state to hardware
     * I wonder what happens if this takes longer than 1 clock tick
     */
    int flush(void);
private:
    void init_sequence(void);
    void send_command(struct oled_cmd cmd);
    void set_command_mode(void);
    void set_data_mode(void);
    void adjust_draw_window(void);

    GPIOOut gpio;
    SPI spi;

    uint8_t screen[OLED_ROWS][OLED_COLS];
};
#endif
