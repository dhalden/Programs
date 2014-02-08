
p = []
s = ["abcdefghijk","abcdefghijkl","abcdefghijklm","abcdefghijklmn","abcdefghijklmno"]

#Make the powerset p for a string st
#The new version of powerset
def powerset(st):
    nums = []
    setlength = pow(2, len(st))

    for i in range(setlength):
        nums.append(i)
    di = []

    for j in range(setlength):
        temp = ""
        stlen = len(st)
        if(j < (setlength/2)):
            temp += st[0]
        for i in range(1, stlen, 1):
            if((j % pow(2, i)) in set(nums[:pow(2,(i-1))])):
                temp += st[i]
        di.append(temp)
        di.sort()
        di.sort(lambda x,y: cmp(len(x),len(y)))
    return di

#takes multiple parameters because there could potentially be more than 2
#unions that it needs to computer
def union(di, *arg):
    temp = set(di[arg[0]])
    for i in range(len(arg)):
        temp = set(temp.union(set(di[arg[i]])))
    temp = "".join(temp)
    return temp

#takes multiple parameters because there could potentially be more than 2
#intersections that it needs to computer
def intersection(di, *arg):
    temp = set(di[arg[0]])
    for i in range(len(arg)):
        temp = set(temp.intersection(set(di[arg[i]]))) 
    temp = "".join(temp)
    return temp    

# Either I'm doing something wrong here, or we solved something wrong in class
def usandns(di):
    u = []
    n = []
    for i in range(0,len(di),1):
    #    for j in range(0,len(di),1):
        u.append(union(di,i))
        n.append(intersection(di,i))
    u.sort(lambda x,y: cmp(len(x),len(y)))
    n.sort(lambda x,y: cmp(len(x),len(y)))
    return u,n

for j in range (len(s)):
    p.append(powerset(s[j]))
    u,n = usandns(p[j]) 
    print("length of powerset = %s" % len(p[j]))
    print("length of u = %s\n" % (len(u)))
    tot1 = 0
    for i in range(len(u)):
        if(u[i] != ''):
            tot1 += len(u[i])


    print("length of n %s\n" % (len(n)))
    tot2 = 0
    for i in range(len(n)):
        if(n[i] != ''):
            tot2 += len(n[i])

    print("total for unions = %s\n" % tot1)
    print("total for intersections = %s\n" % tot2)
