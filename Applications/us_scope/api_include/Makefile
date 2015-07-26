# Ultrasound stimulator include Makefile

OBJECTS=button_dir generate_burst
RM=rm

CROSS_COMPILE?=arm-linux-gnueabi-
CC=$(CROSS_COMPILE)gcc
CFLAGS+= -Wall -Werror -g

OUT_DIR = ../../objs/

all:
	-mkdir ../objs
	for inc in $(OBJECTS); do \
		$(MAKE) -C $$inc all CROSS_COMPILE=$(CROSS_COMPILE) OUT_DIR=$(OUT_DIR); \
	done

clean:
	for inc in $(OBJECTS); do \
		$(MAKE) -C $$inc clean CROSS_COMPILE=$(CROSS_COMPILE); \
	done
	rm -rf ../objs/
