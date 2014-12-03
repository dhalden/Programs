import math
sq =[];
for i in range(1,1001):
    sq.append(i*i)
    print sq[i-1]
trip = {}
temp = 0
for i in range(0,len(sq)):
    for j in range(0,i):
        if (sq[i] - sq[i-j]) in sq:
            trip[temp] = [math.sqrt(sq[i]),math.sqrt(sq[i-j]),math.sqrt(sq[i] - sq[i-j])]
            temp += 1
print trip

for key in trip:
    if 1000 % int(trip[key][0]+trip[key][1]+trip[key][2]) == 0:
        print trip[key]
