#ifndef TRACE_H
#define TRACE_H

#include <stdint.h>

#include <libopencm3/cm3/itm.h>
#include <libopencm3/cm3/scs.h>
#include <libopencm3/cm3/tpiu.h>
#include <libopencm3/stm32/dbgmcu.h>
#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

// Update this
#define CPU_CLOCK_FREQ 96000000

#define TRACE_PROTOCOL_MANCHESTER 1
#define TRACE_PROTOCOL_ASYNCHRONOUS 2 /* UART */

void trace_init(int protocol, uint32_t bitrate);
void trace_init_STM32F4xx(void);
void trace(const char *msg);
void tracec(char c);

#endif // TRACE_H