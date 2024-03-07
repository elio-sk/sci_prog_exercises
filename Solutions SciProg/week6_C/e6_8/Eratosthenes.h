#ifndef ERATOSTHENES
#define ERATOSTHENES
#include <stdio.h>
#include <stdlib.h>

struct Eratosthenes {
    int nmax;
    int nprimes;
    int* primes;
};

typedef struct Eratosthenes Eratosthenes;

Eratosthenes* doEratosthenesSieve(int nmax);

#endif
