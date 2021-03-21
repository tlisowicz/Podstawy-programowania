#include <iostream>

using namespace std;

class Zwierze{

public:
    string gatunek;
    string imie;
    Zwierze(string imie, string gatunek): imie(imie), gatunek(gatunek){} 
};

class CzlowiekZnanyZWidzenia
{

protected:
    string cechaCharakterystyczna;

public:
    CzlowiekZnanyZWidzenia(string ch): cechaCharakterystyczna(ch){};
    
    void set(string ch)
    {
        cechaCharakterystyczna=ch;
    }

    void get()const
    {
        cout<<"Cecha charakterystyczna: "<<cechaCharakterystyczna<<endl;
    }
};

class CzlowiekZnanyZImienia: public CzlowiekZnanyZWidzenia
{

protected:
    string imie;

public:
    CzlowiekZnanyZImienia(string imie, string ch): imie(imie), CzlowiekZnanyZWidzenia(ch){}
    
    void set(string imie)
    {
        this->imie=imie;
    }

    string get()const
    {
        return imie;
    }
};

class CzlowiekZnanyZInternetu
{

protected:
    string gdziePoznany;
    string CzymZwrocilMojaUwage;

public:
    CzlowiekZnanyZInternetu(string gP, string CZMU): gdziePoznany(gP), CzymZwrocilMojaUwage(CZMU){};
    
    void set(string gP, string CZMU)
    {
        gdziePoznany=gP;
        CzymZwrocilMojaUwage=CZMU;
    }

    void get()const
    {
        cout<<"gdziePoznany: "<<gdziePoznany<<endl<< "CzymZwrocilMojaUwage: "<<CzymZwrocilMojaUwage<<endl;
    }
};

class DobrzeZnanyKolega: public CzlowiekZnanyZImienia, public CzlowiekZnanyZInternetu
{

protected:
    string skadGoZnam;
    Zwierze ZwierzeDomowe;

public: 
        DobrzeZnanyKolega(string sGz, Zwierze zwierze, string imie, string ch, string gP, string CZMU): skadGoZnam(sGz), ZwierzeDomowe(zwierze),   CzlowiekZnanyZImienia(imie, ch), CzlowiekZnanyZInternetu(gP, CZMU) {};
    
    void set(string sGz, Zwierze &zwierze)
    {
       skadGoZnam=sGz;
       ZwierzeDomowe=zwierze;
    }

    void get()const
    {
        cout<<"Imie kolegi: "<<CzlowiekZnanyZImienia::get()<<endl;
        cout<<"skadGoZnam: "<<skadGoZnam<<endl;
        cout<<"ZwierzeDomowe: "<<ZwierzeDomowe.gatunek<<" "<<ZwierzeDomowe.imie<<endl;
        CzlowiekZnanyZInternetu::get();
        CzlowiekZnanyZWidzenia::get();
        

    }
};

int main(){
    Zwierze z1("Burek", "Pies");
    DobrzeZnanyKolega kolega("Ze szkoly", z1, "Wojtek", "Wiekie dlonie", "W szkole", " Ma podobne zainteresowania" );
    kolega.get();
   


}