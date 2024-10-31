#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "array.h"
#include "polynom.h"


class Tinterface : public QWidget
{
    Q_OBJECT

    QLabel *coeffsLabel, *imIndicator;
    QLineEdit *reCoeffsLE, *imCoeffsLE;

    QPushButton *addRootBTN;

    QPushButton *changeRootBTN;
    QLineEdit *changeRootLineEdit;

    QLabel *leadingCoeff;
    QLineEdit *reLeadCoeff, *imLeadCoeff;

    QPushButton *addLeadCoeffBTN;

    QLabel *calculateValueAtPoint;
    QLineEdit *valueAtPointLE;
    QPushButton *calculateValueAtPointBTN;
    QLabel *valueAtPointLabel;

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonBtn;

    QLabel *outputLabel;

    Polynom *polynom;
    number *roots;
    int rootsAmount = 0;
    number An = 0;



public:
    Tinterface(std::string title, QWidget *parent = nullptr);
    ~Tinterface();
    number *pushBack(number *arr, number elem);

public slots:
    void addRoot();

    void changeRoot();

    void addLeadCoeff();

    void valueAtPoint();

    void printWithDegrees();

    void printWithRoots();


};
#endif // INTERFACE_H
