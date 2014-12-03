clear
D = 0.40;
v = 0.15;
c0 = 1;
k = 3.47e-06;
t = 0:1:2000000;


for i=1:length(t)
   C(i) = exp(-k*i);
end

figure
plot(t,C,'b');
title('Derek Halden');
xlabel('t, seconds');
ylabel('C, concentration kg/L')
