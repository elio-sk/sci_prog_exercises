u_exact=@(t) (-t.^2)/2+t/2; 
f=@(t) 1; u_x0=0; u_xn=0; h=1/10;
N=round(1/h)-1; x=0:h:1; 
A=2*diag(ones(N,1))-diag(ones(N-1,1),-1)-diag(ones(N-1,1),1);
g=@(t,x) f(t).*(t-x)/h;
%b=zeros(N,1);
for j=1:N,
    b(j)=h*quad(@(t)g(t,x(j)),x(j),x(j+1))-...
h*quad(@(t)g(t,x(j+2)),x(j+1),x(j+2));
end
b(1)=b(1)+u_x0; b(end)=b(end)+u_xn; u=A\(b'); u=[u_x0;u;u_xn];
plot(x,u,'r-*','MarkerSize',8)
hold on
fplot(u_exact,[0 1],'b')
legend('FEM solution','Exact solution')