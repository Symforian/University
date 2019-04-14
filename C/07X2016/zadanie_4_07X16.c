//288477
//lista A
//zadanie 4

#include <stdio.h>

int zlicz_dlugosc(int n)
{
    int dlugosc=0;

    for(int i=0; n>0; i++)
    {
        n=n/10;
        dlugosc++;
    }
    return dlugosc;

}


int potega(int n, int st)
{
    int pom=n;

    for(int i=1; i<st; i++)
        pom*=n;
    return pom;
}


int suma_poteg(int n, int st)
{
    int suma=0;

    for(int i=0; n>0; i++)
    {
        suma+=potega(n%10,st);
        n/=10;
    }

    return suma;
}


int main(void)
{
    int n, dlugosc;

    scanf("%d",&n);

    dlugosc=zlicz_dlugosc(n);

    if(suma_poteg(n,dlugosc)==n)
        printf("TAK\n");
        else
            printf("NIE\n");

    return 0;
}
