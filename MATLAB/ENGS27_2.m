clear
M = [0 0.05 .9 .05 0; 0 .3 .6 .09 .01;0 .03 .9 .04 .03; 0 .03 .04 .9 .03; 0 0 0 0 1]
[V D] = eig(M);


P = M([5 1:4],[5 1:4]);
R = P([1], [1]);
A = P([2:5],[1]);
B = P([2:5],[2:5]);
D = inv(eye(4) - B)*ones(4,1)
E = inv(eye(4) - B)*[0; 12000; 84000; 240000]
