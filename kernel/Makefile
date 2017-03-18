OBJECTS =build/start.o build/kmain.o build/graphics.o build/gdt.o build/idt.o build/system.o build/interrupt.o build/isr.o build/irq.o build/timer.o

KERNEL=build/kernel.elf
CC=gcc -Wall -m32 -c -Iinclude -Wno-error
AS=nasm -f elf32
LD=ld -m elf_i386 -T link.ld
BUILD_DIR=build/
ISOGEN?=genisoimage

all: ${KERNEL}

${KERNEL}: ${OBJECTS}
	${LD} -o $@ ${OBJECTS}

${BUILD_DIR}%.o : %.asm
	${AS} $< -o $@

${BUILD_DIR}%.o : %.c
	${CC} $< -o $@

run: ${KERNEL}
	qemu-system-i386 -m 2G -kernel ${KERNEL}

clean:
	rm -rf ${KERNEL} ${BUILD_DIR}*.o ${BUILD_DIR}*.img
