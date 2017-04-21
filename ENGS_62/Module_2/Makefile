# filename: Makefile
# Author: Matthew A. West '17
# Date Created: 2017-01-05
#
# Purpose: Ease the use of command-line tools in ENGS 62
# 
# Modifications:
# 2017-01-12 - Matt West '17 - brought in changes from Stephen Taylor


# USAGE: make | make <file>.elf | make <tool> [ IMG=<file>.elf ] | make clean

###### SET THIS ######
# Select a board:
# If the text on the board's upper right says MB997D, uncomment the first line
# If the text on the board's upper right says MB997B or MB997C uncomment the second line
#BOARDTYPE=board/stm32f429disc1.cfg
BOARDTYPE=board/stm32f4discovery.cfg
######################

###### SET THIS ######
# Directory locations
# You may need to modify each path to point to the correct
# directory on your machine.
######################
TOOLDIR=/usr/local/gcc-arm-none-eabi-*/bin
QEMUDIR=/Applications/GNU\ ARM\ Eclipse/QEMU/2.8.*/bin
OPENOCDDIR=/Applications/GNU\ ARM\ Eclipse/OpenOCD/0.10.*/bin

###### SET THIS ######
# List all the programs you want to build
all: init.elf first.elf fact.elf
######################

###### SET THIS ######
# Default Program to run (unless specified on command line i.e. IMG=<file>.elf
IMG=fact.elf
######################


#######################
# Shortcuts for tools
#######################

# Assembler - this translates assembly code (.S) into a binary object file (.o)
AS=${TOOLDIR}/arm-none-eabi-as

# Compiler - this translates C code (.c) to a binary object file (.o)
CC=${TOOLDIR}/arm-none-eabi-gcc

# Linker - This takes one or more binary object files (.o) and outputs a binary
#          blob with which to program the board (.elf)
LD=${TOOLDIR}/arm-none-eabi-ld

# GNU Debugger - This is used for debugging, both in the simulator and on the
#                board. You'll use it to load your binary blob onto the board.
GDB=${TOOLDIR}/arm-none-eabi-gdb

# Object Dumper - This dumps the symbols and code from the binary blob
#                 (disassembly)
OBJDUMP=${TOOLDIR}/arm-none-eabi-objdump

# QEMU - This is a simulator which knows how to simulate our board. It can be
#        run in ordinary mode, which simply executes the program, or debug mode,
#        which listens for gdb connections.
QEMU=${QEMUDIR}/qemu-system-gnuarmeclipse

# OpenOCD - This utility communicates with the physical hardware on the board. It
#           is used for flashing the program onto the board, and for debugging.
OPENOCD=${OPENOCDDIR}/openocd


#######################
# Building image files
#######################

# Here is how we generate a .elf from a .o file
%.elf : %.o
	${LD} -Ttext=0x08000000 -entry RESET_HANDLER $< -o $@ 

# Here is how we generate a .o from a .S file
%.o : %.S
	${AS} -c -mcpu=cortex-m4 -mimplicit-it=thumb -g2 $< -o $@ 

# Here is what we delete to clean the current directory
clean :
	rm -f *.o *.elf *~


#######################
# Tool Targets -- use the default image unless designated on command line (i.e. IMG=<file>.elf)
#######################

# make qemu will start the simulator with main.elf
qemu :
	${QEMU} -board STM32F4-Discovery --image ${IMG}

# make qemu-gdb will start the simulator, while making it listen for debug
# connections
qemu-gdb :
	${QEMU} -board STM32F4-Discovery -s -S --image ${IMG} &

# make gdb-qemu will start gnu debugger and connect it to QEMU (the simulator)
gdb-qemu : 
	${GDB} -se ${IMG} -ex 'target remote localhost:1234'

# See a dump of the image file
dump :
	${OBJDUMP} -d ${IMG}

# make openocd connects to the board
openocd :
	${OPENOCD} -f ${BOARDTYPE}

# make gdb-openocd will connect to the board (openocd must also be open)
# To program the board, use the command 'load <file>.elf' in gdb once it has opened
gdb-openocd :
	${GDB} -se ${IMG} -ex 'target remote localhost:3333' -ex 'monitor reset halt' -ex 'load ${IMG}' -ex 'monitor reset halt'
 
