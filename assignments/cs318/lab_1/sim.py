from random import randint

class ValError(Exception):
    def __init__(self, value):
        self.value = value
    def __str__(self):
        return repr(self.value)

class newsteam:
    registers = [0,8,72,861,59,245,73,89]
    __immreg = 0
    pcounter = 0
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
                bistring = self.randomword()
                badd += 0x1
            else:
                if (i == 8):
                    bistring = '1010011100010011'
                elif (i >= 65):
                    if (i == 137):
                        bistring = '1010011100010011'
                    else: 
                        bistring = self.randomword() 
                else: 
                    bistring = self.randomword()
                badd += 0x1
            self.bistrings[hex(badd)] = ((bistring))
        #print self.bistrings
        # 4 self.registers means that I have 2-bit
        #000 this register will always be zero, for a couple of reasons
    def randomword(self):
        bistring = bin(randint(0, pow(2,7)) + 127)
        temp = (bin(randint(0,pow(2,7))+ 127))
        bistring = bistring[2:]  + temp[2:]
        for j in range(16 - len(bistring)):
            bistring = '0' + bistring
        return bistring
    
    def reportr(self):
        print(self.registers)
    
    def reportpc(self):
        print(self.pcounter)

    def reportm(self):
        sorted_pairs = sorted(self.bistrings, key=lambda k:int(k,16))
        for k in sorted_pairs:
            print(k, self.bistrings[k])
    

    #NOTE because of the change I made to how I'm dealing with wmemaddr, this 
    #might not be necessary.
    #this works because all of the memory addresses that I need to write to are
    #less than 64. The reads, on the other hand, should simply be contained in a
    #register
    def wm(self,a):
        self.bistrings[hex(a)] = self.registers[7]
        self.pcounter += 10

    def wr(self, a):
        if(a == 1):
            self.registers[a] = self.bistrings[hex(9)][:8]
        elif(a == 2):
            self.registers[a] = self.bistrings[hex(9)][8:]
        elif(a == 3):
            self.registers[a] = self.bistrings[hex(96)][8:]
        elif(a == 7):
            self.registers[a] = self.registers[0]
        self.pcounter += 10

    def smr(self,a):
        self.registers[6] = 4*a 
        self.pcounter += 10

    def search(self):
        temp = ''
        if(self.registers[6] % 2 == 0):
            #print(self.registers[6]/2)
            temp = self.bistrings[hex(((self.registers[6])/2) + 48)][:8] 
        else:
            temp = self.bistrings[hex(((self.registers[6])/2) + 48)][8:] 
        r1 = self.registers[1]
        r2 = self.registers[2]
        r3 = self.registers[3]
        #r3 = str(int(r3) ^ int(r1))
        #temp = str(int(temp) ^ int(r2))
        if(((int(temp) ^ int(r2) == 0) and ((int(r3) ^ int(r1)) == 0))):
            self.pcounter += 20
            r3 = 0
        else:
            r3 = temp 
            self.pcounter += 10
        self.registers[3] = r3 


    def sub(self,b):
        self.registers[b] = 64 - self.registers[b]
        self.pcounter += 10

    def beq(self,a):
        self.registers[6] += 1
        if(self.registers[6] == 4*a):
            self.pcounter += 10
        else:
            self.pcounter -= 10

    def srl(self):
        if (self.registers[6] == 193):
            self.registers[7] = -1
        else:
            self.registers[7] = int((self.registers[6] - 96)/2)
        self.pcounter += 10

    def bsq(self,a):
        self.registers[6] +=1
        if(self.registers[6] == (193)):
            self.pcounter += 10
        else:
            self.pcounter -= 10

    def hal(self):
        self.pcounter += 10
        return 0 #exit(0)
    
    #this is a recursive method to add all of the bits in
    #a 16 bit integer together.
    def rxor(self):
        self.registers[7] += ((self.rxorr(str(self.bistrings[hex(self.registers[6])])[:8]) 
            + self.rxorr(str(self.bistrings[hex(self.registers[6])])[8:]))%2)
        self.pcounter += 10

    def rxorr(self, arr):
        if (len(arr) > 1):
            return ((self.rxorr(arr[:len(arr)/2]) 
                     + self.rxorr(arr[(len(arr)/2):]))%2)
        else:
            return int(arr)
        self.pcounter += 10




def main():
    i = 0
    assembler = newsteam()
    assembler.__init__()
    #evens or odds 
    assembler.smr(8)
    assembler.wr(7)
    #NOTE: Problem with getting 96 into register
    while (assembler.registers[6] < 96): 
        #NOTE: collapse smr & luw into one step
        assembler.rxor()
        #NOTE: NEED TO INCREMENT WHEN BEQING!!!
        assembler.registers[6] += 2
    assembler.sub(7)
    assembler.wm(12)

    print(assembler.registers)
    print(assembler.bistrings)
    



if __name__ =='__main__':

    main()
