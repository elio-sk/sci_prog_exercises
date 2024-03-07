%Exercise 2
A=input("Enter the first square matrix")
B=input("Enter the second square matrix")
a=size(A); b=size(B);
C=[A, zeros(a(1),b(1));zeros(b(1),a(1)), B]