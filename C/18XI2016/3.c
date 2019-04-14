#include <stdio.h>
#include <stdlib.h>

void Output_Buffer_State(void);
void Clear_Buffer(char* b);
char* Assign_Block(long l,char* b);
char* Find_Block(char c, long l);
void Set_Block(char *b, long l, char c);
char* Relocate(void);
void Process_Request(void);
void p(char* b);
void Release_Block(char *b, long l);
int Buffer_Empty(void);

int rozm;
int main()
{
    scanf("%d",&rozm);
    char T[rozm];
   // printf("%p",T);
    Clear_Buffer(T);
    p(T);
    free(T);
    return 0;
}
void Clear_Buffer(char* b)
{
    int i = 0;
    while(1)
    {*(b+i)='0';
        i=i+1;
        if(i==rozm)
            break;
    }
}
void p(char* b)
{
    int i = 0;
    while(i<rozm)
    {
        if(*(b+i)=='0')
            printf("_");
        else
            printf("%c",*(b+i));
        i+=1;
    }
}
char* Assign_Block(long l,char* b)
{
    char* pom=b;


    free(pom);
    return b;
}
