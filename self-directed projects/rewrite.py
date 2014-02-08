#The old version of Powerset
def powerset(st):
    nums = []
    for i in range(pow(2, len(st))):
        nums.append(i)
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
        if(len(st) > 3 and ((j % 8) in set(nums[0:4]))):
            temp += st[3]
        if(len(st) > 4 and ((j % 16) in set(nums[0:8]))):
            temp += st[4]
        if(len(st) > 5 and ((j % 32) in set(nums[0:16]))):
            temp += st[5]
        if(len(st) > 6 and ((j % 64) in set(nums[0:32]))):
            temp += st[6]
        if(len(st) > 7 and ((j % 128) in set(nums[0:64]))):
            temp += st[7]
        if(len(st) > 8 and ((j % 256) in set(nums[0:128]))):
            temp += st[8]
        if(len(st) > 9 and ((j % 512) in set(nums[0:256]))):
            temp += st[9]
        if(len(st) > 10 and ((j % 1024) in set(nums[0:512]))):
            temp += st[10]
        if(len(st) > 11 and ((j % 2048) in set(nums[0:1024]))):
            temp += st[11]
        if(len(st) > 12 and ((j % 4096) in set(nums[0:2048]))):
            temp += st[12]
        if(len(st) > 13 and ((j % 8192) in set(nums[0:4096]))):
            temp += st[13]
        if(len(st) > 14 and ((j % 16384) in set(nums[0:8192]))):
            temp += st[14]
        
        di.append(temp);
        di.sort()
        di.sort(lambda x,y: cmp(len(x),len(y)))    
    return di
s = "abcde"

print(powerset(s))
