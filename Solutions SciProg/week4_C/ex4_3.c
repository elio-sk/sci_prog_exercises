#include <stdio.h>

main () {
	double x,y,z,t;
	printf("Input x=");
    scanf("%lf",&x);
    printf("Input y=");
    scanf("%lf",&y);
    printf("Input z=");
    scanf("%lf",&z);
    if(x<y){
    	t=x;
    	x=y;
    	y=t;
	}
	if(y<z){
    	t=y;
    	y=z;
    	z=t;
	}
	if(x<y){
    	t=x;
    	x=y;
    	y=t;
	}
    printf("The sorted values are:\n x=%f \n y=%f \n z=%f \n",x,y,z);
}
