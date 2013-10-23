import math
import numpy as np
import matplotlib.pyplot as plt
from pylab import *



t = arange (0.0, pi, .001)
s = sin(t)
plot(t,s, linewidth = .5)

x = arange(0.0, 2, .001)
y = x
plot(x,y, linewidth = .5)

xlabel('x')
ylabel('y')
title('the sine wave')
savefig("sineWave example")
show()
