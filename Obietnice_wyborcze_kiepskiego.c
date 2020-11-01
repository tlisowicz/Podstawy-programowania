#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
srand(time(NULL));
switch (rand()%4){
case 1: printf("Kielbasę browary\n");
break;
case 2: printf("Inne towary\n");
break;
case 3: printf("Opiekę lekarską\n");
break;
case 4: printf("Rentę wysoką\n");
break;}
return 0;}

