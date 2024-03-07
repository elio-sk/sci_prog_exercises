function [la,y]=poweriteration(A,I,J,a,m,x0,tol)
if(sum(x0(x0==0))==length(x0) || isempty(x0)==1)
    error('Input x0 accordingly.')
end
for i=1:length(A)
    for j=1:length(A)
        if A(i,j)~=A(j,i)
            error('Input matrix A is not symmetric')
        end
    end
end
j=1;
b=mvmsparse(I,J,a,m,x0);
y=b/norm(b);
la(1)=dot(y,b);
while (norm(b-la(j)*y)<=tol)
    j=j+1;
    b=mvmsparse(I,J,a,m,y);
    y=b/norm(b);
    la(j)=dot(y,b);
        if (abs(la(j))<=tol && abs(la(j-1)-la(j))<=tol)
            break;
        elseif (abs(la(j-1)-la(j))<=tol*abs(la(j)))
            break;
        end
end
disp(la)
end
%input
%A=[3 2 4; 2 0 2; 4 2 3]; I=[1 2 3 1 3 1 2 3]; J=[1 4 6 9];
%a=[3 2 4 2  2 4 2 3]; m=3; x0=[3 5 1]; tol=1e-10;  tic
%[la,y]=poweriteration(A,I,J,a,m,x0,tol)  toc
%Matrix A has eigenvector [2 1 2] and la=8;


