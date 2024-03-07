function y = mvmsparse(I,J,a,m,x)

y= zeros(m,1);
coord = zeros(1,2);

JJ = zeros(length(a),1);

for k = 1:length(J)-1  
p_entry = J(k);
n_entry = J(k+1);
JJ([p_entry:n_entry-1]) = k;
end

for k = 1:length(a)  
    i = I(k);
    j = JJ(k);
    y(i) =  y(i)+a(k)*x(j);
end
