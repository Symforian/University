#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
bool czy_pierwsza(int liczba);

int main()
{
    int n;
    scanf("%d",&n);
    if(czy_pierwsza(n))
        {
            printf("%d^1\n",n);
            return 0;
        }
    else
    {
        int licznik=0;
        int pomi=0;
        for(int i=2;n>1;i++)
        {
            while(!czy_pierwsza(i))
                i++;
            if(czy_pierwsza(i))
            {
                pomi=i;
                if(n%i==0)
                {
                    n/=i;
                    licznik++;
                    if(n!=1)
                        --i;
                }
                if(pomi==i && licznik>0)
                {
                    printf("%d^%d",i,licznik);
                    licznik=0;
                    if(n!=1)
                        {
                            printf("*");
                            if(czy_pierwsza(n))
                                {
                                    printf("%d^1\n",n);
                                    return 0;
                                }
                        }
                }
            }
        }

        printf("\n");

    }
    return 0;
}

bool czy_pierwsza(int liczba)
{

    for(int i=2;i*i<=liczba;i++)
    {
        if(liczba%i==0)
            return false;
    }
    return true;

}


/*
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int tab[100000000]={0};

bool czy_pierwsza(int liczba);

int potega(int liczba, int wykladnik);

int main()
{
    int n;
    scanf("%d",&n);
    if(czy_pierwsza(n))
        {
            printf("%d^1\n",n);
            return 0;
        }
    else
    {
        int pom=n;
        pom=n;

        for(int i=2;pom>1;i++)
        {
            if((czy_pierwsza(i)) && pom%i==0)
            {
                pom/=i;
                tab[i]++;
                --i;
            }
        }
        for(int i=2;i<=99999999;i++)
        {
            if(tab[i]>0)
                {
                    printf("%d^%d",i,tab[i]);
                    pom*=potega(i,tab[i]);
                    if(pom<n)
                        {
                            printf("*");
                        }
                }

        }
        printf("\n");

    }
    return 0;
}

bool czy_pierwsza(int liczba)
{
    int pom=sqrt((float)liczba);
    for(int i=2; i<=pom;i++)
    {
        if(liczba%i==0)
            return 0;
    }
    return 1;
}

int potega(int liczba, int wykladnik)
{
    int wynik=1;
    for(int i=1;i<=wykladnik;i++)
    {
        wynik*=liczba;
    }
    return wynik;
}
*/

