#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void anl_a_rn(void) {
	printf("ANL_A_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R0,#0f0H
	anl A,R0
  #pragma ENDASM	
	if (ACC!=0xa0) test_status = 0;
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void anl_a_di(void) {
	printf("ANL_A_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	anl A,0x1b
  #pragma ENDASM	
	if (ACC!=0x5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void anl_a_ri(void) {
	printf("ANL_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0f0H
	mov R1,#0x1b
	anl A,@R1
    #pragma ENDASM	
	if (ACC!=0xa0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void anl_a_da(void) {
	printf("ANL_A_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	anl A,#0fH
    #pragma ENDASM	
	if (ACC!=0x5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void anl_di_a(void) {
	printf("ANL_DI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	anl 0x1b,A
    #pragma ENDASM	
	if (R(3,3)!=0x5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void anl_di_da(void) {
	printf("ANL_DI_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R3,#0f0H
	anl 0x1b,#0a5H
  #pragma ENDASM	
	if (R(3,3)!=0xa0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void orl_a_rn(void) {
	printf("ORL_A_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R0,#0f0H
	orl A,R0
    #pragma ENDASM	
	if (ACC!=0xf5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void orl_a_di(void) {
	printf("ORL_A_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	orl A,0x1b
    #pragma ENDASM	
	if (ACC!=0xaf) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void orl_a_ri(void) {
	printf("ORL_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0f0H
	mov R1,#0x1b
	orl A,@R1
    #pragma ENDASM	
	if (ACC!=0xf5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void orl_a_da(void) {
	printf("ORL_A_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	orl A,#0fH
    #pragma ENDASM	
	if (ACC!=0xaf) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM 
    error();	
}

void orl_di_a(void) {
	printf("ORL_DI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	orl 0x1b,A
    #pragma ENDASM	
	if (R(3,3)!=0xaf) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM 
    error();	
}

void orl_di_da(void) {
	printf("ORL_DI_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R3,#0f0H
	orl 0x1b,#0a5H
    #pragma ENDASM	
	if (R(3,3)!=0xf5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void xrl_a_rn(void) {
	printf("XRL_A_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R0,#0f0H
	xrl A,R0
  #pragma ENDASM	
	if (ACC!=0x55) test_status = 0;
	
	#pragma ASM 
	pop acc
  pop psw	
  #pragma ENDASM
  error();  
}

void xrl_a_di(void) {
	printf("XRL_A_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	xrl A,0x1b
  #pragma ENDASM	
	if (ACC!=0xaa) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void xrl_a_ri(void) {
	printf("XRL_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0f0H
	mov R1,#0x1b
	xrl A,@R1
    #pragma ENDASM	
	if (ACC!=0x55) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void xrl_a_da(void) {
	printf("XRL_A_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	xrl A,#0fH
    #pragma ENDASM	
	if (ACC!=0xaa) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void xrl_di_a(void) {
	printf("XRL_DI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R3,#0fH
	xrl 0x1b,A
    #pragma ENDASM	
	if (R(3,3)!=0xaa) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void xrl_di_da(void) {
	printf("XRL_DI_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R3,#0f0H
	xrl 0x1b,#0a5H
  #pragma ENDASM	
	if (R(3,3)!=0x55) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void clr_a(void) {
	printf("CLR_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0ffH
	clr A
  #pragma ENDASM	
	if (ACC!=0x0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void cpl_a(void) {
	printf("CPL_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0a5H
	cpl A
  #pragma ENDASM	
	if (ACC!=0x5a) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void rl_a(void) {
	printf("RL_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0a0H
	rl A
  #pragma ENDASM	
	if (ACC!=0x41) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void rlc_a(void) {
	printf("RLC_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0a0H
	rlc A
  #pragma ENDASM	
	if (ACC!=0x40) test_status = 0;
	if (CY!=1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void rr_a(void) {
	printf("RR_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0e1H
	rr A
  #pragma ENDASM	
	if (ACC!=0xf0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void rrc_a(void) {
	printf("RRC_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0e1H
	rrc A
  #pragma ENDASM	
	if (ACC!=0x70) test_status = 0;
	if (CY!=1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}

void swap_a(void) {
	printf("SWAP_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#037H
	swap A
  #pragma ENDASM	
	if (ACC!=0x73) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error(); 	
}
