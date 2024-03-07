function y=aitken(x)
for i=1:length(x)-2
    y(i)=x(i)-((x(i+1)-x(i)).^2)./(x(i+2)-2*x(i+1)+x(i));
    y=y'
end
end
% input x=1./[1:100]; x=x' y=aitken(x)