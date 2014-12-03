Sigx = [4 2 0 1; 2 7 1 1; 0 1 9 0; 1 1 0 3];
ux = [1; -3; 4; 2];
%Y = -X1 3X2 X3 -2X2
Y = [-1 3 1 -2];
Ey = Y*ux;
Vary = ux'*Sigx*ux;

Z = [1 1 2 -1; 0 1 0 2];%*X
Ez = Z*ux
covz = cov(Z)
