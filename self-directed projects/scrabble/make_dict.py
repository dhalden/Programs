import pickle
f = open('dict.txt','r')
wdict = {}

for line in f:
    line = line[:len(line)-1]
    sort = ''.join(sorted(line))
    if sort in wdict:
        wdict[sort].append(line)
    else:
        wdict[sort] = [line]

output = open('data.pkl', 'wb')
print(wdict)
pickle.dump(wdict, output)
output.close
f.close
