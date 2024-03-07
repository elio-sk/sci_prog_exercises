function B = chessboard(n)
%input n from command window
%call the function from cm as B = chessboard(n)
B = ones(n);
B(1:2:n,1:2:n)=0;
B(2:2:n,2:2:n)=0;
end