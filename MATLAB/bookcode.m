%Derek Halden
%Problem 4 code
L=1; tmax=800;
D= 10^-5
Mx= 83;
Mt= 401;

Tinit = 0*ones(Mx,1)
for i = 1:Mx
    if (((i/85) < 3/8) || ((i/85) > 5/8))
        Tinit(i)= 0;
    else 
        Tinit(i) = 100;
    end
end
T0 = 0;
TL = 0;

dt = tmax/(Mt-1);
dx = L/(Mx+1);

tspan = 0:dt:tmax;
xspan = 0:dx:L;

gamma = D*dt/dx^2;

if Mx ~= 1
    A= (1-2*gamma)*diag(ones(1,Mx))...
        + gamma*diag(ones(1,Mx-1),1)...
        + gamma*diag(ones(1,Mx-1),-1);
end
Bu = gamma*[T0; zeros(Mx-2,1); TL];

T = zeros(Mx,Mt);
T(:,1) = Tinit;
for i=1:Mt-1
    T(:,i+1) = A*T(:,i) + Bu;
end;
T= [T0*ones(1,Mt); T; TL*ones(1, Mt)];

Nplot= 10;

figure(1); clf;
subplot(1,2,1)
    kx = 2:floor(Mx/Nplot):Mx;
    plot(tspan, T(kx, :));
    set(gca, 'ylim', [0, 1.05]*max([T0, TL, Tinit']))
    xlabel('t'), ylabel('T(x, t)')
    legtext = [ones(length(kx), 1)*'x=',num2str(xspan(kx)')];
    legend(legtext,1)
    grid
    
subplot(1,2,2)
    kt = 1:floor(Mt/Nplot):Mt;
    plot(xspan, T(:, kt)','.-');
    set(gca, 'ylim', [0, 1.05]*max([T0, TL, Tinit']))
    xlabel('x'), ylabel('T(x, t)')
    legtext = [ones(length(kt), 1)*'t=',num2str(tspan(kt)')];
    legend(legtext,1)
    grid