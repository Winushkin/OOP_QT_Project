#ifndef INTERFACE_H
#define INTERFACE_H

#include "iostream"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "polynom.h"


class Tinterface : public QWidget
{
    Q_OBJECT
    QLabel *name_a, *delimeter_a;
    QLineEdit *a_re, *a_im;

    QLabel *name_b, *delimeter_b;
    QLineEdit *b_re, *b_im;

    QLabel *name_c, *delimeter_c;
    QLineEdit *c_re, *c_im;

    QLabel *name_x, *delimeter_x;
    QLineEdit *x_re, *x_im;

    QPushButton *value_btn;
    QPushButton *root_btn;
    QPushButton *print_classic_btn;
    QPushButton *print_canonic_btn;

    QLabel *output;

public:
    Tinterface(std::string title, QWidget *parent = nullptr);
    ~Tinterface();

//public slots:
    // Polynom* fill(number leadingCoefficient, number* roots, int rootsCount);

};
#endif // INTERFACE_H
