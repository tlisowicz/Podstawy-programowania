#include <stdio.h>
#include   <string.h>
int main()
{
    FILE *plik=fopen("Plik1.txt", "r");
    FILE *plik2=fopen("Plik2.txt", "w");
    if(plik==NULL)
    {
        perror(NULL);
    }
    char ch;
    ch= fgetc(plik);
    while(ch !=EOF)
    {
        fputc(ch, plik2);
        ch=fgetc(plik);
    }
    fclose(plik);
    fclose(plik2);
    return 0;
}


