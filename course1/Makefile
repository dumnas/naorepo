#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Introduction to Embedded Systems Module 2 [Week 2 Application Assignment]
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#   We support two platforms; the host environment and the target embedded system MSP432.
#
# Platform Overrides:
#   The host system will allow you to simulate software on a host platform.
#   The target system will be used in upcoming assignments as we begin to create
#   our microcontroller applications.
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides
#PLATFORM = HOST

BASENAME = course1


#########################################################
# make all PLATFORM=HOST (no spaces before and after '='
#########################################################

#CC = gcc
ifeq ($(PLATFORM), HOST)
  #CC = gcc -DHOST -DCOURSE1 -DVERBOSE
  CC = gcc -DHOST -DCOURSE1
  LDFLAGS = -Wl,-Map=$(MAPFILE)
  CPPFLAGS =
  CFLAGS = -Wall -Werror -g -O0 -std=c99
endif

ifeq ($(PLATFORM), MSP432)

  # Architectures Specific Flags
  LINKER_FILE = -T msp432p401r.lds
  CPU   = cortex-m4
  ARCH  = armv7e-m
  FLOAT = hard
  FPU   = fpv4-sp-d16
  SPECS = nosys.specs

  CC = arm-none-eabi-gcc -DMSP432
  LDFLAGS = -Wl,-Map=$(MAPFILE) $(LINKER_FILE)
  CPPFLAGS =
  CFLAGS = -mcpu=$(CPU) -mthumb -march=$(ARCH) -mfloat-abi=$(FLOAT) \
           -mfpu=$(FPU) --specs=$(SPECS) -Wall -Werror -g -O0 -std=c99
endif


TARGET  = $(BASENAME).out
MAPFILE = $(BASENAME).map
OBJS   = $(SOURCES:.c=.o)

PROJECT_ASM = $(BASENAME).asm


.PHONY: build
build: all

.PHONY: all
all: $(TARGET)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) $(MAPFILE) *.i *.d *.asm

%.o: %.c
	$(CC) -c $< -o $@ $(INCLUDES) $(CFLAGS) $(LDFLAGS)

%.i: %.c
	$(CC) -E $< -o $@ $(INCLUDES) $(CFLAGS) $(LDFLAGS)

%.d: %.c
	$(CC) -M $< -o $@ $(INCLUDES) $(CFLAGS) $(LDFLAGS)

%.asm: %.c
	$(CC) -S $< -o $@ $(INCLUDES) $(CFLAGS) $(LDFLAGS)


$(TARGET): $(OBJS) $(SOURCES)
	$(CC) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $(TARGET) $(OBJS)



# for project.asm
# %.asm: %.o
# 	@echo "Generating assembly output" $@
# 	objdump -S $^ > $@

# %.asm : %.out
# 	objdump --disassemble $< > $@

