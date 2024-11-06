#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

#include "../server/array.h"
#include "../server/number.h"
#include "../server/polynom.h"
#include "../common/common.h"
#include "../common/common.cpp"



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

    friend QString& operator<< (QString&,const QString&);


public:
    Tinterface(QWidget *parent = 0);
    ~Tinterface();

public slots:
    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);

};

#endif // INTERFACE_H
