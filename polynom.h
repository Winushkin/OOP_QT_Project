#ifndef OOPPRACTICE_POLYNOM_H
#define OOPPRACTICE_POLYNOM_H

#include "number.h"

class Polynom {
    number* roots = nullptr;
    number* coefficients = nullptr;
    int degree = 0;
public:
    Polynom();

    Polynom* fill(number leadingCoefficient, number* roots, int rootsCount);

    void printWithDegrees();

    void printWithRoots();

    number valueAtPoint(number point);

    friend ostream& operator << (ostream & os, const Polynom & c);
};


#endif