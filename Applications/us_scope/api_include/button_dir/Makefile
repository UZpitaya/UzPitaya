#
#  Red Pitaya Ultrasound stimulator Makefile
#

CROSS_COMPILE = arm-linux-gnueabi-

#Define header includes
RP_PATH_INCLUDE = -I ../include/

#Define library includes
RP_LIB_INCLUDE = -L ../include/ -lm -lpthread -lrp

#Cross compiler definition
CC = $(CROSS_COMPILE)gcc
#Flags
CFLAGS = -g -std=gnu99 -Wall -Werror
#Objects
OBJECTS = btn.o
#Target file
TARGET = button_press

OUT_DIR ?= ../

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(RP_LIB_INCLUDE)
	cp $(TARGET) $(OUT_DIR)	

%.o: %.c
	$(CC) -c $(CFLAGS) $(RP_PATH_INCLUDE) $< -o $@

#Build the executable
all: $(TARGET)

clean:
	$(RM) $(TARGET) *.o ~* 
