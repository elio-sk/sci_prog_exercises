function [II, JJ, AA] = naive2ccs(I,J,a,m,n)
II=I;
AA=a;
JJ=zeros(1,n+1);
JJ(1)=J(1);              
JJ(n+1)=length(J)+1;   
l=1;
d=0;
for k=1:(length(J)-1)
    if J(k+1)>J(k) 
        d=J(k+1)-J(k);
        for i=1:d  
        JJ(l+i)=k+1;
        end
        l=l+d; 
    end
    if J(k+1)<n && k==length(J)-1 %If the last column has only 0 elements
        d2=n-J(k+1);  
        for i=1:d2
        JJ(l+i)=JJ(l);  
        end
    end
end
JJ
end