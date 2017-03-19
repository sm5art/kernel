#include "system.h"
#include "idt.h"
#include "irq.h"
#include "syscall.h"
#include "interrupt.h"

void idt_set_gate(unsigned char num, unsigned long base, unsigned short sel, unsigned char flags)
{
  idt[num].base_lo = (base & 0xFFFF);
  idt[num].base_hi = (base >> 16) & 0xFFFF;
  idt[num].sel = sel;
  idt[num].always0 = 9;
  idt[num].flags = flags;
}

/* Installs the IDT */
void idt_install()
{
    /* Sets the special IDT pointer up, just like in 'gdt.c' */
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    outb(0x20, 0x11);
    outb(0xA0, 0x11);
    outb(0x21, 0x20);
    outb(0xA1, 0x28);
    outb(0x21, 0x04);
    outb(0xA1, 0x02);
    outb(0x21, 0x01);
    outb(0xA1, 0x01);
    outb(0x21, 0x0);
    outb(0xA1, 0x0);
    /* Add any new ISRs to the IDT here using idt_set_gate */
    idt_set_gate( 0, isr0 , 0x08, 0x8E);
    idt_set_gate( 1, isr1 , 0x08, 0x8E);
    idt_set_gate( 2, isr2 , 0x08, 0x8E);
    idt_set_gate( 3, isr3 , 0x08, 0x8E);
    idt_set_gate( 4, isr4 , 0x08, 0x8E);
    idt_set_gate( 5, isr5 , 0x08, 0x8E);
    idt_set_gate( 6, isr6 , 0x08, 0x8E);
    idt_set_gate( 7, isr7 , 0x08, 0x8E);
    idt_set_gate( 8, isr8 , 0x08, 0x8E);
    idt_set_gate( 9, isr9 , 0x08, 0x8E);
    idt_set_gate( 10, isr10 , 0x08, 0x8E);
    idt_set_gate( 11, isr11 , 0x08, 0x8E);
    idt_set_gate( 12, isr12 , 0x08, 0x8E);
    idt_set_gate( 13, isr13 , 0x08, 0x8E);
    idt_set_gate( 14, isr14 , 0x08, 0x8E);
    idt_set_gate( 15, isr15 , 0x08, 0x8E);
    idt_set_gate( 16, isr16 , 0x08, 0x8E);
    idt_set_gate( 17, isr17 , 0x08, 0x8E);
    idt_set_gate( 18, isr18 , 0x08, 0x8E);
    idt_set_gate( 19, isr19 , 0x08, 0x8E);
    idt_set_gate( 20, isr20 , 0x08, 0x8E);
    idt_set_gate( 21, isr21 , 0x08, 0x8E);
    idt_set_gate( 22, isr22 , 0x08, 0x8E);
    idt_set_gate( 23, isr23 , 0x08, 0x8E);
    idt_set_gate( 24, isr24 , 0x08, 0x8E);
    idt_set_gate( 25, isr25 , 0x08, 0x8E);
    idt_set_gate( 26, isr26 , 0x08, 0x8E);
    idt_set_gate( 27, isr27 , 0x08, 0x8E);
    idt_set_gate( 28, isr28 , 0x08, 0x8E);
    idt_set_gate( 29, isr29 , 0x08, 0x8E);
    idt_set_gate( 30, isr30 , 0x08, 0x8E);
    idt_set_gate( 31, isr31 , 0x08, 0x8E);

    idt_set_gate(32, irq0, 0x08, 0x8E);
    idt_set_gate(33, irq1, 0x08, 0x8E);
    idt_set_gate(34, irq2, 0x08, 0x8E);
    idt_set_gate(35, irq3, 0x08, 0x8E);
    idt_set_gate(36, irq4, 0x08, 0x8E);
    idt_set_gate(37, irq5, 0x08, 0x8E);
    idt_set_gate(38, irq6, 0x08, 0x8E);
    idt_set_gate(39, irq7, 0x08, 0x8E);
    idt_set_gate(40, irq8, 0x08, 0x8E);
    idt_set_gate(41, irq9, 0x08, 0x8E);
    idt_set_gate(42, irq10, 0x08, 0x8E);
    idt_set_gate(43, irq11, 0x08, 0x8E);
    idt_set_gate(44, irq12, 0x08, 0x8E);
    idt_set_gate(45, irq13, 0x08, 0x8E);
    idt_set_gate(46, irq14, 0x08, 0x8E);
    idt_set_gate(47, irq15, 0x08, 0x8E);
    /* Points the processor's internal register to the new IDT */
    idt_load();
    irq_init();
}
