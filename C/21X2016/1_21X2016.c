//288477
//Lista 2
//zadanie 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c=1,licznik=0;
    while((a=getchar())!=EOF)                           //wczytuje kolejne znaki, az do EOF
        {
            if(c==0)                                    //gdy wczytany jest jeden pomijam sprawdzanie czy s¹ równe i ich wypisywanie/przekszta³canie
            {
                if(a==b)                                //jesli sa rowne zwiekszam licznik
                {
                    licznik++;
                }
                    else if(licznik>0)                  //jesli nie sa rowne sprawdzam czy poprzednie sprawdzane byly rowne, tzn czy licznik byl zwiekszony
                    {
                        printf("\n");                   //drukuje znak nowej linii, zeruje licznik
                        licznik=0;

                    }
                        else if(b<='Z' && b>='A')       //jesli poprzednia i obecna sa rozne wypisuje poprzednia jestli jest wielka litera zmieniam na mala
                        {
                            b+=' ';
                            putchar(b);
                        }
                            else if(b<='z' && b>='a')   // jesli jest mala litera zmieniam na wielk¹
                            {
                                b-=' ';
                                putchar(b);
                            }
                                else if(b==' ')         // jesli nie jest ani mala ani wielka litera tzn, ze jest "spacj¹" i zmieniam go na wykrzyknik
                                {                       // nie wiem czy ten "if" jest potrzebny poniewaz nie ma nic o cyfrach i nie wiem czy trzeba je przepisywac, ignorowac, czy ich nie bedzie
                                    b='!';
                                    putchar(b);
                                }



            }
            b=a;                                        //za poprzednia przyjmuje obecna
            if(c==1)     //                             //po czytaniu jednej "odblokowuje" sprawdzanie czy dwie sa rowne, wypisywanie itd.
                c=0;

        }
    return 0;
}
