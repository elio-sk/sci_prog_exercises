#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

double* scanVector(int length) {
int j = 0;
double* vector = NULL;
assert(length > 0);

vector = malloc(length*sizeof(double));
assert(vector != NULL);
for (j=0; j<length; ++j) {
vector[j] = 0;
printf("vector[%d] = ", j);
scanf("%lf", &vector[j]);
}
return vector;
}

void printVector(double* vector, int length) {
int j = 0;
assert(vector != NULL);
assert(length > 0);

for (j=0; j<length; ++j) {
printf("vector[%d] = %f\n", j, vector[j]);
}
}

double* cut(double *x, int *n, double cmin, double cmax) {
int i=0; int k=0;
for (i=0; i<*n; i++) {
    if (x[i]<cmin || x[i]>cmax) {
        for (k=i; k<(*n)-1; k++) {
            x[k] = x[k+1];
        }
        (*n)--;
    }
    
}
return x;
}



void main(){
double cmin=0.0; double cmax=0.0;
double *x=NULL;
int dim=0;

printf("dim = ");
scanf("%d", &dim);
    
printf("cmin =");
scanf("%f", &cmin);
printf("cmax =");
scanf("%f", &cmax);
assert(cmin < cmax);

    x = scanVector(dim);
    printVector(x, dim);



x=cut(x, &dim, cmin, cmax);
printf("\n\n");
printVector(x, dim);


}


