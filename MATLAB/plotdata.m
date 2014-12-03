hold on
plot(x, T(1,:) ,'b')
plot(x, T(100,:) ,'r')
plot(x, T(2500,:) ,'g')
plot(x, T(5000,:) ,'y')
plot(x, T(7500,:) ,'k')
plot(x, T(10000,:) ,'p')
plot(x, T(25000,:) ,'c')
plot(x, T(100000,:),'m')
title('Derek Halden')
ylabel('T(x,t) , Degrees')
xlabel('x, meters')
legend('t = 1', 't = 100', 't = 2500', 't = 5000', 't = 7500', 't = 10000', 't = 25000', 't = 100000');