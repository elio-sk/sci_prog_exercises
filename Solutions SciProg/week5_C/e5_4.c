#include <stdio.h>
#include <assert.h>
#include <math.h>

int max(int x,int y) {
	int maximum;
	if(x>y){
		maximum=x;
	}
	else{
		maximum=y;
	}
	return maximum;
}

int lcm(int x,int y){
	int m=max(x,y);
		while (1) {
		if ( m % x == 0 && m % y == 0) {
			break;
		}
		++m;
	}
	return m;
}
void main() {

    int a, b;
    printf("Enter integer a= ");
    scanf("%d", &a);
    printf("Enter integer b= ");
    scanf("%d", &b);
    printf("The least common divisor of %d and %d is %d.", a, b, lcm(a, b));
}
//test a=4 b=5
