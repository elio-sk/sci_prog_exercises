#include <stdio.h>

void points(double x, double y, double u, double v, double a, double b) {
	if(((b - v)*(u - x) == (v - y)*(a-u)))
	printf("Yes they lay on the same line.");
	else
	printf("No they don't lay in the same line.");
}

main (){
	double x,y,u,v,a,b;
	printf("Input x=");
    scanf("%lf",&x);
    printf("Input y=");
    scanf("%lf",&y);
    printf("Input u=");
    scanf("%lf",&u);
    printf("Input v=");
    scanf("%lf",&v);
    printf("Input a=");
    scanf("%lf",&a);
    printf("Input b=");
    scanf("%lf",&b);
	points(x,y,u,v,a,b);
}
