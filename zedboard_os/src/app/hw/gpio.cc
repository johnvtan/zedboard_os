#include <app/hw/gpio.h>

GPIOOut::GPIOOut(uint32_t base, enum gpio_channel channel) : hw(base)
{
    state = 0; 
    if (channel == GPIO_CH_1) {
        data = GPIO_DATA;
        tri = GPIO_TRI;
    } else if (channel == GPIO_CH_2) {
        data = GPIO2_DATA;
        tri = GPIO2_TRI;
    }

    // default state is output
    hw.write_reg(tri, 0);

}

GPIOOut::~GPIOOut(void) {

}

void GPIOOut::set_state(uint32_t new_state) {
    state = new_state;
    hw.write_reg(data, state);
}

void GPIOOut::set(uint8_t pin) {
    state |= (1 << pin);
    hw.write_reg(data, state);
}

void GPIOOut::clear(uint8_t pin) {
    state &= ~(1 << pin);
    hw.write_reg(data, state);
}

void GPIOOut::toggle(uint8_t pin) {
    state ^= (1 << pin);
    hw.write_reg(data, state);
}

bool GPIOOut::is_set(uint8_t pin) {
    return ((1 << pin) & state) > 0;
}

/*
 * GPIO Input base class implementation
 */
GPIOIn::GPIOIn(uint32_t base, enum gpio_channel channel) : hw(base)
{
    if (channel == GPIO_CH_1) {
        data = GPIO_DATA;
        tri = GPIO_TRI;
    } else if (channel == GPIO_CH_2) {
        data = GPIO2_DATA;
        tri = GPIO2_TRI;
    }

    // set as input
    hw.write_reg(tri, 0xFF);
}

GPIOIn::~GPIOIn(void) {

}

uint32_t GPIOIn::get_state(void) {
    uint32_t rv = hw.read_reg(data);
    return rv;
}

bool GPIOIn::is_set(uint8_t pin) {
    bool rv = (hw.read_reg(data) & (1 << pin)) > 0;
    return rv;
}

bool GPIOIn::is_clear(uint8_t pin) {
    return !is_set(pin);
}
