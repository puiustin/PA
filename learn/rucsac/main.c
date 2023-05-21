#include <stdio.h>

#include "Prob_Rucsac.h"

int main()
{
    Obiect obiecte[] = {
        {10, 60, 0.0},
        {20, 100, 0.0},
        {30, 120, 0.0}};
    int N = 3;
    int Gmax = 50;

    printf("Rezolvarea problemei intregi:\n");
    rezolvare(obiecte, N, Gmax);

    printf("\nRezolvarea problemei fractionare:\n");
    rezolvare2(obiecte, N, Gmax);

    return 0;
}
