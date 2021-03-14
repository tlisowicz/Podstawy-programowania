#include <iostream>

using namespace std;

class StudenckaLodowka{
        public:
        StudenckaLodowka();
        ~StudenckaLodowka();
    class Chlodnia{
        public:
        Chlodnia();
        ~Chlodnia();
    };
    class Zamrazalnik{
        public:
        Zamrazalnik();
        ~Zamrazalnik();
    };
    
};

StudenckaLodowka::StudenckaLodowka(){
    cout<<"Kreuje Lodowke"<<endl;
}
StudenckaLodowka::Chlodnia::Chlodnia(){
    cout<<"Kreuje Chlodnie"<<endl; 
}

StudenckaLodowka::Zamrazalnik::Zamrazalnik(){
    cout<<"Kreuje Zamrazalnik"<<endl; 
}

StudenckaLodowka::~StudenckaLodowka(){
    cout<<"Usuwam Lodowke"<<endl;
}
StudenckaLodowka::Chlodnia::~Chlodnia(){
    cout<<"Usuwam Chlodnie"<<endl; 
}

StudenckaLodowka::Zamrazalnik::~Zamrazalnik(){
    cout<<"Usuwam Zamrazalnik"<<endl; 
}
int main(){
    StudenckaLodowka l1;
    StudenckaLodowka::Zamrazalnik zamrazalnik;
    StudenckaLodowka::Chlodnia chlodnia;

}