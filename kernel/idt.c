#include "system.h"
#include "idt.h"
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

    /* Add any new ISRs to the IDT here using idt_set_gate */
    idt_set_gate( 0, isr0 , 0x08, 0x8E);
    idt_set_gate( 1, isr1 , 0x08, 0x8E);
    /* Points the processor's internal register to the new IDT */
    idt_load();
}
