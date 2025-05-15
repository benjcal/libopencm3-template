#include "trace.h"

void trace_init(int protocol, uint32_t bitrate) {
    uint32_t clockfreq = (protocol == 1) ? 2 * bitrate : bitrate;

    SCS_DEMCR |= SCS_DEMCR_TRCENA;

    TPIU_CSPSR = 1;
    TPIU_SPPR = protocol; /* 1 = Manchester, 2 = Asynchronous */

    TPIU_ACPR = CPU_CLOCK_FREQ / clockfreq - 1;
    TPIU_FFCR = 0;

    ITM_LAR = 0xC5ACCE55;
    ITM_TCR = ITM_TCR_SWOENA | ITM_TCR_ITMENA;
    ITM_TPR = 0;

    ITM_TER[0] = 1;
}

void trace_init_STM32F4xx(void) {
    rcc_periph_clock_enable(RCC_GPIOB);
    gpio_mode_setup(GPIOB, GPIO_MODE_AF, GPIO_PUPD_NONE, GPIO3);
    gpio_set_af(GPIOB, GPIO_AF0, GPIO3);
    DBGMCU_CR |= DBGMCU_CR_TRACE_IOEN;
}

void trace(const char *msg) {
    while (!(ITM_STIM8(0) & ITM_STIM_FIFOREADY))
        ;
    while (*msg != '\0')
        ITM_STIM8(0) = *msg++;
}

void tracec(char c) {
    while (!(ITM_STIM8(0) & ITM_STIM_FIFOREADY))
        ;

    ITM_STIM8(0) = c;
}