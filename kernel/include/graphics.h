#define WHITE_TXT 0x07 /* light gray on black text */
#define FB_DARK_GREY 0x08

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15


void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
unsigned int k_printf(char *message, int line);
void k_clear_screen();
void fb_move_cursor(unsigned short pos);
