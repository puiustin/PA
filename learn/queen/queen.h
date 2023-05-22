#ifndef queen_h
#define queen_h

#include <stdbool.h>

void afisare(int **tabla, int n);
int isSafe(int **tabla, int row, int col, int n);
int nRegine(int **tabla, int n, int col);

#endif
