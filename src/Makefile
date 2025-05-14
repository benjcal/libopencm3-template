PROJECT = firmware
BUILD_DIR = bin

CFILES = main.c
# CFILES = main-usb.c
# CFILES += usb.c
# CFILES = main-trace.c
# CFILES += trace.c

DEVICE=stm32f411ceu6

# You shouldn't have to edit anything below here.
VPATH += $(SHARED_DIR)
INCLUDES += $(patsubst %,-I%, . $(SHARED_DIR))
OPENCM3_DIR=../libopencm3

include $(OPENCM3_DIR)/mk/genlink-config.mk
include ../rules.mk
include $(OPENCM3_DIR)/mk/genlink-rules.mk
