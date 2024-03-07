%Ex.3.1
format long
f=@(x) (cos(2*x)).^2 -x.^2; df=@(x) -4*cos(2*x).*sin(2*x)-2*x;
[c,fc,xb,yb] = bisection(f,0,1.5,100)
[x0,xs,ys] = secantMethod(f,[0 1.5],100,1e-4)
[xn,yn]=newton_mod(f,df,1,1e-4,100)

