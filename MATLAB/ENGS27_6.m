t = 1
s2 = 2*t
x = -3:.001:3
y = (1/(sqrt(2*pi*s2)))*exp(-x.^2/(2*s2))
plot(x,y,'b')