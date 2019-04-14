#include <stdio.h>
#include <stdlib.h>

typedef struct kwadrat
{
    char wartosc;
    struct kwadrat *a,*b,*c,*d;
}Calosc;
struct kwadrat* funkcja_szukajaca_miejsca_inaczej_cwiartki(int n, char k, int miejsce);
int main(void)
{
    int n;
    char k;
    k=getchar();
    if(k=='P')
    k=getchar();
    if(k=='1')
    {
        scanf("%d",&n);
        scanf("%d",&n);
        for(int i=0;i<n*n;i++)
        {
            k=getchar();

        }

    }
    else
    return 0;


    return 0;
}
struct kwadrat* funkcja_szukajaca_miejsca_inaczej_cwiartki(int n, char k, int miejsce)
{
    struct kwadrat* ptr=(struct kwadrat*)malloc(sizeof(struct kwadrat));
    return ptr;
}
/*
int cwiarteczka(int n, int ktory, int indeks);
int definicja_cwiartek(char gdzie);
struct kwadrat
{
    char wartosc;
    struct kwadrat *a,*b,*c,*d;
} OBRAZEK;
void rekurde (struct kwadrat *ptr, char wart, int n, int k, int i);
void rozneTakie(char znak,struct kwadrat *ptr);
void zerojedenminus(struct kwadrat* ptr, char znak);
void skret(struct kwadrat* ptr);
int main()
{
    getchar();
    getchar();
    int n;
    struct kwadrat *ptr=&OBRAZEK;
    scanf("%d",&n);
    scanf("%d",&n);
    int k=0,linia=n;
    char pom[n*n],operacje;
    getchar();
    while(k<(n*n))
    {
        if(linia!=0)
        {
        pom[k]=getchar();
        linia--;
        rekurde(ptr,pom[k],n,k,n-linia);
        k++;
        }
        else
        {
            getchar();
            linia=n;
        }
    }
    getchar();
    while(operacje!='.')
    {
    printf("%c%c\n%c%c",(*ptr->a).wartosc,(*ptr->b).wartosc,(*ptr->c).wartosc,(*ptr->d).wartosc);
        operacje=getchar();
    rozneTakie(operacje,ptr);
    ptr=&OBRAZEK;
    }

    printf("%c",OBRAZEK.wartosc);

    free(ptr);
    return 0;
}

int cwiarteczka(int n, int ktory, int indeks)
{
    if(ktory<=n/2 && indeks<=n/2)
            return 1;
    else if (ktory<=n/2 && indeks>n/2)
            return 2;
    else if(indeks<=n/2)
            return 4;
    else
            return 3;

}

void rekurde (struct kwadrat *ptr, char wart, int n, int k, int i)
{
    if(n>1)
    {
        switch(cwiarteczka(n,k,i))
        {
        case 1:
            {
                ptr->a=(struct kwadrat*)malloc(sizeof(struct kwadrat));
                rekurde(ptr->a,wart,n/2,k,i);
                break;
            }
        case 2:
            {
                ptr->b=(struct kwadrat*)malloc(sizeof(struct kwadrat));
                rekurde(ptr->b,wart,n/2,k-n/2,i/2);\
                break;
            }
        case 4:
            {
                ptr->c=(struct kwadrat*)malloc(sizeof(struct kwadrat));
                rekurde(ptr->c,wart,n/2,k%(2*n),i);
                break;

            }
        case 3:
            {
                ptr->d=(struct kwadrat*)malloc(sizeof(struct kwadrat));
                rekurde(ptr->d,wart,n/2,k-5*n/2,i/2);

                break;
            }
        }

    }
    else
    (*ptr).wartosc=wart;

}
void rozneTakie(char znak,struct kwadrat *ptr)
{
    char pomocnik;
    pomocnik=getchar();
    if(pomocnik!='\n')
    {
        if(znak=='0' || znak=='1' || znak=='-' || znak=='=' || znak=='*' || znak=='#')
        {
            pomocnik=getchar();
            char buffor=pomocnik;
            int i=definicja_cwiartek(pomocnik);
                while(definicja_cwiartek(pomocnik)!=-1)
            {   int done=0;
                if(buffor==pomocnik){}

            else
                {
                    if((*ptr).wartosc=='1'|| (*ptr).wartosc=='0')
                    {
                        printf("Dokopane do wartosci\n");
                        done=1;
                        if(znak=='*' || (znak='0'&& (*ptr).wartosc=='0')||(znak='1'&& (*ptr).wartosc=='1')){}
                        else if(znak=='0'){(*ptr).wartosc='0';}
                        else if(znak=='1'){(*ptr).wartosc='1';}
                        else if(znak=='-')
                        {
                            if(znak=='0'){(*ptr).wartosc='1';}
                        else if(znak=='1'){(*ptr).wartosc='0';}
                        }
                        else if(znak=='=' || znak=='#'){printf("Do wyniku wypisz 1\n");}


                    } else
                        {
                            switch(i)
                        {
                        case 1:
                            ptr=ptr->a;
                            break;
                        case 2:
                            ptr=ptr->b;
                            break;
                        case 4:
                            ptr=ptr->c;
                            break;
                        case 3:
                            ptr=ptr->d;
                            break;

                        }
                        }

                    buffor=pomocnik;
                }
                if(buffor!='\n')
                pomocnik=getchar();
                else if(done==0)
                {
                    if(znak=='0' || znak=='1' || znak=='-')
                    zerojedenminus(ptr,znak);
                    else if(znak=='*')
                        skret(ptr);
                }

                i=definicja_cwiartek(pomocnik);
            }

        }

    }
    else
        {
            if(znak=='0')
        {
            zerojedenminus(ptr,znak);
        }
    else if(znak=='1')
            {
                zerojedenminus(ptr,znak);
            }
    else if(znak=='-')
        {
            if(OBRAZEK.wartosc=='1')
                zerojedenminus(ptr,znak);
            else if(OBRAZEK.wartosc=='0')
                zerojedenminus(ptr,znak);
            else
                zerojedenminus(ptr,znak);
        }
    else if(znak=='*')
            {if(OBRAZEK.wartosc=='1'||OBRAZEK.wartosc=='0'){}
            else
                {
                    struct kwadrat* pom;
                    pom=OBRAZEK.a;
                    OBRAZEK.a=OBRAZEK.b;
                    OBRAZEK.b=OBRAZEK.c;
                    OBRAZEK.c=OBRAZEK.d;
                    OBRAZEK.d=pom;
                    free(pom);
                }
            }
        }
}
int definicja_cwiartek(char gdzie)
{
    if(gdzie=='a' || gdzie=='A')
        return 1;
    if(gdzie=='b'||gdzie=='B')
        return 2;
    if(gdzie=='c'||gdzie=='C')
        return 4;
    if(gdzie=='d'||gdzie=='D')
        return 3;
    else
        return -1;
}

void zerojedenminus(struct kwadrat* ptr, char znak)
{
    printf("Zero jeden minus!\t%c\n",(*ptr).wartosc);
    if(((*ptr).wartosc=='1' && znak=='1')||((*ptr).wartosc=='0' && znak=='0'))
    {    }
    else
        {
        if((*ptr).wartosc=='1')
        (*ptr).wartosc='0';
        else
        if((*ptr).wartosc=='0')
        (*ptr).wartosc='1';
        else
            {
                zerojedenminus(ptr->a,znak);
                zerojedenminus(ptr->b,znak);
                zerojedenminus(ptr->c,znak);
                zerojedenminus(ptr->d,znak);
            }
        }
}

void skret(struct kwadrat* ptr)
{
    printf("Skrecam!\n");
                        struct kwadrat* pom;
                    pom=ptr->a;
                    ptr->a=ptr->b;
                    ptr->b=ptr->c;
                    ptr->c=ptr->d;
                    ptr->d=pom;
                    free(pom);
}*/
