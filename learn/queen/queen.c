#include <stdio.h>
#include <stdlib.h>
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
