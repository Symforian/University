
#include "f-protot.h"
#include <stdlib.h>
#include <stdio.h>
/*
W pliku spz io.c:
void input and check data(void) – wprowadzanie danych podanych w kolejno-
œci: n, m, A; poszczególne dane s¹ odseparowane od siebie co najmniej jednym znakiem
niewidocznym w tekœcie (przyk³ad danych wejœciowych zamieszczono w dodatku 3);
void output data(int B[]) – wyprowadzanie wyników w postaci posortowanego,
niemalej¹cego ci¹gu liczb ca³kowitych oddzielonych pojedynczymi odstêpami;
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
