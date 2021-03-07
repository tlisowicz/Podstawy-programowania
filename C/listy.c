#include <stdio.h>
#include <stdlib.h>

typedef struct Lista_Liczb
{
int liczba;
struct Lista_Liczb *nastepny;
} Liczba1, Liczba2, Liczba3,Liczba4;

Liczba1 *poczatek=NULL;

void dopisz(Liczba1 **poczatek, int liczba_wpisz){
    Liczba1 *wsk;
    wsk= malloc(sizeof(Liczba1));
    wsk->liczba= liczba_wpisz;
    wsk->nastepny= (*poczatek);
    *poczatek=wsk;
    const int num=1;
    printf("Elemnet Listy %d\n", wsk->liczba);
    }

int main()
{poczatek= malloc(sizeof(Liczba1));
dopisz(&poczatek, 6);
dopisz(&poczatek, 68);
dopisz(&poczatek, 7);
dopisz(&poczatek, 456);


}
