function [error_neville, error_naive]=richardson_sch(n,x0)
rho=0.1:0.1:0.9;
for j=1:9
f=@(x) exp(x);
df=@(x) exp(x);
for k=1:n
    h(k)=rho(j)^k;
    D(k)=(f(x0+h(k))-f(x0))./h(k);
end
gn=neville2(h,D,0);
error_neville(j)=abs(gn-df(x0));
error_naive(j)=abs(D(end)-df(x0));
value_richardson(j)=gn;
end
disp(value_richardson)
end

% input [error_neville, error_naive]=richardson_sch(n,x0)
%comment the value_richardson is more accurate for exp(1)
%when step is 0.9 and not 0.1 because
%0.1^10 is smaller than 0.9^10 because of small nr. rounding