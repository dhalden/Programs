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
	 input [2:0] SRC,
    input [15:0] INPUTA,
	 //Note: the immediate is piped through inputb
    input [15:0] INPUTB,
	 input [15:0] INPUTC,
	 input [15:0] MEMIN,
    output reg [15:0] OUT,
    output reg ZERO,
	 output reg [1:0] BRANCH,
	 output wire EQUAL
    );
	 
    //    assign EQUAL = (INPUTA == INPUTB) ? 1 : 0;
	reg temp;
	always @(INPUTA, INPUTB, INPUTC, MEMIN, OP, SRC)
	begin
	
	//where there are zeros, you need to make the zero output to the reg ZERO
	case(OP)
		0 : OUT = (SRC == 6) ? 193 : 0;
		1 : OUT = 1;
		2 : OUT =  64 - INPUTA;
		3 : OUT = MEMIN; //I just don't know what to put here yet. I will figure this out later
		4 :
		begin
		$display("InputA %b, InputB %b, InputC %b, Memin %b",INPUTA,INPUTB,INPUTC,MEMIN);
		if(((MEMIN ^ INPUTA) == 0) && ((INPUTC ^ INPUTB) == 0)) begin
			OUT = 0;
		   assign temp = 0;
		end else begin
			OUT = MEMIN;
			assign temp = 1;
		end
		//OUT = (((MEMIN ^ INPUTA) == 0) && ((INPUTC ^ INPUTB) == 0)) ? 16'hffff : MEMIN; //Search: I think the logic for this is correct...
		BRANCH = (temp != 0) ? 2'b00 : 2'b10;
		$display("OUT %b, Branch %b",OUT, BRANCH);
		end
		5 :
		begin
		OUT = ((INPUTB << 2) == (INPUTA + 1)) ? 0 : (INPUTA + 1);
		BRANCH = (OUT == 0) ? 2'b0 : 2'b01;
		end
		6 : OUT = 1;
		7 : OUT = (INPUTB << 2);
		8 : OUT = INPUTA + ((((MEMIN[0:0]^MEMIN[1:1])^(MEMIN[2:2]^MEMIN[3:3]))^((MEMIN[4:4]^MEMIN[5:5])^(MEMIN[6:6]^MEMIN[7:7])))^
		          (((MEMIN[8:8]^MEMIN[9:9])^(MEMIN[10:10]^MEMIN[11:11]))^((MEMIN[12:12]^MEMIN[13:13])^(MEMIN[14:14]^MEMIN[15:15]))));
		9 : OUT = (INPUTA == 16'hffff) ? 16'hffff : ((INPUTA >> 1) - 96);
		10:
		begin
		OUT = ((INPUTA + 1) == 289) ? 16'hffff : (INPUTA + 1);
		BRANCH = (OUT == 16'hffff) ? 2'b0 : 2'b01;
		end
		default: OUT = 0;
	endcase
	 
	case(OUT)
		16'b0 :
		begin
		ZERO = 1'b1;
		BRANCH = (OP == 4 || OP == 5 || OP == 10 ) ? BRANCH : 2'b00;
		end
		default :
		begin
		BRANCH = (OP == 4 || OP == 5 || OP == 10 ) ? BRANCH : 2'b00;
		ZERO = 1'b0;
		end
	endcase
	//$display("INPUTA: %d", INPUTA);
	//$display("ALU Out %d, OP in %d \n",OUT,OP);
	end

endmodule
