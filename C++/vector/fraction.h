#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include <stdexcept>

/** Implementacja ulamka:
Zaimplementuj klase Ulamek (ang. Fraction), posiadająca licznik (ang. numerator) i mianownik (ang. denominator).
       Powinna zawierac jeden konstruktor ustawiajacy licznik i mianownik (domyslne wartosci licznika=0 a mianownika domyslna 1)
       Gettery i settery do wartosci licznika i mianownika
          Settery nie powinny skracac ulamkow
       operator+ dla ulamka zwracajacy ulamek
       operator* dla ulamka zwracajacy ulamek
Niepoprawny mianownik powinien byc zglaszany przez wyjatek std::invalid_argument.
Prosze o skracanie ulamkow po operacji + i * (pomocny moze sie okazac algorytm euklidesa), oczywiscie tutaj robimy tylko dla przypadkow dodatnich
**/

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator=0, int denominator=1);
    int getNumerator()const { return numerator; }
    int getDenominator()const { return denominator; }
    void setDenominator(int den);
    void setNumerator(int num) { numerator = num; }
    Fraction operator+(Fraction& f1);
    Fraction operator*(Fraction& f1);
};

#endif // FRACTION_H
