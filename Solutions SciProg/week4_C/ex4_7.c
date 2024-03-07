#include <stdio.h>

int fibonacci(int n) {
	if(n<=1)
	return n;
	else{
		return fibonacci(n-1)+fibonacci(n-2);
	}
 }

    
    main() {
    	int n,f;
    	printf("Input n=");
        scanf("%d",&n);
        f=fibonacci(n);
        if(n<0)
        printf("Input data accordingly.");
        else
        printf("fibonacci(%d) = %d ",n,f);
	}
