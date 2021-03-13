#include <iostream>

using namespace std;

int *doubleCopy(int *start, int *end){

if (start==NULL || end==NULL) return NULL;
int rozmiar= end-start+1;
int* tab = new int[rozmiar];

for( int i=0; i<rozmiar; ++i){
    tab[i]= *(start+i)*2;
}
return tab;
} 

int main(){

int tab[5]= {1, 6, 7, 4, 3};
int *tab2=doubleCopy(&tab[0], &tab[5]);

for (int i=0; i<5; ++i){
    cout<< tab2[i]<<" ";
}

return 0;}