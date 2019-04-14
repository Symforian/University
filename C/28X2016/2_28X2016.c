#include   <stdio.h>

int zzd(int liczba, int system);                                            //zamiana z dziesietnego

int potega (int podstawa, int stopien);

int main (void)
{
    printf("Podaj liczbe i jej system (oddzielone pojedyncza spacja)\n");
    char tablica[1000000];
    int przerywnik=2;
    int dlugosc=0;
    for(int i=0; i<1000000; i++)                                            //Wczytywanie xxxx...x yy, gdzie x jest dowolna ilosc a yy sa co najwyzej dwa
    {
        tablica[i]=getchar();                                               // gdzie xxxxx sa kolejnymi cyframi(znakami) liczby, a yy sa znakiem/znakami systemu

        if(tablica[i]==' ')
        {
            przerywnik--;                                                   //jesli wczytano spacje, oznacza to, ze rozpczyna sie wczytywanie systemu
        }
        else if(przerywnik == 1)
        {
            if(tablica[i]=='1')                                             // jesli zostala wczytana 1 to wczytaj jeszcze jeden znak (gdyz system jest co najmniej dziesietny
            {
                przerywnik--;                                               //w przeciwnym razie zakoncz
            }
            else if(tablica[i]=='9' ||tablica[i]=='8' ||tablica[i]=='7' ||tablica[i]=='6' ||tablica[i]=='5' ||tablica[i]=='4' ||tablica[i]=='3' ||tablica[i]=='2')
                {
                break;
                }
        }
        else if(przerywnik==0)                                              //po wczytaniu ostatniego znaku jesli pierwszy y byl 1 konczymy wczytywanie
        {
            break;
        } else
        dlugosc++;
    }
   int liczba=0;
   int system;
   if(tablica[dlugosc+1]!='1')                                              // jesli pierwszy y okreslajacy system nie jest jedynka to za system przyjmujemy ten y
            system=tablica[dlugosc+1]-'0';

   else
            system=10*(tablica[dlugosc+1]-'0')+tablica[dlugosc+2]-'0';      // w przeciwnym razie za system przyjmujemy 10*(pierwszy)y+(drugi)y

    int j=0;
    for(int i=dlugosc-1; i>=0;i--)                                          //zamiana na dziesietny
    {
        if(tablica[i]>='A' && tablica[i]<='F')                              //jesli znak jest litera od A do F to przyjmujemy kolejne wartosci od 10 do 15
        {
            tablica[i]-=7;                                                  //mozna by to bylo zrobic switchem aby nie odejmowac od ascii liczb
        }
        liczba=liczba+((potega(system,j))*(tablica[i]-'0'));
        j++;
    }
    system=10;                                                              //zamienilem na system 10 w powyzszej petli
        for(int i=2;i<=16;i++)                                              //zmieniam na kolejne systemy poczawszy od 2 az do 16
        {
            printf("Liczba w systemie %d\t to: \t",i);
            zzd(liczba,i);
            printf("\n");
        }




    return 0;
}
int potega (int podstawa, int stopien)
{
    int pom=1;
    if(podstawa>0)
    {
        for(int i = 1; i<=stopien; i++)
        pom*=podstawa;
    }
    else if(podstawa==0)
        {
            return pom;
        }
    return pom;

}

int zzd(int liczba, int system)
{
    int pom=system;
    int k=system-1;
    int licznik=0;
    while(liczba>=pom)
            pom*=system;
    pom/=system;
    while(licznik!=liczba || pom>0)
            {
                while(k>=0 )
                {
                    if((k*pom)+licznik<=liczba)
                    {
                        licznik+=(k*pom);
                        if(k>=10)
                        switch(k)
                        {
                            case 10:
                                printf("A");
                                break;
                            case 11:
                                printf("B");
                                break;
                            case 12:
                                printf("C");
                                break;
                            case 13:
                                printf("D");
                                break;
                            case 14:
                                printf("E");
                                break;
                            case 15:
                                printf("F");
                                break;
                        }
                            else
                        printf("%d",k);
                        k=-1;
                    }
                    else
                        k--;
                }
                k=system-1;
                pom/=system;
            }
            return 0;
}
