`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    13:24:09 10/27/2011 
// Design Name: 
// Module Name:    reg_file 
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
module reg_file(
	 input wire CLK,
	 input wire RegWrite,
    input wire [2:0] srcA,
    input wire [2:0] writeReg,
    input wire [15:0] writeValue,
	 
    output [15:0] ReadA,
    output [15:0] ReadB,
	 output [15:0] ReadC
    );
	 
reg [15:0] registers[15:0];

//I like this because I do have a zero register. I'm keeping it
assign ReadA = (srcA == 3'b000) ? 16'b0 : registers[srcA];
//These are only ever used for Search, so I can hard code them to be registers
//2 and 3.
//That way I can decide later whether or not to use them, and just always leave a value on them
//Register 2 will also be attached with a mux to the immediate.
assign ReadB = registers[2];
assign ReadC = registers[3];

always @ (posedge CLK)
begin
  if (RegWrite && (writeReg != 4'b0000))
  begin
    registers[writeReg] <= writeValue;
	 $display("Register write %d = %d",writeReg,writeValue);
  end
end

endmodule
