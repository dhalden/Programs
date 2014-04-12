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
	reg [2:0] srcB;
	reg [2:0] srcC;
	reg [2:0] writeReg;
	reg [15:0] writeValue;

	// Outputs
	wire [15:0] ReadA;
	wire [15:0] ReadB;
	wire [15:0] ReadC;

	// Instantiate the Unit Under Test (UUT)
	reg_file uut (
		.CLK(CLK), 
		.RegWrite(RegWrite), 
		.srcA(srcA), 
		.srcB(srcB),
		.srcC(srcC),		
		.writeReg(writeReg), 
		.writeValue(writeValue), 
		.ReadA(ReadA),
      .ReadB(ReadB),		
		.ReadC(ReadC)
	);

	initial begin
		// Initialize Inputs
		CLK = 0;
		RegWrite = 0;
		srcA = 0;
		srcB = 0;
		writeReg = 0;
		writeValue = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		// check if writing works
		srcA = 3'b001;
		writeReg = 3'b001;
		writeValue = 16'hABCD;
		RegWrite = 1;
		
		#20;
		// verify writing to reg 0 does not work
		srcA = 3'b001;
		writeReg = 3'b000;
		writeValue = 16'h2030;
		
		#20;
		//verify writing without RegWrite has no impact
		RegWrite = 0;
		writeReg = 3'b010;
		writeValue = 16'hABCD;
		srcA = 3'b010;

      #20;     
		writeReg = 3'b100;
		writeValue = 16'hA1CD;
		RegWrite = 1;
		
		#20;
		srcC = 3'b100;
		RegWrite = 0;
		
		
		
	end
always
#10 CLK = ~CLK;
      
endmodule

