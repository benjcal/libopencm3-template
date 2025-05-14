#ifndef USB_H
#define USB_H

#include <libopencm3/stm32/gpio.h>
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/usb/cdc.h>
#include <libopencm3/usb/dwc/otg_fs.h>
#include <libopencm3/usb/usbd.h>
#include <stddef.h>

void usb_setup(void);
void usb_poll(void);
void usb_send(const char *data, int len);
int usb_data_available(void);
int usb_read_data(char *buf, int maxlen);

#endif // USB_H