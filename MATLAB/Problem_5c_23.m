D = 0.40;
v = 0.15;
c0 = 1;
k = 3.47e-06;
C0 = c0/sqrt(4*pi*D);
t=[6650 33000 66660 100000 133300 166600];
C = ones(10000,length(t));
x = ones(10000,1);
x(1) = 0;

for i = 1:length(C)
    x(i) = i/(length(C)/30000) - 1/(length(C)/30000);
    for j = 1:length(t)
        C(i,j) = C0*(t(j)^(-1/2))*exp(-k*t(j))*exp(-((x(i)-v*t(j))^2)/(4*D*t(j)));
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
legend('t=6650', 't=33000', 't=66660', 't=100000', 't=133300', 't=166600')