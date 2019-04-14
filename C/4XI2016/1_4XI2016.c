//288477
//lista 4 zadamoe 1

#include <stdio.h>
#include <stdlib.h>

int zeroZprzodu_czy_cyfra_znak_czy_inne(char znak_poprzedni, char znak_obecny, int dlugosc, int czyTOzero);

int porownywanie_jesli_rozna_dlugosc_i_takie_same_znaki_lub_rozne_znaki(char znak1, char znak2, int dlugosc1, int dlugosc2);

int main()
{
    char liczba1[130]={'0'},liczba2[130]={'0'},wczytany,poprzedni='0';
    int dlugosc1=0,dlugosc2=0,czekaj=1,ile=0,ktora=1,czy_to_zero1=0,czy_to_zero2=0,pamietaj_o_tym_minusie=0;
    while(poprzedni!=EOF)
    {
     //   printf("\nDlugosc 1 to %d a dlugosc 2 to %d\t ich znaki to kolejno |%c|   |%c|\n",dlugosc1,dlugosc2,liczba1[0],liczba2[0]);
        wczytany=getchar();
        if(czekaj==0)
        {
            if(ktora==1)
            {
            switch(zeroZprzodu_czy_cyfra_znak_czy_inne(poprzedni,wczytany,dlugosc1,czy_to_zero1))
            {
                case 0:
                    {
                        if(liczba1[0]=='0')
                        {
                            czy_to_zero1=1;
                            if(pamietaj_o_tym_minusie==0)
                            liczba1[0]=' ';//dodatnia
                            else
                            {
                                liczba1[0]='-';
                                pamietaj_o_tym_minusie=0;
                            }
                            dlugosc1=1;
                        }
                        else
                            if(liczba1[0]=='-' && wczytany>='0' && wczytany<='9')
                            {
                                liczba1[0]='-';
                                if(wczytany=='0')
                                    czy_to_zero1=1;
                            }

                        pamietaj_o_tym_minusie=0;
                        break;
                    }
                case 1:
                    {
                        czy_to_zero1=0;
                        liczba1[dlugosc1]=poprzedni;
                        dlugosc1++;
                        pamietaj_o_tym_minusie=0;
                        break;
                    }
                case 2:
                    {
                        if(poprzedni=='-')
                            {
                                if(liczba1[0]=='0')
                                {
                                    liczba1[0]='-';
                                }
                                else
                                {
                                    pamietaj_o_tym_minusie=1;
                                    ktora=2;
                                    ile++;
                                }
                            }
                        else
                            {
                                if(liczba1[0]=='0')
                                    liczba1[0]=' ';
                                dlugosc1++;
                                liczba1[dlugosc1]=poprzedni;
                                if(poprzedni!='0')
                                    czy_to_zero1=0;
                                if(dlugosc1==1)
                                    dlugosc1++;
                            }
                        break;
                    }
                case 3:
                    {
                        czy_to_zero1=1;
                        liczba1[0]=' ';
                        dlugosc1=2;
                        ile++;
                        ktora=2;
                        pamietaj_o_tym_minusie=0;
                        break;
                    }
                case -1:
                    {

                        if(dlugosc1>0)
                        {
                            ile++;
                            ktora=2;
                        }
                        pamietaj_o_tym_minusie=0;
                        break;
                    }
            }

            }//koniec wczytywania pierwszego
            else//(ktora==2)
            {
                switch(zeroZprzodu_czy_cyfra_znak_czy_inne(poprzedni,wczytany,dlugosc2,czy_to_zero2))
                {
                    case 0:
                        {
                            if(liczba2[0]=='0')
                            {
                                czy_to_zero2=1;
                                if(pamietaj_o_tym_minusie==0)
                                    liczba2[0]=' ';//dodatnia
                                else
                                    {
                                    liczba2[0]='-';
                                    pamietaj_o_tym_minusie=0;
                                    }

                                dlugosc2=1;
                            }
                            else
                                if(liczba2[0]=='-' && wczytany>='0' && wczytany<='9')
                            {
                                liczba2[0]='-';
                                if(wczytany=='0')
                                    czy_to_zero2=1;
                            }
                            pamietaj_o_tym_minusie=0;
                            break;
                        }
                    case 1:
                        {
                            czy_to_zero2=0;
                            liczba2[dlugosc2]=poprzedni;
                            dlugosc2++;
                            pamietaj_o_tym_minusie=0;
                            break;
                        }
                    case 2:
                        {
                            if(poprzedni=='-')
                            {
                                if(liczba2[0]=='0')
                                {
                                    liczba2[0]='-';
                                }
                                else
                                {
                                    pamietaj_o_tym_minusie=1;
                                    ktora=1;
                                    ile++;
                                }
                            }
                            else
                                {
                                    if(liczba2[0]=='0')
                                        liczba2[0]=' ';
                                    dlugosc2++;
                                    liczba2[dlugosc2]=poprzedni;
                                    if(poprzedni!='0')
                                        czy_to_zero2=0;
                                    if(dlugosc2==1)
                                        dlugosc2++;
                                }
                            break;
                        }
                    case 3:
                        {
                            czy_to_zero2=1;
                            liczba2[0]=' ';
                            dlugosc1=2;
                            ile++;
                            ktora=1;
                            pamietaj_o_tym_minusie=0;
                            break;
                        }
                    case -1:
                        {
                            if(dlugosc2>0)
                            {
                                ile++;
                                ktora=1;
                            }
                            pamietaj_o_tym_minusie=0;
                            break;
                        }
                }
            }//koniec wczytywanai drugiego
        }//koniec odczytywania
        else czekaj=0;
        poprzedni=wczytany;
        if(ile==2)//porownywac
        {
            if(czy_to_zero1==1)
                liczba1[0]=' ';
            if(czy_to_zero2==1)
                liczba2[0]=' ';
           if((liczba1[0]!=liczba2[0])||(liczba1[0]==liczba2[0]&&dlugosc1!=dlugosc2))
                {
                    if(porownywanie_jesli_rozna_dlugosc_i_takie_same_znaki_lub_rozne_znaki(liczba1[0],liczba2[0],dlugosc1,dlugosc2)==1)
                    {                  //pierwsza mniejsza
                        for(int i=0; i<=dlugosc2;i++)
                        {
                            liczba2[i]='0';
                        }
                        dlugosc2=0;
                        czy_to_zero2=0;
                        ktora=2;
                        ile--;
                        if(pamietaj_o_tym_minusie==1)
                            liczba2[0]='-';
                    }
                    else                //druga mniejsza
                    {
                        for(int i=0; i<=dlugosc1;i++)
                        {
                            liczba1[i]='0';
                        }
                        dlugosc1=0;
                        czy_to_zero1=0;
                        ktora=1;
                        ile--;
                        if(pamietaj_o_tym_minusie==1)
                            liczba1[0]='-';
                    }
                } //tutaj konczy sie porownywanie_jesli_rozna_dlugosc_i_takie_same_znaki_lub_rozne_znaki()
                else//taka sama dlugosc te same znaki
                {
                    for(int i=1; i <=dlugosc1; i++)
                    {
                        if(liczba1[0]==' ')//dodatnie
                        {
                            if(liczba1[i]<liczba2[i])
                                //pierwsza mniejsza
                            {
                                for(int i=0; i<=dlugosc2;i++)
                                {
                                    liczba2[i]='0';
                                }
                                dlugosc2=0;
                                czy_to_zero2=0;
                                ktora=2;
                                ile--;
                                if(pamietaj_o_tym_minusie==1)
                                    liczba2[0]='-';
                                break;
                            }
                            else
                            {
                                if(liczba2[i]<liczba1[i])
                                //druga mniejsza
                                {
                                    for(int i=0; i<=dlugosc1;i++)
                                    {
                                        liczba1[i]='0';
                                    }
                                    dlugosc1=0;
                                    czy_to_zero1=0;
                                    ktora=1;
                                    ile--;
                                    if(pamietaj_o_tym_minusie==1)
                                        liczba1[0]='-';
                                    break;
                                }
                            }
                            if(i==dlugosc1)//jesli rowne
                            {
                                for(int i=0; i<=dlugosc2;i++)
                                {
                                    liczba2[i]='0';
                                }
                                dlugosc2=0;
                                czy_to_zero2=0;
                                ktora=2;
                                ile--;
                                if(pamietaj_o_tym_minusie==1)
                                    liczba2[0]='-';
                            }
                        }
                        else//ujemne
                        {
                            if(liczba1[i]>liczba2[i])
                                //pierwsza mniejsza
                            {
                                for(int i=0; i<=dlugosc2;i++)
                                {
                                    liczba2[i]='0';
                                }
                                dlugosc2=0;
                                czy_to_zero2=0;
                                ktora=2;
                                ile--;
                                if(pamietaj_o_tym_minusie==1)
                                    liczba2[0]='-';
                                break;
                            }
                            else
                            {
                                if(liczba2[i]>liczba1[i])
                                //druga mniejsza
                                {
                                    for(int i=0; i<=dlugosc1;i++)
                                    {
                                        liczba1[i]='0';
                                    }
                                    dlugosc1=0;
                                    czy_to_zero1=0;
                                    ktora=1;
                                    ile--;
                                    if(pamietaj_o_tym_minusie==1)
                                        liczba1[0]='-';
                                    break;
                                }
                            }
                            if(i==dlugosc1)//jesli rowne
                            {
                                for(int i=0; i<=dlugosc2;i++)
                                {
                                    liczba2[i]='0';
                                }
                                dlugosc2=0;
                                czy_to_zero2=0;
                                ktora=2;
                                ile--;
                                if(pamietaj_o_tym_minusie==1)
                                    liczba2[0]='-';
                            }
                        }
                    }
                }
        } // tutaj konczy sie porownywanie
    }//EOF
    printf("\n");
    if(liczba1[0]==' ')
    {
        if(czy_to_zero1==0)
        {
            for(int i = 1; i <=dlugosc1-1 ; i++)
                printf("%c",liczba1[i]);
        }
        else
            printf("0");
    }
    else
    {
        if(liczba1[0]=='-')
        {
            for(int i = 0; i <=dlugosc1-1 ; i++)
            printf("%c",liczba1[i]);
        }
        else
        {
            if(liczba2[0]==' ')
            {
                if(czy_to_zero2==0)
                {
                for(int i = 1; i <=dlugosc2-1 ; i++)
                    printf("%c",liczba2[i]);
                }
                else
                    printf("0");
            }
            else
                {
                    if(liczba2[0]=='-')
                    {
                    for(int i = 0; i <=dlugosc2-1 ; i++)
                    printf("%c",liczba2[i]);
                    }
                }
        }
    }

    return 0;
}

int zeroZprzodu_czy_cyfra_znak_czy_inne(char znak_poprzedni, char znak_obecny, int dlugosc, int czyTOzero)
{

    if (znak_poprzedni=='0' && ((znak_obecny>='0' && znak_obecny<='9')||znak_obecny==EOF) && (czyTOzero==1 || dlugosc==0))
        return 0;
    else if (znak_poprzedni>='0' && znak_poprzedni<='9' && dlugosc>0)
        return 1;
    else if ((znak_poprzedni=='-' && (znak_obecny<='9' && znak_obecny>='0')) || ((znak_poprzedni>'0' && znak_poprzedni<='9')&&dlugosc==0))
        return 2;
    else if(znak_poprzedni=='0' && (znak_obecny==EOF || znak_obecny>'9' || znak_obecny<'0'))
        return 3;
    else
        return -1;

}
int porownywanie_jesli_rozna_dlugosc_i_takie_same_znaki_lub_rozne_znaki(char znak1, char znak2, int dlugosc1, int dlugosc2)
{
    if(znak1!=znak2)
        {
            if(znak1==' ')
                return 2;
            else
                return 1;
        }
    else
        {
            if(znak1==' ')
            {
                if(dlugosc1>dlugosc2)
                    return 2;
                else
                    return 1;
            }
            else
                if(dlugosc1<dlugosc2)
                    return 2;
                else
                    return 1;

        }
}

