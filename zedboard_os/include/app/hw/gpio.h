#ifndef __GPIO_H__
#define __GPIO_H__

#include <stdint.h>
#include <app/hw/hw_base.h>

#define PMOD_GPIO_BASE_ADDR 0x411F0000UL
#define LED_GPIO_BASE_ADDR 0x41200000UL
#define SW_GPIO_BASE_ADDR 0x41210000UL
#define BTN_GPIO_BASE_ADDR 0x41220000UL

/** Register offsets */
#define GPIO_DATA 0x0000
#define GPIO_TRI 0x0004
#define GPIO2_DATA 0x0008
#define GPIO2_TRI 0x000C
#define GIER 0x011C
#define IP_IER 0x0128
#define IP_ISR 0x0120

enum gpio_channel
{
    GPIO_CH_1,
    GPIO_CH_2,
};

class GPIOOut
{
public:
    GPIOOut(uint32_t base, enum gpio_channel channel);
    ~GPIOOut(void);
    void set_state(uint32_t new_state);
    void set(uint8_t pin);
    void clear(uint8_t pin);
    void toggle(uint8_t pin);
    bool is_set(uint8_t pin);
private:
    HWBase hw;
    uint32_t state;
    uint32_t data;
    uint32_t tri;
};

class GPIOIn
{
public:
    GPIOIn(uint32_t base, enum gpio_channel channel);
    ~GPIOIn(void);
    uint32_t get_state(void);
    bool is_set(uint8_t pin);
    bool is_clear(uint8_t pin);
private:
    HWBase hw;
    uint32_t data;
    uint32_t tri;
};

#endif
