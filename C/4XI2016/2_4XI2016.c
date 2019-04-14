//288477
//Lista 4 zadanie 2
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
    long int Mem[63]={0};
unsigned long int fibRec(int n);
unsigned long int fibIte(int n);
unsigned long int fibRecMem(int n);
int main()
{

    int n;
    long int t0,t1,t2,t3;
    unsigned long int a;
    scanf("%d",&n);
    if(n>0 && n<=62)
    {
        t0=clock();
        a=fibRec(n);
        t1=clock();
        printf("%u\nCzas rekurencyjny   %ld\n",a,t1-t0);
        t0=clock();
        a=fibIte(n);
        t2=clock();
        printf("%u\nCzas iteracyjny     %ld\n",a,t2-t0);
        t0=clock();
        a=fibRecMem(n);
        t3=clock();
        printf("%u\nCzas rekurencyjny z zapamietywaniem     %ld\n",a,t3-t0);
        return 0;
    }
    else if(n==0)
         {
            printf("0\n");
            return 0;
         }
    else
    {
        printf("-1\n");
        return 0;
    }

}

unsigned long int fibRec(int n)
{
    if(n==1 || n ==2)
        return 1;
    else
        return fibRec(n-1)+fibRec(n-2);
}

unsigned long int fibIte(int n)
{
    int pom=2;
    int pom2;
    int j=1;
    if(n==1 || n==2)
        return 1;
    else
    {

        for(int i = 3 ; i<n;i++)
        {
            pom2=pom;
            pom+=j;
            j=pom2;
        }
        return pom;
    }
}

unsigned long int fibRecMem(int n)
{
        /*if(n<=0 || n>=62)
        return -1;
    else*/
        if(n==1 && Mem[n]==0)
    {
        Mem[n]=1;
    }
    else
        if(n==2 && Mem[n]==0)
    {
        Mem[n]=1;
    }else
    if(Mem[n]>0)
        return Mem[n];
        else
        {
            Mem[n]=fibRecMem(n-1)+fibRecMem(n-2);
        }
    return Mem[n];
}
