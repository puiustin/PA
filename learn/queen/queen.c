#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "queen.h"

void afisare(int **tabla, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (tabla[i][j] == 1)
                printf(" W ");
            else
                printf(" - ");
        }
        printf("\n");
    }
}

bool esteSigura(int **tabla, int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (tabla[row][i])
            return false;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tabla[i][j])
            return false;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (tabla[i][j])
            return false;
    return true;
}

bool nRegine(int **tabla, int n, int col)
{
    if (col >= n)
        return true;
    for (int i = 0; i < n; i++)
    {
        if (esteSigura(tabla, i, col, n))
        {
            tabla[i][col] = 1;
            if (nRegine(tabla, n, col + 1))
                return true;
            tabla[i][col] = 0;
        }
    }
    return false;
}

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
