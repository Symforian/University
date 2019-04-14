#include <stdio.h>
#include <stdlib.h>


int *MaxElem (int*tab,int n);
double Srednia (int *tab,int n);
void Wypisz (int *tab,int n);
void Sortuj (int *tab, int n);
int ileParzystych (int *tab,int n);
void Odwroc (int *tab,int n);


int main()
{
    int *Ptr;
    int n,i;
    scanf("%d",&n);
    Ptr = (int*) malloc (n*sizeof(int));
    if (Ptr==NULL)
        return 0;
    for (i=0; i<n; i++)
    {
        scanf ("%d",&Ptr[i]);
    }
    for (i=0; i<n; i++)
        printf ("%d ",Ptr[i]);
    printf("\n");
    printf ("Wskaznik na maksymalny element %p\n",MaxElem(Ptr,n));
    printf("Maksymalny element %d\n",*MaxElem(Ptr,n));
    printf("Srednia arytmetyczna %g\n", Srednia(Ptr,n));
    printf ("Funkcja wypisujaca ");
    Wypisz (Ptr,n);
    printf("\n");
    printf("Funkcja sortujaca ");
    Sortuj (Ptr,n);
    Wypisz (Ptr,n);
    printf("\n");
    printf ("Elementow parzystych %d\n", ileParzystych(Ptr,n));
    printf("Odwrocona tablica ");
    Odwroc (Ptr,n);
    Wypisz (Ptr,n);
    printf("\n");
    free (Ptr);
    return 0;
}
int *MaxElem (int*tab,int n)
{
    int max=0;
    for (int i=0; i<n; i++)
    {
        if (tab[i]>tab[max]) max=i;
    }

    return &tab[max];
}
double Srednia (int *tab,int n)
{
    if (n==0) return 0;
    double srednia=0;
    for (int i=0; i<n; i++) srednia+=tab[i];
    srednia=srednia/n;
    return srednia;
}
void Wypisz (int *tab, int n)
{
    printf("%d ",n);
    for (int i=0; i<n; i++)
    {
        printf("%d ",tab[i]);
    }
}
void Sortuj (int *tab, int n)
{
    int i=0;
    int j=0;
    int a;
    for (i=0; i<n-1; i++)
    {
        for (j=0; j<n-i-1; j++)
        {
            if (tab[j]<tab[j+1])
            {
                a = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = a;
            }
        }
    }
}
int ileParzystych (int *tab,int n)
{
    int parzyste=0;
    for (int i=0; i<n; i++)
    {
        if (tab[i]%2==0) parzyste++;
    }
    return parzyste;
}
void Odwroc (int *tab, int n)
{
    int j=n-1;
    int i=0;
    int pom;
    while(i<j)
    {
        pom=tab[i];
        tab[i]=tab[j];
        tab[j]=pom;
        i++;
        j--;
    }
}
