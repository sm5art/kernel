
struct registers
{
  unsigned long ds;
  unsigned long edi, esi, ebp, esp, edx, ecx, eax;
  unsigned long int_no, err_code;
  unsigned long eip, cs, eflags, useresp, ss;
};

void isr_handler(struct registers regs);
