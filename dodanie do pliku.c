#include <stdio.h>
int main()
{
    FILE *plik=fopen("Sapkowski.txt", "w");
    if(plik==NULL)
    {
        perror(NULL);
    }

    fprintf(plik, "%s", "Lepiej zaliczać się do niektórych niż do wszystkich\n");
    fclose(plik);
    fopen("Sapkowski.txt", "a");
    fprintf(plik, "%s", "Lepiej bez celu iść naprzód niż bez celu stać w miejscu, a z pewnością o niebo lepiej, niż bez celu się cofać");
    fclose(plik);
    return 0;
}


