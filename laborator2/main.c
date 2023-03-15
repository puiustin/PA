#include <stdio.h>
#include <stdlib.h>

#include "func.h"

int main(void)
{
    FILE *fisier = fopen("fisier.txt", "w+");
    MASINA a,
        b;
    int n, linie;
    // citire(&a);
    // setMarca(&a, "BMW");
    // copie(&b, a);
    // afisare(b);

    printf("Introduceti numarul n pentru matrice: \n");
    scanf("%d", &n);
    MASINA **parcare = malloc(n * sizeof(MASINA *));
    for (int i = 0; i < n; i++)
        parcare[i] = malloc(n * sizeof(MASINA));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            citire(&parcare[i][j]);

    printf("Introduceti linia careia doriti sa ii aflati suma: \n");
    scanf("%d", &linie);
    printf("Suma liniei este: %d\n", sumaLinie(parcare, n, linie));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            afisare(parcare[i][j]);
            fafisare(fisier, parcare[i][i]);
        }

    MASINA *v = malloc(n * sizeof(MASINA));
    for (int i = 0; i < n; i++)
        copie(&v[i], parcare[i][i]);

    printf("Vectorul v contine urmatoarele automobile sortate: \n");
    sortare(v, n);
    for (int i = 0; i < n; i++)
        afisare(v[i]);

    return 0;
}