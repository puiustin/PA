#include <stdio.h>

#include "mergesort.h"

int main(void)
{
    int n;

    printf("Introduceti numarul de elemente ale vectorului: ");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        printf("Introduceti al %d-lea element: ", i + 1);
        scanf("%d", &v[i]);
    }
    mergesort(v, 0, n - 1);
    printf("Elementele vectorului sunt: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
    printf("\n");
    return 0;
}