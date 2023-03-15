#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"

int **mat_alloc(int l, int c)
{
    int **m = malloc(l * sizeof(int *));
    for (int i = 0; i < l; i++)
        m[i] = (int *)calloc(c, sizeof(int));
    return m;
}

void citire(int **m, int l, int c)
{
    for (int i = 0; i < l; i++)
        for (int j = 0; j < c; j++)
        {
            printf("m[%d][%d] = ", i, j);
            scanf("%d", &m[i][j]);
        }
}

int **patrat(int **m, int l, int c)
{
    if (l != c)
        return NULL;
    else
    {
        int **p = mat_alloc(l, c);
        for (int i = 0; i < l; i++)
            for (int j = 0; j < c; j++)
                for (k = 0; k < l; k++)

                    return p;
    }
}

int sumadiag(int **m, int l, int c)
{
    int s = 0;
    for (int i = 0; i < l; i++)
        s = s + m[i][i];
    return s;
}

void afisare(int **m, int l, int c)
{
    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < c; j++)
            printf("%d ", m[i][j]);
        printf("\n");
    }
}