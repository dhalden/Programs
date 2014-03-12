from random import randint

class ValError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class newsteam:
    registers = [0,0,0,0,0,0,0,0]
    __immreg = 0
    __pcounter = 0
    bistrings = {}  
    def __init__ (self):
        #current memory address to write to: self.registers[7]
        #current memory address to read from: self.registers[6] 
        #current register to write to 
        #the program counter
        #Make this a dictionary, and the reference values are all "addresses"
        badd = 0x0000
        bistring = 0 
        for i in range(192):
            if (i >= 30 and i < 64):
                #bistring = bin(randint(0, pow(2,8)) + 32768)
                bistring = bin(randint(0, pow(2,7)) + 127)
                temp = (bin(randint(0,pow(2,7))+ 127))
                bistring = bistring[2:]  + temp[2:]
                for j in range(16 - len(bistring)):
                    bistring = '0' + bistring
                badd += 0x2
            else:
                if (i == 9):
                    bistring = '1010011100010011'
                elif (i >= 65):
                    if (i == 90):
                        bistring = '1010011100010011'
                    else: 
                        bistring = bin(randint(0, pow(2,7)) + 127)
                        temp = (bin(randint(0,pow(2,7))+ 127))
                        bistring = bistring[2:]  + temp[2:]
                        for j in range(16 - len(bistring)):
                            bistring = '0' + bistring
                else: 
                    bistring = bin(randint(0, pow(2,7)) + 127)
                    temp = (bin(randint(0,pow(2,7))+ 127))
                    bistring = bistring[2:]  + temp[2:]
                    for j in range(16 - len(bistring)):
                        bistring = '0' + bistring
                badd += 0x2
            self.bistrings[hex(badd)] = ((bistring))
        #print self.bistrings
        # 4 self.registers means that I have 2-bit
        #000 this register will always be zero, for a couple of reasons
    
    #if specifying a register, 'a' should a number, and 'b' should be 0'
    #if specifying memory, 'a' should be 0, and 'b' should be a number
    def sdri(self,a):
        if((bin(a) > 0) and (bin(a) < 0b1000)):
            self.__immreg = bin(a)
        else:
            raise ValError('int provided is not in self.registers')

    #NOTE because of the change I made to how I'm dealing with wmemaddr, this 
    #might not be necessary.
    #this works because all of the memory addresses that I need to write to are
    #less than 64. The reads, on the other hand, should simply be contained in a
    #register
    def wm(self,a):
        self.bistrings[hex(a)] = self.registers[7]
    
    def smr(self,a):
        self.registers[6] = int(self.registers[6]) + a
        print(self.registers[6])

    # add the immediate, to the destination register specified 
    #in the first 3 bits 

    def addi(self,a):
        if(a < 64):
            if (self.__immreg == 0b000):
                self.registers[0b000] = 0
            else:
                self.registers[self.__immreg] = (
                            self.registers[self.__immreg] + a) % pow(2,16)

    #def add(self, a,b):
     #   if(a == 0b000):
      #      self.registers[0b000] = 0
       # else:
        #    self.registers[a] = (
                #self.registers[a] + self.registers[b]) % pow(2,16)
            #maybe have a carryout to memory? maybe if the addition = 1

    #is this okay?
    def search(self,a,b):
        #print(self.registers[b], self.registers[b+1])
        #print("register 4, the first time: " + str( self.registers[4]))
        self.registers[3] = str(int(self.registers[3]) ^ int(self.registers[1]))
        if(int(self.registers[3]) == self.registers[0]):
            self.registers[3] = str(int(self.registers[4]) ^
                                      int(self.registers[2]))
            if (int(self.registers[3] == self.registers[0])):
                self.registers[3] = 0
            else:
                #print("register 4: " + str( self.registers[4]))
                self.registers[3] = self.registers[4]
        else:
            #print("register 4: " + str( self.registers[4]))
            self.registers[3] = self.registers[4]


    def sub(self,b):
        self.bistrings['0x08'] = 32 - self.registers[b]

    #NOTE:If I can get rid of this, then there is no need for having 3-bit registers
    #Also, if I have 6-bit  registers, maybe there is no need for this?
    def beq(self,a,b):
        if(a == b):
            self.__pcounter += 10

    def jump(self,label):
        self.__pcounter == label

    #NOTE: I MIGHT NOT NEED THIS
    def sll(self,a):
        a << 1 
        cout = a / (pow(2,16))
        self.bistrings[self.registers[7]] += cout

    #load upper word
    #denotes add 1 for search function
    def luw(self,a):
        self.registers[a] = int(self.bistrings[hex(self.registers[6])])
        self.registers[6] += 2;

    #NOTE:THIS NEEDS TO BE IN A FORM SUCH THAT MEMORY IS
    # ONLY HALF-WORD ADDRESSABLE
    #load half word
    def lqw(self,a):
        if(self.registers[6] % 2 == 0):
            self.registers[a] = (self.bistrings[hex(self.registers[6])][:8])
            #print(str(a) + ' ' + self.bistrings[hex(self.registers[6])][:8])
        else:
            self.registers[a] = (
                         self.bistrings[hex(self.registers[6]-1)][8:])
            self.registers[7] += 1
        self.registers[6] += 1;
        #self.registers[7] += 1;

    def hal(self):
        return exit(0)
    
    #this is a recursive method to add all of the bits in
    #a 16 bit integer together.
    def rxor(self):
        s= str(self.registers[2])
        t= str(self.registers[3])
        u= str(self.registers[4])
        v= str(self.registers[5])
         #s = str(bin(rnum))[2:]
        self.registers[7] += ((self.rxorr(s[:8]) + self.rxorr(s[8:]))%2)
        self.registers[7] += ((self.rxorr(t[:8]) + self.rxorr(t[8:]))%2)
        self.registers[7] += ((self.rxorr(u[:8]) + self.rxorr(u[8:]))%2)
        self.registers[7] += ((self.rxorr(v[:8]) + self.rxorr(v[8:]))%2)
        print self.registers[2:6], self.registers[7],"\n"

    def rxorr(self, arr):
        #print(arr)
        if (len(arr) > 1):
            return ((self.rxorr(arr[:len(arr)/2]) 
                     + self.rxorr(arr[(len(arr)/2):]))%2)
        else:
            return int(arr)




def main():
    i = 10
    assembler = newsteam()
    assembler.__init__()
#evens or odds tenative (59)
    assembler.smr(32)
    #NOTE: Problem with getting 96 into register
    while (assembler.registers[6] < 96): 
        #NOTE: collapse smr & luw into one step
        assembler.luw(2)
        assembler.luw(3)
        assembler.luw(4)
        assembler.luw(5)
        assembler.rxor()
    assembler.sub(7)
    assembler.wm(12)

    print(assembler.registers)
    print(assembler.bistrings)



if __name__ =='__main__':
    main()
