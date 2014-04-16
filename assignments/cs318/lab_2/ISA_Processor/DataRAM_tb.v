`timescale 1ns / 1ps

////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer:
//
// Create Date:   23:54:07 04/09/2014
// Design Name:   DataRAM
// Module Name:   /home/jebediah/My_Stuff/Programs/assignments/cs318/lab_2/ISA_Processor/DataRAM_tb.v
// Project Name:  ISA_Processor
// Target Device:  
// Tool versions:  
// Description: 
//
// Verilog Test Fixture created by ISE for module: DataRAM
//
// Dependencies:
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
////////////////////////////////////////////////////////////////////////////////

module DataRAM_tb;

	// Inputs
	reg [15:0] DataAddress;
	reg ReadMem;
	reg WriteMem;
	reg [15:0] DataIn;
	reg Search;
	reg CLK;

	// Outputs
	wire [15:0] DataOut;

	// Instantiate the Unit Under Test (UUT)
	DataRAM uut (
	   .Search(Search),
		.DataAddress(DataAddress), 
		.ReadMem(ReadMem), 
		.WriteMem(WriteMem), 
		.DataIn(DataIn), 
		.DataOut(DataOut), 
		.CLK(CLK)
	);

	initial begin
		// Initialize Inputs
		DataAddress = 0;
		ReadMem = 0;
		WriteMem = 0;
		DataIn = 0;
		Search = 0;
		CLK = 0;

		// Wait 100 ns for global reset to finish
		#100;
		DataAddress = 55;
		ReadMem = 1;
		Search = 0;
		#100;
		DataAddress = 110;
		ReadMem = 1;
		Search = 1;
		#100;
		DataAddress = 55;
		ReadMem = 1;
		Search = 0;
		#100;
		DataAddress = 111;
		ReadMem = 1;
		Search = 1;
		#100;
		DataAddress = 241;
		Search = 1;
		ReadMem = 1;
		#100;
		DataAddress = 116;
		Search = 1;
		ReadMem = 1;
		#100;
		DataAddress = 117;
		Search = 1;
		ReadMem = 1;
		#100;
		DataAddress = 240;
		Search = 1;
		ReadMem = 1;
		#100;
		DataAddress = 180;
		ReadMem = 1;
		Search = 1;
        
		// Add stimulus here

	end
	always begin
     #5  CLK = ~CLK; // Toggle clock every 5 ticks
   end
      
endmodule

