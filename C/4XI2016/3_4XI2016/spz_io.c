
#include "f-protot.h"
#include <stdlib.h>
#include <stdio.h>
/*
W pliku spz io.c:
void input and check data(void) � wprowadzanie danych podanych w kolejno-
�ci: n, m, A; poszczeg�lne dane s� odseparowane od siebie co najmniej jednym znakiem
niewidocznym w tek�cie (przyk�ad danych wej�ciowych zamieszczono w dodatku 3);
void output data(int B[]) � wyprowadzanie wynik�w w postaci posortowanego,
niemalej�cego ci�gu liczb ca�kowitych oddzielonych pojedynczymi odst�pami;
*/
     int n,m;
     int A[];
void input_and_check_data(void)
    {
        scanf("%d%d",&n,&m);
        for(int i=0; i<n; i++)
        {
            scanf("%d",&A[i]);
        }
    }

void output_data(int B[])
{
        /*printf("%d\t%d\n",n,m);
            for(int i=0; i<n; i++)
        {
            printf("%d ",B[i]);
        }*/
}
