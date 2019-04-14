#include <stdio.h>
#include <stdlib.h>


int main()
{
    char liczba_1[130]= {'0'};

    char liczba_2[130]= {'0'};
    char a,b;
    int zmiennik=0;
    int dlugosc_1=0;
    int dlugosc_2=0;
    int pomin1raz=1;
    int zer1=0,zer2=0;
    int pom=0;
    int znak=0;
    int znak_1=0;
    int licznik=0;
    int znak_2=0;
    b=getchar();
    while(b!=EOF)
    {
        if(pomin1raz!=1)
        {
            if(licznik<2)
            {
                if((a>='0' && a<='9') || a==' ' || a=='+' || a=='-')                             //jesli jest cyfra lub znakiem
                {
                    if(znak==0)                         //jesli nie znamy jej znaku
                    {
                        if(a=='-')                  //znak jest ujemny
                        {
                            if(zmiennik==0)         //jesli to pierwsza liczba
                            {
                                znak_1=-1;
                                znak=1;
                            }
                            else                    //jesli to druga liczba
                            {
                                znak_2=-1;
                                znak=1;
                            }
                        }
                        else if(a==' ' || a=='+'||a=='0')                       //znak jest dodatni
                        {
                            if(zmiennik==0)         //pierwsza liczba
                            {
                                znak=1;
                                znak_1=1;
                                if(a=='0')
                                    zer1++;
                            }
                            else                    //druga liczba
                            {
                                znak=1;
                                znak_2=1;
                                if(a=='0')
                                    zer2++;
                            }
                        }else
                            if(zmiennik==0)                 //pierwsza liczba
                                {
                                    liczba_1[dlugosc_1]=a;
                                    dlugosc_1++;
                                }
                                else                            //druga liczba
                                {
                                    liczba_2[dlugosc_2]=a;
                                    dlugosc_2++;
                                }
                            }
                        }

                    else if(a>='0' && a<='9')           //jesli znamy znak to kolejne cyfry wpisujemy do tablicy
                    {
                        if(zmiennik==0)                 //pierwsza liczba
                        {
                            if(a=='0' && dlugosc_1==0)
                            {
                                zer1++;
                            }else
                            {liczba_1[dlugosc_1]=a;
                            dlugosc_1++;
                        }}
                        else                            //druga liczba
                        {
                            if(a=='0'&&dlugosc_2==0)
                            {
                                zer2++;
                            }else
                            {liczba_2[dlugosc_2]=a;
                            dlugosc_2++;}
                        }
                    }
                    else
                    {
                        if(zmiennik==0)             //pierwsza liczba
                        {
                            zmiennik=1;
                            znak=0;
                            licznik++;
                        }
                        else                        //druga liczba
                        {
                            zmiennik=0;
                            znak=0;
                            licznik++;
                        }
                    }
            }
            else //mamy dwie liczby
            {
                if(znak_1<znak_2)
                {
                    while(dlugosc_2>=0)
                    {
                        liczba_2[dlugosc_2]='0';
                        dlugosc_2--;
                    }
                        znak_2=0;
                        zmiennik=1;
                        zer2=0;
                        licznik--;
                        dlugosc_2=0;
                }
                else if(znak_2<znak_1)
                {
                    while(dlugosc_1>=0)
                    {
                        liczba_1[dlugosc_1]='0';
                        dlugosc_1--;
                    }
                        znak_1=0;
                        zmiennik=0;
                        zer1=0;
                        licznik--;
                        dlugosc_1=0;
                }
                else                                            //znaki sa takie same
                {
                    if(dlugosc_1<dlugosc_2)                 //jesli maja rozna dlugosc
                    {
                        while(dlugosc_2>=0)
                        {
                            liczba_2[dlugosc_2]='0';
                            dlugosc_2--;
                        }
                            znak_2=0;
                            zmiennik=1;
                            zer2=0;
                            licznik--;
                            dlugosc_2=0;
                    }
                    else                                    //rozna dlugosc
                        if(dlugosc_2<dlugosc_1)
                        {
                            while(dlugosc_1>=0)
                            {
                                liczba_1[dlugosc_1]='0';
                                dlugosc_1--;
                            }
                                znak_1=0;
                                zmiennik=0;
                                zer1=0;
                                licznik--;
                                dlugosc_1=0;
                        }
                        else if(znak_1==1)                          //sa dodatkie
                        {

                            while(pom<=dlugosc_1)
                            {
                                if(liczba_1[pom]<liczba_2[pom])
                                {
                                    while(dlugosc_2>=0)
                                    {
                                        liczba_2[dlugosc_2]='0';
                                        dlugosc_2--;
                                    }
                                        znak_2=0;
                                        zmiennik=1;
                                        zer2=0;
                                        licznik--;
                                        dlugosc_2=0;
                                    break;

                                }
                                else if(liczba_2[pom]<liczba_1[pom])
                                {
                                    while(dlugosc_1>=0)
                                    {
                                        liczba_1[dlugosc_1]='0';
                                        dlugosc_1--;
                                    }
                                        znak_1=0;
                                        zmiennik=0;
                                        zer1=0;
                                        licznik--;
                                        dlugosc_1=0;
                                    break;

                                }
                                pom++;
                            }
                        }
                        else                                //sa ujemne
                        {

                        }
                }
                znak=0;
            }

        }
        pomin1raz=0;
        a=b;
        b=getchar();
    }

    if(liczba_1[0]!='0')
    {
        if(znak_1<0)
            printf("-");

        for(int i=0; i<dlugosc_1; i++)
        {
            printf("%c",liczba_1[i]);
        }
    }
    else
    {
        if(znak_2<0)
            printf("-");
        for(int i=0; i<dlugosc_2; i++)
        {
            printf("%c",liczba_2[i]);
        }
    }

    return 0;
}
