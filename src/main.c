#include "libopencm3/stm32/gpio.h"
#include "libopencm3/stm32/rcc.h"

int main(void) {
  rcc_periph_clock_enable(RCC_GPIOC);

  gpio_mode_setup(GPIOC, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, GPIO13);

  while (1) {
    gpio_toggle(GPIOC, GPIO13);
    for (int i = 0; i < 1000000; ++i)
      ;
  }
}
