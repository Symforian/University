#include <stdio.h>
#include <stdlib.h>
typedef struct e_drzewa *Wsk_drzewa;
typedef struct e_drzewa {
double liczba;
int ile_razy;
Wsk_drzewa lewy;
Wsk_drzewa prawy;
} Wezel_drzewa;
static Wsk_drzewa dopisz_liczbe(Wsk_drzewa p,double dana);
static int wypisz_drzewo(Wsk_drzewa p,int n);
static void usun_drzewo(Wsk_drzewa p);
int main(void)
{
Wsk_drzewa Korzen=NULL;
double dana;
while (scanf("%lf",&dana) == 1)
Korzen=dopisz_liczbe(Korzen,dana);
wypisz_drzewo(Korzen,0);
usun_drzewo(Korzen);
putchar('\n');
return 0;
}
static Wsk_drzewa dopisz_liczbe(Wsk_drzewa korzen,double dana)
{
Wsk_drzewa *pop,akt;
for (pop=&korzen,akt=korzen; akt != NULL; )
if (dana < akt->liczba)
pop=&akt->lewy, akt=akt->lewy;
else if (dana > akt->liczba)
pop=&akt->prawy, akt=akt->prawy;
else {
++akt->ile_razy;
return korzen;
}
if ((akt=(Wsk_drzewa)malloc(sizeof(Wezel_drzewa))) == NULL) {
fprintf(stderr,"Brak pamieci w stercie dla %lf\n",dana);
exit(1);
}
akt->liczba=dana;
akt->ile_razy=1;
akt->lewy=akt->prawy=NULL;
*pop=akt;
return korzen;
}
static int wypisz_drzewo(Wsk_drzewa p,int n)
{
if (p != NULL) {
n=wypisz_drzewo(p->lewy,n);
for (int i=p->ile_razy; i > 0; --i)
printf("%.2lf%c",p->liczba,(++n%8 ? ' ' : '\n'));
n=wypisz_drzewo(p->prawy,n);
}
return n;
}
static void usun_drzewo(Wsk_drzewa p)
{
if (p != NULL) {
usun_drzewo(p->lewy);
usun_drzewo(p->prawy);
free(p);
}
}

