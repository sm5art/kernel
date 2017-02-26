# kernel
a simple kernel written in C and assembly

# requirements
1. gcc
2. nasm
3. ld
4. qemu-system-i386 <---- for testing purposes

# how to compile
```
$ cd kernel
$ make all
```

# how to run
```
$ qemu-system-i386 -kernel kernel.elf
```
