CFLAGS = -Wall -O0 -ffreestanding -nostartfiles -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -march=armv8-a+crc -mcpu=cortex-a53

LFLAGS = -T link.ld
COMPILER_PATH = ./compiler/gcc-arm-none-eabi-8-2018-q4-major/bin

all: clean kernel.img

kernel.img:
	$(COMPILER_PATH)/arm-none-eabi-gcc $(LFLAGS) $(CFLAGS) *.S *.c -o kernel.elf
	$(COMPILER_PATH)/arm-none-eabi-objcopy -O binary kernel.elf kernel.img

clean:
	rm kernel.elf kernel.img *.o >/dev/null 2>/dev/null || true

clean_all:
	rm kernel.elf kernel.img *.o >/dev/null 2>/dev/null || true
	rm -rf ./compiler || true

bootstrap:
	mkdir compiler
	cd compiler && wget https://developer.arm.com/-/media/Files/downloads/gnu-rm/8-2018q4/gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2
	cd compiler && tar xjvf gcc-arm-none-eabi-8-2018-q4-major-linux.tar.bz2 gcc-arm-none-eabi-8-2018-q4-major

run:
	qemu-system-arm -M raspi2 -kernel kernel.img -serial stdio
