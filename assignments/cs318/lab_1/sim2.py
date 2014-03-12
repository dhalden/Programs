from sim import newsteam

def main():
    i = 10
    assembler = newsteam()
    assembler.__init__()
    #search
    assembler.smr(20)
    assembler.lqw(1)
    assembler.lqw(2)
    assembler.smr(60)
    assembler.smr(14)
    #make a shift up one command that does everything I need
    assembler.lqw(3)
    while(assembler.registers[6] < 192): 
        #NOTE: Tomorrow, check and see if you can combine
        #these instructions.
        # and just have an add 1 at the beginning of each
        #runthrough
        assembler.lqw(4)
        print(assembler.registers)
        assembler.search(3, 1)
        print(assembler.registers)
        if(assembler.registers[3] == 0):
            break
        assembler.lqw(4)
        assembler.search(3, 1)
        if(assembler.registers[3] == 0):
            break
    if(assembler.registers[6] == 49)
        assembler.registers[7] = -1
    assembler.wm()

    print (assembler.registers) 
    print (assembler.bistrings)


if __name__ =='__main__':
    main()
