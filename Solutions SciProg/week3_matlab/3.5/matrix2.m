function [C,A] = matrix2(N)
    x = rand(1,N);
    y = rand(1,N);
 
 I = zeros(1,N^2);
 J = zeros(1,N^2);
 a = zeros(1,N^2);
 n = 1;
 for i=0:N-1
     i=(n-1)*N;
    for j=1:N
      I(i+j)=j;
      J(i+j)=n;
    end
    n=n+1;
end
triangles = delaunay(x,y);
    n = size(triangles,1);
    for i = 1:n
        nodes = triangles(i,:);
        B = [1 1 1 ; x(nodes) ; y(nodes)];
        grad = B \ [0 0 ; 1 0 ; 0 1];
        new_value = det(B)*grad*grad'/2;
      %  A(nodes,nodes)=A(nodes,nodes)+new_value;
        
        for k=1:length(nodes)
          for l=1:length(nodes)
            I(N*(nodes(l)-1)+nodes(k))=nodes(k);
            J(N*(nodes(l)-1)+nodes(k))=nodes(l);
            a(N*(nodes(l)-1)+nodes(k))=a(N*(nodes(l)-1)+nodes(k))+new_value(k,l);
        end  
        end
    end

    C = sparse(I,J,a,N,N); 
end
