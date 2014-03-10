from sim import newsteam

def main():
    i = 10
    assembler = newsteam()
    assembler.__init__()
    #search
   assembler.sdri(1)
   assembler.addi(0)
   while(assembler.registers[6] < 182): 
       assembler.llw(2)
       assembler.luw(3)
       assembler.xnor(2,3)


if __name__ =='__main__':
    main()
