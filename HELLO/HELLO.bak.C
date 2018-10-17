/*------------------------------------------------------------------------------
HELLO.C

Copyright 1995-2005 Keil Software, Inc.
------------------------------------------------------------------------------*/

//#include <REG52.H>                /* special function register declarations   */
                                  /* for the intended 8051 derivative         */

#include <stdio.h>                /* prototype declarations for I/O functions */


sbit UART_OK = 0x88^0;
bit TEST = 0x20^1;
sfr UART_DATA = 0x81;

timerint () interrupt 31 {
   TEST = 0;
}

char putchar (char x) {
	while(UART_OK==0);
	UART_DATA = x;
}

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/
void main (void) {

/*------------------------------------------------
Setup the serial port for 1200 baud at 16MHz.
------------------------------------------------*/


/*------------------------------------------------
Note that an embedded program never exits (because
there is no operating system to return to).  It
must loop and execute forever.
------------------------------------------------*/
  while (1) {
    //P1 ^= 0x01;     		    /* Toggle P1.0 each time we print */
    printf ("Hello World\n");   /* Print "Hello World" */
                                   }
}


