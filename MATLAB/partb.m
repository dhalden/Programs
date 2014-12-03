clear
close all
t = linspace(-5,5,100);
[x,y] = meshgrid(t);

T = zeros(length(t),length(t));
Tx = T;
Ty = T;
for i=1:length(t)
    T(i,:) = exp(-(t(i).^2)-(t.^2));
end
[Tx,Ty] = gradient(T,.1,.1);
%surface(x,y,T);
contour(t,t,T)
hold on
quiver(t,t,Tx,Ty)
hold off
