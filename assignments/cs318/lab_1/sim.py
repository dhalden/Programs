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
        badd = 0x0020
        for i in range(pow(2,8)):
            bistring = bin(randint(0, pow(2,8)) + 32768)
            bistring = bistring[2:]
            for j in range(8 - len(bistring)):
                bistring = '0' + bistring
            #print bistring
            self.bistrings[hex(badd)] = (str(bistring))
            badd += 0x2
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
        self.bistrings['0x0c'] = self.registers[1]
    
    def smr(self,a):
        self.registers[6] = int(self.registers[6]) + a

    # add the immediate, to the destination register specified in the first 3 bits 
    def addi(self,a):
        if(a < 64):
            if (self.__immreg == 0b000):
                self.registers[0b000] = 0
            else:
                self.registers[self.__immreg] = (self.registers[self.__immreg] + a) % pow(2,16)

    def add(self, a,b):
        if(a == 0b000):
            self.registers[0b000] = 0
        else:
            self.registers[a] = (self.registers[a] + self.registers[b]) % pow(2,16)
            #maybe have a carryout to memory? maybe if the addition = 1

#NOTE Do I still need this?
    def bxnor(self,a,b):
        if(a == 0b000):
            self.registers[0b000] = 0
        else:
            self.registers[a] = self.registers[a] ^ self.registers[b]

    def sub(self,b):
        print("band: "+ str(self.registers[b]))
        self.bistrings['0x08'] = 32 - self.registers[b]

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
    def luw(self,a):
        self.registers[a] = int(self.bistrings[hex(self.registers[6]+2)],10)

    #load lower word
    def llw(self,a):
        #print(int( '0b' + self.bistrings[hex(self.registers[6])][16:]))
        self.registers[a] = int(self.bistrings[hex(self.registers[6])])

    def hal(self):
        return exit(0)
    
    #this is a recursive method to add all of the bits in a 16 bit integer together.
    def rxor(self):
        s= str(self.registers[2])
        t= str(self.registers[3])
        u= str(self.registers[4])
        v= str(self.registers[5])
         #s = str(bin(rnum))[2:]
        self.registers[1] += ((self.rxorr(s[:8]) + self.rxorr(s[8:]))%2)
        self.registers[1] += ((self.rxorr(t[:8]) + self.rxorr(t[8:]))%2)
        self.registers[1] += ((self.rxorr(u[:8]) + self.rxorr(u[8:]))%2)
        self.registers[1] += ((self.rxorr(v[:8]) + self.rxorr(v[8:]))%2)
        print self.registers[2:6], self.registers[1],"\n"

    def rxorr(self, arr):
        #print(arr)
        if (len(arr) > 1):
            return ((self.rxorr(arr[:len(arr)/2]) + self.rxorr(arr[(len(arr)/2):]))%2)
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
        assembler.llw(2)
        assembler.luw(3)
        assembler.smr(4)
        assembler.llw(4)
        assembler.luw(5)
        assembler.rxor()
        assembler.smr(4)
    assembler.sub(1)
    assembler.wm(1)

    print(assembler.registers)
    print(assembler.bistrings)



if __name__ =='__main__':
    main()
