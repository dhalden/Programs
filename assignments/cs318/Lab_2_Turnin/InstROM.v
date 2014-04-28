`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 	Derek Halden
// 
// Create Date:    15:50:22 11/02/2007 
// Design Name: 
// Module Name:    InstROM 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: This is a basic verilog module to behave as an instruction ROM
// 				 template.
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module InstROM(InstAddress, InstOut);
    input [7:0] InstAddress;
    output [9:0] InstOut;
	 
	 // Instructions have [4bit opcode][6bit immediate or 3bit(useless) + 3bit rt]
	 
	 reg[9:0] InstOut;
	 always @ (InstAddress)
		begin
		case (InstAddress)
		
		// opcode = 0 tbd, rt = 7
		0 : InstOut = 10'b0000000111;  // load from address at reg 0 to reg 1  
		
		// opcode = 7 smr, immediate = 8
		1 : InstOut = 10'b0111001000; 
		
		// opcode = 8 rxor,  imm = XXXXXX
		2 : InstOut = 10'b1000111111;  // sw reg 1 to address in reg 0
		
		// opcode = 5 beq, imm = 24
      3 : InstOut = 10'b0101011000;  // beqz reg1 to absolute address 1
		
		// opcode = 6 wm, imm = 3
		4 : InstOut = 10'b0110000011; 
		
		// opcode = 2 sub, rt = 7
		5 : InstOut = 10'b0010000111;
		
		// opcode = 6 wm, imm = 2
		6 : InstOut = 10'b0110000010;
		
		// opcode = 1 halt, XXX
		7 : InstOut = 10'b0001000000;
		/**/
		
		/*
		// opcode = 7 smr, imm = 48
		0 : InstOut = 10'b0111110000;
		
		//opcode = tbd, rt = 6
		1 : InstOut = 10'b0000000110;
		
		// opcode = 3 wr, rt = 1
		2 : InstOut = 10'b0011000001;
		
		// opcode = 3 wr, rt = 2
		3 : InstOut = 10'b0011000010;
		
		// opcode = 3 wr, rt = 3
		4 : InstOut = 10'b0011000011;
		
		// opcode = search, XXX
		5 : InstOut = 10'b0100111111;
		
		// opcode = 10 bsq, imm = XXX(48)
		6 : InstOut = 10'b1010110000;
		
		// opcode = 9 srl, rt = XXX
		7 : InstOut = 10'b1001000111;
		
		// opcode = 6 wm, imm = 10
		8 : InstOut = 10'b0110001010;
		
		// opcode = 1 halt, imm = XXX
		9 : InstOut = 10'b0001000000;
		/**/
		//halt for default
		default : InstOut = 10'b0001000000;
    endcase
	 $display("Instruction: %b", InstOut);
  end

endmodule
