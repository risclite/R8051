#ifndef __INSTRUCTION
#define __INSTRUCTION

typedef unsigned char UCHAR;

typedef	volatile UCHAR  VUCHAR;

#define R(M,N)  *(VUCHAR data *) (8*(M)+(N)) 

#define test_status *(VUCHAR xdata *) 0x7e

#define kill_self *(VUCHAR xdata *) 0x7f

#define bit_data *(VUCHAR bdata *) 0x20


extern void error(void);
extern void instruction_test_all(void);

#define ARITHMETIC

#define ADD_A_RN
#define ADD_A_DI
#define ADD_A_RI
#define ADD_A_DA
#define ADDC_A_RN
#define ADDC_A_DI
#define ADDC_A_RI
#define ADDC_A_DA
#define SUBB_A_RN
#define SUBB_A_DI
#define SUBB_A_RI
#define SUBB_A_DA
#define INC_A
#define INC_RN
#define INC_DI
#define INC_RI
#define INC_DP
#define DEC_A
#define DEC_RN
#define DEC_DI
#define DEC_RI
#define MULT
#define DIVIDE
#define DA_A

extern void arithmetic(void);
extern void add_a_rn(void);
extern void add_a_di(void);
extern void add_a_ri(void);
extern void add_a_da(void);
extern void addc_a_rn(void);
extern void addc_a_di(void);
extern void addc_a_ri(void);
extern void addc_a_da(void);
extern void subb_a_rn(void);
extern void subb_a_di(void);
extern void subb_a_ri(void);
extern void subb_a_da(void);
extern void inc_a(void);
extern void inc_rn(void);
extern void inc_di(void);
extern void inc_ri(void);
extern void inc_dp(void);
extern void dec_a(void);
extern void dec_rn(void);
extern void dec_di(void);
extern void dec_ri(void);
extern void mult(void);
extern void divide(void);
extern void da_a(void);

#define LOGICAL

#define ANL_A_RN
#define ANL_A_DI
#define ANL_A_RI
#define ANL_A_DA
#define ANL_DI_A
#define ANL_DI_DA
#define ORL_A_RN
#define ORL_A_DI
#define ORL_A_RI
#define ORL_A_DA
#define ORL_DI_A
#define ORL_DI_DA
#define XRL_A_RN
#define XRL_A_DI
#define XRL_A_RI
#define XRL_A_DA
#define XRL_DI_A
#define XRL_DI_DA
#define CLR_A
#define CPL_A
#define RL_A
#define RLC_A
#define RR_A
#define RRC_A
#define SWAP_A

extern void logical(void);
extern void anl_a_rn(void);
extern void anl_a_di(void);
extern void anl_a_ri(void);
extern void anl_a_da(void);
extern void anl_di_a(void);
extern void anl_di_da(void);
extern void orl_a_rn(void);
extern void orl_a_di(void);
extern void orl_a_ri(void);
extern void orl_a_da(void);
extern void orl_di_a(void);
extern void orl_di_da(void);
extern void xrl_a_rn(void);
extern void xrl_a_di(void);
extern void xrl_a_ri(void);
extern void xrl_a_da(void);
extern void xrl_di_a(void);
extern void xrl_di_da(void);
extern void clr_a(void);
extern void cpl_a(void);
extern void rl_a(void);
extern void rlc_a(void);
extern void rr_a(void);
extern void rrc_a(void);
extern void swap_a(void);

#define TRANSFER

#define MOV_A_RN
#define MOV_A_DI
#define MOV_A_RI
#define MOV_A_DA
#define MOV_RN_A
#define MOV_RN_DI
#define MOV_RN_DA
#define MOV_DI_A
#define MOV_DI_RN
#define MOV_DI_DI
#define MOV_DI_RI
#define MOV_DI_DA
#define MOV_RI_A
#define MOV_RI_DI
#define MOV_RI_DA
#define MOV_DP_DA
#define MOVC_A_DP
#define MOVC_A_PC
#define MOVX_A_RI
#define MOVX_A_DP
#define MOVX_RI_A
#define MOVX_DP_A
#define PUSH_DI
#define POP_DI
#define XCH_A_RN
#define XCH_A_DI
#define XCH_A_RI
#define XCHD_A_RI

extern void transfer(void);
extern void mov_a_rn(void);
extern void mov_a_di(void);
extern void mov_a_ri(void);
extern void mov_a_da(void);
extern void mov_rn_a(void);
extern void mov_rn_di(void);
extern void mov_rn_da(void);
extern void mov_di_a(void);
extern void mov_di_rn(void);
extern void mov_di_di(void);
extern void mov_di_ri(void);
extern void mov_di_da(void);
extern void mov_ri_a(void);
extern void mov_ri_di(void);
extern void mov_ri_da(void);
extern void mov_dp_da(void);
extern void movc_a_dp(void);
extern void movc_a_pc(void);
extern void movx_a_ri(void);
extern void movx_a_dp(void);
extern void movx_ri_a(void);
extern void movx_dp_a(void);
extern void push_di(void);
extern void pop_di(void);
extern void xch_a_rn(void);
extern void xch_a_di(void);
extern void xch_a_ri(void);
extern void xchd_a_ri(void);

#define BOOLEAN

#define CLR_C
#define CLR_BIT
#define SETB_C
#define SETB_BIT
#define CPL_C
#define CPL_BIT
#define ANL_C_BIT
#define ANL_C_NBIT
#define ORL_C_BIT
#define ORL_C_NBIT
#define MOV_C_BIT
#define MOV_BIT_C
#define JC_C
#define JNC_C
#define JB_BIT
#define JNB_BIT
#define JBC_BIT


extern void boolean(void);
extern void clr_c(void);
extern void clr_bit(void);
extern void setb_c(void);
extern void setb_bit(void);
extern void cpl_c(void);
extern void cpl_bit(void);
extern void anl_c_bit(void);
extern void anl_c_nbit(void);
extern void orl_c_bit(void);
extern void orl_c_nbit(void);
extern void mov_c_bit(void);
extern void mov_bit_c(void);
extern void jc_c(void);
extern void jnc_c(void);
extern void jb_bit(void);
extern void jnb_bit(void);
extern void jbc_bit(void);

#define PROGRAM

#define ACALL_FUNC
#define LCALL_FUNC
#define RET_FUNC
#define RETI_FUNC
#define AJMP_FUNC
#define SJMP_FUNC
#define JMP_FUNC
#define JZ_FUNC
#define JNZ_FUNC
#define CJNE_A_DI_REL
#define CJNE_A_DA_REL
#define CJNE_RN_DA_REL
#define CJNE_RI_DA_REL
#define DJNZ_RN_REL
#define DJNZ_DI_REL

extern void program(void);
extern void acall_func(void);
extern void lcall_func(void);
extern void ret_func(void);
extern void reti_func(void);
extern void ajmp_func(void);
extern void sjmp_func(void);
extern void jmp_func(void);
extern void jz_func(void);
extern void jnz_func(void);
extern void cjne_a_di_rel(void);
extern void cjne_a_da_rel(void);
extern void cjne_rn_da_rel(void);
extern void cjne_ri_da_rel(void);
extern void djnz_rn_rel(void);
extern void djnz_di_rel(void);

#endif