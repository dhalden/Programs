pals = []
for i in range(100000, 1000000):
    
    print str(i), str(i)[0:3] + (str(i)[5]  +  str(i)[4] +  str(i)[3])
    if str(i)[0:3] == (str(i)[5]  +  str(i)[4] +  str(i)[3]):
        pals.append(i)


print pals;
temp = 0
newi = 0
for i in range(100,1000):
    j = temp 
    for j in range(temp, len(pals)):
        if pals[j] % i == 0 and pals[j] /i < 1000:
            if pals[j] > pals[temp]:
                temp = j
                newi = i
print newi
print pals[temp]
