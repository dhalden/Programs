D = 0.40;
v = 0.15;
c0 = 1;
k = 3.47e-06;
C0 = c0/sqrt(4*pi*D);
t=[0.1 1 10 100 1000 10000];
C = ones(10000,length(t));
C(1) = C0;
x = ones(10000,1);
x(1) = 0;

for i = 2:length(C)
    x(i) = i/(length(C)/1) - 1/(length(C)/1);
    for j = 1:length(t)
        C(i,j) = 0.45*(t(j)^(-1/2))*exp(-(x(i)^2)/(0.16*t(j)));
    end
end
hold on
plot(x(:,1), C(:,1), 'b');
plot(x(:,1), C(:,2), 'r');
plot(x(:,1), C(:,3), 'g');
plot(x(:,1), C(:,4), 'm');
plot(x(:,1), C(:,5), 'k');
plot(x(:,1), C(:,6), 'c');
title('Derek Halden')
xlabel('x, meters')
ylabel('c, concentration')
legend('t=0.1','t=1', 't=10', 't=100', 't=1000', 't=10000')


