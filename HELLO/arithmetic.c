#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void add_a_rn(void) {
	printf("ADD_A_RN\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R0,#0fH
	add A,R0
  #pragma ENDASM	
	if (ACC!=0x10) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R1,#40H
	add A,R1
	#pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R2,#81H
	add A,R2
  #pragma ENDASM
	if (ACC!=0x01) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	add A,R3
  #pragma ENDASM
	if (ACC!=0x82) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM 	
	error();
}

void add_a_di(void) {
	printf("ADD_A_DI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R0,#0fH
	add A,0x18
  #pragma ENDASM	
	if (ACC!=0x10) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R1,#40H
	add A,0x19
	#pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R2,#81H
	add A,0x1a
  #pragma ENDASM
	if (ACC!=0x01) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	add A,0x1b
  #pragma ENDASM
	if (ACC!=0x82) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM 
  error();	
}

void add_a_ri(void) {
	printf("ADD_A_RI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R2,#0fH
	mov R0,#1aH
	add A,@R0
  #pragma ENDASM	
	if (ACC!=0x10) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R2,#40H
	mov R0,#1aH
	add A,@R0
	#pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R3,#81H
	mov R1,#1bH
	add A,@R1
  #pragma ENDASM
	if (ACC!=0x01) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	mov R1,#1bH
	add A,@R1
  #pragma ENDASM
	if (ACC!=0x82) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error(); 	
}

void add_a_da(void) {
	printf("ADD_A_DA\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	add A,#0fH
  #pragma ENDASM	
	if (ACC!=0x10) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	add A,#40H
	#pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	add A,#81H
  #pragma ENDASM
	if (ACC!=0x01) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	add A,#0C2H
  #pragma ENDASM
	if (ACC!=0x82) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error(); 	
}

void addc_a_rn(void) {
	printf("ADDC_A_RN\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R0,#0fH
	setb C
	addc A,R0
  #pragma ENDASM	
	if (ACC!=0x11) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R1,#40H
	setb C
	addc A,R1
	#pragma ENDASM
	if (ACC!=0x81) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R2,#81H
	setb C
	addc A,R2
  #pragma ENDASM
	if (ACC!=0x02) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	setb C
	addc A,R3
  #pragma ENDASM
	if (ACC!=0x83) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error(); 	
}

void addc_a_di(void) {
	printf("ADDC_A_DI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R0,#0fH
	setb C
	addc A,0x18
  #pragma ENDASM	
	if (ACC!=0x11) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R1,#40H
	setb C
	addc A,0x19
	#pragma ENDASM
	if (ACC!=0x81) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R2,#81H
	setb C
	addc A,0x1a
  #pragma ENDASM
	if (ACC!=0x02) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	setb C
	addc A,0x1b
  #pragma ENDASM
	if (ACC!=0x83) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM 
  error();  
}

void addc_a_ri(void) {
	printf("ADDC_A_RI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	mov R2,#0fH
	mov R0,#1aH
	setb C
	addc A,@R0
  #pragma ENDASM	
	if (ACC!=0x11) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	mov R2,#40H
	mov R0,#1aH
	setb C
	addc A,@R0
	#pragma ENDASM
	if (ACC!=0x81) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	mov R3,#81H
	mov R1,#1bH
	setb C
	addc A,@R1
  #pragma ENDASM
	if (ACC!=0x02) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	mov R3,#0C2H
	mov R1,#1bH
	setb C
	addc A,@R1
  #pragma ENDASM
	if (ACC!=0x83) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void addc_a_da(void) {
	printf("ADDC_A_DA\n");	
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#01H
	setb C
	addc A,#0fH
  #pragma ENDASM	
	if (ACC!=0x11) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
		
	#pragma ASM
	mov acc,#40H
	setb C
	addc A,#40H
	#pragma ENDASM
	if (ACC!=0x81) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#80H
	setb C
	addc A,#81H
  #pragma ENDASM
	if (ACC!=0x02) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;
	
	#pragma ASM
  mov acc,#0C0H
	setb C
	addc A,#0C2H
  #pragma ENDASM
	if (ACC!=0x83) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void subb_a_rn(void) {
	printf("SUBB_A_RN\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#10H
	mov R0,#0eH
	setb C
	subb A,R0
  #pragma ENDASM	
	if (ACC!=0x1) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
	
	#pragma ASM
	mov acc,#80H
	mov R1,#3fH
	setb C
	subb A,R1
	#pragma ENDASM
	if (ACC!=0x40) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#01H
	mov R2,#80H
	setb C
	subb A,R2
  #pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;

	#pragma ASM
  mov acc,#82H
	mov R3,#0C1H
	setb C
	subb A,R3
  #pragma ENDASM
	if (ACC!=0xC0) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void subb_a_di(void) {
	printf("SUBB_A_DI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#10H
	mov R0,#0eH
	setb C
	subb A,0x18
  #pragma ENDASM	
	if (ACC!=0x1) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
	
	#pragma ASM
	mov acc,#80H
	mov R1,#3fH
	setb C
	subb A,0x19
	#pragma ENDASM
	if (ACC!=0x40) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#01H
	mov R2,#80H
	setb C
	subb A,0x1a
  #pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;

	#pragma ASM
  mov acc,#82H
	mov R3,#0C1H
	setb C
	subb A,0x1b
  #pragma ENDASM
	if (ACC!=0xC0) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void subb_a_ri(void) {
	printf("SUBB_A_RI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#10H
	mov R2,#0eH
	setb C
	mov R0,#1aH
	subb A,@R0
  #pragma ENDASM	
	if (ACC!=0x1) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
	
	#pragma ASM
	mov acc,#80H
	mov R2,#3fH
	setb C
	mov R0,#1aH
	subb A,@R0
	#pragma ENDASM
	if (ACC!=0x40) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#01H
	mov R3,#80H
	setb C
	mov R1,#1bH
	subb A,@R1
  #pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;

	#pragma ASM
  mov acc,#82H
	mov R3,#0C1H
	setb C
	mov R1,#1bH
	subb A,@R1
  #pragma ENDASM
	if (ACC!=0xC0) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void subb_a_da(void) {
	printf("SUBB_A_DA\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#10H
	setb C
	subb A,#0eH
  #pragma ENDASM	
	if (ACC!=0x1) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;
	AC = 0;
	
	#pragma ASM
	mov acc,#80H
	setb C
	subb A,#3fH
	#pragma ENDASM
	if (ACC!=0x40) test_status = 0;
	if (AC!=1) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	OV = 0;

	
	#pragma ASM
  mov acc,#01H
	setb C
	subb A,#80H
  #pragma ENDASM
	if (ACC!=0x80) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;
	OV = 0;
	CY = 0;

	#pragma ASM
  mov acc,#82H
	setb C
	subb A,#0C1H
  #pragma ENDASM
	if (ACC!=0xC0) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;
	CY = 0;	
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}


void inc_a(void) {
	printf("INC_A\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	inc A
  #pragma ENDASM	
	if (ACC!=0xa6) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void inc_rn(void) {
	printf("INC_RN\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1b,#0a5H
	inc R3
  #pragma ENDASM	
	if (R(3,3)!=0xa6) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void inc_di(void) {
	printf("INC_DI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1c,#0a5H
	inc 0x1c
  #pragma ENDASM	
	if (R(3,4)!=0xa6) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void inc_ri(void) {
	printf("INC_RI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1c,#0a5H
	mov R1,#1cH
	inc @R1
  #pragma ENDASM	
	if (R(3,4)!=0xa6) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}


void inc_dp(void) {
	printf("INC_DP\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov DPTR,#1234H
	inc DPTR
  #pragma ENDASM	
	if (DPL!=0x35) test_status = 0;
	if (DPH!=0x12) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}


void dec_a(void) {
	printf("DEC_A\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	dec A
  #pragma ENDASM	
	if (ACC!=0xa4) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void dec_rn(void) {
	printf("DEC_RN\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1b,#0a5H
	dec R3
  #pragma ENDASM	
	if (R(3,3)!=0xa4) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void dec_di(void) {
	printf("DEC_DI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1c,#0a5H
	dec 0x1c
  #pragma ENDASM	
	if (R(3,4)!=0xa4) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM 	
  error();
}

void dec_ri(void) {
	printf("DEC_RI\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov 0x1c,#0a5H
	mov R1,#1cH
	dec @R1
  #pragma ENDASM	
	if (R(3,4)!=0xa4) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void mult(void) {
	printf("MULT\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	setb C
	mov acc,#08H
	mov 0xf0,#03H
	mul AB
  #pragma ENDASM	
	if (ACC!=0x18) test_status = 0;
	if (B!=0x0) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	#pragma ASM
	setb C
	mov acc,#0a8H
	mov 0xf0,#0efH
	mul AB
  #pragma ENDASM	
	if (ACC!=0xd8) test_status = 0;
	if (B!=0x9c) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void divide(void) {
	printf("DIVIDE\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	setb C
	setb OV
	mov acc,#0fbH
	mov 0xf0,#12H
	div AB
  #pragma ENDASM	
	if (ACC!=0xd) test_status = 0;
	if (B!=0x11) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=0) test_status = 0;

	#pragma ASM
	setb C
	mov acc,#0a8H
	mov 0xf0,#0H
	div AB
  #pragma ENDASM	
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=0) test_status = 0;
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void da_a(void) {
	printf("DA\n");
	#pragma ASM  
	push psw
	push acc
  mov  psw,#0H	
  setb rs0     
	setb rs1	
  #pragma ENDASM 
	
	#pragma ASM
	mov acc,#56H
	mov R3,#67H
	setb AC
	setb C
	addc A,R3
	da A
  #pragma ENDASM	
	if (ACC!=0x24) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=1) test_status = 0;
	if (CY!=1) test_status = 0;

	#pragma ASM
	mov acc,#30H
	add A,#99H
	da A
  #pragma ENDASM	
	if (ACC!=0x29) test_status = 0;
	if (AC!=0) test_status = 0;
	if (OV!=0) test_status = 0;
	if (CY!=1) test_status = 0;


	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}
