#ifndef func
#define func
struct Masina
{
    // daca e nume compus se citeste cu cratima
    // e.g., Aston Martin se va introduce ca  Aston-Martin
    char *marca; /*daca numele e compus se citeste cu underscore: AAA_BBB*/
    int pret;
    char numar[8]; /* e.g., IF09BCX, B89FMH*/
};
typedef struct Masina MASINA;
void citire(MASINA *x);
void afisare(MASINA x);
void setMarca(MASINA *x, char marca[32]);
void copie(MASINA *x, MASINA y);
int sumaLinie(MASINA **masini, int n, int linie);
void sortare(MASINA *v, int n);
void fafisare(FILE *fisier, MASINA x);
void fcitire(FILE *fisier, MASINA *x);

#endif