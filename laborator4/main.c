#include <stdio.h>

#include "list.h"

int main()
{
    Node *lista = createlist();

    Punct punct1 = {"punct_1", 0.0, 0.0};
    Punct punct2 = {"punct_2", 1.0, 0.0};
    Punct punct3 = {"punct_3", 1.0, 1.0};
    Punct punct4 = {"punct_4", 0.0, 1.0};

    Punct modific = {"punct_50", 50.0, 30.0};

    addonpos(lista, punct1, 0);
    addonpos(lista, punct2, 1);
    addonpos(lista, punct3, 2);
    addonpos(lista, punct4, 3);

    printf("Perimetru: %f\n", perimetru(lista));
    printf("Lista inainte de stergere: \n");
    afisare(lista);

    delonpos(lista, 1);

    printf("Lista dupa stergere: \n");
    afisare(lista);

    modifyonpos(lista, modific, 1);
    printf("Lista dupa modificare: \n");
    afisare(lista);

    deletelist(lista);
    return 0;
}