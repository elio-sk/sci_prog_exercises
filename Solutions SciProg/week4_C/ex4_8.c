#include <stdio.h>

void hanoi(int n,int i, int j, int m){
	if (n == 1)
    {
        printf("Disk 1 moves from rod %d to rod %d \n", i, j);
        return;
    }
    else{
    	  hanoi(n-1, i, m, j);
          printf("Disk %d moves from rod %d to rod %d \n", n, i, j);
          hanoi(n-1,m, j, i);
  
	}
}

main(){
	int n;
	printf("Input n=");
	scanf("%d",&n);
	hanoi(n,1,3,2);
	return 0;
}

