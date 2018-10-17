#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void clr_c(void) {
	printf("CLR_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	setb C
	clr C
    #pragma ENDASM	
	if (CY!=0x0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void clr_bit(void) {
	printf("CLR_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#0ffH
	clr 0x7
    #pragma ENDASM	
	if (bit_data!=0x7f) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void setb_c(void) {
	printf("SETB_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	setb C
    #pragma ENDASM	
	if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void setb_bit(void) {
	printf("SETB_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#0H
	setb 0x6
    #pragma ENDASM	
	if (bit_data!=0x40) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cpl_c(void) {
	printf("CPL_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	clr C
	cpl C
    #pragma ENDASM	
	if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void cpl_bit(void) {
	printf("CPL_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#55H
	cpl 0x7
    #pragma ENDASM	
	if (bit_data!=0xd5) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void anl_c_bit(void) {
	printf("ANL_C_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#7fH
	setb C
	anl C,0x7
    #pragma ENDASM	
	if (CY!=0x0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void anl_c_nbit(void) {
	printf("ANL_C_NBIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#010H
	setb C
	anl C,/0x4
    #pragma ENDASM	
	if (CY!=0x0) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void orl_c_bit(void) {
	printf("ORL_C_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#80H
	clr C
	orl C,0x7
    #pragma ENDASM	
	if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void orl_c_nbit(void) {
	printf("ORL_C_NBIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#0efH
	clr C
	orl C,/0x4
    #pragma ENDASM	
	if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_c_bit(void) {
	printf("MOV_C_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#080H
	clr C
	mov C,0x7
    #pragma ENDASM	
	if (CY!=0x1) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void mov_bit_c(void) {
	printf("MOV_BIT_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#000H
	setb C
	mov 0x4,C
    #pragma ENDASM	
	if (bit_data!=0x10) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jc_c(void) {
	printf("JC_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	clr C
	JC  ERROR0_JC_C
	cpl C
	JC  RIGHT0_JC_C
	nop
	nop
	nop
ERROR0_JC_C: clr A
    SJMP EXIT0_JC_C
    nop
    nop
RIGHT0_JC_C: mov A,#0ffH
    SJMP EXIT0_JC_C
    nop
    nop
EXIT0_JC_C: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;
	
	#pragma ASM
    sjmp NOW_JC_C
	nop
	nop
	nop
ERROR1_JC_C: clr A
    SJMP EXIT1_JC_C
    nop
    nop
RIGHT1_JC_C: mov A,#0ffH
    SJMP EXIT1_JC_C
    nop
    nop	
	nop
	nop
NOW_JC_C:	clr C
	JC  ERROR1_JC_C
	cpl C
	JC  RIGHT1_JC_C
	nop
	nop
EXIT1_JC_C: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;	
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jnc_c(void) {
	printf("JNC_C\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	setb C
	JNC  ERROR0_JNC_C
	cpl C
	JNC  RIGHT0_JNC_C
	nop
	nop
	nop
ERROR0_JNC_C: clr A
    SJMP EXIT0_JNC_C
    nop
    nop
RIGHT0_JNC_C: mov A,#0ffH
    SJMP EXIT0_JNC_C
    nop
    nop
EXIT0_JNC_C: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;
	
	#pragma ASM
    sjmp NOW_JNC_C
	nop
	nop
	nop
ERROR1_JNC_C: clr A
    SJMP EXIT1_JNC_C
    nop
    nop
RIGHT1_JNC_C: mov A,#0ffH
    SJMP EXIT1_JNC_C
    nop
    nop	
	nop
	nop
NOW_JNC_C:	setb C
	JNC  ERROR1_JNC_C
	cpl C
	JNC  RIGHT1_JNC_C
	nop
	nop
EXIT1_JNC_C: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;	
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jb_bit(void) {
	printf("JB_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#0f7H
	jb  0x3,ERROR0_JB_BIT
	cpl 0x3
	jb  0x3,RIGHT0_JB_BIT
	nop
	nop
	nop
ERROR0_JB_BIT: clr A
    SJMP EXIT0_JB_BIT
    nop
    nop
RIGHT0_JB_BIT: mov A,#0ffH
    SJMP EXIT0_JB_BIT
    nop
    nop
EXIT0_JB_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;
	
	#pragma ASM
    sjmp NOW_JB_BIT
	nop
	nop
	nop
ERROR1_JB_BIT: clr A
    SJMP EXIT1_JB_BIT
    nop
    nop
RIGHT1_JB_BIT: mov A,#0ffH
    SJMP EXIT1_JB_BIT
    nop
    nop	
	nop
	nop
NOW_JB_BIT:	mov 0x20,#0f7H
	jb  0x3,ERROR1_JB_BIT
	cpl 0x3
	jb  0x3,RIGHT1_JB_BIT
	nop
	nop
EXIT1_JB_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;	
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jnb_bit(void) {
	printf("JNB_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#010H
	jnb  0x4,ERROR0_JNB_BIT
	cpl 0x4
	jnb  0x4,RIGHT0_JNB_BIT
	nop
	nop
	nop
ERROR0_JNB_BIT: clr A
    SJMP EXIT0_JNB_BIT
    nop
    nop
RIGHT0_JNB_BIT: mov A,#0ffH
    SJMP EXIT0_JNB_BIT
    nop
    nop
EXIT0_JNB_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;
	
	#pragma ASM
    sjmp NOW_JNB_BIT
	nop
	nop
	nop
ERROR1_JNB_BIT: clr A
    SJMP EXIT1_JNB_BIT
    nop
    nop
RIGHT1_JNB_BIT: mov A,#0ffH
    SJMP EXIT1_JNB_BIT
    nop
    nop	
	nop
	nop
NOW_JNB_BIT: mov 0x20,#010H
	jnb  0x4,ERROR1_JNB_BIT
	cpl 0x4
	jnb  0x4,RIGHT1_JNB_BIT
	nop
	nop
EXIT1_JNB_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;	
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}

void jbc_bit(void) {
	printf("JBC_BIT\n");
	#pragma ASM  
	push psw
	push acc
    mov  psw,#0H	
    setb rs0     
	setb rs1	
    #pragma ENDASM 
	
	#pragma ASM
	mov 0x20,#0f7H
	jbc  0x3,ERROR0_JBC_BIT
	cpl 0x3
	jbc  0x3,RIGHT0_JBC_BIT
	nop
	nop
	nop
ERROR0_JBC_BIT: clr A
    SJMP EXIT0_JBC_BIT
    nop
    nop
RIGHT0_JBC_BIT: mov A,#0ffH
    SJMP EXIT0_JBC_BIT
    nop
    nop
EXIT0_JBC_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;
	if (bit_data!=0xf7) test_status = 0;
	
	#pragma ASM
    sjmp NOW_JBC_BIT
	nop
	nop
	nop
ERROR1_JBC_BIT: clr A
    SJMP EXIT1_JBC_BIT
    nop
    nop
RIGHT1_JBC_BIT: mov A,#0ffH
    SJMP EXIT1_JBC_BIT
    nop
    nop	
	nop
	nop
NOW_JBC_BIT: mov 0x20,#0f7H
	jbc  0x3,ERROR1_JBC_BIT
	cpl 0x3
	jbc  0x3,RIGHT1_JBC_BIT
	nop
	nop
EXIT1_JBC_BIT: nop	
    #pragma ENDASM	
	if (ACC!=0xff) test_status = 0;	
	if (bit_data!=0xf7) test_status = 0;
	
	#pragma ASM 
	pop acc
    pop psw	
    #pragma ENDASM
    error();  
}
