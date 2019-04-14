#include <stdio.h>
#include <stdlib.h>

int main()
{

    int N,M;
    scanf("%d%d",&N,&M);
    if(N>100||N<1||M>100||M<1)
        return 0;
    char T[N][M];
    for(int i=0;i<N;i++)
    {
        for(int j=0; j<M;j++)
        scanf("%c",&T[i][j]);
    }
   /* int P,L;
    scanf("%d%d",&P,&L);
    char S[L];
    for(int i=0;i<L;i++)
        scanf("%c",&S[i]);
    if(P==L)
    {
        T[0][2]=T[0][3]='X';*/
    for(int i=0;i<N;i++)
    {
        printf("%d\n",i);
        for(int j=0; j<M;j++)
        printf("%c",T[i][j]);

   }
   // }
    return 0;
}
