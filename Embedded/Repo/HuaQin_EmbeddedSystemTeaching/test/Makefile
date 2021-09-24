
NAME := test
CROESS_COMPILE := arm-linux-gnueabihf-
#======================================================================#
CC := $(CROESS_COMPILE)gcc
LD := $(CROESS_COMPILE)ld
OBJDUMP := $(CROESS_COMPILE)objdump 
OBJCOPY := $(CROESS_COMPILE)objcopy
CFLAGS += -g   -O0  -mabi=apcs-gnu -mfpu=neon -mfloat-abi=softfp  -fno-builtin \
		-nostdinc  -I ./include 
#======================================================================#
OBJSss := $(wildcard start/*.s) $(wildcard *.s) $(wildcard *.c) \
	$(wildcard ./src/*.c) $(wildcard ./src/*.s) 
OBJSs := $(patsubst %.s,%.o,$(OBJSss))
OBJS := $(patsubst %.c,%.o,$(OBJSs))
#======================================================================#
%.o:%.s  
	$(CC) $(CFLAGS) -c -o $@ $<
%.o:%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all:$(OBJS)
	#链接所有目标文件
	$(LD) $(OBJS) -T map.lds -o $(NAME).elf			
	#格式转换 ELF -> BIN 
	$(OBJCOPY) -O binary $(NAME).elf $(NAME).bin	
	#反汇编
	$(OBJDUMP) -D $(NAME).elf > $(NAME).dis         
#======================================================================#
clean:
	rm -rf $(OBJS) *.dis *.o *.bin *.elf

