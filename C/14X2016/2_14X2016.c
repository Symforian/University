//288477
//Lista 1
//zadanie 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{

    printf("Zgadnij liczbe losowa (0-100) w 10 probach\n");
    srand(time(NULL));
    int n = 0 + rand()%100;
    int k;
    int wyg=0;
    for(int i = 0; i<10; i++)
    {
        scanf("%d",&k);
        if(k==n)
            {
                printf("Wygrales w %d. probie",i);
                i+=10;
                wyg=1;
            }
            else
                {if(k>n)
                        printf("Szukana jest mniejsza\n");
                    else
                        printf("Szukana jest wieksza\n");
                }
    }
    if(wyg==0)
    {
        printf("\n\nPrzegrales, szukana to %d",n);
    }

    return 0;
}
