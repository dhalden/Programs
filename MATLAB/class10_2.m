%Derek Halden
%Problem 3 code
D=10^-5;
x=0:.01:1;
t=0:.001:100;
T= zeros(length(t), length(x));
 for j= 1:length(x)
     if ((x(j) < (3/8)) || (x(j) > 5/8))
         T(1,j) = 0;
     else
         T(1,j) = 100;
     end
 end
for i = 1:length(t)
   for j = 2:length(x) 
     Tn = 0;
     if ((x(j) < (3/8)) || (x(j) > 5/8))
        for n = 1:100
            Tn = Tn + (-1/(n*pi))*((-1^n)*60 + 40*(1-(-1^n)))*sin(n*pi*x(j))*exp(-((n*pi)^2)*D*t(i));
        end
     else
        for n = 1:100
            Tn = Tn + (1/(n*pi))*((-1^(n+1))*60 + 80*(1-(-1^n)))*sin(n*pi*x(j))*exp(-((n*pi)^2)*D*t(i));
        end
     end
     T(i,j) = Tn + 30*x(j) + 20;
   end
end
figure
hold on
plot(x, T(1,:) ,'b')
plot(x, T(100,:) ,'r')
plot(x, T(2500,:) ,'g')
plot(x, T(5000,:) ,'y')
plot(x, T(7500,:) ,'k')
plot(x, T(10000,:) ,'p')
title('Derek Halden')
ylabel('T(x,t) , Degrees')
xlabel('x, meters')
legend('t = 1', 't = 100', 't = 2500', 't = 5000', 't = 7500', 't = 10000');

