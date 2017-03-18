#include "irq.h"
#include "syscall.h"
#include "graphics.h"

isr_t interrupt_handlers[256];

// This gets called from our ASM interrupt handler stub.
void irq_handler(struct registers regs)
{
   // Send an EOI (end of interrupt) signal to the PICs.
   // If this interrupt involved the slave.
   if (regs.int_no >= 40)
   {
       // Send reset signal to slave.
       outb(0xA0, 0x20);
   }
   // Send reset signal to master. (As well as slave, if necessary).
   outb(0x20, 0x20);
   if (interrupt_handlers[regs.int_no] != 0)
   {

       isr_t handler = interrupt_handlers[regs.int_no];

       handler(&regs);
   }
}

void register_interrupt_handler(short n, isr_t handler)
{
  interrupt_handlers[n] = handler;
}
