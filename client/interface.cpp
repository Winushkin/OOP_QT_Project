#include "interface.h"

Tinterface::Tinterface(QWidget *parent){
    setWindowTitle(QString::fromStdString("работа 5 "));
    setFixedSize(700, 400);

    coeffsLabel = new QLabel("Коэффициент:", this);
    coeffsLabel->setGeometry(50, 20, 100, 25);
    reCoeffsLE = new QLineEdit("0", this);
    reCoeffsLE->setGeometry(150, 20, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(180, 20, 25, 25);
    imCoeffsLE = new QLineEdit("0", this);
    imCoeffsLE->setGeometry(210, 20, 25, 25);

    addRootBTN = new QPushButton("Добавить корень", this);
    addRootBTN->setGeometry(50, 50, 150, 30);

    changeRootBTN = new QPushButton("Изменить корень с индексом", this);
    changeRootBTN->setGeometry(250, 50, 200, 30);
    changeRootLineEdit = new QLineEdit(this);
    changeRootLineEdit->setGeometry(455, 50, 30, 30);

    leadingCoeff = new QLabel("an = ", this);
    leadingCoeff->setGeometry(50, 90, 25, 25);
    reLeadCoeff = new QLineEdit(this);
    reLeadCoeff->setGeometry(90, 90, 25, 25);
    imIndicator = new QLabel("+i", this);
    imIndicator->setGeometry(130, 90, 25, 25);
    imLeadCoeff = new QLineEdit(this);
    imLeadCoeff->setGeometry(160, 90, 25, 25);
    addLeadCoeffBTN = new QPushButton("Добавить an", this);
    addLeadCoeffBTN->setGeometry(50, 120, 150, 30);

    calculateValueAtPoint = new QLabel("Вычислить значение в точке x =", this);
    calculateValueAtPoint->setGeometry(50, 150, 250, 25);
    valueAtPointLE = new QLineEdit(this);
    valueAtPointLE->setGeometry(255, 150, 25, 25);
    calculateValueAtPointBTN = new QPushButton("Вычислить", this);
    calculateValueAtPointBTN->setGeometry(50, 180, 100, 30);
    valueAtPointLabel = new QLabel("", this);
    valueAtPointLabel->setGeometry(300, 180, 100, 25);

    printWithRootsBTN = new QPushButton("Показать с корнями", this);
    printWithRootsBTN->setGeometry(50, 250, 220, 30);

    printCanonBtn = new QPushButton("Показать в каноническом виде", this);
    printCanonBtn->setGeometry(280, 250, 220, 30);

    outputLabel = new QLabel("Вывод:", this);
    outputLabel->setGeometry(50, 300, 300, 25);


    connect(calculateValueAtPointBTN,SIGNAL(pressed()), this,SLOT(formRequest()));
    connect(printCanonBtn ,SIGNAL(pressed()), this,SLOT(formRequest()));


}

Tinterface::~Tinterface() {
    delete outputLabel;
    delete printCanonBtn;
    delete printWithRootsBTN;
    delete calculateValueAtPointBTN;
    delete valueAtPointLE;
    delete calculateValueAtPoint;
    delete addLeadCoeffBTN;
    delete imLeadCoeff;
    delete leadingCoeff;
    delete reLeadCoeff;
    delete changeRootLineEdit;
    delete changeRootBTN;
    delete addRootBTN;
    delete imCoeffsLE;
    delete imIndicator;
    delete reCoeffsLE;
    delete coeffsLabel;
}


void Tinterface::formRequest()
{
    QString msg;
    QPushButton *btn = (QPushButton*)sender();

    if ( btn == addRootBTN ){
        msg << QString().setNum(ADD_ROOT_REQUEST);
        msg << reCoeffsLE->text() << imCoeffsLE->text();
    }
    if ( btn == changeRootBTN ) {
        msg << QString().setNum(CHANGE_ROOT_REQUEST);
        msg << changeRootLineEdit->text();
        msg << reCoeffsLE->text() << imCoeffsLE->text();
    }
    if ( btn == addLeadCoeffBTN ){
        msg << QString().setNum(ADD_COEFFICIENT_REQUEST);
        msg << reLeadCoeff->text() << imLeadCoeff->text();
    }
    if ( btn == calculateValueAtPointBTN ){
        msg << QString().setNum(VALUE_AT_POINT_REQUEST);
        msg << valueAtPointLE->text();
    }
    if ( btn == printCanonBtn ){
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    }
    if ( btn == printWithRootsBTN ){
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    }
    emit request(msg);
}

void Tinterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-1);

    p = msg.indexOf(separator);
    text = msg.left(p);
    switch (t)
    {
        case VALUE_AT_POINT_ANSWER:
            valueAtPointLabel->setText(text);
            break;

        case PRINT_POLYNOM_ANSWER:
            outputLabel->setText(text);
            break;

        default:
            break;
    }

    msg = msg.mid(p+1,msg.length()-p-1);

}
