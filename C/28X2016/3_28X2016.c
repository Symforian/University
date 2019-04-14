#include <stdio.h>
#include <stdlib.h>

int czyToRozmiarPlanszy();
int sprawdz(int rozmiar);
int main()
{
    char wsp[20][20];
    char literka='A';
    char ob=getchar();
    int plansza=0;
    int pomi,pomj,pom;
    int MB=0,MW=0;
    int b=0,w=0;
    while(ob!=EOF)
    {
        if(ob=='S' && plansza==0)
        {
            plansza=czyToRozmiarPlanszy();
            if(plansza != 0)
            for(int i =0;i<=plansza;i++)
                for(int j=0;j<=plansza;j++)
            {
                if(i==0 && j!=0)
                    wsp[i][j]=literka+j-1;
                else
                    if(i!=0 && j==0)
                    wsp[i][j]=literka+i-1;
                else if(i==0 && j==0)
                    wsp[i][j]=' ';
                else
                    wsp[i][j]='.';
            }
        }
        else if(ob==';')
        {
            ob=getchar();
            if(ob==EOF)
                break;
            else
                if(ob=='B')
            {
                pom=sprawdz(plansza);//1619 0405
                if(pom>0)
                    {
                        pomi=pom%100;
                        pomj=pom/100;
                        wsp[pomi][pomj]='X';
                    }
            }
            else
                if(ob=='W')
            {
                pom=sprawdz(plansza);//1619 0405
                if(pom>0)
                    {
                        pomi=pom%100;
                        pomj=pom/100;
                        wsp[pomi][pomj]='O';
                    }
            }
        }
        ob=getchar();
    }
                for(int i =0;i<=plansza;i++,printf("\n"))
                {
                    if(MB<b)
                        MB=b;
                    if(MW<w)
                        MW=w;
                    b=0;
                    w=0;
                    for(int j=0;j<=plansza;j++)
                {
                    printf("%c ",wsp[i][j]);
                    if(wsp[i][j]=='X')
                        b++;
                    else if(wsp[i][j]=='O')
                        w++;

                }
                }
                printf("%d %d",MB,MW);



    return 0;
}

int czyToRozmiarPlanszy()
{
    int wczytywana;
    int wynik;

        wczytywana=getchar();
        if(wczytywana=='Z')
        {
            wczytywana=getchar();
            if(wczytywana=='[')
            {
                wczytywana=getchar();
                if(wczytywana=='1')
                {
                    wynik=10;
                    wczytywana=getchar();
                    if(wczytywana>='0' && wczytywana<='9')
                        {
                            wynik+=(wczytywana-'0');
                            wczytywana=getchar();
                            if(wczytywana==']')
                                return wynik;
                        }

                }
                else if(wczytywana > '1' && wczytywana<='9')
                {
                    wynik=wczytywana-'0';
                    wczytywana=getchar();
                    if(wczytywana==']')
                        return wynik;
                }
            }
        }
        return 0;
}

int sprawdz(int rozmiar)
{

    int wynik=1;
    char pom;


    int wczytywana=getchar();
    if(wczytywana=='[')
    {
        for(int i = 0; i<=rozmiar;i++)
        {
            if(i==rozmiar)
                pom='a'+i-1;
        }
        wczytywana=getchar();
        if(wczytywana>='a' && wczytywana<=pom)
           {
            for(int i =1;i<=rozmiar;i++)
            if(wczytywana-i+1=='a')
           {
               wynik=100*i;
               break;
           }
            wczytywana=getchar();
                if(wczytywana>='a' && wczytywana<=pom)
           for(int i =1;i<=rozmiar;i++)
            if(wczytywana-i+1=='a')
           {
               wynik+=i;
               break;
           }
            wczytywana=getchar();
           if(wczytywana==']')
            return wynik;
           }
    }

    return 0;
}
/*
int zwracajnik(int rozmiar)
{
    switch(rozmiar)
{case 1:
    return 'a';
case 2:
    return 'b';
case 3:
    return 'c';
case 4:
    return 'd';
case 5:
    return 'e';
case 6:
    return 'f';
case 7:
    return 'g';
case 8:
    return 'h';
case 9:
    return 'i';
case 10:
    return 'j';
case 11:
    return 'k';
case 12:
    return 'l';
case 13:
    return 'm';
case 14:
    return 'n';
case 15:
    return 'o';
case 16:
    return 'p';
case 17:
    return 'q';
case 18:
    return 'r';
case 19:
    return 's';}
    return 0;
}

char zwracajnik2(char znak)
{
    if(znak=='a')
        return 1;
    if(znak=='b')
        return 2;
    if(znak=='c')
        return 3;
    if(znak=='d')
        return 4;
    if(znak=='e')
        return 5;
    if(znak=='f')
        return 6;
    if(znak=='g')
        return 7;
    if(znak=='h')
        return 8;
    if(znak=='i')
        return 9;
    if(znak=='j')
        return 10;
    if(znak=='k')
        return 11;
    if(znak=='l')
        return 12;
    if(znak=='m')
        return 13;
    if(znak=='n')
        return 14;
    if(znak=='o')
        return 15;
    if(znak=='p')
        return 16;
    if(znak=='q')
        return 17;
    if(znak=='r')
        return 18;
    if(znak=='s')
        return 19;
    return -1;

}*/
