function [xn,yn]=newton_mod(f,der_f,x0,t_rel,max_iter,varargin)
if nargin >5
    tol=varargin{1};
else
    tol=1e-12;
end
xn(1)=x0;
yn(1)=feval(f,xn(1));
dy(1)=feval(der_f,xn(1));
for i=2:max_iter
    xn(i)=xn(i-1)-yn(i-1)/dy(i-1);
    yn(i)=feval(f,xn(i));
    t_rel=abs(xn(i)-xn(i-1)/min(abs(xn(i)),abs(xn(i-1))));
    if(abs(yn(i)<=max(tol,t_rel*feval(f,x0))))
        fprintf('Method has converged by relative tolerance criterion on %d iteration \n',i);
    end
    if (abs(xn(i)-xn(i-1))<=tol*max(1,abs(xn(i)) && abs(yn(i))<=tol))
        fprintf('Method has converged by absolute tolerance criterion \n');
        break;
    end
    dy(i)=feval(der_f,xn(i));
    iter=i;
    end
    if(iter>=max_iter)
        error('Solution cannot be found with required tolerance');
    end
    n=length(xn);
    k=1:n;
    r=[k' xn' yn'];
    disp('    Newton iteration   x    y')
    disp(r)
     %input f=@(x) x.^2+exp(x)-2; der_f=@(x) 2*x+exp(x);
    % call [x,y]=newton(f,der_f,0.1,10^-6,10^-4,100)