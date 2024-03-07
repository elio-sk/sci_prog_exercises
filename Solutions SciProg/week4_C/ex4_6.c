#include <stdio.h>

int division(int m,int n) {
	if(m<n){
	return 0;	
	}
	else{
	return 1+division(m-n,n);
	}

}
    
    main() {
    	int m,n,d;
    	printf("Input m=");
        scanf("%d",&m);
        printf("Input n=");
        scanf("%d",&n);
        d=division(m,n);
        if(m<0 || n<=0)
        printf("Input data accordingly.");
        else
        printf("%d/%d = %d ",m,n,d);
	}
