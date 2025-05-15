#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include "trace.h"

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_96MHZ]);

    trace_init(TRACE_PROTOCOL_ASYNCHRONOUS, 2000000);
    trace_init_STM32F4xx();

    // LED PC13
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

    while (1) {
        gpio_toggle(GPIOC, GPIO13);
        trace("Hello");

        for (int i = 0; i < 1000000; i++)
            __asm("nop");
    }
}
