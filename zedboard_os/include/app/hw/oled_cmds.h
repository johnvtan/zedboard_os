#ifndef __OLED_CMDS_H__
#define __OLED_CMDS_H__

#define SSD1306_LCDWIDTH    128
#define SSD1306_LCDHEIGHT   32

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF
#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA
#define SSD1306_SETVCOMDETECT 0xDB
#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9
#define SSD1306_SETMULTIPLEX 0xA8
#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10
#define SSD1306_SETSTARTLINE 0x40
#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22
#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8
#define SSD1306_SEGREMAP 0xA0
#define SSD1306_SEGREVERSE 0xA1
#define SSD1306_CHARGEPUMP 0x8D
#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A

#define OLED_INIT_CMD_SEQ_LEN 19

struct oled_cmd
{
    uint8_t cmd;
    uint8_t arg_len;
    uint8_t args[2];
};

const struct oled_cmd oled_init_cmd_sequence[OLED_INIT_CMD_SEQ_LEN] =  
    {
        { .cmd = SSD1306_DISPLAYOFF,          .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_SETDISPLAYCLOCKDIV,  .arg_len = 1, .args = {0x80, 0} }, 
        { .cmd = SSD1306_SETMULTIPLEX,        .arg_len = 1, .args = {0x1F, 0} },
        { .cmd = SSD1306_SETDISPLAYOFFSET,    .arg_len = 1, .args = {0, 0} },
        { .cmd = SSD1306_SETSTARTLINE,        .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_CHARGEPUMP,          .arg_len = 2, .args = {0x14, 0xA1} },
        { .cmd = SSD1306_COMSCANINC,          .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_SETCOMPINS,          .arg_len = 1, .args = {0x02, 0} },
        { .cmd = SSD1306_SETCONTRAST,         .arg_len = 1, .args = {0x8F, 0} },
        { .cmd = SSD1306_SETPRECHARGE,        .arg_len = 1, .args = {0xF1, 0} },
        { .cmd = SSD1306_SETVCOMDETECT,       .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_SETSTARTLINE,        .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_DISPLAYALLON_RESUME, .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_NORMALDISPLAY,       .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_DISPLAYON,           .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_MEMORYMODE,          .arg_len = 1, .args = {0x00, 0} },
        { .cmd = SSD1306_SEGREMAP,            .arg_len = 0, .args = {0, 0} },
        { .cmd = SSD1306_COLUMNADDR,          .arg_len = 2, .args = {0x00, SSD1306_LCDWIDTH-1} },
        { .cmd = SSD1306_PAGEADDR,            .arg_len = 2, .args = {0x00, SSD1306_LCDHEIGHT-1} },
    };

#endif
