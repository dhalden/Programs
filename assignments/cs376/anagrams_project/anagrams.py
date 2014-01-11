
di = {}
d = open("dict.txt", 'r')
nd = open("mdict.txt", 'w')
for line in d:
   if line.contains
   newline = ''.join(sorted(line))
   print(newline)
   print (line)
   nd.write(line + " \t  " + newline)
   di[newline] = line


