#ifndef prob_rucsac_h
#define prob_rucsac_h

typedef struct
{
    int greutate;
    int profit;
    int raport;
} Obiect;

void rezolvare(Obiect obiecte[], int N, int Gmax);
void rezolvare2(Obiect obiecte[], int N, int Gmax);
#endif