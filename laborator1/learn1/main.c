#include "vector.h"
#include <stdio.h>

int main()
{
    int n;
    printf("Introduceti numarul de elemente al vectorului: \n");
    scanf("%d", &n);
    int *v = vec_alloc(n);
    printf("Introduceti elementele vectorului: \n");
    citire(v, n);
    sort(v, n);
    afisare(v, n);
    return 0;
}