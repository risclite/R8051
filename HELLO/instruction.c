#include <REG52.H>
#include <stdio.h> 
#include "instruction.h"

void error(void){
	if (test_status==0) {
    printf("ERROR HERE...\n");
		while(1);
	}
}	

void instruction_test_all(void){
#ifdef ARITHMETIC
  arithmetic();  
#endif
#ifdef LOGICAL
	logical();
#endif
#ifdef TRANSFER
	transfer();
#endif
#ifdef BOOLEAN
	boolean();
#endif
#ifdef PROGRAM
	program();
#endif
}

void arithmetic(void){
#ifdef ADD_A_RN
    add_a_rn();
#endif
#ifdef ADD_A_DI
    add_a_di();
#endif	
#ifdef ADD_A_RI
    add_a_ri();
#endif		
#ifdef ADD_A_DA
    add_a_da();
#endif
#ifdef ADDC_A_RN
    addc_a_rn();
#endif	
#ifdef ADDC_A_DI
    addc_a_di();
#endif		
#ifdef ADDC_A_RI
    addc_a_ri();
#endif
#ifdef ADDC_A_DA
    addc_a_da();
#endif
#ifdef SUBB_A_RN
    subb_a_rn();
#endif
#ifdef SUBB_A_DI
    subb_a_di();
#endif
#ifdef SUBB_A_RI
    subb_a_ri();
#endif
#ifdef SUBB_A_DA
    subb_a_da();
#endif
#ifdef INC_A
    inc_a();
#endif
#ifdef INC_RN
    inc_rn();
#endif
#ifdef INC_DI
    inc_di();
#endif
#ifdef INC_RI
    inc_ri();
#endif
#ifdef INC_DP
    inc_dp();
#endif
#ifdef DEC_A
    dec_a();
#endif
#ifdef DEC_RN
    dec_rn();
#endif
#ifdef DEC_DI
    dec_di();
#endif
#ifdef DEC_RI
    dec_ri();
#endif
#ifdef MULT
    mult();
#endif
#ifdef DIVIDE
    divide();
#endif
#ifdef DA_A
    da_a();
#endif
}

void logical(void){
#ifdef ANL_A_RN
    anl_a_rn();
#endif	
#ifdef ANL_A_DI
    anl_a_di();
#endif	
#ifdef ANL_A_RI
    anl_a_ri();
#endif	
#ifdef ANL_A_DA
    anl_a_da();
#endif
#ifdef ANL_DI_A
    anl_di_a();
#endif	
#ifdef ANL_DI_DA
    anl_di_da();
#endif	
#ifdef ORL_A_RN
    orl_a_rn();
#endif	
#ifdef ORL_A_DI
    orl_a_di();
#endif	
#ifdef ORL_A_RI
    orl_a_ri();
#endif	
#ifdef ORL_A_DA
    orl_a_da();
#endif
#ifdef ORL_DI_A
    orl_di_a();
#endif	
#ifdef ORL_DI_DA
    orl_di_da();
#endif	
#ifdef XRL_A_RN
    xrl_a_rn();
#endif	
#ifdef XRL_A_DI
    xrl_a_di();
#endif	
#ifdef XRL_A_RI
    xrl_a_ri();
#endif	
#ifdef XRL_A_DA
    xrl_a_da();
#endif
#ifdef XRL_DI_A
    xrl_di_a();
#endif	
#ifdef XRL_DI_DA
    xrl_di_da();
#endif
#ifdef CLR_A
    clr_a();
#endif
#ifdef CPL_A
    cpl_a();
#endif
#ifdef RL_A
    rl_a();
#endif
#ifdef RLC_A
    rlc_a();
#endif
#ifdef RR_A
    rr_a();
#endif
#ifdef RRC_A
    rrc_a();
#endif
#ifdef SWAP_A
    swap_a();
#endif
}

void transfer(void){
#ifdef MOV_A_RN
    mov_a_rn();
#endif	
#ifdef MOV_A_DI
    mov_a_di();
#endif		
#ifdef MOV_A_RI
    mov_a_ri();
#endif	
#ifdef MOV_A_DA
    mov_a_da();
#endif
#ifdef MOV_RN_A
    mov_rn_a();
#endif
#ifdef MOV_RN_DI
    mov_rn_di();
#endif	
#ifdef MOV_RN_DA
    mov_rn_da();
#endif		
#ifdef MOV_DI_A
    mov_di_a();
#endif
#ifdef MOV_DI_RN
    mov_di_rn();
#endif
#ifdef MOV_DI_DI
    mov_di_di();
#endif
#ifdef MOV_DI_RI
    mov_di_ri();
#endif
#ifdef MOV_DI_DA
    mov_di_da();
#endif
#ifdef MOV_RI_A
    mov_ri_a();
#endif
#ifdef MOV_RI_DI
    mov_ri_di();
#endif
#ifdef MOV_RI_DA
    mov_ri_da();
#endif
#ifdef MOV_DP_DA
    mov_dp_da();
#endif
#ifdef MOVC_A_DP
    movc_a_dp();
#endif
#ifdef MOVC_A_PC
    movc_a_pc();
#endif
#ifdef MOVX_A_RI
    movx_a_ri();
#endif
#ifdef MOVX_A_DP
    movx_a_dp();
#endif
#ifdef MOVX_RI_A
    movx_ri_a();
#endif
#ifdef MOVX_DP_A
    movx_dp_a();
#endif
#ifdef PUSH_DI
    push_di();
#endif
#ifdef POP_DI
    pop_di();
#endif
#ifdef XCH_A_RN
    xch_a_rn();
#endif
#ifdef XCH_A_DI
    xch_a_di();
#endif
#ifdef XCH_A_RI
    xch_a_ri();
#endif
#ifdef XCHD_A_RI
    xchd_a_ri();
#endif
}

void boolean(void){
#ifdef CLR_C
    clr_c();
#endif	
#ifdef CLR_BIT
    clr_bit();
#endif
#ifdef SETB_C
    setb_c();
#endif
#ifdef SETB_BIT
    setb_bit();
#endif
#ifdef CPL_C
    cpl_c();
#endif
#ifdef CPL_BIT
    cpl_bit();
#endif	
#ifdef ANL_C_BIT
    anl_c_bit();
#endif
#ifdef ANL_C_NBIT
    anl_c_nbit();
#endif
#ifdef ORL_C_BIT
    orl_c_bit();
#endif
#ifdef ORL_C_NBIT
    orl_c_nbit();
#endif
#ifdef MOV_C_BIT
    mov_c_bit();
#endif
#ifdef MOV_BIT_C
    mov_bit_c();
#endif
#ifdef JC_C
    jc_c();
#endif
#ifdef JNC_C
    jnc_c();
#endif
#ifdef JB_BIT
    jb_bit();
#endif
#ifdef JNB_BIT
    jnb_bit();
#endif
#ifdef JBC_BIT
    jbc_bit();
#endif
}

void program(void){
#ifdef ACALL_FUNC
    acall_func();
#endif	
#ifdef LCALL_FUNC
    lcall_func();
#endif	
#ifdef RET_FUNC
    ret_func();
#endif
#ifdef RETI_FUNC
    reti_func();
#endif	
#ifdef AJMP_FUNC
    ajmp_func();
#endif	
#ifdef SJMP_FUNC
    sjmp_func();
#endif	
#ifdef JMP_FUNC
    jmp_func();
#endif	
#ifdef JZ_FUNC
    jz_func();
#endif	
#ifdef JNZ_FUNC
    jnz_func();
#endif
#ifdef CJNE_A_DI_REL
    cjne_a_di_rel();
#endif
#ifdef CJNE_A_DA_REL
    cjne_a_da_rel();
#endif
#ifdef CJNE_RN_DA_REL
    cjne_rn_da_rel();
#endif
#ifdef CJNE_RI_DA_REL
    cjne_ri_da_rel();
#endif
#ifdef DJNZ_RN_REL
    djnz_rn_rel();
#endif
#ifdef DJNZ_DI_REL
    djnz_di_rel();
#endif
}

