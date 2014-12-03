x=round(rand(100000,1));
s=cumsum(x);
f=[1:100000];
y=s./(f') - 0.5;
plot(y, 'b');
axis([1 100000 -0.2 0.2 ]);
hold on;