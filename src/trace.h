#ifndef TRACE_H
#define TRACE_H

#include <stdint.h>

#include <libopencm3/cm3/itm.h>
#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/tpiu.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#define CPU_CLOCK_FREQ 96000000

void trace_init(int protocol, uint32_t bitrate);
void trace_init_STM32F4xx(void);
void trace(const char *msg);

#endif // TRACE_H