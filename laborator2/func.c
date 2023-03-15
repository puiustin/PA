#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "func.h"

void citire(MASINA *x)
{
    char aux[100];
    printf("Introduceti marca: \n");
    scanf("%s", aux);
    x->marca = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(x->marca, aux);
    printf("Introduceti pretul: \n");
    scanf("%d", &x->pret);
    printf("Introduceti numarul: \n");
    scanf("%s", x->numar);
}

void afisare(MASINA x)
{
    printf("Marca: %s - Pret: %d - Numar: %s\n", x.marca, x.pret, x.numar);
}

void setMarca(MASINA *x, char marca[32])
{
    strcpy(x->marca, marca);
}

void copie(MASINA *x, MASINA y)
{
    x->marca = malloc((strlen(y.marca) + 1) * sizeof(char));
    strcpy(x->marca, y.marca);
    x->pret = y.pret;
    strcpy(x->numar, y.numar);
}

int sumaLinie(MASINA **masini, int n, int linie)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s = s + masini[linie][i].pret;
    return s;
}

void sortare(MASINA *v, int n)
{
    MASINA aux;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
            if (v[i].pret > v[j].pret)
            {
                copie(&aux, v[j]);
                copie(&v[j], v[j + 1]);
                copie(&v[j + 1], aux);
            }
}

void fafisare(FILE *fisier, MASINA x)
{
    fprintf(fisier, "Marca: %s - Pret: %d - Numar: %s\n", x.marca, x.pret, x.numar);
}

void fcitire(FILE *fisier, MASINA *x)
{
    char aux[100];
    fgets(aux, 100, fisier);
    x->marca = malloc((strlen(aux) + 1) * sizeof(char));
    strcpy(x->marca, aux);
    fscanf(fisier, "%d", &x->pret);
    fgets(x->numar, 8, fisier);
}
