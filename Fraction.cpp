#include"Fraction.h"

Fraction Fraction::operator+(Fraction b) {
	Fraction result;
	result.setNumerator(m_numerator * b.denominator() + b.numerator() * m_denominator);
	result.setDenominator(m_denominator * b.denominator());
	return result;
}

Fraction Fraction::operator-(Fraction b) {
	Fraction result;
	result.setNumerator(m_numerator * b.denominator() - b.numerator() * m_denominator);
	result.setDenominator(m_denominator * b.denominator());
	return result;
}

Fraction Fraction::operator*(Fraction b) {
	Fraction result;
	result.setNumerator(m_numerator * b.numerator());
	result.setDenominator(m_denominator * b.denominator());
	return result;
}

Fraction Fraction::operator/(Fraction b) {
	if (b.numerator() == 0) {
		std::cout << "Cant divide by fraction with 0 in n-r's place." << std::endl;
		return Fraction(0, 1);
	}
	Fraction result;
	result.setNumerator(m_numerator * b.denominator());
	result.setDenominator(m_denominator * b.numerator());
	return result;
}

bool Fraction::operator==(Fraction b) {
	return (m_numerator * b.denominator() == b.numerator() * m_denominator);
}

bool Fraction::operator!=(Fraction b) {
	return !(*this == b);
}

bool Fraction::operator<(Fraction b) {
	return (m_numerator * b.denominator() < b.numerator() * m_denominator);
}

bool Fraction::operator>(Fraction b) {
	return (m_numerator * b.denominator() > b.numerator() * m_denominator);
}


//uniqueMeth1(it finds whose num-r is bigger)
bool Fraction::operator<<(Fraction b) {
	return (m_numerator < b.numerator());
}

//uniqueMeth2(it finds whose din-r is bigger)
bool Fraction::operator>>(Fraction b) {
	return (m_denominato < b.m_denominator);
}


void Fraction::OutputFraction()
{
	std::cout<<m_numerator<<"/"<<m_denominator<<std::endl;
}

Fraction Fraction::InputFraction()
{
	int num, den;
	std::cout << " numerator?: ";
	std::cin >> num;
	std::cout << "denominator?: ";
	std::cin >> den;
	return Fraction(num, den);
}

void Fraction::privedenieKnesokrat()
{
	int NOD = 1;
	for (int i = 1; i <= std::min(m_numerator, m_denominator); ++i) {
		if (m_numerator % i == 0 && m_denominator % i == 0) {
			NOD = i;
		}
	}
	m_numerator /= NOD;
	m_denominator /= NOD;
}










