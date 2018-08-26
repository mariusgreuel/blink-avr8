#
# makefile
# Copyright (C) 2018 Marius Greuel. All rights reserved.
#

ifndef MY_TOOLCHAIN_AVR8
    $(error error : environment variable MY_TOOLCHAIN_AVR8 is not defined. MY_TOOLCHAIN_AVR8 must point to the tools-avr8 repository)
endif

BOARD ?= ArduinoUno
#BOARD ?= ArduinoNano
#BOARD ?= Digispark
#BOARD ?= DigisparkPro
#BOARD ?= ProMicro
#BOARD ?= FabISP
#BOARD ?= USBASP

SOURCES = main.cpp
CPPFLAGS = -DBOARD_$(BOARD)

include $(MY_TOOLCHAIN_AVR8)/build/boards.mk
include $(MY_TOOLCHAIN_AVR8)/build/avr8.mk
