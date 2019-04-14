#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int strlenMY(char *txt);
bool palindrom(char *txt);
char* scanMY(int nMaxLen); //– wczytuje ci¹g znaków z konsoli do tablicy
//(nie wiêcej ni¿ nMaxLen)
char *strncpyMY(char *s,char *t,int n); //- kopiowanie co najwy¿ej n
//znaków tekstu t do s.
char *strncatMY(char *s,char *t,int n); //- dopisywanie co najwy¿ej n
//znaków tekstu t na koñcu tekstu s.
int strncmpMY(char *s,char *t,int n);// - porównywanie tekstu t z
//tekstem s przy uwzglêdnieniu co najwy¿ej n znaków.
char *strchrMY(char *string, char c); //- zwraca wskaŸnik na ostatnie
//wyst¹pienie litery c w tekœcie wskazywanym przez string. Jeœli litera
//nie wystêpuje zwracany jest NULL.

int main()
{
    int dlug;
    dlug=getchar()-'0';
    printf("%d",dlug);
    char* ptr=scanMY(dlug);
        for(int j=0;j<=dlug;j++)
    {
        printf("'%c'\n",*(ptr+j));
    }
    printf("\n%d",palindrom(ptr));




    free(ptr);
    return 0;
}
int strlenMY(char *txt)
{
    int ile=0;
    for(int j=0;;j++)
    {
        if(*(txt+j)!=EOF)
            ile++;
        else
            break;

    }
    if(ile>0)
    return ile-1;
    else
        return ile;
}

bool palindrom(char *txt)
{
    bool pal=1;
    int d=strlenMY(txt)-1;
    for(int i=0;i<=d;i++,d--)
    {
        if(*(txt+i)==*(txt+d))
            continue;
        else
        {
            pal=0;
            break;
        }
    }

    return pal;
}
char* scanMY(int nMaxLen)
{
    char *ptr;
    ptr=(char*)malloc(nMaxLen*sizeof(char));
    for(int i=0;i<=nMaxLen;i++)
    {
        *(ptr+i)=getchar();
        if(*(ptr+i)==EOF)
            break;
    }

    return ptr;
}


/*

    char *ptr;
    ptr=(char*)malloc(sizeof(char));
    *ptr=getchar();
    int i=0;
    while(*(ptr+i)!=EOF)
    {
        realloc(ptr,(i+1)*sizeof(char));
        i++;
        *(ptr+i)=getchar();
    }
    */
