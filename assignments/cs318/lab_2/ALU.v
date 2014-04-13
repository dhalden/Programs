`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:04:22 10/27/2011 
// Design Name: 
// Module Name:    ALU 
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
module ALU(
    input CLK,
    input [3:0] OP,
    input [15:0] INPUTA,
	 //INPUTB can either be a register, or an immediate
    input [15:0] INPUTB,
	 input [15:0] INPUTC,
	 input [15:0] MEMIN,
    output reg [15:0] OUT,
    output reg ZERO,
	 output wire EQUAL
    );
	 
    //    assign EQUAL = (INPUTA == INPUTB) ? 1 : 0;
	
	always @(INPUTA, INPUTB, INPUTC, MEMIN, OP)
	begin
	
	//where there are zeros, you need to make the zero output to the reg ZERO
	case(OP)
		0 : OUT = 0;
		1 : OUT = 1;
		2 : OUT =  64 - INPUTA;
		3 : OUT = INPUTA; //I just don't know what to put here yet. I will figure this out later
		4 : OUT = (((MEMIN ^ INPUTA) == 0) && ((INPUTC ^ INPUTB) == 0)) ? 0 : MEMIN; //Search: I think the logic for this is correct...
		5 : OUT = ((INPUTB + 1) == (INPUTA << 2)) ? 0 : (INPUTB + 1);
		6 : OUT = 1;
		7 : OUT = (INPUTA << 2);
		8 : OUT = ((((MEMIN[0:0]^MEMIN[1:1])^(MEMIN[2:2]^MEMIN[3:3]))^((MEMIN[4:4]^MEMIN[5:5])^(MEMIN[6:6]^MEMIN[7:7])))^
		          (((MEMIN[8:8]^MEMIN[9:9])^(MEMIN[10:10]^MEMIN[11:11]))^((MEMIN[12:12]^MEMIN[13:13])^(MEMIN[14:14]^MEMIN[15:15]))));
		9 : OUT = (INPUTA == 289) ? -1 : ((INPUTA >> 1) - 96);
		10: OUT = ((INPUTA + 1) == 289) ? 0 : (INPUTA + 1); 
		default: OUT = 0;
	endcase
	 
	case(OUT)
		16'b0 : ZERO = 1'b1;
		default : ZERO = 1'b0;
	endcase
	//$display("ALU Out %d \n",OUT);
	end

endmodule
