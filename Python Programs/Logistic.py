import math
import numpy as np
import matplotlib.pyplot as plt
from pylab import *



t = arange (0.0, 1.0, .001)
s = t*(1 - t)
plot(t,s, linewidth = .5)

x = arange(0.0, .5, .001)
y = x
plot(x,y, linewidth = .5)

xlabel('x')
ylabel('y')
title('The logistic curve')
savefig("logistic curve example")
show()
