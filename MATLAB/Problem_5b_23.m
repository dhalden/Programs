D = 0.40;
v = 0.15;
c0 = 1;
k = 3.47e-06;
C0 = c0/sqrt(4*pi*D);
x=[1 5 10 15]*(10^3);
C = ones(10000,length(x));
t = ones(12000,1);
t(1) = 0;

for i = 1:length(t)
    t(i) = 10*i;
    for j = 1:length(x)
        C(i,j) = C0*(t(i)^(-1/2))*exp(-((x(j)-v*t(i))^2)/(4*D*t(i)));
    end
end


figure
hold on
plot(t(:,1), C(:,1), 'b');
plot(t(:,1), C(:,2), 'r');
plot(t(:,1), C(:,3), 'g');
plot(t(:,1), C(:,4), 'm');
title('Derek Halden')
xlabel('t, seconds')
ylabel('c, concentration')
legend('x=1 km','x = 5 km', 'x = 10 km', 'x = 15 km')