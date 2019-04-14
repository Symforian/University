#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int n,k=0;
    char buff='1';
    scanf("%d",&n);
    getchar();
    char tabl[n+1][50];

        for(int i=0;i<n+1;i++)
    {
        while(buff!=' ')
    {

        tabl[i][k]=buff;
        buff=getchar();
        k++;

    }
    if(k!=0)
    k=0;
    else
        buff=getchar();
    }
    for(int i=0;i<n+1;i++)
    {
        printf("\n");
        for(int j=0; tabl[i][j]!=' ';j++)
        printf("%c",tabl[i][j]);
    }

    return 0;
}
