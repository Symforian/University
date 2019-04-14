#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <math.h>


bool obfita(int m)
{
    int suma_dzielnikow=1;
    double r = sqrt(m);
    for(int i=2;i<=r;i++)
    {
        if(m%i==0)
        {
               suma_dzielnikow+=i;
               if(i!=m/i)
               {
               suma_dzielnikow+=m/i;
               }
               if(suma_dzielnikow>m || INT_MAX-suma_dzielnikow<i+(m/i))
                    return 1;

        }
    }

    return 0;
}

int main(void)
{
    int znal_1=0;

    int m,n=0,p=0;
    scanf("%d",&m);
    while (m<INT_MAX-2 && (n==0 || p==0))
    {
        if(znal_1==0 && (n!=0 || p!=0))
            znal_1=1;
        m++;

        if(m%2==0 && obfita(m) && p==0)
        {
            p=m;


        }
        else
            if(m%2==1 && obfita(m) && n==0)
        {
            n=m;

        }
        if(znal_1==1)
            m++;

    }
    if(p==0)
        printf("BRAK ");
    else
        printf("%d ",p);
    if(n==0)
        printf("BRAK\n");
    else
        printf("%d\n",n);
    return 0;
}
