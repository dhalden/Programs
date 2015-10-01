import numpy as np
import random
import matplotlib.pyplot as plt

def iterate(c,init):
    x=[]
    x.append(c*init*(1-init))
    for i in range(1,256):
        t = c*x[i-1]*(1-(x[i-1]))
        if(t in x):
            return(x[x.index(t):])
        x.append(t)
    return x[len(x)-50:]

p = np.linspace(0, 4.0, 4000)
fig = plt.figure()
ax1 = fig.add_subplot(1,1,1)
c = 0
for i in p:
    y=[]
    x = iterate(i,0.37)
    c = (c+66051) % int('FFFFFF',16)
    #print(hex(c))
    for j in range(len(x)):
        y.append(i)
    ax1.scatter(y, x, marker='.', color='#{0:06X}'.format(c))
plt.show()
