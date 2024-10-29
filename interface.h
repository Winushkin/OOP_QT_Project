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
    QLabel *coeffsLabel, *imIndicator;
    QLineEdit *reCoeffsLE, *imCoeffsLE;

    QPushButton *addRootBTN;

    QPushButton *changeRootBTN;
    QLineEdit *changeRootLineEdit;

    QLabel *leadingCoeff; // imIndicator
    QLineEdit *reLeadCoeff, *imLeadCoeff;

    QPushButton *addLeadCoeffBTN;

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonBtn;

    QLabel *outputLabel;






public:
    Tinterface(std::string title, QWidget *parent = nullptr);
    ~Tinterface();

public slots:
    void value();
//    void printWithDegrees();
//    void printWithRoots();


};
#endif // INTERFACE_H
