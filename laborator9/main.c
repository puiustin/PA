#include <stdio.h>

#include "graf.h"

int main(void)
{
    // GraphM *gm = createM();
    // printf("\n Matricea de adiacenta\n");
    // printGraphM(gm);
    // printf("\n-------------------------------\n");

    GraphL *gl = createL();
    printf("\n Lista \n");
    printGraphL(gl);
    printf("\n-------------------------------\n");

    // printf("MatrixToList\n");
    // GraphL *MtoL = MatrixToList(gm);
    // printGraphL(MtoL);
    // printf("\n");

    printf("ListToMatrix\n");
    GraphM *LtoM = listToMatrix(gl);
    printGraphM(LtoM);

    // freeGraphL(MtoL);
    freeGraphM(LtoM);

    return 0;
}