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

    for (int i = 0; i < n; i++)
        for (int j = n - 1; j >= 0; j--)
        {
            int aux = 0;
            clock_t t;
            t = clock();
            nRegine(tabla, j, i, &aux);
            t = clock() - t;
            double elapsed = ((double)t) / CLOCKS_PER_SEC;
            if (n == aux)
            {
                afisare(tabla, n);
                printf("\nTimp executie: %0.6f secunde\n", elapsed);
            }
        }

    for (int i = 0; i < n; i++)
        free(tabla[i]);
    free(tabla);

    return 0;
}
