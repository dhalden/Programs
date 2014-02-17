def turnT(i, t, m):
    t = (t + 1*i) % 6
    m = (m + 2*i) % 9
    return(t, m)

def turnM(i, t, m, b):
    m = (m + 1*i) % 9
    t = (t + 2*i) % 6
    b = (b + 2*i) % 12
    return (t, m, b)

def turnB(i, m, b):
    b = (b + 1*i) % 12
    m = (m + 2*i) % 9
    return (m, b)




for i in range(19):
    for j in range(19):
        for k in range(37):
            t = 1
            m = 8
            b = 2
            t, m = turnT(i, t, m)
            t, m, b = turnM(j, t, m, b)
            m, b = turnB(k, m, b)
            if((t == 3) and (m == 6) and (b == 11)):
                print(i, j, k)
