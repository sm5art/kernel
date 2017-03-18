#include "graphics.h"
#include "system.h"
#include "syscall.h"

int csr_x = 0;
int csr_y = 0;

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg)
{
    char *fb = (char *) 0xb8000;
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F);
}

/* k_clear_screen : to clear the entire text screen */
void k_clear_screen()
{
	unsigned int i=0;
  char a = ' ';
	while(i < (80*25*2))
	{
		fb_write_cell(i, a, FB_DARK_GREY, WHITE_TXT);
    i++;
	};
};

void print_d(int n){
   if (n < 0) {
       k_putc('-');
       n = -n;
   }

   if (n == 0)
       k_putc('0');

   if (n/10)
       print_d(n/10);

   k_putc(n%10 + '0');
}

void move_csr(void)
{
    int temp;

    /* The equation for finding the index in a linear
    *  chunk of memory can be represented by:
    *  Index = [(y * width) + x] */
    temp = csr_y * 80 + csr_x;

    /* This sends a command to indicies 14 and 15 in the
    *  CRT Control Register of the VGA controller. These
    *  are the high and low bytes of the index that show
    *  where the hardware cursor is to be 'blinking'. To
    *  learn more, you should look up some VGA specific
    *  programming documents. A great start to graphics:
    *  http://www.brackeen.com/home/vga */
    outb(0x3D4, 14);
    outb(0x3D5, temp >> 8);
    outb(0x3D4, 15);
    outb(0x3D5, temp);
}

void k_putc(char c){
  if(csr_x >= 0 & csr_y >= 25){
    csr_x = 0;
    csr_y = 0;
    k_clear_screen();
  }
  /* Handle a backspace, by moving the cursor back one space */
  if(c == 0x08)
  {
      if(csr_x != 0) csr_x--;
  }
  /* Handles a tab by incrementing the cursor's x, but only
  *  to a point that will make it divisible by 8 */
  else if(c == 0x09)
  {
      csr_x = (csr_x + 8) & ~(8 - 1);
  }
  /* Handles a 'Carriage Return', which simply brings the
  *  cursor back to the margin */
  else if(c == '\r')
  {
      csr_x = 0;
  }
  /* We handle our newlines the way DOS and the BIOS do: we
  *  treat it as if a 'CR' was also there, so we bring the
  *  cursor to the margin and we increment the 'y' value */
  else if(c == '\n')
  {
      csr_x = 0;
      csr_y++;
  }
  /* Any character greater than and including a space, is a
  *  printable character. The equation for finding the index
  *  in a linear chunk of memory can be represented by:
  *  Index = [(y * width) + x] */
  else if(c >= ' ')
  {
      fb_write_cell((2*csr_x)+(2*csr_y*80), c, FB_DARK_GREY, WHITE_TXT);
      csr_x++;
  }

  /* If the cursor has reached the edge of the screen's width, we
  *  insert a new line in there */
  if(csr_x >= 80)
  {
      csr_x = 0;
      csr_y++;
  }

  move_csr();
}

/* k_printf : the message and the line # */
unsigned int k_printf(char *message)
{
  int i;
  for (i=0; i< strlen(message); i++){
    k_putc(message[i]);
  }
	return(1);
}
