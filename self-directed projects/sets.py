
p = []
s = "abc"

#Make the powerset p for a string st
def powerset(st):
    di = []
    setlength = pow(2, len(st))
    for j in range(setlength): 
        temp = ""
        if(j < (setlength/2)):
            temp += st[0]
        if(len(st) > 1 and ((j % 2) == 0)):
            temp += st[1]
        if(len(st) > 2 and ((j % 4) in set([0,1]))):
            temp += st[2]
        if(len(st) > 3 and ((j % 8) in set([0,1,2,3]))):
            temp += st[3]
        if(len(st) > 4 and ((j % 16) in set([0,1,2,3,4,5,6,7]))):
            temp += st[4]
        di.append(temp);
        di.sort(lambda x,y: cmp(len(x),len(y)))    
    return di

#takes multiple parameters because there could potentially be more than 2
#unions that it needs to computer
def union(di, *arg):
    temp = ""
    for i in range(len(arg)):
        temp = "".join(set(temp.join(di[arg[i]])))
    return temp    

#takes multiple parameters because there could potentially be more than 2
#intersections that it needs to computer
def intersection(di, *arg):
    temp = di[arg[0]]
    for i in range(len(arg)):
        temp = "".join(set(temp).intersection(set(di[arg[i]]))) 
    return temp    

# Either I'm doing something wrong here, or we solved something wrong in class
def usandns(di):
    u = []
    n = []
    for i in range(0,len(di),1):
        for j in range(len(di)-1,-1,-1):
            u.append(union(di,i,j))
            n.append(intersection(di,i,j))
    u.sort(lambda x,y: cmp(len(x),len(y)))
    n.sort(lambda x,y: cmp(len(x),len(y)))
    return u,n

p = powerset(s)
print p, len(p)
u,n = usandns(p) 
print("unions = %s\n length of u = %s\n" % (u, len(u)))
tot1 = 0
for i in range(len(u)):
    if(u[i] != ''):
        tot1 += len(u[i])
print("intersections = %s\n length of n %s\n" % (n, len(n)))
tot2 = 0
for i in range(len(n)):
    if(n[i] != ''):
        tot2 += len(n[i])

print("total for unions = %s\n" % tot1)
print("total for intersections = %s\n" % tot2)
