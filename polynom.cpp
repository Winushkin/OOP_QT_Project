#include "polynom.h"


Polynom::Polynom(): coefficients(nullptr), roots(nullptr), degree(0) {}


number Polynom::valueAtPoint(number point){
    number sum = 0;
    if(degree == 0) return *(coefficients);
    for(int i = 0; i < degree; i++){
        number a = *(coefficients + i);
        number b = pow(point, degree - i);
        sum += a * b;
    }
    sum += *(coefficients + degree);
    return sum;
}


Polynom *Polynom::fill(number leadingCoefficient, number* roots, int rootsCount) {
    Polynom* polynom = new Polynom();
    polynom->roots = roots;
    polynom->coefficients = new number [rootsCount];
    polynom->coefficients[0] = leadingCoefficient;
    if(rootsCount > 1){
        polynom->degree = rootsCount - 1;
        for (int i = 1; i <= polynom->degree; ++i) {
            polynom->coefficients[i] = 0;
        }
        for (int i = 0; i < polynom->degree; ++i) {
            number root = roots[i];
            for (int j = i; j >= 0; --j) {
                polynom->coefficients[j + 1] += polynom->coefficients[j];
                polynom->coefficients[j] *= root * -1;
            }
        }
        for(int i = 0; i < rootsCount / 2; i++){
            swap(polynom->coefficients[i], polynom->coefficients[rootsCount - i - 1]);
        }
    }else polynom->degree = 0;
    return polynom;
}


ostringstream Polynom::polynomWithRoots() {
    ostringstream s;
    s <<  "p(x) = ";
    if(*(coefficients) != 0) {
        if(*(coefficients) != 1) s << *(coefficients);
        for(int i = 0; i < degree; i++){
            if(*(roots + i) != 0){
                if (*(roots + i) > 0) {
                    s << "(x-" << *(roots + i) << ")";
                } else {
                    s << "(x+" << (*(roots + i) * -1) << ")";
                }
            }else{
                s << "x";
            }
        }
    }else{
        s << "0";
    }
    return s;
}


ostringstream Polynom::polynomWithDegrees() {
    ostringstream s;
    s << "p(x) = ";
    if(roots == nullptr) {
        s << *(coefficients);
        return s;
    }
    if (*(coefficients) != 0){
        if(*(coefficients) != 1) s << " (" << *(coefficients) << ") x^" << degree;
        else s << "x^" << degree;
    }
    for ( int i = 1; i < degree - 1; i++ ){
        if (*(coefficients + i) != 0){
            s << " ";
            if(*(coefficients + i) > 0) s << "+";
            if (*(coefficients + i) != 1) s << "(" <<  *(coefficients + i) << ") x^" << degree - i;
            else s << "x^" << degree - i;
        }
    }
    if ( *(coefficients + degree - 1) != 0 ){
        if(*(coefficients + degree - 1) > 0){
            s << " + (" << *(coefficients + degree - 1) << ")x";
        }else s << " (" << *(coefficients + degree - 1) << ")x";
    }
    if ( *(coefficients + degree) != 0 ){
        if(*(coefficients + degree) > 0 ) s << " +" ;
        s << " (" << *(coefficients + degree) << ")";
    }
    return s;
}



std::ostream &operator<<(std::ostream &os, const Polynom &polynom) {
    os << "p(x) = ";
    if(polynom.roots == nullptr) {
        os << *(polynom.coefficients);
        return os;
    }
    if (*(polynom.coefficients) != 0){
        if(*(polynom.coefficients) != 1) os << " (" << *(polynom.coefficients) << ") x^" << polynom.degree;
        else os << "x^" << polynom.degree;
    }
    for ( int i = 1; i < polynom.degree - 1; i++ ){
        if (*(polynom.coefficients + i) != 0){
            os << " ";
            if(*(polynom.coefficients + i) > 0) os << "+";
            if (*(polynom.coefficients + i) != 1) os << "(" <<  *(polynom.coefficients + i) << ") x^" << polynom.degree - i;
            else os << "x^" << polynom.degree - i;
        }
    }
    if ( *(polynom.coefficients + polynom.degree - 1) != 0 ){
        if(*(polynom.coefficients + polynom.degree - 1) > 0){
            os << " + (" << *(polynom.coefficients + polynom.degree - 1) << ")x";
        }else os << " (" << *(polynom.coefficients + polynom.degree - 1) << ")x";
    }
    if ( *(polynom.coefficients + polynom.degree) != 0 ){
        if(*(polynom.coefficients + polynom.degree) > 0 ) os << " +" ;
        os << " (" << *(polynom.coefficients + polynom.degree) << ")";
    }
    return os;
}