#include <iostream>
#include <cmath>
#include <QString>
using namespace std;


#ifndef OOP_PRACTICE_2_COMPLEX_H
#define OOP_PRACTICE_2_COMPLEX_H


class TComplex{
    double re;
    double im;
    static QChar SEPARATOR; //added in 5

public:

    TComplex();

    TComplex(double re, double im);

    TComplex(const QByteArray&); //added in 5

    TComplex(double re);

    double getRe() const;

    double getIm() const;

    double module(TComplex *complex);

    std::string to_str() const;

    TComplex operator+(TComplex &second) const;

    TComplex operator-(TComplex &second) const;

    TComplex operator/(TComplex &second) const;

    TComplex operator/(double second) const;

    TComplex operator*(TComplex &second) const;

    TComplex operator*(int second) const;

    TComplex operator+=(TComplex second);

    TComplex operator-=(TComplex second);

    TComplex operator/=(TComplex second);

    TComplex operator*=(TComplex second);

    TComplex operator+=(double second);

    TComplex operator/=(double second);

    TComplex operator=(double &second);

    bool operator==(TComplex &second) const;

    bool operator!=(int second) const;

    bool operator!=(TComplex &second) const;

    bool operator<(TComplex &second);

    bool operator>(TComplex &second);

    bool operator>(int second);

    bool operator==(int second) const;

    static void setSeparator(QChar);//added in 5

    operator QString ();//added in 5

    friend TComplex pow(TComplex complex, double n);
    friend istream& operator >> (istream & in, TComplex & c);
    friend ostream& operator << (ostream & os, const TComplex & c);
    friend QByteArray& operator>>(QByteArray&,TComplex&);

};


#endif //OOP_PRACTICE_2_COMPLEX_H
