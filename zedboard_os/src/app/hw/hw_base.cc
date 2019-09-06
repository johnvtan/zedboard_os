#include <app/hw/hw_base.h>

HWBase::HWBase(uint32_t base_addr) : base(base_addr) {
}

HWBase::~HWBase(void) {

}

uint32_t HWBase::read_reg(uint32_t reg_off) {
    // base is a uint32_t
    uint32_t addr = base + reg_off;
    return *(volatile uint32_t *)addr;
}

void HWBase::write_reg(uint32_t reg_off, uint32_t val) {
    // base is a uint32_t
    uint32_t addr = base + reg_off;
    *(volatile uint32_t *)addr = val;
}
