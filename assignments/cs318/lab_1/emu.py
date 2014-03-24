import sys
import code
from contextlib import contextmanager
from StringIO import StringIO
try:
    from contextlib import redirect_stdout
except ImportError:
    @contextmanager
    def redirect_stdout(new_target):
        old_target, sys.stdout = sys.stdout, new_target # replace sys.stdout
        try:
            yield new_target
        finally:
            sys.stdout = old_target

mess = ["""
----------------------------------------------------------------------------------------------------
|Registers:                                                                                        |
"""
,
"""
----------------------------------------------------------------------------------------------------
|Program Counter:                                                                                  |
"""
,
"""
----------------------------------------------------------------------------------------------------
|Next Command (Translation + Binary):                                                              |
"""
,
"""
----------------------------------------------------------------------------------------------------
|Memory:                                                                                           |
"""
,
"""
|                                                                                                  |
----------------------------------------------------------------------------------------------------
"""
]

bconversions = {
'0000':'tbd',
'0001':'hal',
'0010':'sub',
'0011':'wr',
'0100':'search',
'0101':'beq',
'0110':'wm',
'0111':'smr',
'1000':'rxor',
'1001':'srl',
'1010':'bsq',
}

script = open("lab1demo.bi", "r")

i = 0
cmds = []
binaries = []
temp = ''
for line in script:
    if not(line[:4] in ['0100','0001','1000','1001']):
        temp = (bconversions[line[:4]] + "(" + str(int(line[4:10],2)) + ")\n")
    else:
        temp = (bconversions[line[:4]] + "(" + ")\n")
    cmds.append(temp)
    binaries.append(line)
    i += 1
 
line = StringIO()
line2 = StringIO()
line3 = StringIO()
line4 = StringIO()
console = code.InteractiveConsole()
console.push('from sim import newsteam\n')
console.push('assembler = newsteam()\n')
console.push('assembler.__init__()\n')
with redirect_stdout(line):
    console.push('assembler.reportr()\n')
with redirect_stdout(line2):
    console.push('assembler.reportpc()\n')
with redirect_stdout(line3):
    console.push('assembler.reportm()\n')

print("this is the result: %s %s %s %s %s %s %s "
      % (mess[0],str(line.getvalue()), mess[1], str(line2.getvalue()), mess[3], str(line3.getvalue())
         , mess[4]))

f = open('log2.out', 'a')
print >> f , line3.getvalue()
f.close()
line = StringIO()
line3 = StringIO()



i = 0
pc = int(str(line2.getvalue()))/10
while(pc < len(cmds)): 
    i +=1
    print i
    line2 = StringIO()
#    if (pc == 7 or pc == 8 or pc >= 11):
 #       with redirect_stdout(line3):
 #           console.push('assembler.reportm()')
 #       print(mess[3] + line3.getvalue())
 #       line3 = StringIO()

 #       with redirect_stdout(line):
 #           console.push('assembler.reportr()\n')
 #       print(line.getvalue())
 #       line = StringIO() 

    print("%s %s %s" % (mess[2], cmds[pc], binaries[pc]))
    console.push("assembler." + cmds[pc])

    if(pc >= 15):
        with redirect_stdout(line3):
            console.push('assembler.reportm()')
        print(mess[3] + line3.getvalue())
        line3 = StringIO()

    with redirect_stdout(line2):
        console.push('assembler.reportpc()\n')
    pc = int(str(line2.getvalue()))/10

    with redirect_stdout(line):
        console.push('assembler.reportr()\n')
    print(line.getvalue())
    line = StringIO() 


line2 = StringIO() 
with redirect_stdout(line):
    console.push('assembler.reportr()\n')
with redirect_stdout(line2):
    console.push('assembler.reportpc()\n')
with redirect_stdout(line3):
    console.push('assembler.reportm()\n')

print("this is the final result for Memory result: %s %s %s %s %s %s %s "
      % (mess[0],str(line.getvalue()), mess[1], str(line2.getvalue()), mess[3], str(line3.getvalue())
         , mess[4]))

f = open('log3.out', 'a')
print >>  f , line3.getvalue()
f.close()

print("Dynamic instruction count: " + str(i))
