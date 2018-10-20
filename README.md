R8051
=====

Thank you for interesting in this new type of 8051 soft core. This core has only 2 files and the main one has 700 statements to support all 111 instructions of 8051. Yes, I make it with fully synthesizable verilog. 

First of all, please open **rtl/r8051.v** and review it.The another file: **rtl/instruction.v** is an included file which has some verilog functions. These are all RTL files to implementation.

There is a folder: **Hello** that has 111-instructions compliance tests project. If your have the software "KEIL", you can open this project and check it. You can comment or uncomment any single instruction test and re-compile again. The other folder **sim** has one testbench file: **tb.v**, it is understandable easily for verilog designer. You may compile **tb.v** and **r8051.v** for your verilog simulator. This testbench file will link the compiled binary file of **HELLO** directory to the simulation. Instructions in the binary file will be fetched one by one and be executed. You can open a wave window and drag signals you are instresting in.

Maybe you are pulsed with how this works. 8051 has 111-instructions and each has 1 or 2 or 3 bytes.This CPU core will fetch 1 byte every clock. There is a 3-byte-long pipiline, named: A, B, C according to time. For 1-byte instrctions, if it is in A, its operand is loaded from memory pool, and the result is stored to memory pool when this instrcution enters B position. For one 2-bytes intruction, when the head byte of it is in the position A, it has enough info for loading operands from memory pool. When the head byte is in B, the tail byte is in A and it is for storing the result to memory pool since all 2 bytes are available. For one 3-bytes instruction, when the head byte is in B , the middle byte is in A and the tail byte is not present, its two operands are being fetched. In the next clock, its two operands are available and all 3 bytes of it are present in "A-B-C" pipeline, which is good for storing the result into the destination. So, one byte by one byte, different-length instructions are executed in this pipeline.

I made it with an incremental method. As a centipede for example, it has a bulk body and 111 legs. I build the bulk body firstly and give it one leg one time. When all legs are installed, this centipede is finished. In the fold **illustration**, there are several **.v** files. The **r8051_bulk.v** is the bulk body I mentioned and it could not interpret any instruction. It may look ugly but helpful on its structure. Since 111 instruction are divided into five categories(ARITHMETIC/LOGICAL/DATA/BOOLEAN/PROGRAM), the **r8051_0/1/2/3/4.v** is for every category solely and the **r8051_a/b/c/d/e.v** is for building these 5 categories incrementally. 

If you can read Chinese, please refer this:

![book Picture](https://github.com/risclite/R8051/blob/master/doc/book.jpg)

[Amazon Book: How to design 8051-compatiable soft core for FPGA](https://www.amazon.com/dp/B00UH9GLQ6/)

