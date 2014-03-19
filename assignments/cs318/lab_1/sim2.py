from sim import newsteam

# CURRENT INSTRUCTION COUNT = 354
# THIS COULD BE MUCH SMALLER, AND WILL DEFINITELY NEED TO BE MUCH SMALLER
def main():
    i = 0
    assembler = newsteam()
    assembler.__init__()
    #search
    assembler.wr(1)
    assembler.wr(2)
    assembler.wr(3)
    assembler.smr(24)
    #make a shift up one command that does everything I need
    i += 1
    while(assembler.registers[6] < 192): 
        assembler.search()
        assembler.registers[6] += 1

    if(assembler.registers[6] == 193):
        assembler.registers[7] = -1
    assembler.wm(10)

    print (assembler.registers) 
    print (i)
    print (assembler.bistrings)


if __name__ =='__main__':
    main()
