#include "timer.h"
#include "irq.h"
#include "syscall.h"
#include "graphics.h"

int tick = 0;

void timer_cb(struct registers regs)
{
  if(tick % 50 == 0){
    k_printf("Seconds: ");
    print_d(tick/50);
    k_printf("\n");
  }
  tick++;
}

void init_timer(int frequency)
{
   // Firstly, register our timer callback.
   register_interrupt_handler(IRQ0, &timer_cb);

   // The value we send to the PIT is the value to divide it's input clock
   // (1193180 Hz) by, to get our required frequency. Important to note is
   // that the divisor must be small enough to fit into 16-bits.
   long divisor = 1193180 / frequency;

   // Send the command byte.
   outb(0x43, 0x36);

   // Divisor has to be sent byte-wise, so split here into upper/lower bytes.
   short l = (short)(divisor & 0xFF);
   short h = (short)( (divisor>>8) & 0xFF );

   // Send the frequency divisor.
   outb(0x40, l);
   outb(0x40, h);
}
