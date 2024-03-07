function Z=plotPotential(f,a,b,tau,varargin)
x=a:tau:b;
y=a:tau:b;
[X, Y]=meshgrid(x,y);
Z=f(X,Y);
figure(1)
surf(X,Y,Z,'LineStyle','none')
view(2)
colorbar
if nargin>=5
    n=varargin{1};
    figure(2)
    contourf(X,Y,Z,n,'LineColor','k')
end
end



