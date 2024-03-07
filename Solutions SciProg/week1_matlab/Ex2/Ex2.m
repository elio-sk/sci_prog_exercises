%Exercise 2
A=input("Enter the first square matrix\n")
B=input("Enter the second square matrix\n")
a=size(A); b=size(B);
C=[A, zeros(length(A),length(B));zeros(length(B),length(A)), B]