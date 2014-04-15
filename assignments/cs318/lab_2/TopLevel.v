`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    18:37:58 02/16/2012 
// Design Name: 
// Module Name:    TopLevel 
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
module TopLevel(
    input start,
	 input CLK,
    output halt,
	 output wire [2:0] write_register,
    output [15:0] regWriteValue,
    output REG_WRITE,
    output [15:0] memWriteValue,
    output MEM_WRITE,
    output [7:0] PC,
	 output [1:0] Branch,
    output reg [15:0] InstCounter,
	 output wire [9:0] Instruction,
	 output wire SEARCH,
	 output wire [15:0] MemOut
    );

	// control signals not defined as outputs
	 wire MEM_READ,REG_DST,MEM_TO_REG,HALT;
	 wire [3:0] ALU_OP;
	 wire [1:0] ALU_SRC_B;
	 // ALU outputs
	 wire ZERO, EQUAL;
	 wire [15:0] ALUOut;
	 
	 
	 // Data mem wires
	 //wire [15:0] MemOut;
	 wire [15:0] memReadValue;
	 
	 // IF module inputs
	 //wire [15:0] Target;
	 
	 // Register File
	 
	 wire [15:0] ReadA;
	 wire [15:0] ReadB;
	 wire [15:0] ReadC; //added
	 wire [15:0] DataCounter;
	 wire [15:0] DataRead;
	 wire [15:0] DataAddress;
	 wire [2:0] SrcA;
	 wire [2:0] regSrcAddress;
	 	 
	 // ALU wires
	 wire [15:0] SE_Immediate;
	 wire [15:0] IntermediateMux;
	 wire [15:0] ALUInputB;
	 wire [15:0] ReadB_Immediate;
	 
	 
	//Things I added 
	wire [8:0] MEM_TO_READ_FROM;
	wire IMMEDIATE; 
	wire [2:0]WRITE_REG; //the register to write to
	wire WRFLAG;
	//wire SEARCH;

	 //assign regWriteValue = (MEM_TO_REG==1)?ALUOut:MemOut;
	 assign regWriteValue = ALUOut;
	 
	 // manage ALU SRC MUX
	 assign SE_Immediate = {{13{Instruction[2]}}, Instruction[2:0]};
	 assign IntermediateMux = (ALU_SRC_B==2'b01)?SE_Immediate:ReadB;
	 
	 // manage the write register and write data muxesassign ALUInputB = (In==2'b10)?0  : IntermediateMux;
	 assign write_register = (WRFLAG) ? WRITE_REG : Instruction[2:0];
	 // assign input to memory
	 assign memWriteValue = ReadA;
	 assign memReadValue = ReadA;
	 assign ReadB_Immediate = (IMMEDIATE) ? {10'b0, Instruction[5:0]}: ReadB;
	 assign regSrcAddress = (SrcA != 0) ? SrcA : Instruction[2:0];
	 assign DataAddress = (MEM_WRITE) ? {10'b0, Instruction[5:0]} : DataCounter;
	 assign DataRead =(REG_DST) ? MEM_TO_READ_FROM : DataCounter;
	 

	 
	 // Fetch Module (really just PC, we could have incorporated InstRom here as well)
	 IF if_module (
	 //Note: The logic on this isn't quite right yet. I'm not sure about how
	 //This Branch instruction will work out...
		.Branch(Branch),
		.Init(start),
		.Halt(halt),
		.CLK(CLK),
		.PC(PC)
	);

	// instruction ROM
	InstROM inst_module(
	.InstAddress(PC), 
	.InstOut(Instruction)
	);

	// Control module
	Control control_module (
		.OPCODE(Instruction[9:6]), 
		.ALU_OP(ALU_OP), 
		.ALU_SRC_B(ALU_SRC_B), 
		.REG_WRITE(REG_WRITE), 
		.MEM_WRITE(MEM_WRITE), 
		.MEM_READ(MEM_READ), 
		.REG_DST(REG_DST), 
		.MEM_TO_REG(MEM_TO_REG), 
		.HALT(halt),
		.MEM_TO_READ_FROM(MEM_TO_READ_FROM),
		.IMMEDIATE(IMMEDIATE),
		.WRITE_REG(WRITE_REG),
		.WRFLAG(WRFLAG),
		.SEARCH(SEARCH),
		.SRCA(SrcA)
	);
	/*always@(ALUOut)
	begin
	$display("REG_WRITE: %d",REG_WRITE);
	$display("write_register: %d",write_register);
	$display("ALUOut: %d",ALUOut);
	$display("DataCounter: %d\n",DataCounter);
	end */

	reg_file register_module (
		.Start(Start),
		.CLK(InstCounter), 
		.RegWrite(REG_WRITE), 
		.srcA(regSrcAddress),
		.writeReg(write_register), 	  // mux above
		.writeValue(ALUOut), 
		.ReadA(ReadA), 
		.ReadB(ReadB),
		.ReadC(ReadC),
		.ReadMem(DataCounter)
	);
	
	 always@(negedge CLK)
    begin
		$display("writeReg : %d", REG_WRITE);
	   $display("Instruction : %b", Instruction);
		$display("ReadA : %d", ReadA);
		$display("regSrcAddress : %d", regSrcAddress);
		$display("write_register: %d", write_register);
		$display("ALUOut : %d\n", ALUOut);
		$display("DataCounter: %d",DataCounter);
		$display("MEM_READ %d",MEM_READ);
		// $display("MEM_WRITE %d",MEM_WRITE);
		$display("MemOut %d",MemOut);
		$display("SEARCH %d\n",SEARCH);
	   // $display("DataCounter : %d", DataCounter); 
    end
	 DataRAM Data_Module(
		.DataAddress(DataRead),
		.DataWrite(DataAddress),
		.ReadMem(MEM_READ), 
		.WriteMem(MEM_WRITE), 
		.DataIn(memWriteValue), 
		.DataOut(MemOut), 
		.CLK(CLK),
		.Search(SEARCH)
	);
	
		ALU ALU_Module (
		.CLK(CLK), 
		.OP(ALU_OP),
		.SRC(regSrcAddress),
		.INPUTA(ReadA),
	   //INPUTB can either be a register, or an immediate		
		.INPUTB(ReadB_Immediate),
		.INPUTC(ReadC),
		.MEMIN(MemOut),
		.OUT(ALUOut), 
		.BRANCH(Branch),
		.ZERO(ZERO), 
		.EQUAL(EQ)
	);


	
	// might help debug
	
	
	always@(posedge CLK)
	if (start == 1)
		InstCounter = 0;
	else if(halt == 0)
		InstCounter = InstCounter+1;

endmodule
