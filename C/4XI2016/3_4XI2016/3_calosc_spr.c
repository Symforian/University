#include <stdio.h>
#include <stdlib.h>
int n, m;
int A[10000];
int mniejsze[10000];
int rowne[10000];
int B[10000];
void C_K_E(void);
void input_and_check_data(void);
void C_K_L(void);
void Reorg(void);
int C_S(void);
/////////

int main (void)
{
    input_and_check_data();
    C_S();


    return 0;
}



void input_and_check_data(void)
{
    scanf("%d%d",&n,&m);
    if(n<1)
    {
        printf("\nError: size of input table out of range;\n must be between 1 and %d (inclusive).\n",10000);
        exit(0);
    }
    if(m<1)
    {
        printf("\nError: cardinality of key set out of range;\n must be between 1 and %d (inclusive).\n",n);
        exit(0);
    }


    for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
            if(A[i]<0 || A[i]>=m)
            {
                printf("\nError: value of element of input data out of range;\n must be between 0 and %d (inclusive).\n",m-1);
                exit(0);
            }
       }
     printf("Tablica nieposortowana:\n");
     for(int i = 0; i<n; i++)
        printf("%d ",A[i]);
}

void C_K_E(void)
{
    int pom;

    for(int i=0; i<=m;i++)
    {
        rowne[i]=0;
    }

    rowne[0]-=1;
    for(int i=0; i<=n;i++)
    {
        pom=A[i];
        rowne[pom]++;
    }
    if(rowne[0]<0)
        rowne[0]=0;

}

void C_K_L(void)
{
    mniejsze[0]=rowne[0];
    for(int i=1; i<=m-1;i++)
    {
        mniejsze[i]=0;
    }
    for(int i=1; i<=m;i++)
    {
        for(int j=i;j>=0;j--)
        mniejsze[i]+=rowne[j];
    }

}
void Reorg(void)
{
    for(int i = 0; i<=n; i++)
        B[i]=0;
    for(int i = n-1; i>=0; i--)
    {
        B[mniejsze[A[i]]]=A[i];
        mniejsze[A[i]]--;
    }
}

int C_S(void)
{
    C_K_E();


    C_K_L();


    Reorg();
    printf("\nTablica posortowana:\n");
    for(int i =1 ; i<=n;i++)
        printf("%d ",B[i]);
    printf("\n");
    return 0;
}

