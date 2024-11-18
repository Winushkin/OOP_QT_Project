#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>

#include "../server/array.h"
#include "../server/polynom.h"
#include "../common/common.h"


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
    QLineEdit *valueAtPointReLe;
    QLineEdit *valueAtPointImLe;
    QPushButton *calculateValueAtPointBTN;
    QLabel *valueAtPointLabel;

    QPushButton *printWithRootsBTN;
    QPushButton *printCanonBtn;

    QRadioButton *RealMode;
    QRadioButton *ComplexMode;

    QLabel *outputLabel;

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

