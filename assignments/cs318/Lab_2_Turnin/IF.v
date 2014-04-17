`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: Derek Halden
// 
// Create Date:    17:44:49 02/16/2012 
// Design Name: 
// Module Name:    IF 
// Project Name: 
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module IF(
    input [1:0] Branch,
    input Init,
    input Halt,
	 input CLK,
    output reg[7:0] PC
    );
	 
	 always @(posedge CLK)
	 begin
		if(Init==1)
			PC = 0;
		else if(Halt==1)
			PC = PC;
		//This is if a branch instruction is called
		else if(Branch==1)
			PC = PC - 1;
		//this is if a search instruction is called
		else if(Branch==2)
			PC = PC + 2;
		else
			PC = PC + 1;
	 end


endmodule
