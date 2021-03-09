#include <iostream>
#include <math.h>
using namespace std;

#define pi 3.14

class Kolo{
    
    double promien;
public:
    Kolo();
    Kolo(double _promien);
    void area();
    void perimeter();
};

class Prostokat{
    
    double bok1;
    double bok2;
public:
    Prostokat(double _bok);
    Prostokat(double _bok1, double _bok2);
    void area();
    void perimeter();

};

class Trojkat{
   
    double bok1;
    double bok2;
    double bok3;
public:
    Trojkat(double _bok);
    Trojkat(double _bok1, double _bok2, double _bok3 );
    void area();
    void perimeter();

};

void Kolo::area(){
   
   cout<<promien*promien*pi<<endl;
}

void Kolo::perimeter(){
    
    cout<<pi*promien*2<<endl;
}

void Prostokat::area(){
   
   cout<<bok1*bok2<<endl;
}

void Prostokat::perimeter(){
   
   cout<<2*bok1+2*bok2<<endl;
}

void Trojkat::area(){
   
   double p = (1/2)*(bok1+bok2+bok3);
   double a= p*(p-bok1)*(p-bok2)*(p-bok3);
   cout<<sqrt(a)<<endl;
}

void Trojkat::perimeter(){
    
    cout<<bok1+bok2+bok3<<endl;
}



Kolo::Kolo(double _promien){
    
    this->promien=_promien;
    cout<<"Konstruuje kolo"<<endl;

}

Trojkat::Trojkat(double _bok1, double _bok2, double _bok3 ){
    cout<<"Konstruuje trojkat roznoboczny";
    this->bok1=_bok1;
    this->bok2=_bok2;
    this->bok3=_bok3;
    
}

Trojkat::Trojkat(double _bok){
    cout<<"Konstruuje trojkat rownoboczny";
    this->bok1=_bok;
    this->bok2=_bok;
    this->bok3=_bok;
    
}

Prostokat::Prostokat(double _bok1, double _bok2){
    cout<<"Konstruuje prostokat"<<endl;
   this->bok1=_bok1;
   this->bok2=_bok2;
}

Prostokat::Prostokat(double _bok){
    cout<<"Konstruuje kwadrat"<<endl;
   this->bok1=_bok;
   this->bok2=_bok;
}

int main(){

    Kolo k1(5.3);
    k1.area();
    k1.perimeter();
    Trojkat t1(3.5, 4.6, 5.7);
    t1.area();
    t1.perimeter();
    Prostokat p1(6);
    p1.area();
    p1.perimeter();
}