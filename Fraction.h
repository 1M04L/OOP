#pragma once
#include <iostream>
#include <algorithm>

class Fraction {
public:
	Fraction(int num = 0, int den = 1) {
		if (den == 0) {
			std::cout << " D-r cant be 0." << std::endl;
			m_numerator = 0;
			m_denominator = 1;
		} else {
			m_numerator = num;
			m_denominator = den;
		}
	}

	int numerator() const {
		return m_numerator;
	}
	int denominator() const {
		return m_denominator;
	}

	void setNumerator(int num) {
		m_numerator = num;
	}
	void setDenominator(int den) {
		if (den == 0) {
			std::cout << "D-r cant be 0." << std::endl;
			return;
		}
		m_denominator = den;
	}

	Fraction operator+(Fraction b);
	Fraction operator-(Fraction b);
	Fraction operator*(Fraction b);
	Fraction operator/(Fraction b);

	bool operator==(Fraction b);
	bool operator!=(Fraction b);
	bool operator<(Fraction b);
	bool operator>(Fraction b);

	bool operator<<(Fraction b);//check whatfor lower
	bool operator>>(Fraction b);

	Fraction operator^(Fraction b);

	void OutputFraction();

	Fraction InputFraction();

	void privedenieKnesokrat();


private:
	int m_numerator;
	int m_denominator;
};
