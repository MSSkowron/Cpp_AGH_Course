#include <iostream>
#include <cstring>
#include <cctype>
#include <ostream>
#include <istream>
#include <sstream>

using namespace std;

#include "fraction.h"

#if IMPLEMENTED_classFractionExists
#ifndef _MSC_FULL_VER // if not Visual Studio Compiler
    #warning "Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym"
#else
    #pragma message ("Klasa jest do zaimplementowania. Instrukcja w pliku naglowkowym")
#endif

int Fraction::getNumerator() const{
    return numerator;
}
void Fraction::setNumerator(int n){
    numerator = n;
}
int Fraction::getDenominator() const{
    return denominator;
}
void Fraction::setDenominator(int d){
    denominator = d;
}
void Fraction::print() const{
    cout << numerator <<"/"<<denominator<<"\n";
}
int Fraction::removedFractions() {
    return removedFractions_;
}
std::string Fraction::getFractionName() const{
    return fractionName;
}
int Fraction::getInvalidDenominatorValue() {
    return invalidDenominatorValue;
}
int Fraction::getDefaultDenominatorValue(){
    return defaultDenominatorValue;
}
//Zapisuje zawartość obiektu do przekazanego jako parametr strumienia wyjściowego("licznik/mianownik").
void Fraction::save(std::ostream& os) const{
    string strNumerator = to_string(numerator);
    string strSlash = "/";
    string strDenominator = to_string(denominator);
    string str_result = strNumerator + strSlash + strDenominator;
    os << str_result;
}
//Wczytuje zawartość do obiektu ze strumienia wejściowego("licznik/mianownik").
void Fraction::load(std::istream& is){
    string num = "";
    string denumerator="";
    while(is){
        char o = char(is.get());
        if(o=='/'){
            break;
        }
        if(isdigit(o)){
            num += o;
        }
    }
    while(is){
        char o = char(is.get());
        if(isdigit(o)){
            denumerator += o;
        }
    }

    setNumerator(stoi(num));
    setDenominator(stoi(denumerator));
}
int Fraction::removedFractions_ = 0;
#endif // IMPLEMENTED_classFractionExists

