k=0:5;
for i=1:length(k)
    N=100*(2^k(i));
    x(i)=N;
    tic
    A = matrix(N);
    time(i)=toc;
end
for i=1:length(k)
    tic
    A = matrix2(N);
    time2(i)=toc;
end
loglog(x,time,'r')
hold on
loglog(x,time2,'b')
legend('Time Matrix','Time Matrix2')
r=polyfit(log(x),log(time),1);