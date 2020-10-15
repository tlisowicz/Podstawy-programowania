#include <stdio.h>

int main()
{printf("Pokażę ci różnicę między operatorami  & i &&. Podaj dwie liczby całkowite:\n");
int liczba1, liczba2;
scanf("%i\n", &liczba1);
scanf("%i", &liczba2);
printf("Jeżeli użyjesz & to dwie liczby zostaną przemnożone bitowo i otrzymasz wynik %d\n", liczba1 & liczba2);
printf("Jeżeli użyjesz && to program wykona iloczyn logiczny w tym przypadku zostanie przyjęte prawda(1) i prawda(1) czyli otrzymasz %d\n", liczba1 && liczba2);
return 0;}
