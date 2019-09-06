#include <app/hw/oled.h>
#include <kernel/os.h>

extern myOS OS;

OLED::OLED(void) : gpio(LED_GPIO_BASE_ADDR, GPIO_CH_2), spi(OLED_SPI_BASE_ADDR)
{
   init_sequence();

   clear_screen();
   set_command_mode();
   adjust_draw_window();
   set_data_mode();
   flush();
}

OLED::~OLED(void) {

}

void OLED::clear_screen(void) {
    // clear screen
   for (int i = 0; i < OLED_ROWS; i++) {
       for (int j = 0; j < OLED_COLS; j++) {
           screen[i][j] = 0;
       }
   }
}

int OLED::set_pixel(int x, int y) {
    if (x < 0 || x >= OLED_WIDTH) {
        return -1;
    }

    if (y < 0 || y >= OLED_HEIGHT) {
        return -1;
    }

    int y_index = y / OLED_PAGE_SIZE;
    int y_mod = y % OLED_PAGE_SIZE; 
    screen[y_index][x] |= (1 << y_mod);
    return 0;
}

int OLED::clear_pixel(int x, int y) {
    if (x < 0 || x >= OLED_WIDTH) {
        return -1;
    }

    if (y < 0 || y >= OLED_HEIGHT) {
        return -1;
    }
    int y_index = y / OLED_PAGE_SIZE;
    int y_mod = y % OLED_PAGE_SIZE;
    screen[y_index][x] &= ~(1 << y_mod);
    return 0;
}

int OLED::toggle_pixel(int x, int y) {
    if (x < 0 || x >= OLED_WIDTH) {
        return -1;
    }

    if (y < 0 || y >= OLED_HEIGHT) {
        return -1;
    }
    int y_index = y / OLED_PAGE_SIZE;
    int y_mod = y % OLED_PAGE_SIZE;
    screen[y_index][x] ^= (1 << y_mod);
    return 0;
}

// sets a 3x3 box centered at x,y
void OLED::set_box(int x, int y, int edge) {
    for (int i = 0; i < edge; i++) {
        for (int j = 0; j < edge; j++) {
            set_pixel(x+i, y+j);
        }
    }
}

int OLED::flush(void) {
    int written = 0;
    int rv = 0;
    for (int i = 0; i < OLED_ROWS; i++) {
        rv = spi.write(screen[i], OLED_WIDTH);
        if (rv > 0) {
            written += rv;
        }
    }
    return written;
}

// voodoo magic to turn on the OLED
void OLED::init_sequence(void) {
    spi.reset();

    gpio.set_state(0xE);
    OS.sleep(1);
    gpio.set_state(0x6);

    struct oled_cmd cmd;
    cmd.cmd = 0xAE;
    cmd.arg_len = 0;

    send_command(cmd);

    gpio.set_state(0x4);
    OS.sleep(10);
    gpio.set_state(0x6);

    cmd.cmd = 0x8D;
    cmd.arg_len = 1;
    cmd.args[0] = 0x14;
    send_command(cmd);

    cmd.cmd = 0xD9;
    cmd.arg_len = 1;
    cmd.args[0] = 0xF1;
    send_command(cmd);

    gpio.set_state(0x2);
    OS.sleep(30);

    cmd.cmd = 0x81;
    cmd.arg_len = 1;
    cmd.args[0] = 0x0F;
    send_command(cmd);

    cmd.cmd = 0xA0;
    cmd.arg_len = 0;
    send_command(cmd);

    cmd.cmd = 0xC0;
    cmd.arg_len = 0;
    send_command(cmd);

    cmd.cmd = 0xDA;
    cmd.arg_len = 1;
    cmd.args[0] = 0;
    send_command(cmd);

    cmd.cmd = 0xA6;
    cmd.arg_len = 0;
    send_command(cmd);

    cmd.cmd = 0xAF;
    cmd.arg_len = 0;
    send_command(cmd);

    cmd.cmd = SSD1306_DISPLAYALLON_RESUME;
    cmd.arg_len = 0;
    send_command(cmd);

    set_command_mode();
}

void OLED::send_command(struct oled_cmd cmd) {
    spi.write(&cmd.cmd, 1);
    spi.write(cmd.args, cmd.arg_len);
    spi.drain();
}

void OLED::set_command_mode(void) {
    gpio.clear(OLED_CMD_DATA_PIN);
}

void OLED::set_data_mode(void) {
    gpio.set(OLED_CMD_DATA_PIN);
}

void OLED::adjust_draw_window(void) {
    struct oled_cmd cmd;
    cmd.cmd = SSD1306_MEMORYMODE;
    cmd.arg_len = 1;
    cmd.args[0] = 0;
    send_command(cmd);

    cmd.cmd = SSD1306_SEGREMAP;
    cmd.arg_len = 0;
    send_command(cmd);

    cmd.cmd = SSD1306_COLUMNADDR;
    cmd.arg_len = 2;
    cmd.args[0] = 0;
    cmd.args[1] = SSD1306_LCDWIDTH-1;
    send_command(cmd);

    cmd.cmd = SSD1306_PAGEADDR;
    cmd.arg_len = 2;
    cmd.args[0] = 0;
    cmd.args[1] = SSD1306_LCDHEIGHT-1;
    send_command(cmd);
}
