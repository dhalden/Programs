`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:08:46 02/16/2012 
// Design Name: 
// Module Name:    Control 
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
module Control(
    input [3:0] OPCODE,
	 input [2:0] WR_REG,
    output reg [3:0]ALU_OP,
    output reg [1:0]ALU_SRC_B,
    output reg REG_WRITE,
    output reg [1:0]BRANCH,
    output reg MEM_WRITE,
    output reg MEM_READ,
    output reg REG_DST,
    output reg MEM_TO_REG,
	 output reg HALT,
	 output reg [8:0] MEM_TO_READ_FROM,
	 output reg IMMEDIATE, 
	 output reg [2:0]WRITE_REG, //the register to write to
	 output reg WRFLAG,
	 output reg SEARCH
    );
	always @(OPCODE or WR_REG)
	begin
		
		case(OPCODE)
			//tbd
			0 : 
			begin
				 REG_DST = 0;
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0 don't care
				 ALU_OP = 0; 	 	// 0 add, 1 sub don't care
				 MEM_TO_REG = 0;	// use mem read
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 0;
				 WRFLAG = 0;
				 SEARCH = 0;
			end
			//halt
			1 : 
			begin
				 //Maybe use REG_DST to decide what to choose for
				 //the register destination?
				 REG_DST = 1;
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 1 is SE 3 bit immediate
				 ALU_OP = 0; 	 	// 0 add, 1 sub 
				 MEM_TO_REG = 0;	// use alu result
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 1;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 //Since this varies sometimes, you will need to use a
				 //mux to decide between this and the instruction itself
				 WRITE_REG = 0;
				 WRFLAG = 0;
				 SEARCH = 0;

			end
			//subtract
			2 : 
			begin
				REG_DST = 1;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 2; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 0;
				 WRFLAG = 0;
				 SEARCH = 0;
			end
			//write register
			3 : 
			begin
				 REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 2; 	// 2 is zero
				 ALU_OP = 3; 	 	// 0 add, 1 sub
				 MEM_TO_REG = 1;	// use alu, don't care
				 MEM_READ = 1;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 case(WR_REG)
					1:
					begin
						MEM_TO_READ_FROM = 9;
						WRFLAG = 0;
						WRITE_REG = 1;
					end
					2:
					begin
						MEM_TO_READ_FROM = 9;
						WRFLAG = 1;
						WRITE_REG = 2;
					end
					3:
					begin
						MEM_TO_READ_FROM = 7'b1100000;
						WRFLAG = 1;
						WRITE_REG = 3;
					end
					default:
					begin
						MEM_TO_READ_FROM = 0;
						WRFLAG = 0;
						WRITE_REG = 0;
					end
				endcase
				 IMMEDIATE = 0;
				 SEARCH = 0;

			end
			//search
			4 : 
			begin
				REG_DST = 1;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 4; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 1;	// use alu, don't care
				 MEM_READ = 1;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 3;
				 WRFLAG = 1;
				 SEARCH = 1;
			end
			//beq
			5 : 
			begin
				 REG_DST = 0;		// don't care
				 BRANCH = 1;
				 ALU_SRC_B = 2; 	// 2 is 0, don't care
				 ALU_OP = 5; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 1;
				 WRITE_REG = 6;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			//Write Memory
			6 : 
			begin
			    REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 6; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 1;
				 REG_WRITE = 0;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 0;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			//set memory read
			7 : 
			begin
             REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 7; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 7;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			//ripple xor
			8 : 
			begin
             REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 8; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 1;	// use alu, don't care
				 MEM_READ = 1;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 7;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			//Srl (kind of)
			9 : 
			begin
             REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 9; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 7;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			//Branch searchqual 
			10 : 
			begin
             REG_DST = 0;		// don't care
				 BRANCH = 1;
				 ALU_SRC_B = 0; 	// 2 is 0, don't care
				 ALU_OP = 10; 	 	// 0 add, 1 sub, don't care
				 MEM_TO_REG = 0;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 1;
				 HALT = 0;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 1;
				 WRITE_REG = 6;
				 WRFLAG = 1;
				 SEARCH = 0;
			end
			15 : 
			begin
				 REG_DST = 0;		// don't care
				 BRANCH = 0;
				 ALU_SRC_B = 0; 	// 2 is zero
				 ALU_OP = 0; 	 	// 0 add, 1 sub
				 MEM_TO_REG = 1;	// use alu, don't care
				 MEM_READ = 0;
				 MEM_WRITE = 0;
				 REG_WRITE = 0;
				 HALT = 1;
				 MEM_TO_READ_FROM = 0;
				 IMMEDIATE = 0;
				 WRITE_REG = 0;
				 SEARCH = 0;
			end
			default: HALT = 1;
		endcase
	end

endmodule
