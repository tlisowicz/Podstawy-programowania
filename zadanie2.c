#include <stdio.h>
int main ()
{printf("Pytanie za 40 000zl:  Który instrument stroi muzyk?:\n 1.kocioł\n 2. okarynę\n");
int a;
scanf("%d", &a);
    switch (a) {
        case 1: printf("Grasz dalej");
            goto pytanie_2;
        break;
        case 2: printf("Zła odpowiedź");
        break;
pytanie_2:
    printf("Pytanie za 100 000zl:  Z gry na jakim instrumencie słynie Czesław Mozil?:\n 1.na akordeonie\n 2. na kornecie\n");
        int b;
    scanf("%d", &b);
    switch (b) {
        case 1: printf("Grasz dalej");
            goto pytanie_3;
        break;
        case 2: printf("Zła odpowiedź");
        break;
pytanie_3:
        printf("Pytanie za 1 000 000zl:   Ile to jest 1111 razy 1111, jeśli 1 razy 1 to 1, a 11 razy 11 to 121?:\n 1.123 434 321\n 2. 1 234 321\n");
                int c;
    scanf("%d", &c);
    switch (c) {
        case 1: printf("Zła odpowiedź");
            goto pytanie_3;
        break;
        case 2: printf("Wygałeś 1mln!");
        break;}}
        }

return 0;}
