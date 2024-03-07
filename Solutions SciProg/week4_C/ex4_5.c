#include <stdio.h>

int binomial(int n,int k) {
	if (k > n){
	return 0;
	}
	else{
	if (k == 0 || k == n){
    return 1;	
	}
	else{
	return binomial(n-1,k)+ binomial(n-1,k-1);	
	}	
	} 
}
    
    main() {
    	int n,k,c;
    	printf("Input n=");
        scanf("%d",&n);
        printf("Input k=");
        scanf("%d",&k);
        c=binomial(n,k);
        if(k<0 || n<0)
        printf("Input data accordingly.");
        else
        printf("C(%d, %d)=%d ",n,k,c);
	}
