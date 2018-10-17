/*------------------------------------------------------------------------------
HELLO.C

Copyright 1995-2005 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG52.H>                /* special function register declarations   */
                                  /* for the intended 8051 derivative         */

#include <stdio.h>                /* prototype declarations for I/O functions */

#include "instruction.h"


/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/
void main (void) {
  test_status = 1;
	
	instruction_test_all();
	
	
	if (test_status) {
		printf("Test success!\n");
	}else{
		printf("Test failed!\n");
	}
  printf("Test finished!\n");
	kill_self = 1;
  while (1);
}


