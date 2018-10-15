/////////////////////////////////////////////////////////////////////////////////////
//
//Copyright 2018  Li Xinbing
//
//Licensed under the Apache License, Version 2.0 (the "License");
//you may not use this file except in compliance with the License.
//You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
//Unless required by applicable law or agreed to in writing, software
//distributed under the License is distributed on an "AS IS" BASIS,
//WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//See the License for the specific language governing permissions and
//limitations under the License.
//
/////////////////////////////////////////////////////////////////////////////////////


//ARITHMETIC OPERATIONS
//ADD
function add_a_rn(input [7:0] i);  add_a_rn = (i[7:3]==5'b00101); endfunction
function add_a_di(input [7:0] i);  add_a_di=(i==8'b00100101); endfunction
function add_a_ri(input [7:0] i);  add_a_ri=(i[7:1]==7'b0010011); endfunction
function add_a_da(input [7:0] i);  add_a_da = (i==8'b00100100);  endfunction
//ADDC
function addc_a_rn(input [7:0] i); addc_a_rn = (i[7:3]==5'b00111); endfunction
function addc_a_di(input [7:0] i); addc_a_di = (i==8'b00110101); endfunction
function addc_a_ri(input [7:0] i); addc_a_ri = (i[7:1]==7'b0011011); endfunction
function addc_a_da(input [7:0] i); addc_a_da = (i==8'b00110100); endfunction
//SUBB
function subb_a_rn(input [7:0] i); subb_a_rn=(i[7:3]==5'b10011); endfunction
function subb_a_di(input [7:0] i); subb_a_di=(i==8'b10010101); endfunction
function subb_a_ri(input [7:0] i); subb_a_ri=(i[7:1]==7'b1001011); endfunction
function subb_a_da(input [7:0] i); subb_a_da = (i==8'b10010100); endfunction
//INC
function inc_a (input [7:0] i); inc_a = (i==8'b00000100); endfunction
function inc_rn(input [7:0] i); inc_rn = (i[7:3]==5'b00001); endfunction
function inc_di(input [7:0] i); inc_di = (i==8'b00000101); endfunction
function inc_ri(input [7:0] i); inc_ri = (i[7:1]==7'b0000011); endfunction
function inc_dp(input [7:0] i); inc_dp =(i==8'b10100011); endfunction
//DEC
function dec_a(input [7:0] i); dec_a = (i==8'b00010100); endfunction
function dec_rn(input [7:0] i); dec_rn = (i[7:3]==5'b00011); endfunction
function dec_di(input [7:0] i); dec_di = (i==8'b00010101); endfunction
function dec_ri(input [7:0] i); dec_ri = (i[7:1]==7'b0001011); endfunction
//MUL
function mul(input [7:0] i); mul=(i==8'b10100100); endfunction
//DIV
function div(input [7:0] i); div=(i==8'b10000100); endfunction
//DA
function da(input [7:0] i); da = (i==8'b11010100); endfunction

//LOGICAL OPERATIONS
//ANL
function anl_a_rn(input [7:0] i); anl_a_rn = (i[7:3]==5'b01011); endfunction
function anl_a_di(input [7:0] i); anl_a_di = (i==8'b01010101); endfunction
function anl_a_ri(input [7:0] i); anl_a_ri = (i[7:1]==7'b0101011); endfunction
function anl_a_da(input [7:0] i); anl_a_da = (i==8'b01010100); endfunction
function anl_di_a(input [7:0] i); anl_di_a = (i==8'b01010010); endfunction
function anl_di_da(input [7:0] i); anl_di_da = (i==8'b01010011); endfunction
//ORL
function orl_a_rn(input [7:0] i); orl_a_rn = (i[7:3]==5'b01001); endfunction
function orl_a_di(input [7:0] i); orl_a_di = (i==8'b01000101); endfunction
function orl_a_ri(input [7:0] i); orl_a_ri = (i[7:1]==7'b0100011); endfunction
function orl_a_da(input [7:0] i); orl_a_da = (i==8'b01000100); endfunction
function orl_di_a(input [7:0] i); orl_di_a=(i==8'b01000010); endfunction
function orl_di_da(input [7:0] i); orl_di_da=(i==8'b01000011); endfunction
//XRL
function xrl_a_rn(input [7:0] i); xrl_a_rn = (i[7:3]==5'b01101); endfunction
function xrl_a_di(input [7:0] i); xrl_a_di = (i==8'b01100101); endfunction
function xrl_a_ri(input [7:0] i); xrl_a_ri = (i[7:1]==7'b0110011); endfunction
function xrl_a_da(input [7:0] i); xrl_a_da = (i==8'b01100100); endfunction
function xrl_di_a(input [7:0] i); xrl_di_a = (i==8'b01100010); endfunction
function xrl_di_da(input [7:0] i); xrl_di_da = (i==8'b01100011); endfunction
//CLR
function clr_a(input [7:0] i); clr_a = (i==8'b11100100); endfunction
//CPL
function cpl_a(input [7:0] i); cpl_a = (i==8'b11110100); endfunction
//RL
function rl(input [7:0] i); rl = (i==8'b00100011); endfunction
//RLC
function rlc(input [7:0] i); rlc = (i==8'b00110011); endfunction
//RR
function rr(input [7:0] i); rr = (i==8'b00000011); endfunction
//RRC
function rrc(input [7:0] i); rrc = (i==8'b00010011); endfunction
//SWAP
function swap(input [7:0] i); swap = (i==8'b11000100); endfunction

//DATA TRANSFER
//MOV
function mov_a_rn(input [7:0] i); mov_a_rn = (i[7:3]==5'b11101); endfunction
function mov_a_di(input [7:0] i); mov_a_di = (i==8'b11100101); endfunction
function mov_a_ri(input [7:0] i); mov_a_ri = (i[7:1]==7'b1110011); endfunction
function mov_a_da(input [7:0] i); mov_a_da = (i==8'b01110100); endfunction
function mov_rn_a(input [7:0] i); mov_rn_a = (i[7:3]==5'b11111); endfunction
function mov_rn_di(input [7:0] i); mov_rn_di = (i[7:3]==5'b10101); endfunction
function mov_rn_da(input [7:0] i); mov_rn_da = (i[7:3]==5'b01111); endfunction
function mov_di_a(input [7:0] i); mov_di_a = (i==8'b11110101); endfunction
function mov_di_rn(input [7:0] i); mov_di_rn = (i[7:3]==5'b10001); endfunction
function mov_di_di(input [7:0] i); mov_di_di = (i==8'b10000101); endfunction
function mov_di_ri(input [7:0] i); mov_di_ri = (i[7:1]==7'b1000011); endfunction 
function mov_di_da(input [7:0] i); mov_di_da = (i==8'b01110101); endfunction
function mov_ri_a(input [7:0] i);  mov_ri_a = (i[7:1]==7'b1111011); endfunction
function mov_ri_di(input [7:0] i); mov_ri_di = (i[7:1]==7'b1010011); endfunction
function mov_ri_da(input [7:0] i); mov_ri_da=(i[7:1]==7'b0111011); endfunction
function mov_dp_da(input [7:0] i); mov_dp_da=(i==8'b10010000); endfunction
//MOVC
function movc_a_dp(input [7:0] i); movc_a_dp = (i==8'b10010011); endfunction
function movc_a_pc(input [7:0] i); movc_a_pc = (i==8'b10000011); endfunction
//MOVX
function movx_a_ri(input [7:0] i); movx_a_ri = (i[7:1]==7'b1110001); endfunction
function movx_a_dp(input [7:0] i); movx_a_dp = (i==8'b11100000); endfunction
function movx_ri_a(input [7:0] i); movx_ri_a = (i[7:1]==7'b1111001); endfunction
function movx_dp_a(input [7:0] i); movx_dp_a = (i==8'b11110000); endfunction
//PUSH
function push(input [7:0] i); push = (i==8'b11000000); endfunction
//POP
function pop(input [7:0] i); pop = (i==8'b11010000); endfunction
//XCH
function xch_a_rn(input [7:0] i); xch_a_rn = (i[7:3]==5'b11001); endfunction
function xch_a_di(input [7:0] i); xch_a_di = (i==8'b11000101); endfunction
function xch_a_ri(input [7:0] i); xch_a_ri = (i[7:1]==7'b1100011); endfunction
//XCHD
function xchd(input [7:0] i); xchd = (i[7:1]==7'b1101011); endfunction

//BOOLEAN VARIABLE MANIPULATION
//CLR
function clr_c(input [7:0] i); clr_c = (i==8'b11000011); endfunction
function clr_bit(input [7:0] i); clr_bit = (i==8'b11000010); endfunction
//SETB
function setb_c(input [7:0] i); setb_c = (i==8'b11010011); endfunction
function setb_bit(input [7:0] i); setb_bit = (i==8'b11010010); endfunction
//CPL
function cpl_c(input [7:0] i); cpl_c = (i==8'b10110011); endfunction
function cpl_bit(input [7:0] i); cpl_bit=(i==8'b10110010); endfunction
//ANL
function anl_c_bit(input [7:0] i); anl_c_bit = (i==8'b10000010); endfunction
function anl_c_nbit(input [7:0] i); anl_c_nbit = (i==8'b10110000); endfunction
//ORL
function orl_c_bit(input [7:0] i); orl_c_bit = (i==8'b01110010); endfunction
function orl_c_nbit(input [7:0] i); orl_c_nbit = (i==8'b10100000); endfunction
//MOV
function mov_c_bit(input [7:0] i); mov_c_bit = (i==8'b10100010); endfunction
function mov_bit_c(input [7:0] i); mov_bit_c = (i==8'b10010010); endfunction
//JC
function jc(input [7:0] i); jc = (i==8'b01000000); endfunction
//JNC
function jnc(input [7:0] i); jnc =(i==8'b01010000); endfunction
//JB
function jb(input [7:0] i); jb = (i==8'b00100000); endfunction
//JNB
function jnb(input [7:0] i); jnb = (i==8'b00110000); endfunction
//JBC
function jbc(input [7:0] i); jbc = (i==8'b00010000); endfunction

//PROGRAM BRANCHING
//ACALL
function acall(input [7:0] i); acall = (i[4:0]==5'b10001); endfunction
//LCALL
function lcall(input [7:0] i); lcall = (i==8'b00010010); endfunction
//RET
function ret(input [7:0] i); ret = (i==8'b00100010); endfunction
//RETI
function reti(input [7:0] i); reti = (i==8'b00110010); endfunction
//AJMP
function ajmp(input [7:0] i); ajmp = (i[4:0]==5'b00001); endfunction
//LJMP
function ljmp(input [7:0] i); ljmp = (i==8'b00000010); endfunction
//SJMP
function sjmp(input [7:0] i); sjmp = (i==8'b10000000); endfunction
//JMP
function jmp(input [7:0] i); jmp = (i==8'b01110011); endfunction
//JZ
function jz(input [7:0] i); jz = (i==8'b01100000); endfunction
//JNZ
function jnz(input [7:0] i); jnz = (i==8'b01110000); endfunction
//CJNE
function cjne_a_di_rel(input [7:0] i); cjne_a_di_rel = (i==8'b10110101); endfunction
function cjne_a_da_rel(input [7:0] i); cjne_a_da_rel = (i==8'b10110100); endfunction
function cjne_rn_da_rel(input [7:0] i); cjne_rn_da_rel = (i[7:3]==5'b10111); endfunction
function cjne_ri_da_rel(input [7:0] i); cjne_ri_da_rel=(i[7:1]==7'b1011011); endfunction
//DJNZ
function djnz_rn_rel(input [7:0] i); djnz_rn_rel = (i[7:3]==5'b11011); endfunction
function djnz_di_rel(input [7:0] i); djnz_di_rel =(i==8'b11010101); endfunction
//NOP
function nop(input [7:0] i); nop = (i==8'b00000000); endfunction


function [15:0] divide ( input [7:0] a, input [7:0] b);
reg  [7:0]     ans;
reg  [7:0]     rem;
reg  [7:0]     x7;
reg  [7:0]     x6;
reg  [7:0]     x5;
reg  [7:0]     x4;
reg  [7:0]     x3;
reg  [7:0]     x2;
reg  [7:0]     x1;
reg  [7:0]     x0;

reg  [1:0]     y5;
reg  [2:0]     y4; 
reg  [3:0]     y3;
reg  [4:0]     y2;
reg  [5:0]     y1;
reg  [6:0]     y0;
begin

x7 = a;
ans[7] = (|b[7:1])? 1'b0 : x7[7];

x6 = {(~ans[7])&a[7],a[6:0]};
ans[6] = (|b[7:2])? 1'b0 : (x6[7:6]>=b[1:0]);

y5 = ans[6] ? (x6[7:6]-b[1:0]) : x6[7:6];
x5 = { y5, a[5:0] };
ans[5] = (|b[7:3])? 1'b0 : ( x5[7:5]>=b[2:0] );

y4 = ans[5] ? (x5[7:5]-b[2:0]) : x5[7:5];
x4 = { y4, a[4:0]};
ans[4] = (|b[7:4])? 1'b0 : ( x4[7:4]>=b[3:0] );

y3 = ans[4] ? (x4[7:4]-b[3:0]) : x4[7:4];
x3 = {y3, a[3:0]};
ans[3] = (|b[7:5])? 1'b0 : ( x3[7:3]>=b[4:0] );

y2 = ans[3] ? (x3[7:3]-b[4:0]) : x3[7:3];
x2 = {y2,a[2:0]};
ans[2] = (|b[7:6])? 1'b0 : ( x2[7:2]>=b[5:0] );

y1 = ans[2] ? (x2[7:2]-b[5:0]) : x2[7:2];
x1 = {y1,a[1:0]};
ans[1] = (|b[7]) ? 1'b0 : ( x1[7:1]>=b[6:0] );

y0 = ans[1] ? (x1[7:1]-b[6:0]) : x1[7:1];
x0 = {y0,a[0]};
ans[0] = (x0>=b);

rem = ans[0] ? (x0-b) : x0;

divide = {rem,ans};
end

endfunction

