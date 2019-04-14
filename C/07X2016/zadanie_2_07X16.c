#include <stdio.h>

int main(void)
{
    int lata, okresow_w_roku, rok, okres, kwota_pocz, kwota;
    float procent, podatek;

    podatek=0.19;

    printf("Podaj kwote poczatkowa\n");
    scanf("%d",&kwota_pocz);

    printf("Podaj liczbe lat\n");
    scanf("%d",&lata);

    printf("Podaj ilosc okresow w roku\n");
    scanf("%d",&okresow_w_roku);

    printf("Podaj oprocentowanie\n");
    scanf("%f",&procent);


    kwota_pocz*=100;
    kwota=kwota_pocz; rok=1;

    printf("\n_______________\n|Rok\t|Kwota|\n __________________\n");
    while (rok <= lata) {
        okres=1;
        while (okres <= okresow_w_roku) {
            kwota=kwota*(1.0+(procent/okresow_w_roku)*(1-podatek));
            okres=okres+1;
        }

        printf("|%d\t|%9.2f|\n",rok,kwota/100.0);
        rok=rok+1;
    }
    printf(" __________________");
    return 0;
}
