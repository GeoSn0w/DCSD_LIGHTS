CC = gcc
TARGET = DCSD_LIGHTS

CFLAGS ?=
LDFLAGS ?=

ifeq ($(shell uname), Darwin)
	CFLAGS += -c -Wall -I. -I/usr/local/Cellar/libftdi/1.4/include/libftdi1/ -g
	LDFLAGS += -L/usr/local/Cellar/libftdi/1.4/lib -L/usr/local/Cellar/libusb/1.0.22/lib -lftdi1 -lusb-1.0
endif

OBJECTS = program.o

all : $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ $(LDFLAGS)

%.o : %.c
	$(CC) $(CFLAGS) -o $@ $<

clean : 
	rm -rf $(OBJECTS) $(TARGET)
