
TOOL_PREFIX?=
#TOOL_PREFIX?=arm-buildroot-linux-uclibcgnueabihf-

CC = $(TOOL_PREFIX)gcc
CXX = $(TOOL_PREFIX)g++
AR = $(TOOL_PREFIX)ar
RANLIB = $(TOOL_PREFIX)ranlib


TARGET = lc_test

SOURCES += $(wildcard *.c array/*.c list/*.c sort/*c)

INCLUDES += -I./


OBJS += $(SOURCES:%.c=%.o)


CFLAFS = -O2 -Wall -std=c11
LD_FLAGS = -lrt 


all:$(TARGET)

$(TARGET):$(OBJS)
	$(CC) -o $@ $(OBJS) $(CFLAFS) $(LD_FLAGS)
	@rm -r  $(OBJS)

%.o:%.c
	@$(CC) $(CFLAFS) -c $^ -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS) $(TARGET)


.PHONY:all clean
.PHONY:$(TARGET)
