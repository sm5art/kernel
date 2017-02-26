/*
 *
 * kernel.c - version 0.0.1
 *
 */

#include "graphics.h"
#include "io.h"

/* simple kernel written in C */
void k_main()
{
	k_clear_screen();
	k_printf("Hello, world! Welcome to my kernel.\n", 0);
  k_printf("thats a good meme", 1);
	kb_init();
	while(1){
		keyboard_handler_main();
	}
};