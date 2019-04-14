#include <stdio.h>
#include <stdlib.h>

int czy_jakikolwiek (float a, float b, float c);

int czy_prostokatny (float a, float b, float c);

int czy_rownoboczny (float a, float b, float c);

int czy_rownoramienny (float a, float b, float c);

int main()
{
    printf("Wprowadz trzy dlugosci bokow\n");
    float a, b, c;
    scanf("%f%f%f",&a,&b,&c);
    if(czy_jakikolwiek(a,b,c))
    {
        printf("Mozna zbudowac jakikolwiek\n");
        if(czy_prostokatny(a,b,c))
            printf("Mozna zbudowac prostokatny\n");
        else
            printf("Nie mozna zbudowac prostokatnego\n");
        if(a==b && b==c)
            printf("Mozna zbudowac rownoboczny\n");
        else
            printf("Nie mozna zbudowac rownobocznego\n");
        if(czy_rownoramienny(a,b,c))
            printf("Mozna zbudowac rownoramienny\n");
        else
            printf("Nie mozna zbudowac rownoramiennego\n");

    }
    else
    {
        printf("Nie mozna zbudowac jakikolwiek\n");
        printf("Nie mozna zbudowac prostokatnego\n");
        printf("Nie mozna zbudowac rownobocznego\n");
        printf("Nie mozna zbudowac rownoramiennego\n");

    }

    return 0;
}

int czy_jakikolwiek (float a, float b, float c)
{
    if((a+b>c)&&  (a+c>b) &&  (b+c>a))
        return 1;
    else
        return 0;
}


int czy_rownoramienny (float a, float b, float c)
{
    if((a==b || b==c || a==c)&&(a+b>c)&&  (a+c>b) &&  (b+c>a))
    {
        return 1;
    }
    else
        return 0;
}

int czy_prostokatny (float a, float b, float c)
{
    float przeciwp=a;
    float przyp1;
    float przyp2;
    if(przeciwp<b)
        przeciwp=b;
    if(przeciwp < c)
        przeciwp = c;
    if(przeciwp==a)
    {
        przyp1 = b;
        przyp2 = c;
    }
    else if(przeciwp == b)
    {
        przyp1 =a;
        przyp2 =c;
    }
    else
    {
        przyp1 =a;
        przyp2 = b;
    }
    if((przyp1*przyp1)+(przyp2*przyp2)==(przeciwp*przeciwp))
        return 1;
    else
        return 0;

}
