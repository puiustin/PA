#ifndef Prob_Rucsac_h
#define Prob_Rucsac_h

typedef struct
{
    int greutate;
    int profit;
    float raport;
} Obiect;

int compara(const void *a, const void *b);
void rezolvare(Obiect obiecte[], int N, int Gmax);
void rezolvare2(Obiect obiecte[], int N, int Gmax);
void merge(Obiect array[], int left, int middle, int right);
void msort(Obiect array[], int left, int right);
#endif
