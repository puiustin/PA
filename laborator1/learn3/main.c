#include <stdio.h>
#include "functie.h"

int main()
{
    int n;
    printf("Introduceti un numar: ");
    scanf("%d", &n);
    printf("Factoriul de n este: %d\n", fact(n));
    return 0;
}