#ifndef VECTOR_H
#define VECTOR_H

// author: Grzegorz Prowadzacy
#include "fraction.h"
#include "utils/memoryManagement.h"

/** Tresc zadania:
Ćw3 [17pkt] Klasy z dynamiczną zawartością, wyjątki (UWAGA: To bardzo wazne zadanie, jeśli ktoś chce być programista C++ to w srodku nocy powinien umiec takie zadania robic!)
Plan zajęć:

Panstwa zadaniem jest napisanie automatycznie rozszerzajacej sie tablicy dynamicznej
    (zwanej potocznie Vector), oraz funkcji do jej obslugi.
    Nasz Vector ma byc tablica elementow typu Fraction.
    Nasza implementacja wzorowana C++owym std::vector, aczkolwiek inna: http://www.cplusplus.com/reference/vector/vector/
Nie wolno uzyc w srodku std::vector! Zaawansowani moga uzyc uzyc inteligetnych wskaznikow, jesli chca.
Nasza implementacja w razie automatycznego zwiekszania rozmiaru ma allokowac pamiec tylko o 1 wieksza!
    Ma to byc klasa Vector, ktora zawiera w sobie:
    - wskaznik na tablice dynamiczna (ang. data)
    - rozmiar aktualnie zaalokowanej tablicy dynamicznej (ang. capacity)
    - ilosc elementow w tablicy (ang. size)
    Ponadto proszę o zaimplementowanie metod zwracającej liczbę elementów w tablicy size(), wielkosc tablicy capacity()

    Uzupełnij drugą klasę o następujące elementy:
        - konstruktor przyjmujacy liczbe do wstepnej allokacji (z wartoscia domyslna 0)
        - destruktor (zwalniajacy pamiec),
        - konstruktor kopiujący (gleboko) oraz przenoszący,
        - operator podstawienia oraz przenoszący operator podstawienia,
        - metodę dodającą obiekt na koncu tablicy push_back()
        - operator dostepu po indeksie operator[](size_t index)
    Dostep po indeksie poza rozmiar tablicy (size) powinny być zgłaszane poprzez wyjątki std::out_of_range
    Auto-realokacja tablicy w razie braku elementow

    Deklaracje klasy powinny znaleźć się w odpowiednich plikach nagłówkowych, definicje metod i konstruktorów - w plikach źródłowych.
    Wszystkie atrybuty powinny być prywatne, konstruktory i metody - publiczne, metody/konstruktory/destruktory większe niż 1-linijkowe powinny być zadeklarowane w klasie, zdefiniowane poza klasą,

    Obiekty typów klasowych powinny być przekazywane do funkcji/metod przez referencje (zwykłe lub stałe), metody niemodyfikujące zawartości klasy powinny być oznaczane jako const.
    Wszystkie metody, które mogą być stałe proszę aby były

Uwaga:
    co się da na listę inicjalizacyjną konstruktora
    za złe zarządzanie pamięcią (wycieki, pisanie poza pamięcią) mogą być odejmowane punkty

Podpowiedzi:
    - polecam uzycie operatora :?
    - mozna allokowac zero elementow: new int[0];
    - polecam uzycie std::gcd(), ale mozna skracac recznie
**/


class Vector
{
private:
    Fraction* data;
    size_t capacity;
    int size;
public: 
    Vector(int v=0);
    ~Vector();
    Vector(const Vector&& v1);
    void push_back(Fraction u);
    Fraction operator[](size_t index);
    //void setCapacity(int c) { capacity = c; }
  //  void Size(int s) { size = s; }
    size_t Capacity()const { return capacity; }
    int Size()const { return size; }
};

#endif // VECTOR_H
