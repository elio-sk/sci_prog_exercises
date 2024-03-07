function A = matrix(N)
x = rand(1,N);
y = rand(1,N);
triangles = delaunay(x,y);
n = size(triangles,1);
A = sparse(N,N);
for i = 1:n
nodes = triangles(i,:);
B = [1 1 1 ; x(nodes) ; y(nodes)];
grad = B \ [0 0 ; 1 0 ; 0 1];
A(nodes,nodes) = A(nodes,nodes) + det(B)*grad*grad'/2;
end
end