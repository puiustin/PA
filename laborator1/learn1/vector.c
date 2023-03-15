#include "../../Desktop/learn1/vector.h"
#include <stdio.h>
#include <stdlib.h>

int *vec_alloc(int n) {
    int *a = (int *) calloc(n, sizeof(int));
    return a;
}

void citire(int *x, int n) {
    for (int i = 0; i < n; i++)
        scanf("%d", x + i);
}

void sort(int *x, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = i; j < n; j++)
            if (*(x + i) > *(x + j)) {
                int aux = *(x + i);
                *(x + i) = *(x + j);
                *(x + j) = aux;
            }
}

void afisare(int *x, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", *(x + i));
}