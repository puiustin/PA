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
                printf(" = ");
        }
        printf("\n");
    }
}

int isSafe(int **tabla, int row, int col, int n)
{
    int i, j;
    for (i = 0; i < col; i++)
        if (tabla[row][i])
            return 0;
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (tabla[i][j])
            return 0;
    for (i = row, j = col; j >= 0 && i < n; i++, j--)
        if (tabla[i][j])
            return 0;
    return 1;
}

int nRegine(int **tabla, int n, int col)
{
    if (col >= n)
        return 1;
    for (int i = 0; i < n; i++)
    {
        if (isSafe(tabla, i, col, n))
        {
            tabla[i][col] = 1;
            if (nRegine(tabla, n, col + 1))
            {
                return 1;
            }
            tabla[i][col] = 0;
        }
    }
    return 0;
}
