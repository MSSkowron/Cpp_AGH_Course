#include <iostream>
#include <string>
#include <ostream>
using namespace std;
#include "matrix.h"

#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

TwoDimensionMatrix::TwoDimensionMatrix() {
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size ; j++)
        {
            matrix[i][j] = 0;
        }
    }
}

TwoDimensionMatrix::TwoDimensionMatrix(const MatrixElement m[size][size])
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size ; j++)
        {
            matrix[i][j] = m[i][j];
        }
    }
}

TwoDimensionMatrix &TwoDimensionMatrix::operator=(const TwoDimensionMatrix &tdm) {
    for (int i = 0; i < size; i ++)
    {
        for (int j = 0; j < size; j++ )
        {
            matrix[i][j] = tdm.matrix[i][j];
        }
    }
    return *this;
}

MatrixElement TwoDimensionMatrix::get(int row, int column) const {
    return matrix[row][column];
}

std::ostream &operator<<(std::ostream &os, const TwoDimensionMatrix &t) {
    os << t.matrix[0][0] << " " << t.matrix[0][1] << endl
    << t.matrix[1][0] << " " << t.matrix[1][1] << endl;
    return os;
}

std::istream &operator>>(std::istream &is, TwoDimensionMatrix &t) {
    is >> t.matrix[0][0];
    is.ignore(1);
    is >> t.matrix[0][1];
    is.ignore(1);
    is >> t.matrix[1][0];
    is.ignore(1);
    is >> t.matrix[1][1];
    return is;
}

TwoDimensionMatrix operator+(const TwoDimensionMatrix &matrix1, const TwoDimensionMatrix &matrix2) {
    TwoDimensionMatrix m;
    size_t size = matrix1.getSize();
    for (int i = 0; i < size ; i++ )
    {
        for (int j = 0; j < size; j++)
        {
            m.matrix[i][j] = matrix1.matrix[i][j] + matrix2.matrix[i][j];
        }
    }
    return m;
}

MatrixElement *TwoDimensionMatrix::operator[](size_t i) {
    return matrix[i];
}

const MatrixElement *TwoDimensionMatrix::operator[](size_t i) const {
    return matrix[i];
}

TwoDimensionMatrix &TwoDimensionMatrix::operator*=(MatrixElement number) {
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            matrix[i][j] *= number;
        }
    }

    return *this;
}

TwoDimensionMatrix TwoDimensionMatrix::operator&&(const TwoDimensionMatrix & m) const {
    TwoDimensionMatrix result_m;
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            result_m[i][j] = matrix[i][j] && m.matrix[i][j];
        }
    }
    return result_m;
}

TwoDimensionMatrix::operator size_t() const {
    return getSize();
}

