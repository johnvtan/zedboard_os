#ifndef __HW_BASE_H__
#define __HW_BASE_H__

#include <stdint.h>

class HWBase
{
public:
    HWBase(uint32_t base_addr);
    ~HWBase(void);
    uint32_t read_reg(uint32_t reg_off);
    void write_reg(uint32_t reg_off, uint32_t val);
protected:
    uint32_t base;
};
#endif
