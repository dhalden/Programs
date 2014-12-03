function genq(lambda,mu,n); close all; in=poissrnd(lambda,n,1); out=poissrnd(mu,n,1); queues=zeros(n,1);
if in(1) > out(1), queues(1)=in(1)-out(1);
end;
for i=2:n,
queues(i)= max(0,queues(i-1)+in(i)-out(i)); end;
bar(in);
title('Arrivals over time'); print('-dpng','in.png');
figure;
bar(out);
title('Departures over time'); print('-dpng','out.png');
figure;
bar(queues);
title('Queue Size over time'); print('-dpng','queues.png'); figure;
hist(queues);
title('Histogram of Queue Sizes'); print('-dpng','hist.png');
return;