#include <app/hw/spi.h>
#include <kernel/os.h>
#include <xparameters.h>
#include <xspi.h>

// for delays, for now
extern myOS OS;

SPI::SPI(uint32_t base) : hw(base) {

}

SPI::~SPI(void) {

}

int SPI::write(uint8_t *buf, int len) {
    if (len <= 0 || buf == NULL) {
        return -1;
    }

    int written = len;
    while (len--) {
        write_single(*buf++);
    }

    return written;
}

bool SPI::is_fifo_empty(void) {
    bool rv = ((hw.read_reg(SPI_STATUS) & SPI_STATUS_TX_EMPTY) > 0);
    return rv; 
}

bool SPI::is_fifo_full(void) {
    bool rv = ((hw.read_reg(SPI_STATUS) & SPI_STATUS_TX_FULL) > 0);
    return rv;
}

void SPI::drain(void) {
    // ctrl reg is r/w
    uint32_t ctrl_state = hw.read_reg(SPI_CTRL);
    ctrl_state = SPI_CTRL_ENABLE | SPI_CTRL_MASTER_MODE;
    ctrl_state &= ~(SPI_CTRL_MASTER_INHIBIT);
    hw.write_reg(SPI_CTRL, ctrl_state);
    ctrl_state = hw.read_reg(SPI_CTRL);

    stupid_delay();
    while (!is_fifo_empty()) {
        // wait for fifo to be empty. or not full?
    }

    ctrl_state = hw.read_reg(SPI_CTRL);
    ctrl_state = SPI_CTRL_MASTER_INHIBIT | SPI_CTRL_MASTER_MODE;
    ctrl_state &= ~(SPI_CTRL_ENABLE);
    hw.write_reg(SPI_CTRL, ctrl_state);
    ctrl_state = hw.read_reg(SPI_CTRL);
    ctrl_state = 0;
}

void SPI::reset(void) {
	hw.write_reg(SPI_RESET, SPI_RESET_RESET_VAL);
}

void SPI::write_single(uint8_t val) {
    if (is_fifo_full()) {
        drain();
    }
    hw.write_reg(SPI_DTR, val); 
}

// oled is dumb
void SPI::stupid_delay(void) {
    int ticks = 6667;
    while (ticks--) {
        asm volatile("nop");
    }
}
