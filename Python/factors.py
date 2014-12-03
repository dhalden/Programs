import math
prs = []
def factor(k):
    n = int(math.sqrt(k))
    for i in range(1,n):
        if(k % i == 0):
            k = k/i
            prs.append(i)
            i -= 1
factor(600851475143)
print(prs)
