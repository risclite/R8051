#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void acall_func(void) {
	printf("ACALL_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,SP
	acall JUMP_ACALL
	jmp EXIT_ACALL
	nop
	nop
	nop
JUMP_ACALL:	inc A
    inc A
	mov B,SP
	ret
	nop
	nop
EXIT_ACALL: nop
    #pragma ENDASM	
	if (ACC!=B) test_status = 0;
	if (SP!=(B-2)) test_status=0;	
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void lcall_func(void) {
	printf("LCALL_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov A,SP
	lcall JUMP_LCALL
	jmp EXIT_LCALL
	nop
	nop
	nop
JUMP_LCALL:	inc A
    inc A
	mov B,SP
	ret
	nop
	nop
EXIT_LCALL: nop
    #pragma ENDASM	
	if (ACC!=B) test_status = 0;
	if (SP!=(B-2)) test_status=0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}


void ret_func(void) {
	printf("RET_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	lcall JUMP_RET
	mov B,SP
	inc B
	inc B
	jmp EXIT_RET
	nop
	nop
	nop
JUMP_RET:	mov A,SP
	ret
	nop
	nop
EXIT_RET: nop
    #pragma ENDASM	
	if (ACC!=B) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void reti_func(void) {
	printf("RETI_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	lcall JUMP_RETI
	mov B,SP
	inc B
	inc B
	jmp EXIT_RETI
	nop
	nop
	nop
JUMP_RETI:	mov A,SP
	reti
	nop
	nop
EXIT_RETI: nop
    #pragma ENDASM	
	if (ACC!=B) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void ajmp_func(void) {
	printf("AJMP_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	clr A
	ajmp EXIT_AJMP
	mov A,#0ffH
EXIT_AJMP: nop
    #pragma ENDASM	
	if (ACC!=0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}
void sjmp_func(void) {
	printf("SJMP_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	clr A
	sjmp EXIT_SJMP
	mov A,#0ffH
EXIT_SJMP: nop
    #pragma ENDASM	
	if (ACC!=0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jmp_func(void) {
	printf("JMP_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#00H
	mov DPTR,#EXIT_JMP
	inc DPTR
	mov A,#0ffH
	jmp @A+DPTR
	mov A,#0ffH
EXIT_JMP: nop
    #pragma ENDASM	
	if (B!=0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jz_func(void) {
	printf("JZ_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
	mov A,#0ffH
	jz EXIT_JZ
	mov B,#0ffH
	clr A
	JZ EXIT_JZ
	nop
	nop
	mov B,#0H
	nop
	nop
EXIT_JZ: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jnz_func(void) {
	printf("JNZ_FUNC\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
	mov A,#0H
	jnz EXIT_JNZ
	mov B,#0ffH
	inc A
	JNZ EXIT_JNZ
	nop
	nop
	mov B,#0H
	nop
	nop
EXIT_JNZ: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cjne_a_di_rel(void) {
	printf("CJNE_A_DI_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov A,#0H
	mov 0x20,#0H
	cjne A,0x20,EXIT_CJNE_A_DI_REL
	nop
	mov B,#0ffH
	inc 0x20
	cjne A,0x20,EXIT_CJNE_A_DI_REL
	nop
	mov B,#0H
	nop
EXIT_CJNE_A_DI_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cjne_a_da_rel(void) {
	printf("CJNE_A_DA_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov A,#035H
	cjne A,#035H,EXIT_CJNE_A_DA_REL
	nop
	mov B,#0ffH
	cjne A,#036H,EXIT_CJNE_A_DA_REL
	nop
	mov B,#0H
	nop
EXIT_CJNE_A_DA_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cjne_rn_da_rel(void) {
	printf("CJNE_RN_DA_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov R7,#035H
	cjne R7,#035H,EXIT_CJNE_RN_DA_REL
	nop
	mov B,#0ffH
	cjne R7,#036H,EXIT_CJNE_RN_DA_REL
	nop
	mov B,#0H
	nop
EXIT_CJNE_RN_DA_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cjne_ri_da_rel(void) {
	printf("CJNE_RI_DA_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov R7,#035H
	mov R1,#01fH
	cjne @R1,#035H,EXIT_CJNE_RI_DA_REL
	nop
	mov B,#0ffH
	cjne @R1,#036H,EXIT_CJNE_RI_DA_REL
	nop
	mov B,#0H
	nop
EXIT_CJNE_RI_DA_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void djnz_rn_rel(void) {
	printf("DJNZ_RN_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov R7,#01H
    djnz R7,EXIT_DJNZ_RN_REL
    mov B,#0ffH
    djnz R7,EXIT_DJNZ_RN_REL
    nop
    mov B,#0H	
	nop
EXIT_DJNZ_RN_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (R(3,7)!=0xff) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void djnz_di_rel(void) {
	printf("DJNZ_DI_REL\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov B,#0H
    mov R7,#01H
    djnz 0x1f,EXIT_DJNZ_DI_REL
    mov B,#0ffH
    djnz 0x1f,EXIT_DJNZ_DI_REL
    nop
    mov B,#0H	
	nop
EXIT_DJNZ_DI_REL: nop
    #pragma ENDASM	
	if (B!=0xff) test_status = 0;
    if (R(3,7)!=0xff) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

