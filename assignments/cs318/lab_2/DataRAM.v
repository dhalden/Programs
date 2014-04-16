`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Engineer:
//
// Create Date:    19:25:24 11/16/2006
// Design Name:
// Module Name:    DataRAM
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
module DataRAM(DataAddress, DataWrite, ReadMem, WriteMem, Search, DataIn, DataOut, CLK);
    input CLK;

    input [15:0] DataAddress;
	 input [15:0] DataWrite;
    input ReadMem;
    input WriteMem;
    input [15:0] DataIn;
	 input Search;

    output [15:0] DataOut;
    reg [15:0] DataOut;

    reg [15:0] my_memory [0:255];

    initial begin
        $readmemh("dataram_init.list", my_memory);
	 end
	 wire D = DataAddress[0:0];
	 reg [15:0] temp;
    always @ (/*ReadMem or*/ DataAddress or Search)
		  if (Search && ReadMem) begin
				temp = (DataAddress[15:0] >> 1);
		  //Double check and make sure this is okay...
				if(D) begin
					DataOut = {8'b0, my_memory[temp][7:0]};
				end else begin
					DataOut = {8'b0, my_memory[temp][15:8]};
				end
				$display("Memory read M[%d] = %d",temp,DataOut);
        end
		  else begin
			   if(ReadMem) begin
					DataOut = my_memory[DataAddress[15:0]];
					$display("Memory read M[%d] = %d",DataAddress,DataOut);
				end
				else begin
					DataOut = 16'bZ;
				end
        end

    always @ (CLK)
        if(WriteMem) begin
            my_memory[DataWrite] = DataIn;
				$display("Memory write M[%d] = %d",DataWrite,DataIn);
        end

endmodule
