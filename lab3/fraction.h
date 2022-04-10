#include <iostream>

#ifndef FRACTION_H
#define FRACTION_H

class Fraction
{
private:
    void simplify();
    int numerator_;
    int denominator_;
public:
    explicit Fraction(int n = 0, int d = 1): numerator_{n}
    {
        if (d == 0) {throw std::invalid_argument("Denominator cannot be 0!\n");}
        denominator_ = d;
    }

    [[nodiscard]] auto numerator() const
    {
        return numerator_;
    }

    void setNumerator(int n) noexcept
    {
        numerator_ = n;
    }

    [[nodiscard]] auto denominator() const noexcept
    {
        return denominator_;
    }

    void setDenominator(int d)
    {
        if(d == 0){throw std::invalid_argument("Denominator cannot be 0!\n");}
        denominator_ = d;
    }

    Fraction& operator+(const Fraction&);
    Fraction& operator*(const Fraction&);
};
#endif // FRACTION_H
