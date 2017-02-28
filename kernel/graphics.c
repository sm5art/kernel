#include "graphics.h"

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

/* k_printf : the message and the line # */
unsigned int k_printf(char *message, int line)
{
	unsigned int i=0;
  i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n') // check for a new line
		{
      line++;
			i=(line*80*2);
			*message++;
		} else {
      char a = (char)*message;
			fb_write_cell(i, a, FB_DARK_GREY, WHITE_TXT);
			*message++;
      i++;
      i++;
		};
	};
	return(1);
}
