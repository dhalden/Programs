import subprocess as sp

bconversions = {
'0000':'assembler.tbd()',
'0001':'assembler.hal()',
'0010':'assembler.sub()',
'0011':'assembler.addi()',
'0100':'assembler.search()',
'0101':'assembler.beq()',
'0110':'assembler.wm()',
'0111':'assembler.smr()',
'1000':'assembler.rxor()',
'1001':'assembler.sdri()',
'1010':'assembler.luw()',
'1011':'assembler.lqw()',
'1100':'assembler.jump()'
}

#sp.call(["python"])
#sp.call(["import", "antigravity"])

script = open("assembly.bi", "r")

i = 0
commands = []
for line in script:
    if not(line[:4] in ['0100','0001','1000']):
        print (bconversions[line[:4]])
        print (int(line[4:10], 2))
    else:
        print (bconversions[line[:4]])
