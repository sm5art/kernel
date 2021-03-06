/*
 *
 * kernel.c - version 0.0.1
 *
 */

#include "graphics.h"
#include "gdt.h"
#include "idt.h"
#include "timer.h"

/* simple kernel written in C */
void k_main()
{
	k_clear_screen();
	gdt_install();
	idt_install();
	k_printf("hey now\r\nyour an allstar");
	asm volatile("sti");
	init_timer(50);
};
