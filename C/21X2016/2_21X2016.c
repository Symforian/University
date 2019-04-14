//288477
//Lista 2
//zadanie 2
#include <stdio.h>
#include <stdlib.h>


int main()
{
    int a,b,c=1,pom=0,licznik=0,zn=0,lit=0,cyfr=0,wyr=0,zn_b=0,w_lit=0,m_lit=0,sam=0,spol=0,zn_prz=0;
    while((a=getchar())!=EOF)                           //wczytuje kolejne znaki, az do EOF
        {
            pom=lit;
            zn++;                                       //liczenie znakow wszystkich
            if(c==0)                                    //liczenie wyrazow
            {
               if(a<='z'&& a>='A'&& b<='z'&& b>='A')
                licznik++;
               else if(licznik>0)
               {
                   licznik=0;
                   wyr++;
               }

            }
            b=a;                                        //za poprzednia przyjmuje obecna
            if(b>='0'&&b<='9')
                cyfr++;
                else if(b<='z'&&b>='a')                 //liczenie malych liter i liter ogolnie
                {
                    m_lit++;
                    lit++;
                }
                    else if(b<='Z'&&b>='A')             //liczenie wielkich liter i liter ogolnie
                    {
                        w_lit++;
                        lit++;
                    }
                    else if(b==','||b=='.'||b==':'||b=='!'||b=='?') //liczenie zn przestankowych
                        zn_prz++;
                        else if(b==' '||b==9|| b==10 || b==11 || b==12 || b==13)         //liczenie zn bialych
                            zn_b++;
            if(pom<lit)
                {
                    if(b=='a'||b=='A'||b=='e'||b=='E'||b=='y'||b=='Y'||b=='u'||b=='U'||b=='i'||b=='I'||b=='o'||b=='O')
                        sam++;
                    else
                        spol++;
                }
            if(c==1)     //                             //po czytaniu jednej "odblokowuje" sprawdzanie czy dwie sa rowne, wypisywanie itd.
                c=0;

        }
        printf("\nLiczba znakow wynosi %d\nLiczba liter wynosi %d",zn,lit);             //WERSJA Z TEKSTEM
        printf("\nLiczba cyfr wynosi %d\nLiczba wyrazow wynosi %d",cyfr,wyr);
        printf("\nLiczba bialych znakow wynosi %d\nLiczba samoglosek wynosi %d",zn_b,sam);
        printf("\nLiczba spolglosek wynosi %d\nLiczba wielkich liter wynosi %d",spol,w_lit);
        printf("\nLiczba malych liter wynosi %d\nLiczba znakow przestankowych wynosi %d",m_lit,zn_prz);
       // printf("\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d",zn,lit,cyfr,wyr,zn_b,sam,spol,w_lit,m_lit,zn_prz); //WERSJA BEZ TEKSTU
    return 0;
}
