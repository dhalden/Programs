def baseN(num,b,numerals="0123456789abcdefghijklmnopqrstuvwxyz"):
     return ((num == 0) and numerals[0]) or (baseN(num // b, b, numerals).lstrip(numerals[0]) + numerals[num % b]) 

f = open("A-small-practice.in","r")
f.readline()
case = 0
for line in f:
    temp = ""
    d = {}
    i = 1
    check = 1
    for letter in line:
        if letter in d:
            temp = temp + str(d[letter])
        else:
            if i == 1 and check == 1:
                d[letter] = i
                i = i-1
                check = 0
            else:
                d[letter] = i
                i = i + 1
            temp = temp + str(d[letter])
    print("Case #"+ str(case) + ": "+ str(baseN(int(temp), (i+1),"0123456789abcdefghijklmnopqrstuvwxyz")) + "seconds")
    case = case + 1
             
