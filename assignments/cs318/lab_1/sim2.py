from sim import newsteam

# CURRENT INSTRUCTION COUNT = 354
# THIS COULD BE MUCH SMALLER, AND WILL DEFINITELY NEED TO BE MUCH SMALLER
def main():
    i = 0
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
    i += 1
    while(assembler.registers[6] < 192): 
        #NOTE: Tomorrow, check and see if you can combine
        #these instructions.
        # and just have an add 1 at the beginning of each
        #runthrough
        assembler.lqw(4)
        print(assembler.registers)
        assembler.search()
        print(assembler.registers)
        #NOTE: Maybe define a "Break" if registers[3] == 0 then pc = the last
        #command
        if(assembler.registers[3] == 0):
            break
        assembler.lqw(4)
        assembler.search()
        if(assembler.registers[3] == 0):
            break
    if(assembler.registers[6] == 193):
        assembler.registers[7] = -1
    assembler.wm(10)

    print (assembler.registers) 
    print (i)
    print (assembler.bistrings)


if __name__ =='__main__':
    main()
