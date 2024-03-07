function [int,varargout]=midpointrule(f,n,varargin)
if nargin >2 
    a = varargin{1};
    b = varargin{2};
    else
    a=-1;
    b=1;
end

N=2^n;
x=zeros(1,N+1);
if b<a
    disp('Your input data is b<a');
end

x(1)=a;
x(2:N+1)=(1:N).*(b-a)./N+a*ones(1,N);
nodes=x;
sum=0;
for j=1:N
    sum=sum+f((x(j+1)+x(j))/2);
end
int=(b-a)*sum/N;
if nargout>1
    varargout{1}=nodes;
end
end
%input [int,nodes] = midpointrule(@(x) x,5,3,5)