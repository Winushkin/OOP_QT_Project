#include "complex.h"
#include <sstream>

QChar TComplex::SEPARATOR = ';';

using namespace std;

//Constructors
TComplex::TComplex() {
    re = im = 0;
}


TComplex::TComplex(double re) {
    this->re = re;
    im = 0;
}


TComplex::TComplex(double re, double im){
    this->re = re; this->im = im;
}

//Methods
double TComplex::getRe() const{
    return this->re;
}


double TComplex::getIm() const{
    return this->im;
}


double TComplex::module(TComplex *complex) {
    double a = std::pow(complex->getRe(),2);
    double b = std::pow(complex->getIm(), 2);
    return std::pow(a + b, 0.5);
}


TComplex pow(TComplex complex, double n){
    double argZ;
    if(complex.re > 0) argZ = atan(complex.im / complex.re);
    else if(complex.re < 0 && complex.im >= 0) argZ = 3.14 - atan(complex.im / complex.re);
    else if(complex.re < 0 && complex.im < 0) argZ = -3.14 + atan(complex.im / complex.re);
    else if(complex.re == 0 && complex.im > 0) argZ = 3.14/2;
    else argZ = -3.14/2;
    return TComplex(std::pow(complex.module(&complex), n) * cos(argZ * n),
                    std::pow(complex.module(&complex), n) * sin(argZ * n));
}


std::string TComplex::to_str() const {
    ostringstream s;
    if ( im < 0 ){
        s << re << " " << im << "i";
    }
    else if ( im == 0 ) {
        s << re;
    }else{
        s << re << " + " << im << "i";
    }
    string result = s.str();
    return result;
}



//Overloads
TComplex TComplex::operator+(TComplex &second) const{
    return TComplex(re + second.re, im + second.im);
}


TComplex TComplex::operator-(TComplex &second) const{
    return TComplex(re - second.re, im - second.im);
}


TComplex TComplex::operator/(TComplex &second) const{
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    return TComplex(a, b);
}


TComplex TComplex::operator*(TComplex &second) const{
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    return TComplex(a, b);
}


TComplex TComplex::operator+=(TComplex second){
    re += second.re;
    im += second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator-=(TComplex second){
    re -= second.re;
    im -= second.im;
    return TComplex(re, im);
}


TComplex TComplex::operator/=(TComplex second){
    double a = (re * second.re + im * second.im)/(second.re * second.re + second.im * second.im);
    double b = (second.re * im - re * second.im)/(second.re * second.re + second.im * second.im);
    re = a;
    im = b;
    return TComplex(re, im);
}


TComplex TComplex::operator*=(TComplex second){
    double a;
    double b;
    a = re * second.re - im * second.im;
    b = re * second.im + im * second.re;
    re = a;
    im = b;
    return TComplex(re, im);
}


bool TComplex::operator==(TComplex &second) const{
    if(re == second.re && im == second.im) return true;
    return false;
}


bool TComplex::operator!=(int second) const{
    if(re == second && im == 0) return false;
    return true;
}


bool TComplex::operator!=(TComplex &second) const{
    if(re != second.re || im != second.im) return true;
    return false;
}


std::ostream &operator<<(std::ostream &os, const TComplex &complex){
    if (complex.im < 0 && complex.re != 0){
        os << complex.re << complex.im << "i";
    }else if (complex.im != 0 && complex.re == 0){
        os << complex.im << "i";
    }else if (complex.im > 0 && complex.re != 0){
        os << complex.re << "+" << complex.im << "i";
    }else if (complex.im == 0 && complex.re != 0){
        os << complex.re;
    }else {
        os << "0";
    }
    return os;
}


std::istream &operator>>(std::istream & in, TComplex &complex){
    in >> complex.re >> complex.im;
    return in;
}


bool TComplex::operator<(TComplex &second){
    if(module(this) < module(&second)) return true;
    if(module(this) == module(&second)){
        if(atan(this->im/this->re) < atan(second.im/second.re)) return true;
    }
    return false;
}


bool TComplex::operator>(TComplex &second){
    if(module(this) > module(&second)) return true;
    if(module(this) == module(&second)){
        if(atan(this->im/this->re) > atan(second.im/second.re)) return true;
    }
    return false;
}


TComplex TComplex::operator+=(double second){
    re += second;
    return TComplex(re, im);
}


TComplex TComplex::operator/=(double second){
    double a = (re * second)/(second * second);
    double b = (second * im)/(second * second);
    re = a;
    im = b;
    return TComplex(re, im);
}


TComplex TComplex::operator=(double &second){
    return TComplex(second, 0);
}


TComplex TComplex::operator*(int second) const {
    double a;
    double b;
    a = re * second;
    b = im * second;
    return TComplex(a, b);
}

bool TComplex::operator==(int second) const {
    if(re == second && im == 0) return true;
    return false;
}

bool TComplex::operator>(int second) {
    if(module(this) > second) return true;
    if(module(this) == second){
        if(atan(this->im/this->re) > atan(0))return true;
    }
    return false;
}

TComplex::TComplex(const QByteArray &arr) { //added in 5
    int p = arr.indexOf(SEPARATOR.toLatin1());
    re = arr.left(p).toDouble();
    im = arr.right(arr.length()-p-1).toDouble();
}

void TComplex::setSeparator(QChar ch) { //added in 5
    SEPARATOR = ch;
}

TComplex::operator QString() { // added in 5
    QString s = "(";
    s += QString().setNum(re);
    s += "+";
    s += QString().setNum(im);
    s += "i)";
    return s;
}

QByteArray &operator>>(QByteArray &arr, TComplex &c) {
    int p = arr.indexOf(TComplex::SEPARATOR.toLatin1());
    p = arr.indexOf(TComplex::SEPARATOR.toLatin1(),p+1);
    if (p > 0) {
        c = TComplex(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

TComplex TComplex::operator/(double second) const {
    double a = (re * second + im * 0)/(second * second + 0);
    double b = (second * im - re * 0)/(second * second + 0);
    return TComplex(a, b);
}
