function d=pol_derive(a)
[m n]=size(a);
if(m~=1 && n~=1)
    fprintf("Input a row or column vector")
elseif(m==1)
d=[length(a)-1:-1:1].*[a(1:end-1)];
else
    d=[length(a)-1:-1:1].*[a(1:end-1)]';
end
    d=reshape(d,length(d),1);
end

%Suitable test polynomials would be those who have
% only ones as their coefficients
%e.g a=ones(1,5) polynomial of 4th order then d=[4 3 2 1]
%of order 4.