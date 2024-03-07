% Bisection method from slide 82
function [c,fc,xb,yb] = bisection(f,a,b,max_iter,varargin)
if nargin >4
    tol = varargin{1};
else
    tol = 1e-12;
end
fa = feval(f,a);
fb = feval(f,b);
iter=1;
j=1;
while true
    c = (a+b)/2;
    fc = feval(f,c);
    xb(j)=c;
    yb(j)=fc;
    if ( abs(b-a)<=2*tol && abs(fc)<=tol )
        break
        elseif ( fa*fc <= 0 )
            b = c;
            fb = fc;
    else
        a = c;
        fa = fc;
    end
    iter=iter+1;
    if (iter>=max_iter)
        error('Solution cannot be found with required tolerance');
    end
    j=j+1;
end
n=length(xb);
    k=1:n;
    r=[k' xb' yb'];
    disp('    Bisection iteration           x              f(x)')
    disp(r)
    xb;
    yb;
end

    
        




