#define WHITE_TXT 0x07 /* light gray on black text */
#define FB_DARK_GREY 0x08


void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
unsigned int k_printf(char *message, int line);
void k_clear_screen();
