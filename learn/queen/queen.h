#ifndef queen_h
#define queen_h

#include <stdbool.h>

void afisare(int **tabla, int n);
bool esteSigura(int **tabla, int row, int col, int n);
bool nRegine(int **tabla, int n, int col);

#endif
