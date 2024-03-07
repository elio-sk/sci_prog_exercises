v=input("Enter the complex entries of vector\n");
C=input("Enter the positive bound\n");
if (isempty(v)==1 || C<=0)
    fprintf("Input the data required accordingly")
elseif (size(v)==1)
    if v>C
        u=[];
    else
        disp(v)
    end
else
    u=v(abs(v)<=C);
end
disp(u)