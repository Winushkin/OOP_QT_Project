#ifndef OOP_QT_PROJECT_FUNCTION_H
#define OOP_QT_PROJECT_FUNCTION_H

#include "polynom.h"
#include "cmath"
#include "iostream"

inline int factorial(unsigned int n) {
    int result = 1;
    for (unsigned int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

template <class number>
class TFunction : protected Polynom<number> {
public:
    TFunction(unsigned int n, number* coefficients);
    number value(number point);
};

template<class number>
TFunction<number>::TFunction(unsigned int n, number *coefficients) {
    this->degree = n;
    this->coefficients = coefficients;
}

template<class number>
number TFunction<number>::value(number point) {
    number result = 0;
    Polynom<number> polynom (this->degree);
    point = point * 3.14 / 180.0;
    for(int i = 0; i <= polynom.degree; i++) {
        result += pow(point, i) * this->coefficients[i];
    }
    return result;
}

template<class number>
class TFsin: public TFunction<number> {
    number *derivatives;
    number* derivativesCalc(unsigned int n) {
        derivatives = new number[n];
        for (int i = 0; i <= n; ++i) {
            if (i % 4 == 0) {
                derivatives[i] = 0;  // sin(0)
            } else if (i % 4 == 1) {
                derivatives[i] = 1.0 / factorial(i);  // cos(0)
            } else if (i % 4 == 2) {
                derivatives[i] = 0;  // -sin(0)
            } else if (i % 4 == 3) {
                derivatives[i] = -1.0 / factorial(i); // -cos(0)
            }
        }
        return derivatives;
    }
    public:
        TFsin(unsigned int n): TFunction<number>(n, derivativesCalc(n)) {}
    ~TFsin() { delete[] derivatives; }
};

template<class number>
class TFSi: public TFunction<number> {
    number *derivatives;
    number* derivativesCalc(unsigned int n) {
        derivatives = new number[n];
        for (int k = 0; k <= n; ++k) {
            if (k % 2 == 0) {
                derivatives[k] = 0; // Чётные производные равны 0
            } else {
                // Нечётные производные
                int m = k / 2; // m соответствует номеру нечётного члена
                double factorial = 1;
                for (int i = 1; i <= k; ++i) {
                    factorial *= i; // Вычисление факториала
                }
                derivatives[k] = (m % 2 == 0 ? 1 : -1) / ((k + 1) * factorial);
            }
        }
        return derivatives;
    }
    public:
    TFSi(unsigned int n): TFunction<number>(n, derivativesCalc(n)) {}
    ~TFSi() { delete[] derivatives; }
};

#endif //OOP_QT_PROJECT_FUNCTION_H
