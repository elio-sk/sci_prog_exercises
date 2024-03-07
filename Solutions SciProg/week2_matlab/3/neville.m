function v=neville(x,y,t)
if(length(x)~=length(y))
    fprintf("Input data accordingly")
else
    p(1:length(x),1)=y; %first column only
    for m=2:length(x) %upper triangular matrix without 1st column
        for j=1:length(x)+1-m
            %if(j+m<=length(x)+1)
            p(j,m)=((t-x(j))*p(j+1,m-1)-(t-x(j+m-1))*p(j,m-1))/(x(j+m-1)-x(j));
            %end
        end
    end
    v=p(1,end);
    disp(p)

    %Test polynomial
    %p=ones(1,3); x=1:4; y=polyval(p,x); y_real=polyval(p,1.5)
    %v=neville(x,y,1.5)
    %We will see that y_real=4.7500 and by neville v=4.7500

    end
 