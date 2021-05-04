#include "fraction.h"

int NWD(int a, int b)
{
	int pom;
	while (0 != b) 
	{
		pom = b;
		b = a % b;
		a = pom;
		
	}
	return a;
}

int NWW(int a, int b)
{
	return a / NWD(a, b) * b;
}
Fraction::Fraction(int numerator, int denominator): numerator(0), denominator(1)
{	
	if (denominator == 0)
	{
		throw std::invalid_argument("Denominator cannot be equal 0");
	}
	setNumerator(numerator);
	setDenominator(denominator);

}


Fraction Fraction::operator+(Fraction& f1)
{	
	Fraction resault;
	
	int denominator = NWW(this->getDenominator(), f1.getDenominator());
	int numerator = (denominator / this->getDenominator()) * this->getNumerator() + (denominator / f1.getDenominator()) * f1.getNumerator();
	if ( f1.getDenominator()==0) 
	{
		throw std::invalid_argument("Denominator cannot be equal 0");
	}
	
	int nwd = NWD(denominator, numerator);
	resault.setNumerator(numerator/nwd);
	resault.setDenominator(denominator/nwd);
	
	return resault;
}

void Fraction::setDenominator(int den) 
{	
	if (den == 0) 
	{
		throw std::invalid_argument("Denominator cannot be equal 0");
	}
	denominator = den; 
}
Fraction Fraction::operator*(Fraction& f1) 
{
	Fraction resault;
	
	resault.setNumerator(this->getNumerator()* f1.getNumerator());
	resault.setDenominator(this->getDenominator() * f1.getDenominator());
	int a,b;
	a = resault.getNumerator();
	b = resault.getDenominator();
	
	if (a > 0 && b > 0)
	{
		int c = NWD(a, b);
		a = a / c;
		b = b / c;
	}
	resault.setDenominator(b);
	resault.setNumerator(a);
	return resault;
}
