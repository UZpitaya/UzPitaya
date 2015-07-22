CC=$(CROSS_COMPILE)gcc
RM=rm

OBJECTS=main.o fpga.o worker.o calib.o fpga_awg.o

#CFLAGS=$(CFLAGS) -Wall -Werror -g
CFLAGS+= -Wall -Werror -g -fPIC $(INCLUDE)
LDFLAGS=-shared


OUT_DIR ?= ../
CONTROLLER ?= $(OUT_DIR)controller.so

all: $(OBJECTS)

make_c_app: $(OBJECTS)
	$(CC) -o $(CONTROLLER) $(OBJECTS) $(CFLAGS) $(LDFLAGS)

clean::
	-$(RM) -f $(C_OUT_NAME) $(OBJECTS)
