#define WHITE_TXT 0x0F /* light gray on black text */
#define FB_DARK_GREY 0x00

int csr_x;
int csr_y;

void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg);
void k_clear_screen();
void move_csr(void);
void k_putc(char c);
unsigned int k_printf(char *message);
void print_d(int n);
