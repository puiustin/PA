#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "queen.h"

int main()
{
    int n = 8;
    int **tabla = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        tabla[i] = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            tabla[i][j] = 0;

    clock_t t;
    t = clock();
    if (nRegine(tabla, n, 0) == false)
    {
        printf("Solution does not exist");
        return false;
    }
    t = clock() - t;
    double elapsed = ((double)t) / CLOCKS_PER_SEC;

    afisare(tabla, n);
    printf("\nTimp executie: %0.6f secunde", elapsed);

    for (int i = 0; i < n; i++)
        free(tabla[i]);
    free(tabla);

    return 0;
}
