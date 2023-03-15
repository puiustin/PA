#include <stdio.h>
#include "matrice.h"

int main()
{
    int l, c;
    printf("Introduceti numarul de linii si de coloane ale matricei: \n");
    scanf("%d %d", &l, &c);
    int **m = mat_alloc(l, c);
    int **aux = mat_alloc(l, c);
    citire(m, l, c);
    aux = patrat(m, l, c);
    sumadiag(m, l, c);
    afisare(aux, l, c);
    return 0;
}