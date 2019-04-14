//f-protot.h
#include "f-protot.h"
#include <stdio.h>
#include <stdlib.h>

void C_K_E(int *A,int n,int m)
{
    int rowne[m-1];
    for(int i = 0; i<=m-1; i++)
    {
        rowne[i]=0;
    }

    for(int i = 0; i<=n-1; i++)
    {
        if(i==A[i])
            rowne[i]++;
    }

}

void C_K_L(int *rowne,int m)
{
    int mniejsze[m-1];
    for(int i = 0; i<=m-1; i++)
    {
        mniejsze[i]=0;
    }
    mniejsze[0]=rowne[0];
    for(int i = 1; i<=m-1; i++)
    {
        mniejsze[i]=rowne[i]+rowne[i-1];
    }

}

  void Reorg(int *A,int *mniejsze,int n,int m)
  {
        int B[n],nastepny[m-1];
        int *klucz;
        for(int i =0; i<=n; i++)
        {
            klucz=*A[i];
        }
        for(int j=0; j<=m-1; j++)
        {
            mniejsze[j]=nastepny[j]+1;
        }
  }


void C_S(int *A,int n,int m)
{
    int rowne[m-1];
    C_K_E(A,n,m);
    C_K_L(rowne,n);
    Reorg(A,mniejsze,n,m);
}



/*
w pliku spz alg.c:
C K E – odpowiednik procedury POLICZ-KLUCZE-RÓWNE w pseudokodzie,
C K L – odpowiednik procedury POLICZ-KLUCZE-MNIEJSZE w pseudokodzie,
Reorg – odpowiednik procedury REORGANIZUJ w pseudokodzie,
C S – odpowiednik procedury SORTOWANIE-PRZEZ-ZLICZANIE w pseudokodzie.
*/
