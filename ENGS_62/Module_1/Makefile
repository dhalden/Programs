# filename: Makefile
# Author: Matthew A. West '17
# Date Created: 2017-01-05
# Purpose: Ease the use of command-line tools in ENGS 62
######################
# Directory locations
#
# You may need to modify each path to point to the correct
# directory on your machine.
######################
TOOLDIR=	/usr/local/gcc-arm-none-eabi-*/bin
QEMUDIR=	/Applications/GNU\ ARM\ Eclipse/QEMU/2.8.*/bin
OPENOCDDIR=	/Applications/GNU\ ARM\ Eclipse/OpenOCD/0.10.*/bin
#######################
# Shortcuts for tools
#######################

# Assembler - this translates assembly code (.S) into a binary object file (.o)
AS=	${TOOLDIR}/arm-none-eabi-as

# Compiler - this translates C code (.c) to a binary object file (.o)
CC=	${TOOLDIR}/arm-none-eabi-gcc

# Linker - This takes one or more binary object files (.o) and outputs a binary
#          blob with which to program the board (.elf)
LD=	${TOOLDIR}/arm-none-eabi-ld

# GNU Debugger - This is used for debugging, both in the simulator and on the
#                board. You'll use it to load your binary blob onto the board.
GDB=	${TOOLDIR}/arm-none-eabi-gdb

# Object Dumper - This dumps the symbols and code from the binary blob
#                 (disassembly)
OBJDUMP=	${TOOLDIR}/arm-none-eabi-objdump

# QEMU - This is a simulator which knows how to simulate our board. It can be
#        run in ordinary mode, which simply executes the program, or debug mode,
#        which listens for gdb connections.
QEMU=	${QEMUDIR}/qemu-system-gnuarmeclipse

# OpenOCD - This utility communicates with the physical hardware on the board. It
#           is used for flashing the program onto the board, and for debugging.
OPENOCD=	${OPENOCDDIR}/openocd

all: main.elf

# Modify the name of the file you're compiling, as necessary
main.elf : init.o
	${LD} -Ttext=0x08000000 -entry RESET_HANDLER -o main.elf init.o

init.o : init.S
	${AS} -c -mcpu=cortex-m4 -mimplicit-it=thumb -g2 -o init.o init.S

clean :
	rm -f *.o *.elf *~

# make qemu will start the simulator with main.elf
qemu :
	${QEMU} -board STM32F4-Discovery --image main.elf

# make qemu-gdb will start the simulator, while making it listen for debug
# connections
qemu-gdb :
	${QEMU} -board STM32F4-Discovery -s -S --image main.elf

# make gdb-qemu will start gnu debugger and connect it to QEMU (the simulator)
gdb-qemu : 
	${GDB} -se main.elf -ex 'target remote localhost:1234'

# See a dump of the image file
dump :
	${OBJDUMP} -d main.elf

# make openocd connects to the board
#
# If the text on the board's upper right says MB997D, uncomment the first line
# If the text on the board's upper right says MB997B, uncomment the second line

openocd :
#	${OPENOCD} -f board/stm32f429disc1.cfg
#	${OPENOCD} -f board/stm32f4discovery.cfg


# make gdb-openocd will connect to the board (openocd must also be open)
#
# To program the board, use the command 'load main.elf' in gdb once it
# has opened
gdb-openocd :
	${GDB} -se main.elf -ex 'target remote localhost:3333' -ex 'monitor reset halt' -ex 'load main.elf' -ex 'monitor reset halt'
