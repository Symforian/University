#include <stdio.h>
#include <stdlib.h>

struct ulamek
{
    int calkowita;
    int licznik;
    int mianownik;
};

int NWW(int a,int b);
int NWD(int a, int b);

struct ulamek utworz(int licznik,int mianownik);
struct ulamek suma(struct ulamek a,struct ulamek b);
struct ulamek roznica(struct ulamek a,struct ulamek b);
struct ulamek iloczyn(struct ulamek a,struct ulamek b);
struct ulamek iloraz(struct ulamek a,struct ulamek b);
struct ulamek uprosc(struct ulamek a); // uzyj funkcji nwd
void wypisz(struct ulamek a);


int main(void)
{
    struct ulamek a,b,c;
    int licznik,mianownik;
    printf("Podaj licznik mianownik (ulamka pierwszego) oraz licznik mianownik (ulamka drugiego) (oddzielone podjedyncza spacja)\n");
    scanf("%d%d",&licznik,&mianownik);
    a=utworz(licznik,mianownik);
    scanf("%d%d",&licznik,&mianownik);
    b=utworz(licznik,mianownik);
    printf("Pierwszy ulamek: ");
    wypisz(a);
    printf("Pierwszy ulamek po uproszczeniu: ");
    wypisz(uprosc(a));
    printf("\nDrugi ulamek: ");
    wypisz(b);
    printf("Drugi ulamek po uproszczeniu: ");
    wypisz(uprosc(b));
    c=suma(a,b);
    printf("\nSuma ulamkow: ");
    wypisz(c);
    printf("Suma ulamkow po uproszczeniu: ");
    wypisz(uprosc(c));
    c=roznica(a,b);
    printf("\nRoznica ulamkow: ");
    wypisz(c);
    printf("Roznica ulamkow po uproszczeniu: ");
    wypisz(uprosc(c));
    c=iloczyn(a,b);
    printf("\nIloczyn ulamkow: ");
    wypisz(c);
    printf("Iloczyn ulamkow po uproszczeniu: ");
    wypisz(uprosc(c));
    c=iloraz(a,b);
    printf("\nIloraz ulamkow: ");
    wypisz(c);
    printf("Iloraz ulamkow po uproszczeniu: ");
    wypisz(uprosc(c));
    printf("\n");

    return 0;
}

struct ulamek utworz(int licznik,int mianownik)
{
    struct ulamek a;
    a.calkowita=0;
    if(licznik<0 && mianownik<0)
        {
            licznik*=-1;
            mianownik*=-1;
        }
    else
        if(mianownik<0)
        {
            mianownik*=-1;
            licznik*=-1;
        }

    a.licznik=licznik;
    a.mianownik=mianownik;
    if(mianownik==0)
    {   printf("Mianownik nie moze byc rowny 0\n");
        exit(1);
    }
    return a;
}

struct ulamek suma(struct ulamek a,struct ulamek b)
{
    struct ulamek suma;
    if(a.mianownik==b.mianownik)
    {
        suma.mianownik=a.mianownik;
        suma.licznik=a.licznik+b.licznik;
    }
    else
    {
        suma.mianownik=NWW(a.mianownik,b.mianownik);
        a.licznik=b.mianownik*a.licznik;//3/4  1/5   15/20 + 4/20
        b.licznik=a.mianownik*b.licznik;
        suma.licznik=a.licznik+b.licznik;
    }
    suma.calkowita=0;
    return suma;
}
struct ulamek roznica(struct ulamek a,struct ulamek b)
{
        struct ulamek rozn;
    if(a.mianownik==b.mianownik)
    {
        rozn.mianownik=a.mianownik;
        rozn.licznik=a.licznik-b.licznik;
    }
    else
    {
        rozn.mianownik=NWW(a.mianownik,b.mianownik);
        a.licznik=b.mianownik*a.licznik;//3/4  1/5   15/20 + 4/20
        b.licznik=a.mianownik*b.licznik;
        rozn.licznik=a.licznik-b.licznik;
    }
    rozn.calkowita=0;
    return rozn;
}
struct ulamek iloczyn(struct ulamek a,struct ulamek b)
{
        struct ulamek iloc;
        iloc.calkowita=0;
        iloc.mianownik=a.mianownik*b.mianownik;
        iloc.licznik=a.licznik*b.licznik;
    return iloc;
}
struct ulamek iloraz(struct ulamek a,struct ulamek b)
{
    struct ulamek pom;
    pom.licznik=b.mianownik;
    pom.mianownik=b.licznik;
    pom.calkowita=0;
    return iloczyn(a,pom);
}
struct ulamek uprosc(struct ulamek a)
{
    int pom;
    if(a.licznik>=a.mianownik)
        {
            a.calkowita=a.licznik/a.mianownik;
            a.licznik-=(a.mianownik*a.calkowita);
        }
        pom=NWD(a.licznik,a.mianownik);
    if(pom!=1)
            {
            a.licznik/=pom;
            a.mianownik/=pom;
            }
        if(a.licznik<0 && a.mianownik<0)
        {
            a.licznik*=-1;
            a.mianownik*=-1;
        }
    else
        if(a.mianownik<0)
        {
            a.mianownik*=-1;
            a.licznik*=-1;
        }
        return a;


}
int NWW(int a,int b)
{
    int k=1, l=1;
    while(k*a!=l*b)
    {
        if(k*a<l*b)
            k++;
        else
            l++;
    }
    return k*a;
}
int NWD(int a, int b)
{
    int c;
    if(b>a)
        {
            c=a;
            a=b;
            b=c;
        }
    while(b!=0)
    {
        c=a%b;
        a=b;
        b=c;

    }
    return a;
}

void wypisz(struct ulamek a)
{
    if(a.calkowita!=0)
        {
            printf("%d ",a.calkowita);
            if(a.licznik==0)
                printf("\n");
        }
    if(a.licznik!=0)
        printf("%d/%d\n",a.licznik,a.mianownik);
    if(a.calkowita==0 && a.licznik==0)
        printf("0\n");
}
