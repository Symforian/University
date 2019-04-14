#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
int main(void)
{
    char str[1001],znak;
    int n,wynik=0,dl=0,pom=0,p=0,k=2;
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++)
    {
        dl=0;
        p=0;
        k=2;
        pom=0;
        scanf("%c",&znak);
        while(!(isspace(znak)))// p o r t t r -> dl = 6| p = 2| k = 5
        {

            str[dl]=znak;


            if(dl>=2 && dl%2==0 && pom==0)
            {
            if((str[p]==str[k])||//A A
                ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                    ((str[p]=='s'||str[p]=='g')&&
                                                (str[k]=='s'||str[k]=='g'))||
                    ((str[p]=='c'||str[p]=='y')&&
                                                (str[k]=='c'||str[k]=='y'))) {wynik++;pom++;}
                    else
                    k++;
            }
            else if(dl>=3 && dl%2==1 && pom==0)
            {
            if(((str[p+1]==str[k-1])||//BB
                     ((str[p+1]=='b'||str[p+1]=='d'||str[p+1]=='p')&&
                                                  (str[k-1]=='b'||str[k-1]=='d'||str[k-1]=='p'))||
                     ((str[p+1]=='s'||str[p+1]=='g')&&
                                                    (str[k-1]=='s'||str[k-1]=='g'))||
               ((str[p+1]=='c'||str[p+1]=='y')&&
                                                    (str[k-1]=='c'||str[k-1]=='y')))&&
                    ((str[p]==str[k])||//A A
                     ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                      (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                 ((str[p]=='s'||str[p]=='g')&&
                                                    (str[k]=='s'||str[k]=='g'))||
               ((str[p]=='c'||str[p]=='y')&&
                                                    (str[k]=='c'||str[k]=='y')))) {wynik++;pom++;}
                    else
                    p++;
            }
            dl++;
            scanf("%c",&znak);

        }
 //printf("%d\n",p);
    //printf("%d\n",k);
    if(dl==3)
            k=2;
           // printf("%d\n",dl);
        if(pom==0&&dl>2){//jeszcze=10-dl;
                while(k!=dl-1||p!=dl-3)
            {
   // printf("%d\n",p);
   // printf("%d\n",k);
        if(k-p==2)
            {
                if((str[p]==str[k])||//A A
                ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                    ((str[p]=='s'||str[p]=='g')&&
                                                (str[k]=='s'||str[k]=='g'))||
                    ((str[p]=='c'||str[p]=='y')&&
                                                (str[k]=='c'||str[k]=='y'))) {pom++;wynik++;break;}
                                                else
                                                    k++;
                                                }
            else if(k-p==3)
            {

            if(((str[p+1]==str[k-1])||//BB
                     ((str[p+1]=='b'||str[p+1]=='d'||str[p+1]=='p')&&
                                                  (str[k-1]=='b'||str[k-1]=='d'||str[k-1]=='p'))||
                     ((str[p+1]=='s'||str[p+1]=='g')&&
                                                    (str[k-1]=='s'||str[k-1]=='g'))||
               ((str[p+1]=='c'||str[p+1]=='y')&&
                                                    (str[k-1]=='c'||str[k-1]=='y')))&&
                    ((str[p]==str[k])||//A A
                     ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                      (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                 ((str[p]=='s'||str[p]=='g')&&
                                                    (str[k]=='s'||str[k]=='g'))||
               ((str[p]=='c'||str[p]=='y')&&
                                                    (str[k]=='c'||str[k]=='y')))) {pom++;wynik++;break;}
                                                    else
                                                        p++;
            }
            }
        }
        if(pom==0&&dl>2)
        {
            p=dl-3;
            k=dl-1;
                            if((str[p]==str[k])||//A A
                ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                    ((str[p]=='s'||str[p]=='g')&&
                                                (str[k]=='s'||str[k]=='g'))||
                    ((str[p]=='c'||str[p]=='y')&&
                                                (str[k]=='c'||str[k]=='y'))) {wynik++;}
                                                else
                                                {
                                                    p=dl-4;
                            if(((str[p+1]==str[k-1])||//BB
                     ((str[p+1]=='b'||str[p+1]=='d'||str[p+1]=='p')&&
                                                  (str[k-1]=='b'||str[k-1]=='d'||str[k-1]=='p'))||
                     ((str[p+1]=='s'||str[p+1]=='g')&&
                                                    (str[k-1]=='s'||str[k-1]=='g'))||
               ((str[p+1]=='c'||str[p+1]=='y')&&
                                                    (str[k-1]=='c'||str[k-1]=='y')))&&
                    ((str[p]==str[k])||//A A
                     ((str[p]=='b'||str[p]=='d'||str[p]=='p')&&
                                                      (str[k]=='b'||str[k]=='d'||str[k]=='p'))||
                 ((str[p]=='s'||str[p]=='g')&&
                                                    (str[k]=='s'||str[k]=='g'))||
               ((str[p]=='c'||str[p]=='y')&&
                                                    (str[k]=='c'||str[k]=='y')))) {wynik++;}

                                                }
    }
   // if(dl==2 && pom==1)
  //      wynik--;
    }
    printf("%d\n",wynik);

    return 0;
}
