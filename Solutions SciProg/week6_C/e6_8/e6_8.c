#include "Eratosthenes.h"

Eratosthenes* doEratosthenesSieve(int nmax)
{
    Eratosthenes* eratosthenes = malloc(sizeof(Eratosthenes));
    eratosthenes->nmax = nmax;
    eratosthenes->nprimes = 0;
    eratosthenes->primes = malloc(sizeof(int) * nmax);

    int i;
    for (i = 0; i < nmax; i++)
        eratosthenes->primes[i] = 1; 
    for (i = 2; i < nmax; i++)
        if (eratosthenes->primes[i]) 
        {
            int j;
            for (j = i + i; j < nmax; j += i)
                eratosthenes->primes[j] = 0; 
        }
    for (i = 2; i < nmax; i++)
        if (eratosthenes->primes[i])
            eratosthenes->nprimes++; 
    return eratosthenes;
}

int main(){
    int n;
    printf("Input n= ");
    scanf("%d", &n);
    Eratosthenes* eratosthenes = doEratosthenesSieve(n);
    printf("The number of primes smaller than %d is %d\n", n, eratosthenes->nprimes);
    int i;
    printf("The primes are: \n");
    for (i = 2; i < eratosthenes->nmax; i++)
        if (eratosthenes->primes[i])
            printf("%d\n", i);
    return 0;
}
