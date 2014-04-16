`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:42:06 02/16/2012
// Design Name:   Control
// Module Name:   /department/home/leporter/Desktop/basic_processor/Control_tb.v
// Project Name:  basic_processor
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: Control
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module Control_tb;

	// Inputs
	reg [3:0] OPCODE;
	reg [2:0] WR_REG;

	// Outputs
	wire [3:0] ALU_OP;
	wire [1:0] ALU_SRC_B;
	wire REG_WRITE;
	wire BRANCH;
	wire MEM_WRITE;
	wire MEM_READ;
	wire REG_DST;
	wire MEM_TO_REG;
	wire HALT;
	wire [8:0] MEM_TO_READ_FROM;
	wire IMMEDIATE; 
	wire [2:0]WRITE_REG; //the register to write to
	wire WRFLAG;
	wire SEARCH;

	// Instantiate the Unit Under Test (UUT)
	Control uut (
		.OPCODE(OPCODE),
		.WR_REG(WR_REG),
		.ALU_OP(ALU_OP), 
		.ALU_SRC_B(ALU_SRC_B), 
		.REG_WRITE(REG_WRITE), 
		.BRANCH(BRANCH), 
		.MEM_WRITE(MEM_WRITE), 
		.MEM_READ(MEM_READ), 
		.REG_DST(REG_DST), 
		.MEM_TO_REG(MEM_TO_REG), 
		.HALT(HALT),
		.MEM_TO_READ_FROM(MEM_TO_READ_FROM),
		.IMMEDIATE(IMMEDIATE),
		.WRITE_REG(WRITE_REG),
		.WRFLAG(WRFLAG),
		.SEARCH(SEARCH)
		
	);

	initial begin
		// Initialize Inputs
		OPCODE = 0;
		WR_REG = 0;

		// Wait 100 ns for global reset to finish
		//#10;
		//OPCODE = 1;
		#10;
		OPCODE = 2;
		#10;
		OPCODE = 3;
		#10;
		OPCODE = 4;
		#10;
		OPCODE = 5;
		#10;
		OPCODE = 6;
		#10;
		OPCODE = 7;
		#10;
		OPCODE = 8;
		#10;
		OPCODE = 9;
		#10;
		OPCODE = 10;
		#10;
		OPCODE = 11;
		#10;
		OPCODE = 12;
		#10;
		OPCODE = 0;
		#10;
		OPCODE = 3;
		WR_REG = 3;
	   #10;
		WR_REG = 2;
		#10;
		WR_REG = 1;
        
		// Add stimulus here

	end
      
endmodule

