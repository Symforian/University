
#ifndef PROT_H
#define PROT_H
extern int n,m;
extern int A[10000],mniejsze[10000],rowne[10000];
void input_and_check_data(void);
void output_data(int B[]);
void C_K_E(int *A, int n, int m);//licz rowne klucze
void C_K_L(int *rowne, int m);//licz mniejsze klucze
void Reorg(int *A,int *mniejsze, int n, int m);//reorganizuj
void C_S(int *A, int n, int m);//sort przez zliczanie

#endif // PROT_H
