#include <stdio.h>

main()
{
double l,x,y;

printf("Input l=");
scanf("%f",&l);

if(l<=0){
	printf("Input l accordingly.\n");
}
	else {
		printf("Input x=");
		scanf("%f",&x);
		printf("Input y=");
		scanf("%f",&y);
		if((x>0 && y>0) && (x<l && y<l)){
			printf("Point is in the interior of the square.");
		}
		else {
				if(x>l || y>1 || x<0 || y<0){
			printf("Point is in the exterior of the square.");
		}	
		else {
			printf("Point is in the boundary of the square.");
		}
		}
	}
}
