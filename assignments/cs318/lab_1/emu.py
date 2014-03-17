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
|Next Command (Binary + Translation):                                                              |
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
'0011':'addi',
'0100':'search',
'0101':'beq',
'0110':'wm',
'0111':'smr',
'1000':'rxor',
'1001':'sdri',
'1010':'luw',
'1011':'lqw',
'1100':'jump'
}


script = open("evenorodd.bi", "r")

i = 0
cmds = []
temp = ''
for line in script:
    if not(line[:4] in ['0100','0001','1000']):
        temp = (bconversions[line[:4]] + "(" + str(int(line[4:10],2)) + ")\n")
    else:
        temp = (bconversions[line[:4]] + "(" + ")\n")
    cmds.append(temp)
    i += 1
 
line = StringIO()
line2 = StringIO()
line3 = StringIO()
console = code.InteractiveConsole()
console.push('from sim import newsteam\n')
console.push('assembler = newsteam()\n')
console.push('assembler.__init__()\n')

with redirect_stdout(line2):
    console.push('assembler.reportpc()\n')


i = 0
pc = int(str(line2.getvalue()))/10
while(pc < len(cmds)): 
    line2 = StringIO() 
    print("assembler." + cmds[pc])
    console.push("assembler." + cmds[pc])
    with redirect_stdout(line2):
        console.push('assembler.reportpc()\n')
        pc = int(str(line2.getvalue()))/10
    i +=1
    #with redirect_stdout(line):
    #    console.push('assembler.reportr()\n')
    #print(line.getvalue())
    #line = StringIO() 


line2 = StringIO() 
with redirect_stdout(line):
    console.push('assembler.reportr()\n')
with redirect_stdout(line2):
    console.push('assembler.reportpc()\n')
with redirect_stdout(line3):
    console.push('assembler.reportm()\n')

print("this is the result: %s %s %s %s %s %s %s "
      % (mess[0],str(line.getvalue()), mess[1], str(line2.getvalue()), mess[3], str(line3.getvalue())
         , mess[4]))


print("Dynamic instruction count: " + str(i))
