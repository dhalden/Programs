`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   17:47:30 02/16/2012
// Design Name:   IF
// Module Name:   /department/home/leporter/Desktop/basic_processor/IF_tb.v
// Project Name:  basic_processor
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: IF
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module IF_tb;

	// Inputs
	reg [1:0] Branch;
	reg Init;
	reg Halt;
	reg CLK;

	// Outputs
	wire [7:0] PC;

	// Instantiate the Unit Under Test (UUT)
	IF uut (
		.Branch(Branch), 
		//Note: I do not care about this anymore, I will get rid of it at some point
		.Init(Init), 
		.Halt(Halt), 
		.CLK(CLK), 
		.PC(PC)
	);

	initial begin
		// Initialize Inputs
		Branch = 0;
		Init = 0;
		Halt = 0;
		CLK = 0;

		// Wait 100 ns for global reset to finish
		#100;
        
		// Add stimulus here
		Init = 1;
		#20;
		Init = 0;
		#10;
		Branch = 0;
		#10;
		Branch = 1;
		#20;
		Branch = 2;
		
		#20;
		Halt = 1;
		
	end
      
  always begin
     #5  CLK = ~CLK; // Toggle clock every 5 ticks
  end
		
endmodule

