clear
D = 0.40;
v = 0.15;
c0 = 1;
k = 3.47e-06;
t=[5 10 15 20 25 30];
C = ones(10000,length(t));
x = ones(10000,1);

for i = 1:length(C)
    x(i) = i/(length(C)/5) - 1/(length(C)/5);
    for j = 1:length(t)
        C(i,j) = exp(-(x(i) - v*t(j))^2);
    end
end

figure
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
legend('t=5','t=10','t=15', 't=20', 't=25', 't=30')


