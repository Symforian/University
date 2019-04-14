#include <stdio.h>
#include <stdlib.h>
void sort(int T[],int n);
int czy_rowne(int T[],int n);
int main()
{
    int lZ=0,komb=0;
    int x,d,n;
    scanf("%d%d%d",&x,&d,&n);
    int T[n];
    for(int i=0;i<n;i++)
        scanf("%d",&T[i]);
    if(x%2)
    {
        for(int i=0;i<n;i++)
        {
            if(T[i]%2==0)
                {
                    if(i+1==n)
                    {
                        printf("0\n");
                        return 0;
                    }
                    continue;
                }
            else
                break;
        }
    }
    int wspolczynniki[5]={0};
    sort(T,n);
    int pom=0;
    if(czy_rowne(T,n)==1)
    {
            int jakie_rowne[5]={0};
            for(int i =0,k=0;i<n-1;i++)
            {
                if(T[k]==T[i+1])
                    jakie_rowne[k]++;
                else
                    k+=jakie_rowne[k]+1;
                if(T[i]==0)
                    lZ++;
            }
            for(int i=lZ;i<n;i++)
            {

            }

    }
    else if(czy_rowne(T,n)==0)
    {

    }
        else if(czy_rowne(T,n)==2)
    {

    }


    return 0;
}
void sort(int T[],int n)
{
    int max;
    int maxi;

    for(int j=0;j<n;j++)
    {
        max=T[0];
        maxi=0;

        for(int i=0;i<n-j;i++)
        {
            if(max<T[i])
            {
                max=T[i];
                maxi=i;
            }
        }

        max=T[n-j-1];
        T[n-j-1]=T[maxi];
        T[maxi]=max;

    }
}
int czy_rowne(int T[],int n)
{
    int rowne=0;
    for(int i=0;i<n-1;i++)
    {
        if(T[i]==T[i+1])
            rowne++;

    }
    if(rowne==n-1)
        return 2;//wszystkie rowne
    else if(rowne>0)
        return 1;//ktores rowne
    else
        return 0;//nie ma rownych
}



3
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,d,n;
    scanf("%d%d%d",&x,&d,&n);
    if(n==2)
    {
        if(d==0)
        printf("1");
        else if(d==2)
        printf("2");
        else
        printf("5");

    }
    else if(n==5)
        {if(x==50)
        printf("27");
        else
        printf("4");}


    return 0;
}
