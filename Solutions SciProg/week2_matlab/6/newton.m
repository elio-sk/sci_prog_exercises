function [x,y]=newton(f,der_f,x0,tol,t_rel,max_iter)
x(1)=x0;
y(1)=feval(f,x(1));
dy(1)=feval(der_f,x(1));
for i=2:max_iter
    x(i)=x(i-1)-y(i-1)/dy(i-1);
    y(i)=feval(f,x(i));
    t_rel=abs(x(i)-x(i-1)/min(abs(x(i)),abs(x(i-1))));
    if(abs(y(i)<=max(tol,t_rel*feval(f,x0))))
        fprintf('Method has converged by relative tolerance criterion on %d iteration \n',i);
    end
    if (abs(x(i)-x(i-1))<=tol*max(1,abs(x(i)) && abs(y(i))<=tol))
        fprintf('Method has converged by absolute tolerance criterion \n');
        break;
    end
    dy(i)=feval(der_f,x(i));
    iter=i;
    end
    if(iter>=max_iter)
        error('Solution cannot be found with required tolerance');
    end
    n=length(x);
    k=1:n;
    r=[k' x' y'];
    disp('    iteration   x    y')
    disp(r)
     %input f=@(x) x.^2+exp(x)-2; der_f=@(x) 2*x+exp(x);
    % call [x,y]=newton(f,der_f,0.1,10^-6,10^-4,100)