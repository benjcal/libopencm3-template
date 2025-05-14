#include <string.h>

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>

#include "usb.h"

int main(void) {
    rcc_clock_setup_pll(&rcc_hse_25mhz_3v3[RCC_CLOCK_3V3_96MHZ]);

    usb_setup();

    // LED PC13
    rcc_periph_clock_enable(RCC_GPIOC);
    gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

    int i = 1;
    while (1) {
        usb_poll();
        i++;

        // blink
        if (i == 100000) {
            i = 0;
            gpio_toggle(GPIOC, GPIO13);
        }

        // echo
        if (usb_data_available()) {
            char buf[64] = {0};
            usb_read_data(buf, 64);

            usb_send(buf, strlen(buf));
        }
    }
}
