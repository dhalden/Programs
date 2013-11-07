slist = [1,8888,27,6,15,4,3,12,1,1000, 965, 32, 78, 53, 1796]

def sortings():
    for j in range(0, len(slist)):
        stdlo = 0
        stdhi = 1
        for i in range(0, len(slist)):
            if(slist[stdlo] < slist[i]):
                if(slist[stdhi] > slist[i]):
                    temp = slist[stdhi]
                    slist[stdhi] = slist[i]
                    slist[i] = temp
                    stdhi = i
                    stdlo = i - 1
            elif(slist[stdlo] > slist[i]):
                if(slist[stdhi] > slist[i]):
                     temp = slist[stdhi]
                     slist[stdhi] = slist[stdlo]
                     slist[stdlo] = slist[i]
                     slist[i] = temp    
        print('run through: %d list is: %s ' % (j, str(slist)))
                
             
sortings()

