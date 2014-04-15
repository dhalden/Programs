`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   13:31:49 10/27/2011
// Design Name:   reg_file
// Module Name:   /department/home/leporter/Xilinx/lab_basics/reg_file_tb.v
// Project Name:  lab_basics
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: reg_file
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module reg_file_tb;

	// Inputs
	reg CLK;
	reg RegWrite;
	reg [2:0] srcA;
	reg [2:0] writeReg;
	reg [15:0] writeValue;

	// Outputs
	wire [15:0] ReadA;
	wire [15:0] ReadB;
	wire [15:0] ReadC;
	wire [15:0] ReadMem;

	// Instantiate the Unit Under Test (UUT)
	reg_file uut (
		.CLK(CLK), 
		.RegWrite(RegWrite), 
		.srcA(srcA), 		
		.writeReg(writeReg), 
		.writeValue(writeValue), 
		.ReadA(ReadA),
      .ReadB(ReadB),		
		.ReadC(ReadC),
		.ReadMem(ReadMem)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RegWrite = 1;
		srcA = 0;
		writeReg = 7;
		writeValue = 0;

		#10
		RegWrite = 1;
		writeReg = 2;
		writeValue = 16'h00A7;
		
		#10
		RegWrite = 1;
		writeReg = 6;
		writeValue = 16'h0013;
		
		// Wait 100 ns for global reset to finish
		#10;
		
		// Add stimulus here
		// check if writing works
		srcA = 3'b001;
		writeReg = 3'b011;
		writeValue = 16'hABCD;
		RegWrite = 1;
		
		#10;
		// verify writing to reg 0 does not work
		srcA = 3'b001;
		writeReg = 3'b000;
		writeValue = 16'h2030;
		
		#10;
		//verify writing without RegWrite has no impact
		RegWrite = 0;
		writeReg = 3'b010;
		writeValue = 16'hABCD;
		srcA = 3'b010;

      #10;     
		writeReg = 3'b100;
		writeValue = 16'hA1CD;
		RegWrite = 1;
		
		#10;
		srcA = 3'b101;
		RegWrite = 0;
		
		
		
		
		
	end
always
#5 CLK = ~CLK;
      
endmodule

