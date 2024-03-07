function [maximum, count]=max_vector(v)
%input v from command window
%call the function from cm as [maximum, count]=max_vector(v)
maximum=max(v);
count=sum((v==maximum));
fprintf("Maximum is %.4f and it appears %d times ",maximum,count)
end
