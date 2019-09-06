#ifndef __SPI_H__
#define __SPI_H__

#include <stdint.h>
#include <stddef.h>
#include <app/hw/hw_base.h>

#define OLED_SPI_BASE_ADDR 0x41230000

/*
 * Important SPI Register definitions
 */
#define SPI_RESET 0x40
#define SPI_CTRL 0x60
#define SPI_STATUS 0x64
#define SPI_DTR 0x68
#define SPI_SSR 0x70

/*
 * Reset register values
 */
#define SPI_RESET_RESET_VAL 0x0A

/*
 * Control register bit definitions
 */
#define SPI_CTRL_MASTER_INHIBIT (1 << 8)
#define SPI_CTRL_RX_FIFO_RESET (1 << 6)
#define SPI_CTRL_TX_FIFO_RESET (1 << 5)
#define SPI_CTRL_MASTER_MODE (1 << 2)
#define SPI_CTRL_ENABLE (1 << 1)

/* 
 * Status register bit definitions
 */
#define SPI_STATUS_TX_FULL (1 << 3)
#define SPI_STATUS_TX_EMPTY (1 << 2)

class SPI
{
public:
    SPI(uint32_t base);
    ~SPI(void);
    int write(uint8_t *buf, int len);
    bool is_fifo_empty(void); 
    bool is_fifo_full(void);
    void drain(void);
    void reset(void);
private:
    void write_single(uint8_t val);
    void stupid_delay(void);
    HWBase hw;
};

#endif
