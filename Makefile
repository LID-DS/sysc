
export CC = gcc
export RM = rm -f

CFLAGS ?= -Wall

export CCFLAGS = $(CFLAGS) -std=gnu99
export BASE_DIR = $(abspath .)

obj-m += sysc.o
sysc-objs+= src/sysc.o 
KERNELDIR ?= /lib/modules/$(shell uname -r)/build

all: driver

driver:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(shell pwd) clean
