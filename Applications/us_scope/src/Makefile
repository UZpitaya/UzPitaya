CROSS_COMPILE ?= arm-linux-gnueabi-
CC = $(CROSS_COMPILE)gcc
RM=rm

OBJECTS=main.o fpga.o worker.o calib.o fpga_awg.o

#CFLAGS=$(CFLAGS) -Wall -Werror -g
CFLAGS+= -Wall -Werror -g -fPIC $(INCLUDE)
LDFLAGS=-shared


OUT_DIR ?= ../
C_OUT_NAME = $(OUT_DIR)/controller.so

all: $(OBJECTS)
	$(CC) -o $(C_OUT_NAME) $(OBJECTS) $(CFLAGS) $(LDFLAGS) 

clean:
	-$(RM) -f $(OBJECTS) $(C_OUT_NAME)
