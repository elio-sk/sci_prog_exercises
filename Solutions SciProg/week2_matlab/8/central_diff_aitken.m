h0=input('Value of h0')
rho=input('Value of rho')
n=input('Value of n')
f=@(x) exp(x);
df=@(x) exp(x);
for j=1:n
    h(j)=h0*rho^j;
    d1(j)=(f(0+h(j))-f(0))./h(j);
    d2(j)=(f(0+h(j))-f(0-h(j)))./(2*h(j));
    ed1(j)=abs(d1(j)-df(0));
    ed2(j)=abs(d2(j)-df(0));
end
y1=aitken(d1);
y2=aitken(d2);
ey1=abs(y1-df(0));
ey2=abs(y2-df(0));
loglog(1./h,ed1,'ro-','LineWidth',1,'MarkerSize',3)
hold on
loglog(1./h,ed2,'bx-','LineWidth',1,'MarkerSize',3)
legend('one-sided','central')
h(end-1)=[]; h(end)=[];
figure(2)
loglog(1./h,ey1,'ro-','LineWidth',1,'MarkerSize',3)
hold on
loglog(1./h,ey2,'bx-','LineWidth',1,'MarkerSize',3)
legend('one-sided','central')

%input e.g h0=2 rho=0.2 n=10

