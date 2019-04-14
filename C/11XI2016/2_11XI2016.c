//288477
//zadanie 2 lista 5

#include <stdio.h>
#include <stdlib.h>

int NWD(int a, int b);
int abs(int a);             //Wart bezwzgl
int pierw(int a);           //Pierwiastek "ladny"
int max(int a,int b,int c); //najwiekszy wspolczynnik
int B_pierw1(int a);        //pierwiastek "brzydki" czesc wyciagnieta
int B_pierw2(int a);        //pierwiastek "brzydki" czesc pod pierwiastkiem

int main()
{
    printf("Wprowadz wspolczynniki a, b, c rownania \ndrugiego stopnia postaci:\n\tax^2+bx+c=0\n\t");
    int a,b,c;
    int wynik,reszta,x1,x2,pom;
    scanf("%d%d%d",&a,&b,&c);
    if(a==0 || b==0 || c==0){//niepelne
    if(a!=0 && b==0 && c==0)
    {
        printf("\tJest to rownanie niepelne postaci\n\t ax^2=0\n\tjedynym rozwiazaniem (podwojnym) bedzie wiec 0");
    }
    else
    if(a==b && b==0)
        printf("Brak rozwiazania \n\t%d=0\n\tsprzecznosc\n",c);
        else if(a==0 && b!=0 && c!=0)
        {
            printf("Jest to rownanie liniowe postaci\n\tbx+c=0\n\tczyli\n");
            if(c%b==0)
                {
                    wynik=c/b;
                    printf("\t%dx+(%d)=0\n\twiec\n\tx=-(%d)",b,c,wynik);
                }
                else
                {
                    if(c/b!=0)
                        {
                            wynik=-1*(c/b);
                            reszta=(c%b)/NWD(c,b);
                            printf("\t%dx+%d=0\n\twiec\n\tx=%d-(%d/%d)",b,c,wynik,reszta,b/NWD(c,b));
                        }
                    else
                        {
                            reszta=-1*((c%b)/NWD(c,b));
                            printf("\t%dx+%d=0\n\twiec\n\tx=%d/%d",c,b,reszta,b);
                        }
                }


        } else if(a!=0 && b!=0 && c==0)
        {
            printf("Jest to rownanie niepelne postaci\n\t ax^2+bx=0\n\tjednym z rozwiazan bedzie wiec 0:\n\tx(ax+b)=0\n x=0 v x=-b/a\n x=0 v x=");
            if(b%a==0)
            {
                wynik=-1*((b/a)/NWD(a,b));
                printf("%d\n",wynik);
            } else
            {
                if(b/a!=0)
                {
                    wynik=-1*((b/a)/NWD(a,b));
                    reszta=b%a;
                    printf("%d-(%d/%d)",wynik,reszta,a);
                }
                else
                {
                    reszta=-1*((b%a)/NWD(a,b));
                    printf("%d/%d",reszta,a/NWD(a,b));
                }
            }

        }else if(a!=0 && b==0 && c!=0)
        {
            printf("Jest to rownanie niepelne postaci\n\t ax^2+c=0\n\t%dx^2=-(%d)\n\tx^2=(-(%d)/%d)\n\t",a,c,c,a);
            if((c>0 && a>0)||(c<0 && a<0))
                printf("sprzecznosc\n",c,a);
            else
                {
                    a=abs(a);
                    c=abs(c);
                    reszta=NWD(a,c);
                    a=a/reszta;
                    c=c/reszta;
                    printf("x^2=(%d/%d)\n\t",c,a);
                    printf("prawa strona jest dodatnia, mozna pierwiastkowac\n\t");
                    if((pierw(a)!=0) &&(pierw(c)!=0)) //ladny pierwiastek
                        printf("x=%d/%d v x=-(%d/%d)",pierw(c),pierw(a),pierw(c),pierw(a));
                    else if(pierw(a)!=0)
                    {
                        printf("x=pierw(%d)/%d v x=-(pierw(%d)/%d)",c,pierw(a),c,pierw(a));
                    }
                    else if(pierw(c)!=0)
                    {
                        printf("x=%d/pierw(%d) v x=-(%d/pierw(%d))\n\tusuwamy niewymiernosc z mianownika\n\t",pierw(c),a,pierw(c),a);
                        printf("x=(%d*pierw(%d))/%d v x=-((%d*pierw(%d))/%d)\n\t",pierw(c),a,a,pierw(c),a,a);
                    }
                    else //brzydki pierwiastek
                    {
                        printf("x=pierw(%d)/pierw(%d) v x=-(pierw(%d)/pierw(%d))\n\tusuwamy niewymiernosc z mianownika\n\t",c,a,c,a);
                        printf("x=pierw(%d*%d)/%d v x=-(pierw(%d*%d)/%d))\n\t",c,a,a,c,a,a);
                        c*=a;
                        if(pierw(c)!=0)
                            printf("x=%d/%d v x=-(%d/%d)\n\t",c,a,c,a);
                        else
                            {
                                printf("x=pierw(%d)/%d v x=-(pierw(%d)/%d)\n\t",c,a,c,a);
                                if(B_pierw1(c)!=0)
                                {
                                    wynik=B_pierw1(c);
                                    reszta=B_pierw2(c);
                                    pom=NWD(wynik,a);
                                    a/=pom;
                                    wynik/=pom;
                                    printf("x=(%d*pierw(%d))/%d v x=-(%d*pierw(%d)/%d)\n\t",wynik,reszta,a,wynik,reszta,a);
                                }
                            }
                    }
                }

        }
    return 0;
    }//koniec jesli niepelne
    else
    {
        int m;
        int del;
        x2=a;
        m=max(a,b,c);
        for(int i =m;i>=2;i--)
            if(a%i==0 && b%i==0 && c%i==0)
        {
            a/=i;
            b/=i;
            c/=i;
            m/=i;
        }
        if(x2>a)
        printf("\n\tPo uproszczeniu \n\t%dx^2+(%d)x+(%d)=0",a,b,c);
        printf("\n\tLiczymy delte\n\t");
        del=b*b-(4*a*c);
        printf("Delta wynosi %d\n\t",del);
        if(del>0)
        {   printf("Rownanie ma 2 rozwiazania\n\tx=((-(b)+pierw(del))/2*(a)) v x=((-(b)-pierw(del))/2*(a))\n\tczyli\n\tx=((-(%d)+pierw(%d))/2*(%d)) v x=((-(%d)-pierw(%d))/2*(%d))\n\t",b,del,a,b,del,a);
            if(pierw(del)!=0)
        {
            x1=-1*(b)+pierw(del);
            x2=-1*(b)-pierw(del);
            a*=2;
            printf("x=%d/%d v x=%d/%d\n\t",x1,a,x2,a);
            pom=NWD(x1,a);
            x1/=pom;
            if(x1%(a/pom)==0)
                {
                    x1/=(a/pom);
                    printf("x=%d v ",x1);
                }
            else
                if(x1/(a/pom)!=0)
            {
                wynik=x1/(a/pom);
                reszta=x1%(a/pom);
                printf("x=%d+(%d/%d) v",wynik,reszta,a/pom);
            }else
            {
                printf("x=%d/%d v ",x1,a/pom);
            }
            pom=NWD(x2,a);
            x2/=pom;
                if(x2%(a/pom)==0)
                {
                    x2/=(a/pom);
                    printf("x=%d\n\t",x2);
                }
            else
                if(x2/(a/pom)!=0)
            {
                wynik=x2/(a/pom);
                reszta=x2%(a/pom);
                printf("x=%d+(%d/%d)\n\t",wynik,reszta,a/pom);
            }else
            {
                printf("x=%d/%d\n\t",x2,a/pom);
            }

        }else
            {
                b*=-1;
                a*=2;
                if(B_pierw1(del)==0)
                {
                    printf("x=((%d+pierw(%d))/(%d)) v x=((%d-pierw(%d))/(%d))\n\t",b,del,a,b,del,a);
                }
                else
                {
                    pom=NWD(NWD(b,B_pierw1(del)),a);
                    printf("x=(%d+(%d*(pierw(%d))))/(%d) v x=(%d-(%d*(pierw(%d))))/(%d)\n\twiec\n\t",b,B_pierw1(del),B_pierw2(del),a,b,B_pierw1(del),B_pierw2(del),a);
                    printf("x=(%d+(%d*(pierw(%d))))/(%d) v x=(%d-(%d*(pierw(%d))))/(%d)",b/pom,B_pierw1(del)/pom,B_pierw2(del),a/pom,b/pom,B_pierw1(del)/pom,B_pierw2(del),a/pom);
                }
            }

        }
        else if(del==0)
        {
            printf("Rowanie ma jedno rozwiazanie podwojne\n\tx=-b/2a\n\tczyli\n\tx=-(%d)/(2*(%d))",b,a);
            b*=-1;
            a*=2;
            printf("\n\tx=%d/%d\n\t",b,a);
            pom=NWD(b,a);
            a/=pom;
            b/=pom;
            printf("x=%d/%d\n\t",b,a);
            if(b%a==0)
                {   b/=a;
                    printf("x=%d\n\t",b);
                }else if(b/a!=0)
                {
                    wynik=b/a;
                    reszta=b%a;
                    printf("x=%d+(%d/%d)\n\t",wynik,reszta,a);
                }else
                {
                    printf("x=%d/%d\n\t",b,a);
                }

        }
        else
        {
            printf("Delta ujemna brak rozwiazan");
        }
    }

}
int max(int a,int b,int c)
{
    int max= a;
    if(b>max)
        max=b;
    if(c>max)
        max=c;
    return max;
}
int pierw(int a)
{
    if(a==1)
        return 1;

    for(int i = 2; i*i<=a;i++)
            if(i*i==a) return i;
        return 0;
}

int abs(int a)
{
    if(a<0)
        a*=-1;
    return a;
}

int NWD(int a, int b)
{

    int k;
while(b != 0)
    {
        k = a % b;
        a = b;
        b = k;
    }
    return a;
}



int B_pierw1(int a)
{
    int wynik=1;
    for(int i = 2; i*i<=a;i++)
        {
            if(pierw(i*i)!=0)
            {
                if(a%(i*i)==0)
                    {
                        wynik*=i;
                        a/=(i*i);
                        i=1;
                    }
            }
        }
    if(wynik==1)
        return 0;
        else
            return wynik;
}

int B_pierw2(int a)
{
    int pom = B_pierw1(a);
    if(pom>0)
        a=a/(pom*pom);
        return a;
}
