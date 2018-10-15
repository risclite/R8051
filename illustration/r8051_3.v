`define TYPE8052
`define DEL 1
module r8051 (

input  wire        clk,
input  wire        rst,
input  wire        cpu_en,
input  wire        cpu_restart,
	
output reg         rom_en,
output reg  [15:0] rom_addr,
input  wire [7:0]  rom_byte,
	
output wire        ram_rd_en_data,
output wire        ram_rd_en_sfr,
`ifdef TYPE8052
output wire        ram_rd_en_idata,
`endif
output wire        ram_rd_en_xdata,
output wire [15:0] ram_rd_addr,
input  wire [7:0]  ram_rd_byte,
input  wire        ram_rd_vld,
	
output wire        ram_wr_en_data,
output wire        ram_wr_en_sfr,
`ifdef TYPE8052
output wire        ram_wr_en_idata,
`endif
output wire        ram_wr_en_xdata,
output wire [15:0] ram_wr_addr,
output wire [7:0]  ram_wr_byte

);

`include "instruction.v"

/*********************************************************/
//register definition

reg                rd_wait;
reg      [7:0]     cmd1;
reg      [7:0]     cmd2;
reg      [2:0]     cmd_flag;
reg      [15:0]    pc;
reg      [7:0]     acc;
reg                psw_ov;
reg                psw_ac;
reg                psw_c;
reg      [3:0]     psw_other;
reg      [15:0]    dp;
reg      [7:0]     sp;
reg      [7:0]     b;
reg                same_flag;
reg      [7:0]     same_byte;
reg      [7:0]     data1;


/*********************************************************/
//wire definition

wire               work_en;
wire     [7:0]     cmd0;
wire     [7:0]     cmda;
wire     [7:0]     cmdb;
wire     [7:0]     cmdc;
reg                pc_en;
wire     [15:0]    pc_add1;
wire     [15:0]    code_base;
wire     [15:0]    code_rel;
wire     [15:0]    code_addr;
wire               length1;
wire               length2r1;
wire               length2;
wire               length3;
wire               rd_en_data_sfr;
wire               rd_en_data_idata;
wire               rd_en_xdata;
wire               rd_en_data;
wire               rd_en_sfr;
`ifdef TYPE8052
wire               rd_en_idata;
`endif
wire               same_flag_data;
wire               same_flag_sfr;
`ifdef TYPE8052
wire               same_flag_idata;
`endif
wire               same_flag_xdata;
wire               read_internal;
reg      [15:0]    rd_addr;
wire               use_psw_rs;
wire               use_dp;
wire               use_acc;
wire               use_sp;
wire               wait_en;
wire               wr_en_data_sfr;
wire               wr_en_data_idata;
wire               wr_en_xdata;
wire               wr_en_data;
wire               wr_en_sfr;
`ifdef TYPE8052
wire               wr_en_idata;
`endif 
wire               write_internal;
reg      [15:0]    wr_addr;
reg      [7:0]     wr_bit_byte;
reg      [7:0]     wr_byte;
reg      [7:0]     add_a;
reg      [7:0]     add_b;
reg                add_c;
reg                sub_flag;
wire               bit_ac;
wire     [3:0]     low;
wire     [3:0]     high;
wire               bit_c;
wire               bit_high; 
wire               bit_ov; 
wire     [7:0]     add_byte;
wire     [15:0]    mult;
wire     [7:0]     and_out;
wire     [7:0]     or_out; 
wire     [7:0]     xor_out;
wire               wr_acc;
wire               psw_p;
wire     [1:0]     psw_rs;
wire               wr_psw_rs; 
wire     [7:0]     psw;
wire               wr_dp;
wire     [7:0]     sp_sub1;
wire     [7:0]     sp_add1;
wire               wr_sp;
wire     [7:0]     div_ans;
wire     [7:0]     div_rem;
reg      [7:0]     data0;


/*********************************************************/


/*********************************************************/
//work_en

always @ ( posedge clk or posedge rst )
if ( rst )
    rd_wait <= #`DEL 1'b0;
else if ( cpu_restart )
    rd_wait <= #`DEL 1'b0;	
else if ( work_en )
`ifdef TYPE8052
    if ( ram_rd_en_data|ram_rd_en_sfr|ram_rd_en_idata|ram_rd_en_xdata )
`else
    if ( ram_rd_en_data|ram_rd_en_sfr|ram_rd_en_xdata ) 
`endif	
        rd_wait <= #`DEL 1'b1;
    else if ( ram_rd_vld )
        rd_wait <= #`DEL 1'b0;
	else;	
else;

assign work_en = ( rd_wait & ~ram_rd_vld ) ? 1'b0 : cpu_en;

/*********************************************************/

/*********************************************************/
//cmd0/cmd1/cmd2  cmda/cmdb/cmdc

assign cmd0 = rom_byte;

always @ ( posedge clk or posedge rst )
if ( rst )
    cmd1 <= #`DEL 8'b0;
else if ( work_en )
    cmd1 <= #`DEL cmd0;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    cmd2 <= #`DEL 8'b0;
else if ( work_en )
    cmd2 <= #`DEL cmdb;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    cmd_flag <= #`DEL 3'b1;
else if ( cpu_restart )
    cmd_flag <= #`DEL 3'b1;
else if ( work_en )
    if ( wait_en )
	    cmd_flag <= {1'b0,cmd_flag[1:0]};
    else if ( length2|length2r1 )
	    cmd_flag <= #`DEL 3'b101;
	else if ( length3 )
	    cmd_flag <= #`DEL 3'b100;
	else
        cmd_flag <= #`DEL { cmd_flag[1:0],1'b1};
else;

assign cmda = cmd_flag[1] ? cmd0 : 8'b0;

assign cmdb = cmd_flag[2] ? cmd1 : 8'b0;

assign cmdc = cmd2;


/*********************************************************/


/*********************************************************/
//rom_en rom_addr

always @*
if ( ~work_en )
    pc_en = 1'b0;
else if ( wait_en|length2r1 )
    pc_en = 1'b0;
else
    pc_en = 1'b1;

always @ ( posedge clk or posedge rst )
if ( rst )
    pc <= #`DEL 16'd0;
else if ( cpu_restart )
    pc <= #`DEL 16'd0;
else if ( work_en )
    if ( pc_en )
        pc <= #`DEL pc_add1;
	else;
else;

assign pc_add1 = rom_addr + 1'b1;

always @*
if ( ~work_en )
    rom_en = 1'b0;
else if ( wait_en )
    rom_en = 1'b0;
else if ( length2r1 )
    rom_en = 1'b0;
else
    rom_en = 1'b1;

assign code_base = 1'b0 ? dp : pc;

assign code_rel =  ( jc(cmdb)|jnc(cmdb)|jb(cmdc)|jnb(cmdc)|jbc(cmdb) ) ? {{8{cmd0[7]}},cmd0} : {{8{acc[7]}},acc};	
	
assign code_addr = code_base + code_rel;	

always @*
rom_addr = ( (jc(cmdb) & psw_c)|(jnc(cmdb) & ~psw_c)|((jb(cmdc)|jbc(cmdc)) & data0[cmd1[2:0]])|(jnb(cmdc) & ~data0[cmd1[2:0]]) ) ? code_addr : pc;


/*********************************************************/

/*********************************************************/
//command length

assign  length1 = clr_c(cmda)|setb_c(cmda)|cpl_c(cmda);

assign  length2r1 = 1'b0;

assign  length2 = clr_bit(cmda)|setb_bit(cmda)|cpl_bit(cmda)|anl_c_bit(cmda)|anl_c_nbit(cmda)|orl_c_bit(cmda)|orl_c_nbit(cmda)|mov_c_bit(cmda)|mov_bit_c(cmda)|jc(cmda)|jnc(cmda);

assign  length3 = jb(cmda)|jnb(cmda)|jbc(cmda);


/*********************************************************/


/*********************************************************/
//ram_rd_en ram_rd_addr 

assign rd_en_data_sfr = clr_bit(cmdb)|setb_bit(cmdb)|cpl_bit(cmdb)|anl_c_bit(cmdb)|anl_c_nbit(cmdb)|orl_c_bit(cmdb)|orl_c_nbit(cmdb)|mov_c_bit(cmdb)|mov_bit_c(cmdb)|jb(cmdb)|jnb(cmdb)|jbc(cmdb);

assign rd_en_data_idata = 1'b0;

assign rd_en_xdata = 1'b0;

assign rd_en_data = (rd_en_data_sfr|rd_en_data_idata) & ~rd_addr[7];
`ifdef TYPE8052
assign rd_en_sfr = rd_en_data_sfr & rd_addr[7];
assign rd_en_idata = rd_en_data_idata & rd_addr[7];
`else
assign rd_en_sfr = (rd_en_data_sfr|rd_en_data_idata) & rd_addr[7];
`endif
assign same_flag_data = rd_en_data & wr_en_data & (rd_addr[7:0]==wr_addr[7:0]);
assign same_flag_sfr = rd_en_sfr & wr_en_sfr & (rd_addr[7:0]==wr_addr[7:0]);
`ifdef TYPE8052
assign same_flag_idata = rd_en_idata & wr_en_idata & (rd_addr[7:0]==wr_addr[7:0]);
`endif
assign same_flag_xdata = rd_en_xdata & wr_en_xdata & (rd_addr[15:0]==wr_addr[15:0]);
assign read_internal = rd_en_sfr & ( (rd_addr[7:0]==8'he0)|(rd_addr[7:0]==8'hd0)|(rd_addr[7:0]==8'h83)|(rd_addr[7:0]==8'h82)|(rd_addr[7:0]==8'h81)|(rd_addr[7:0]==8'hf0) );
assign ram_rd_en_data = work_en & rd_en_data & ~same_flag_data & ~wait_en;
assign ram_rd_en_sfr = work_en & rd_en_sfr & ~same_flag_sfr & ~read_internal & ~wait_en;
`ifdef TYPE8052
assign ram_rd_en_idata = work_en & rd_en_idata & ~same_flag_idata & ~wait_en;
`endif 
assign ram_rd_en_xdata = work_en & rd_en_xdata & ~same_flag_xdata & ~wait_en;


always @*
if ( clr_bit(cmdb)|setb_bit(cmdb)|cpl_bit(cmdb)|anl_c_bit(cmdb)|anl_c_nbit(cmdb)|orl_c_bit(cmdb)|orl_c_nbit(cmdb)|mov_c_bit(cmdb)|mov_bit_c(cmdb)|jb(cmdb)|jnb(cmdb)|jbc(cmdb) )
    rd_addr = cmd0[7] ? {cmd0[7:3],3'b0} : {3'b001,cmd0[7:3]}; 
else
    rd_addr = 16'd0;

assign ram_rd_addr = rd_addr;	

assign use_psw_rs = 1'b0;

assign use_dp = 1'b0;

assign use_acc = 1'b0;

assign use_sp = 1'b0;

assign wait_en = (use_psw_rs&wr_psw_rs)|(use_dp&wr_dp)|(use_acc&wr_acc)|(use_sp&wr_sp);

/*********************************************************/

/*********************************************************/
//ram_wr_en ram_wr_addr  

assign wr_en_data_sfr = clr_bit(cmdc)|setb_bit(cmdc)|cpl_bit(cmdc)|mov_bit_c(cmdc)|(jbc(cmdb)&data0[cmd1[2:0]]);

assign wr_en_data_idata = 1'b0;

assign wr_en_xdata = 1'b0;

assign wr_en_data = (wr_en_data_sfr|wr_en_data_idata) & ~wr_addr[7];
`ifdef TYPE8052
assign wr_en_sfr = wr_en_data_sfr & wr_addr[7];
assign wr_en_idata = wr_en_data_idata & wr_addr[7];
`else
assign wr_en_sfr = (wr_en_data_sfr|wr_en_data_idata) & wr_addr[7];
`endif
assign write_internal = wr_en_sfr & ( (wr_addr[7:0]==8'he0)|(wr_addr[7:0]==8'hd0)|(wr_addr[7:0]==8'h83)|(wr_addr[7:0]==8'h82)|(wr_addr[7:0]==8'h81)|(wr_addr[7:0]==8'hf0) );
assign ram_wr_en_data = work_en & wr_en_data;
assign ram_wr_en_sfr = work_en & wr_en_sfr & ~write_internal;
`ifdef TYPE8052
assign ram_wr_en_idata = work_en & wr_en_idata;
`endif
assign ram_wr_en_xdata = work_en & wr_en_xdata;

always @*
if ( clr_bit(cmdc)|setb_bit(cmdc)|cpl_bit(cmdc)|mov_bit_c(cmdc)|jbc(cmdc) )
    wr_addr = cmd1[7] ? {cmd1[7:3],3'b0} : {3'b001,cmd1[7:3]};
else 
    wr_addr = 16'd0;
	
assign ram_wr_addr = wr_addr;	

/*********************************************************/


/*********************************************************/
//ram_wr_byte

always @* begin
wr_bit_byte = data0;
if ( clr_bit(cmdc)|jbc(cmdc) )
    wr_bit_byte[cmd1[2:0]] = 1'b0;
else if ( setb_bit(cmdc) )
    wr_bit_byte[cmd1[2:0]] = 1'b1;	
else if ( cpl_bit(cmdc) )
    wr_bit_byte[cmd1[2:0]] = ~wr_bit_byte[cmd1[2:0]];
else if ( mov_bit_c(cmdc) )
    wr_bit_byte[cmd1[2:0]] = psw_c;	
else;
end

always @*
if ( clr_bit(cmdc)|setb_bit(cmdc)|cpl_bit(cmdc)|mov_bit_c(cmdc)|jbc(cmdc) )
    wr_byte = wr_bit_byte;
else 
    wr_byte = 8'd0;

assign ram_wr_byte = wr_byte;	

/*********************************************************/


/*********************************************************/
//acc register

always @*
add_a = 8'b0;


always @*
add_b = 8'b0;


always @*
add_c = 1'b0;	


always @*
sub_flag = 1'b0;


assign {bit_ac,low} = sub_flag ? (add_a[3:0]-add_b[3:0]-add_c) : (add_a[3:0]+add_b[3:0]+add_c);
assign high = sub_flag ? (add_a[6:4]-add_b[6:4]-bit_ac) : (add_a[6:4]+add_b[6:4]+bit_ac);
assign {bit_c,bit_high} = sub_flag ? (add_a[7]-add_b[7]-high[3]) : (add_a[7]+add_b[7]+high[3]);
assign bit_ov = bit_c ^ high[3];
assign add_byte = {bit_high,high[2:0],low};

assign mult = acc * b;
assign {div_rem,div_ans} = divide(acc,b);
assign and_out = acc & data0;
assign or_out  = acc | data0;
assign xor_out = acc ^ data0;

always @ ( posedge clk or posedge rst )
if ( rst )
    acc <= #`DEL 8'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'he0 ) )
	    acc <= #`DEL wr_byte;
	else;
else;

assign wr_acc = (wr_en_sfr & (wr_addr[7:0]==8'he0));

/*********************************************************/


/*********************************************************/
//psw register

assign psw_p = ^acc;

always @ ( posedge clk or posedge rst )
if ( rst )
    psw_ov <= #`DEL 1'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'hd0 ) )
	    psw_ov <= #`DEL wr_byte[2];
	else;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    psw_ac <= #`DEL 1'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'hd0 ) )
	    psw_ac <= #`DEL wr_byte[6];
	else;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    psw_c <= #`DEL 1'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'hd0 ) )
	    psw_c <= #`DEL wr_byte[7];
	else if ( clr_c(cmda) )
        psw_c <= #`DEL 1'b0;
	else if ( setb_c(cmda) )
        psw_c <= #`DEL 1'b1;
    else if ( cpl_c(cmdb) )
        psw_c <= #`DEL ~psw_c;
    else if ( anl_c_bit(cmdc) )
        psw_c <= #`DEL psw_c & data0[cmd1[2:0]];	
	else if ( anl_c_nbit(cmdc) )
        psw_c <= #`DEL psw_c & ~data0[cmd1[2:0]];	
	else if ( orl_c_bit(cmdc) )
        psw_c <= #`DEL psw_c | data0[cmd1[2:0]];
    else if ( orl_c_nbit(cmdc) )
        psw_c <= #`DEL psw_c | ~data0[cmd1[2:0]];	
	else if ( mov_c_bit(cmdc) )
        psw_c <= #`DEL data0[cmd1[2:0]];	
	else;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    psw_other <= #`DEL 4'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'hd0 ) )
	    psw_other <= #`DEL {wr_byte[5:3],wr_byte[1]};
	else;
else;

assign psw_rs = psw_other[2:1];

assign wr_psw_rs = wr_en_sfr & (wr_addr[7:0]==8'hd0);

assign psw = {psw_c,psw_ac,psw_other[3:1],psw_ov,psw_other[0],psw_p};

/*********************************************************/

/*********************************************************/
//dp  sp registers

always @ ( posedge clk or posedge rst )
if ( rst )
    dp <= #`DEL 16'b0;
else if ( work_en )
    if  ( wr_en_sfr & (wr_addr[7:0]==8'h82 ) )
	    dp[7:0] <= #`DEL wr_byte;
	else if  ( wr_en_sfr & (wr_addr[7:0]==8'h83 ) )
	    dp[15:8] <= #`DEL wr_byte;
	else;
else;

assign wr_dp = (wr_en_sfr & ((wr_addr[7:0]==8'h82)|(wr_addr[7:0]==8'h83)));

always @ ( posedge clk or posedge rst )
if ( rst )
    sp <= #`DEL 8'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'h81) )
	    sp <= #`DEL wr_byte;
	else;
else;

assign sp_sub1 = sp - 1'b1;

assign sp_add1 = sp + 1'b1;

assign wr_sp = (wr_en_sfr & (wr_addr[7:0]==8'h81));

always @ ( posedge clk or posedge rst )
if ( rst )
    b <= #`DEL 8'b0;
else if ( work_en )
    if ( wr_en_sfr & (wr_addr[7:0]==8'hf0) )
	    b <= #`DEL wr_byte;
	else;
else;

/*********************************************************/


/*********************************************************/
//ram output

always @*
if ( same_flag )
    data0 = same_byte;
else if ( same_byte[7] )
    data0 = acc;
else if ( same_byte[6] )
    data0 = psw;
else if ( same_byte[5] )
    data0 = dp[15:8];
else if ( same_byte[4] )
    data0 = dp[7:0];
else if ( same_byte[3] )
    data0 = sp;
else if ( same_byte[2] )
    data0 = b;
else
    data0 = ram_rd_byte;

always @ ( posedge clk or posedge rst )
if ( rst )
    data1 <= #`DEL 8'b0;
else if ( work_en )
    data1 <= #`DEL data0;
else;
    
always @ ( posedge clk or posedge rst )
if ( rst )
    same_flag <= #`DEL 1'b0;
else if ( work_en )
`ifdef TYPE8052
    if ( same_flag_data|same_flag_sfr|same_flag_idata|same_flag_xdata )
`else 
    if ( same_flag_data|same_flag_sfr|same_flag_xdata )
`endif	
	    same_flag <= #`DEL 1'b1;
	else
	    same_flag <= #`DEL 1'b0;
else;

always @ ( posedge clk or posedge rst )
if ( rst )
    same_byte <= #`DEL 8'd0;
else if ( work_en )
`ifdef TYPE8052
    if ( same_flag_data|same_flag_sfr|same_flag_idata|same_flag_xdata )
`else
    if ( same_flag_data|same_flag_sfr|same_flag_xdata )
`endif	
	    same_byte <= #`DEL wr_byte;
	else if ( rd_en_sfr & (rd_addr[7:0]==8'he0) ) //acc
	    same_byte <= #`DEL 1'b1<<7;
	else if ( rd_en_sfr & (rd_addr[7:0]==8'hd0) ) //psw
	    same_byte <= #`DEL 1'b1<<6;
	else if ( rd_en_sfr & (rd_addr[7:0]==8'h83) ) //dph
	    same_byte <= #`DEL 1'b1<<5;	
	else if ( rd_en_sfr & (rd_addr[7:0]==8'h82) ) //dpl
	    same_byte <= #`DEL 1'b1<<4;	
	else if ( rd_en_sfr & (rd_addr[7:0]==8'h81) ) //sp
	    same_byte <= #`DEL 1'b1<<3;
	else if ( rd_en_sfr & (rd_addr[7:0]==8'hf0) ) //b
	    same_byte <= #`DEL 1'b1<<2;		
	else
	    same_byte <= #`DEL 8'b0;
else;
	
/*********************************************************/

endmodule
