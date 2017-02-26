OBJECTS =start.o kmain.o graphics.o io.o

KERNEL=kernel.elf
CC=gcc -m32 -c
AS=nasm -f elf32
LD=ld -m elf_i386 -T link.ld

all: ${KERNEL}

${KERNEL}: ${OBJECTS}
	${LD} -o $@ ${OBJECTS}

%.o : %.asm
	${AS} $< -o $@

%.o : %.c
	${CC} $< -o $@

clean:
	rm -rf kernel.elf *.o
