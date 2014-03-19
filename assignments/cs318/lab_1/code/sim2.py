from sim import newsteam

# CURRENT INSTRUCTION COUNT = 354
# THIS COULD BE MUCH SMALLER, AND WILL DEFINITELY NEED TO BE MUCH SMALLER
def main():
    i = 0
    assembler = newsteam()
    assembler.__init__()
    #search
    assembler.lqw(1)
    assembler.lqw(2)
    assembler.smr(24)
    #make a shift up one command that does everything I need
    assembler.lqw(3)
    i += 1
    while(assembler.registers[6] < 192): 
        assembler.search()
        #NOTE: instead try adding 1, and then srl once before you write
        assembler.registers[6] += 1

    if(assembler.registers[6] == 193):
        assembler.registers[6] = -1
    assembler.wm(10)

    print (assembler.registers) 
    print (i)
    print (assembler.bistrings)


if __name__ =='__main__':
    main()
