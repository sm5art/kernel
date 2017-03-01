/*
 *
 * kernel.c - version 0.0.1
 *
 */

#include "graphics.h"
#include "gdt.h"

/* simple kernel written in C */
void k_main()
{
	k_clear_screen();
	gdt_install();
	k_printf("hey now\r\nyour an allstar");
};
