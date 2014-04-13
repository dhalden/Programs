`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   18:12:37 10/27/2011
// Design Name:   ALU
// Module Name:   /department/home/leporter/Xilinx/lab_basics/ALU_tb.v
// Project Name:  lab_basics
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: ALU
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module ALU_tb;

	// Inputs
	reg CLK;
	reg [3:0] OP;
	reg [15:0] INPUTA;
	reg [15:0] INPUTB;
	reg [15:0] INPUTC;
	reg [15:0] MEMIN;

	// Outputs
	wire [15:0] OUT;
	wire ZERO;
	wire EQUAL;

	// Instantiate the Unit Under Test (UUT)
	ALU uut (
		.CLK(CLK), 
		.OP(OP), 
		.INPUTA(INPUTA), 
		.INPUTB(INPUTB), 
		.OUT(OUT), 
		.ZERO(ZERO), 
		.EQUAL(EQUAL),
		.INPUTC(INPUTC),
		.MEMIN(MEMIN)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		OP = 0;
		INPUTA = 0;
		INPUTB = 0;
		INPUTC = 0;
		MEMIN = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		INPUTA = 16'h0004;
		INPUTB = 16'h0004;
		INPUTC = 16'h0004;
		MEMIN  = 16'h0004;
		
		#15;
		//halt
		OP = 1;
		#15
		//sub
		OP = 2;
		#15
		//wr
		OP = 3;
		#15
		//search
		OP = 4;
		#15
		//search
		OP = 4;
		INPUTB = 16'h0003;
		
		#15
		//beq
		OP = 5;
		#15
		//wm
		OP = 6;
		#15;
		//smr
		OP = 7;
		#15
		//rxor
		OP = 8;
		#15
		//rxor
		OP = 8;
		MEMIN  = 16'h0003;
		#15
		//srl
		OP = 9;
		#15
		//bsq
		OP = 10;
		#15
		OP = 11;
		#15
		OP = 12;
		

	end

always
#10 CLK = ~CLK;


endmodule

