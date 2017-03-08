#include "isr.h"
#include "graphics.h"

void isr_handler(struct registers regs)
{
   k_printf("recieved interrupt: ");
}
