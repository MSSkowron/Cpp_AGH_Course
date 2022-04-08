#include <iostream>
#include <stdexcept> // std::out_of_range
#include <numeric> // std::gcd/lcm

#include "fraction.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

Fraction &Fraction::operator+(const Fraction &other)
{

    int lcm =  std::lcm(denominator_,other.denominator_);
    int first = lcm / denominator_;
    int second = lcm / other.denominator_;

    numerator_ = (numerator_*first) + (other.numerator_*second);
    denominator_ = lcm;

    simplify();

    return *this;
}

Fraction &Fraction::operator*(const Fraction &other)
{
    if(this == &other)
    {
        return *this;
    }

    numerator_ = numerator_ * other.numerator_;
    denominator_ = denominator_ * other.denominator_;

    simplify();

    return *this;
}

void Fraction::simplify() {
    int gcd = std::gcd(numerator_,denominator_);
    numerator_ /= gcd;
    denominator_ /= gcd;
}
