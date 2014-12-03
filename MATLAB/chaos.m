alpha=4;
x=[];
x(1)=.4; 
for i=2:100,
x(i)=x(i-1)*(1-x(i-1))*alpha;
end;
plot(x);