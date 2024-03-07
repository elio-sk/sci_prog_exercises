function v=neville2(x,y,t)
if(length(x)~=length(y))
    fprintf("Input data accordingly")
else
    for m=2:length(x) %upper triangular matrix without 1st column
        for j=1:length(x)
            if(j+m<=length(x)+1)
            y(j)=((t-x(j))*y(j+1)-(t-x(j+m-1))*y(j))/(x(j+m-1)-x(j));
            end
        end
end
v=y(1);
end

    %Test polynomial
    %p=ones(1,3); x=1:4; y=polyval(p,x); y_real=polyval(p,1.5)
    %v=neville2(x,y,1.5)
    %We will see that y_real=4.7500 and by neville v=4.7917 so we have some
    %interpolation error