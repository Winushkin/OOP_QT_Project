#include "polynom.h"


Polynom::Polynom(): coefficients(nullptr), roots(nullptr), degree(0) {}


string Polynom::polynomWithRoots() {
    string output = "";
    output += "p(x) = ";
    if(*(coefficients) != 0) {
        if(*(coefficients) != 1) output += (coefficients)->to_str();
        for(int i = 0; i < degree; i++){
            if(*(roots + i) != 0){
                if(*(roots + i) > 0) output +=  "(x-" + (roots + i)->to_str() + ")";
                else {
                    output +=  "(x+" + (*(roots + i) * -1).to_str() + ")";
                }
            }else{
                output +=  "x";
            }
        }
    }else{
        output += "0";
    }
    return output;
}


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

std::string Polynom::polynomWithDegrees() {
    string output = "";
    output += "p(x) = ";
    if (*(coefficients) != 0){
        if(*(coefficients) != 1) output += " (" + (*(coefficients)).to_str() + ") x^" + to_string(degree);
        else output += "x^" + to_string(degree);
    }
    for ( int i = 1; i < degree - 1; i++ ){
        if (*(coefficients + i) != 0){
            output += " ";
            if(*(coefficients + i) > 0) output += "+";
            if (*(coefficients + i) != 1) output += "(" + (coefficients + i)->to_str() + ") x^" + std::to_string(degree - i);
            else output += "x^" + std::to_string(degree - i);
        }
    }
    if ( *(coefficients + degree - 1) != 0 ){
        if(*(coefficients + degree - 1) > 0){
            output += " + (" + (coefficients + degree - 1)->to_str() + ")x";
        }else output += " (" + (coefficients + degree - 1)->to_str() + ")x";
    }
    if ( *(coefficients + degree) != 0 ){
        if(*(coefficients + degree) > 0 ) output += " +" ;
        output += " (" + (coefficients + degree)->to_str() + ")";
    }
    return output;
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