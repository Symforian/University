#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int xM =9, yM=9, lB=6; //Rozmiar planszy xM X yM, liczba bomb = lB;

int main()
{
    srand(time(NULL));
    int lx,ly;
    int (*Y[xM]);

    for(int i=1; i<=xM; i++)
    {
        Y[i] = malloc(yM*sizeof(char));
        for(int j=1; j<=yM; j++)
            Y[i][j]='.';

    }


    for(int i = 0; i < lB; i++)
    {
        int pop = 0;
        if(pop==1) pop=0;
        lx=rand()%xM + 1;
        ly=rand()%yM + 1;
        if(Y[lx][ly]!='*')
        {
            Y[lx][ly]='*';
            if(lx==xM)//jest przy scianie dolnej x
            {
                if(Y[lx-1][ly]=='.')
                    Y[lx-1][ly]='1';
                else if (Y[lx-1][ly]!='*')
                    Y[lx-1][ly]++;
            }
            else if (lx==1) //jest przy scianie gornej x
            {
                if(Y[lx+1][ly]=='.')
                    Y[lx+1][ly]='1';
                else if (Y[lx+1][ly]!='*')
                    Y[lx+1][ly]++;
            }
            else  // nie jest przy scianie x
            {
                if(Y[lx-1][ly]=='.')
                    Y[lx-1][ly]='1';
                else if (Y[lx-1][ly]!='*')
                    Y[lx-1][ly]++;

                if(Y[lx+1][ly]=='.')
                    Y[lx+1][ly]='1';
                else if (Y[lx+1][ly]!='*')
                    Y[lx+1][ly]++;
                //przekatna >V
                if(Y[lx+1][ly+1]=='.')
                    Y[lx+1][ly+1]='1';
                else if (Y[lx+1][ly+1]!='*')
                    Y[lx+1][ly+1]++;
                //przekatne >^
                if(Y[lx+1][ly-1]=='.')
                    Y[lx+1][ly-1]='1';
                else if (Y[lx+1][ly-1]!='*')
                    Y[lx+1][ly-1]++;
                //przekatne <V
                if(Y[lx-1][ly+1]=='.')
                    Y[lx-1][ly+1]='1';
                else if (Y[lx-1][ly+1]!='*')
                    Y[lx-1][ly+1]++;
                //przekatna <^
                if(Y[lx-1][ly-1]=='.')
                    Y[lx-1][ly-1]='1';
                else if (Y[lx-1][ly-1]!='*')
                    Y[lx-1][ly-1]++;
            }


            if(ly==yM)//jest przy scianie prawej y
            {
                if(Y[lx][ly-1]=='.')
                    Y[lx][ly-1]='1';
                else if (Y[lx][ly-1]!='*')
                    Y[lx][ly-1]++;
            }
            else if (ly==1) //jest przy scianie lewej y
            {
                if(Y[lx][ly+1]=='.')
                    Y[lx][ly+1]='1';
                else if (Y[lx][ly+1]!='*')
                    Y[lx][ly+1]++;
            }
            else  // nie jest przy scianie y
            {
                if(Y[lx][ly-1]=='.')
                    Y[lx][ly-1]='1';
                else if (Y[lx][ly-1]!='*')
                    Y[lx][ly-1]++;

                if(Y[lx][ly+1]=='.')
                    Y[lx][ly+1]='1';
                else if (Y[lx][ly+1]!='*')
                    Y[lx][ly+1]++;

                if(lx==xM || lx==0)
                {
                    //przekatna >V
                    if(Y[lx+1][ly+1]=='.')
                        Y[lx+1][ly+1]='1';
                    else if (Y[lx+1][ly+1]!='*')
                        Y[lx+1][ly+1]++;
                    //przekatne >^
                    if(Y[lx+1][ly-1]=='.')
                        Y[lx+1][ly-1]='1';
                    else if (Y[lx+1][ly-1]!='*')
                        Y[lx+1][ly-1]++;
                    //przekatne <V
                    if(Y[lx-1][ly+1]=='.')
                        Y[lx-1][ly+1]='1';
                    else if (Y[lx-1][ly+1]!='*')
                        Y[lx-1][ly+1]++;
                    //przekatna <^
                    if(Y[lx-1][ly-1]=='.')
                        Y[lx-1][ly-1]='1';
                    else if (Y[lx-1][ly-1]!='*')
                        Y[lx-1][ly-1]++;
                }
                //narozniki
            if(lx==1 || ly==1 || lx==xM || ly==yM){
                if(lx==1 && ly==1)
                {
                        //przekatna >V
                        if(Y[lx+1][ly+1]=='.')
                            Y[lx+1][ly+1]='1';
                        else if (Y[lx+1][ly+1]!='*')
                            Y[lx+1][ly+1]++;
                }else if(lx==1 && ly==yM)
                {
                        //przekatne >^
                        if(Y[lx+1][ly-1]=='.')
                            Y[lx+1][ly-1]='1';
                        else if (Y[lx+1][ly-1]!='*')
                            Y[lx+1][ly-1]++;

                }else if (lx==xM && ly==1)
                {
                    if(Y[lx-1][ly+1]=='.')
                        Y[lx-1][ly+1]='1';
                    else if (Y[lx-1][ly+1]!='*')
                        Y[lx-1][ly+1]++;


                }else if (lx==xM && ly==yM)
                    {
                            //przekatna <^
                        if(Y[lx-1][ly-1]=='.')
                            Y[lx-1][ly-1]='1';
                        else if (Y[lx-1][ly-1]!='*')
                            Y[lx-1][ly-1]++;
                    }
            }

        }

    }
        else pop=1;
        i-=pop;
        }
    // printf("%d",xM);

    int koniec=0;
    int x,y;
    while(koniec==0)
    {
    for(int i=1; i <= xM; i++)
    {
        for(int j=1; j<=yM; j++)
            printf("%c",Y[i][j]);
        printf("\n");
    }
    scanf("%d%d",&x,&y);
    printf("\n");
    }
    free(Y);
    return 0;
}


