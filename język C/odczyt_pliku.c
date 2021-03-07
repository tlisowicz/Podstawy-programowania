#include <stdio.h>


int main()
{
    FILE *plik=fopen("Plk.txt", "r");
    if(plik==NULL)
    {
        perror(NULL);
        exit(1);
    }
    char tekst[100];
    fscanf(plik, "%s", tekst);
    printf("%s", tekst);

    return 0;
}

