
#
#  Red Pitaya Makefile
#

CROSS_COMPILE ?= arm-linux-gnueabi-
CC = $(CROSS_COMPILE)gcc

#Define header includes
RP_PATH_INCLUDE = -I ../include/

#Define library includes
RP_LIB_INCLUDE = -L ../include/ -lm -lpthread -lrp

#Flags
CFLAGS = -g -std=gnu99 -Wall -Werror
#Objects
OBJECTS = generate_burst.o
#Target file
TARGET = generate_burst
OUT_DIR ?= ../ 

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(RP_LIB_INCLUDE)
	-cp $(TARGET) $(OUT_DIR) 

%.o: %.c
	$(CC) -c $(CFLAGS) $(RP_PATH_INCLUDE) $< -o $@

clean:
	-$(RM) $(TARGET) *.o ~* 
