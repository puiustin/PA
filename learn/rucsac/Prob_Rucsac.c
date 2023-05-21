// Prob_Rucsac.c
#include <stdio.h>
#include <stdlib.h>
#include "Prob_Rucsac.h"

void rezolvare(Obiect obiecte[], int N, int Gmax)
{
    for (int i = 0; i < N; i++)
    {
        obiecte[i].raport = (float)obiecte[i].profit / obiecte[i].greutate;
    }

    msort(obiecte, 0, N - 1);

    int greutateCurenta = 0;
    for (int i = 0; i < N; i++)
    {
        if (greutateCurenta + obiecte[i].greutate <= Gmax)
        {
            greutateCurenta += obiecte[i].greutate;
            printf("Adaugam obiectul cu greutatea %d si profitul %d.\n", obiecte[i].greutate, obiecte[i].profit);
        }
    }
}

void rezolvare2(Obiect obiecte[], int N, int Gmax)
{
    for (int i = 0; i < N; i++)
    {
        obiecte[i].raport = (float)obiecte[i].profit / obiecte[i].greutate;
    }

    msort(obiecte, 0, N - 1);

    int greutateCurenta = 0;
    for (int i = 0; i < N; i++)
    {
        if (greutateCurenta + obiecte[i].greutate <= Gmax)
        {
            greutateCurenta += obiecte[i].greutate;
            printf("Adaugam obiectul cu greutatea %d si profitul %d.\n", obiecte[i].greutate, obiecte[i].profit);
        }
        else
        {
            int ramas = Gmax - greutateCurenta;
            printf("Adaugam o fractie de %f din obiectul cu greutatea %d si profitul %d.\n",
                   (float)ramas / obiecte[i].greutate, obiecte[i].greutate, obiecte[i].profit);
            break;
        }
    }
}

void merge(Obiect array[], int left, int middle, int right)
{
    int n1 = middle - left + 1;
    int n2 = right - middle;
    Obiect *left_array = malloc(n1 * sizeof(Obiect));
    Obiect *right_array = malloc(n2 * sizeof(Obiect));

    for (int i = 0; i < n1; i++)
        left_array[i] = array[left + i];
    for (int i = 0; i < n2; i++)
        right_array[i] = array[middle + 1 + i];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (left_array[i].raport >= right_array[j].raport)
        {
            array[k] = left_array[i];
            i++;
        }
        else
        {
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = right_array[j];
        j++;
        k++;
    }
    free(left_array);
    free(right_array);
}

void msort(Obiect array[], int left, int right)
{
    int middle;
    if (left < right)
    {
        middle = (left + right) / 2;
        msort(array, left, middle);
        msort(array, middle + 1, right);
        merge(array, left, middle, right);
    }
}
