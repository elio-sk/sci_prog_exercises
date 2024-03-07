function primeNumbers=eratosthenes(n)
primeNumbers=2:n;
p=2;
while(p<=n)
for i=2*p:p:n
    primeNumbers(i-1)=0;
end
p=p+1;
end
primeNumbers=primeNumbers(primeNumbers>0)
end