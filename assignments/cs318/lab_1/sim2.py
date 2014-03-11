from sim import newsteam

def main():
    i = 10
    assembler = newsteam()
    assembler.__init__()
    #search
    assembler.smr(6)
    assembler.llw(1)
    assembler.luw(2)
    assembler.smr(60)
    assembler.smr(26)
    #make a shift up one command that does everything I need
    assembler.lhw(3)
    while(assembler.registers[6] < 182): 
        assembler.luw(4)
        assembler.xnor(3, 1)
        if(assembler.registers[3] == 0)
            break
        assembler.lhw(4)
        assembler.xnor(3, 1)
        if(assembler.registers[3] == 0)
            break
        
       



if __name__ =='__main__':
    main()
