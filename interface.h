#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

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

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonBtn;

    QLabel *outputLabel;


    Polynom* polynom = new Polynom;



public:
    Tinterface(std::string title, QWidget *parent = nullptr);
    ~Tinterface();

public slots:
    void addRoot(const QLineEdit& re, const QLineEdit& im);

    void printWithDegrees();
    void printWithRoots();


};
#endif // INTERFACE_H
