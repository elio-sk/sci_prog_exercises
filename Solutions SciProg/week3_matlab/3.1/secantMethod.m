% Secant method from slide 119
function [x0,xs,ys] = secantMethod(f,x,max_iter,varargin)
if nargin >= 3
    tol = varargin{1};
else
    tol = 1e-12;
end
fx = f(x);
iter=1;
j=1;
while true
    dx = x(2)-x(1);
    assert(dx~=0,'Iteration led to x_{n} = x_{n-1}')
    df = (fx(2)-fx(1))/dx;
    assert(df~=0,'Difference quotient is zero!')
    if (abs(df) <= tol)
        warning('Diff. quotient is close to zero!')
    end
    x = [x(2), x(2)-df\fx(2)];
    fx = [fx(2), f(x(2))];
    abs_dx = abs(dx);
    max_x = max(abs(x));
    xs(j)=x(2);
    ys(j)=fx(2);
    if ( abs(fx(2))<=tol && ...
            ( (abs_dx<=tol && max_x<=tol) || ...
            (abs_dx<=tol*max_x && max_x>tol) ) )
        break;
    end
    if (iter>=max_iter)
        error('Solution cannot be found with required tolerance');
    end
    j=j+1;
    iter=iter+1;
end
x0=x(2);
 n=length(xs);
    k=1:n;
    r=[k' xs' ys'];
    disp('    Secant iteration           x              f(x)')
    disp(r)
end