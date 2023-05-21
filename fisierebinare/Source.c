#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct
{
	int nrmat;
	char numeprenume[30];
	int grupa;
	char pp;
	char teme[10];
	char ex;
} STUDENT;

void lista_studenti(FILE *f)
{
	char numefisier[30];
	STUDENT s;
	int i, nr;
	nr = 0;
	FILE *g;
	printf("\nIntroduceti fisierul text: ");
	fgets(numefisier, 20, stdin);
	g = fopen(numefisier, "w");
	fprintf(g, "\nNr.  Nr. Mat Nume %15s          Grupa PP       Punctaj Teme           Examen ", " ");
	fread(&s, sizeof(STUDENT), 1, f);
	while (!feof(f))
	{
		fprintf(g, "\n%3d %8d %-30s %2d %2d", ++nr, s.nrmat, s.numeprenume, s.grupa, s.pp);
		for (i = 0; i < 10; i++)
			fprintf(g, "%2d ", s.teme[i]);
		fprintf(g, "%6d ", s.ex);
		fread(&s, sizeof(STUDENT), 1, f);
	}
	fclose(g);
}

int main()
{
	FILE *f;
	char numefisier[30];
	STUDENT s;
	int n;
	printf("Introduceti fisierul binar: ");
	scanf("%s", numefisier);
	fflush(stdin);
	f = fopen(numefisier, "r+b");
	if (!f)
		printf("\nFisierul %s nu exista.", numefisier);
	else
		lista_studenti(f);
	fclose(f);

	return 0;
}
