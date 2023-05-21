#include <stdio.h>
#include <stdlib.h>
#include "graf.h"

int main()
{
    int x, y;

    printf("Creare graf cu matrice de adiacenta:\n");
    GraphM *graphM = createM();
    printGraphM(graphM);

    printf("Creare graf cu lista de adiacenta:\n");
    GraphL *graphL = createL();
    printGraphL(graphL);

    printf("Transformare matrice de adiacenta in lista de adiacenta:\n");
    GraphL *graphMtoList = matriceToList(graphM);
    printGraphL(graphMtoList);

    printf("Transformare lista de adiacenta in matrice de adiacenta:\n");
    GraphM *graphLtoMatrix = listToMatrice(graphL);
    printGraphM(graphLtoMatrix);

    printf("Introduceti muchia x si y pentru a verifica daca exista (indicele incepe de la 0):\n");
    scanf("%d %d", &x, &y);
    if (existaMuchie(graphM, x, y))
    {
        printf("Exista o muchie intre %d si %d in grafM.\n", x, y);
    }
    else
    {
        printf("Nu exista o muchie intre %d si %d in grafM.\n", x, y);
    }

    printf("Afisarea muchiilor incidente cu x in grafM:\n");
    afisaremuchii(graphM, x);

    printf("Calculul matricei drumurilor pentru grafM folosind Algoritmul Roy-Warshall:\n");
    royWarshall(graphM);

    freeGraphM(graphM);
    freeGraphL(graphL);
    freeGraphM(graphLtoMatrix);
    freeGraphL(graphMtoList);

    return 0;
}
