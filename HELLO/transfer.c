#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void mov_a_rn(void) {
	printf("MOV_A_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R5,#0f0H
	mov A,R5
    #pragma ENDASM	
	if (ACC!=0xf0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_a_di(void) {
	printf("MOV_A_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R5,#0f0H
	mov A,0x1d
  #pragma ENDASM	
	if (ACC!=0xf0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_a_ri(void) {
	printf("MOV_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#0a5H
	mov R5,#0f0H
	mov R0,#01dH
	mov A,@R0
  #pragma ENDASM	
	if (ACC!=0xf0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_a_da(void) {
	printf("MOV_A_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0f4H
  #pragma ENDASM	
	if (ACC!=0xf4) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_rn_a(void) {
	printf("MOV_RN_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov acc,#038H
	mov R5,A
    #pragma ENDASM	
	if (R(3,5)!=0x38) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_rn_di(void) {
	printf("MOV_RN_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R1,#06aH
	mov R5,0x19
    #pragma ENDASM	
	if (R(3,5)!=0x6a) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_rn_da(void) {
	printf("MOV_RN_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R5,#0f1H
    #pragma ENDASM	
	if (R(3,5)!=0xf1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_di_a(void) {
	printf("MOV_DI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#0dcH
	mov 0x1f,A
    #pragma ENDASM	
	if (R(3,7)!=0xdc) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_di_rn(void) {
	printf("MOV_DI_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R4,#0dcH
	mov 0x1f,R4
    #pragma ENDASM	
	if (R(3,7)!=0xdc) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_di_di(void) {
	printf("MOV_DI_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R4,#016H
	mov 0x1f,0x1c
    #pragma ENDASM	
	if (R(3,7)!=0x16) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_di_ri(void) {
	printf("MOV_DI_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R4,#047H
	mov R1,#01cH
	mov 0x1f,@R1
    #pragma ENDASM	
	if (R(3,7)!=0x47) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_di_da(void) {
	printf("MOV_DI_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x1f,#0abH
    #pragma ENDASM	
	if (R(3,7)!=0xab) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_ri_a(void) {
	printf("MOV_RI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#05fH
	mov R0,#1eH
	mov @R0,A
    #pragma ENDASM	
	if (R(3,6)!=0x5f) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_ri_di(void) {
	printf("MOV_RI_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R7,#033H
	mov R0,#1eH
	mov @R0,0x1f
    #pragma ENDASM	
	if (R(3,6)!=0x33) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_ri_da(void) {
	printf("MOV_RI_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R0,#1eH
	mov @R0,#09aH
    #pragma ENDASM	
	if (R(3,6)!=0x9a) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_dp_da(void) {
	printf("MOV_DP_DA\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov DPTR,#781eH
    #pragma ENDASM	
	if (DPL!=0x1e) test_status = 0;
	if (DPH!=0x78) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}
void movc_a_dp(void) {
	printf("MOVC_A_DP\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	clr A
	mov DPTR,#POINT_MOVC_A_DP
	movc A,@A+DPTR
	JMP EXIT_MOVC_A_DP
	NOP
	NOP
POINT_MOVC_A_DP: DB 78H
    NOP
	NOP
EXIT_MOVC_A_DP: NOP
    #pragma ENDASM	
	if (ACC!=0x78) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void movc_a_pc(void) {
	printf("MOVC_A_PC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,#4H
	movc A,@A+PC
	SJMP EXIT_MOVC_A_PC
	NOP
	NOP
    DB 53H
    NOP
	NOP
EXIT_MOVC_A_PC: NOP
    #pragma ENDASM	
	if (ACC!=0x53) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void movx_a_ri(void) {
	printf("MOVX_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R0,#0H
	mov acc,#95H
	movx @R0,A
	clr A
	movx A,@R0
    #pragma ENDASM	
	if (ACC!=0x95) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void movx_a_dp(void) {
	printf("MOVX_A_DP\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov DPTR,#0001H
	mov acc,#3dH
	movx @DPTR,A
	clr A
	movx A,@DPTR
    #pragma ENDASM	
	if (ACC!=0x3d) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void movx_ri_a(void) {
	printf("MOVX_RI_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R0,#0H
	mov acc,#95H
	movx @R0,A
	clr A
	movx A,@R0
    #pragma ENDASM	
	if (ACC!=0x95) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void movx_dp_a(void) {
	printf("MOVX_DP_A\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov DPTR,#0001H
	mov acc,#3dH
	movx @DPTR,A
	clr A
	movx A,@DPTR
    #pragma ENDASM	
	if (ACC!=0x3d) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void push_di(void) {
	printf("PUSH_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R7,#0edH
	mov A,SP
	push 0x1f
	inc A
	mov R0,SP
	mov B,@R0
    #pragma ENDASM	
	if (ACC!=SP) test_status = 0;
	if (B!=0xed) test_status = 0;
	
	#pragma ASM 
	pop 0x1f
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void pop_di(void) {
	printf("POP_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R6,#0H
	mov R7,#049H
	push 0x1f
	mov A,SP
	pop 0x1e
	dec A
    #pragma ENDASM	
	if (ACC!=SP) test_status = 0;
	if (R(3,6)!=0x49) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void xch_a_rn(void) {
	printf("XCH_A_RN\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R7,#22H
	mov acc,#0ffH
	xch A,R7
    #pragma ENDASM	
	if (ACC!=0x22) test_status = 0;
	if (R(3,7)!=0xff) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void xch_a_di(void) {
	printf("XCH_A_DI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R6,#54H
	mov acc,#088H
	xch A,0x1e
    #pragma ENDASM	
	if (ACC!=0x54) test_status = 0;
	if (R(3,6)!=0x88) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void xch_a_ri(void) {
	printf("XCH_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R5,#99H
	mov acc,#0a1H
	mov R1,#1dH
	xch A,@R1
    #pragma ENDASM	
	if (ACC!=0x99) test_status = 0;
	if (R(3,5)!=0xa1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void xchd_a_ri(void) {
	printf("XCHD_A_RI\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov R5,#99H
	mov acc,#0a1H
	mov R1,#1dH
	xchd A,@R1
    #pragma ENDASM	
	if (ACC!=0xa9) test_status = 0;
	if (R(3,5)!=0x91) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

