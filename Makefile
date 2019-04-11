CFLAGS = -Wall -O0 -ffreestanding -nostartfiles -mfpu=crypto-neon-fp-armv8 -mfloat-abi=hard -march=armv8-a+crc -mcpu=cortex-a53

LFLAGS = -T link.ld

all: clean kernel.img

#arm-none-eabi-gcc $(CFLAGS) $(LFLAGS) ./*.S -c ./*.c -o kernel.elf

kernel.img:
	arm-none-eabi-gcc $(LFLAGS) $(CFLAGS) *.S *.c -o kernel.elf
	arm-none-eabi-objcopy -O binary kernel.elf kernel.img

clean:
	rm kernel.elf kernel.img *.o >/dev/null 2>/dev/null || true

run:
	qemu-system-arm -M raspi2 -kernel kernel.img -serial stdio
