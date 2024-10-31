#include "interface.h"
#include "polynom.h"

Tinterface::Tinterface(std::string title, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(QString::fromStdString(title));
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

    connect(addRootBTN, SIGNAL(pressed()), this, SLOT(addRoot()));
    connect(changeRootBTN, SIGNAL(pressed()), this, SLOT(changeRoot()));
    connect(addLeadCoeffBTN, SIGNAL(pressed()), this, SLOT(addLeadCoeff()));
    connect(calculateValueAtPointBTN, SIGNAL(pressed()), this, SLOT(valueAtPoint()));
    connect(printWithRootsBTN, SIGNAL(pressed()), this, SLOT(printWithRoots()));
    connect(printCanonBtn, SIGNAL(pressed()), this, SLOT(printWithDegrees()));

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


number *Tinterface::pushBack(number *arr, number elem){
    number* resizeArr = new number[rootsAmount + 1];
    for(int i = 0; i < rootsAmount; i++){
        *(resizeArr + i) = *(arr + i);
    }
    rootsAmount++;
    *(resizeArr + rootsAmount - 1) = elem;

    delete []arr;
    arr = resizeArr;
    return arr;
}



void Tinterface::addRoot() {
    double re = reCoeffsLE->text().toDouble();
    double im = imCoeffsLE->text().toDouble();
    number root = TComplex(re, im);
    if ( rootsAmount == 0 ){
        roots = new number[0];
    }
    roots = pushBack(roots, root);
}

void Tinterface::changeRoot() {
    int index = changeRootLineEdit->text().toInt();
    if ( index > 0 && index < rootsAmount ) {
        string re = reCoeffsLE->text().toStdString();
        string im = imCoeffsLE->text().toStdString();
        number root(stod(re), stod(im));
        roots[index] = root;
    }
}


void Tinterface::addLeadCoeff() {
    double re = stod(reLeadCoeff->text().toStdString());
    double im = stod(imLeadCoeff->text().toStdString());
    An = TComplex(re, im);
}

void Tinterface::valueAtPoint() {
    number point = TComplex(valueAtPointLE->text().toDouble());
    QString output;
    if ( rootsAmount == 0 ){
        output = QString::fromStdString(An.to_str());
    }else{
        polynom = Polynom().fill(An, roots, rootsAmount + 1);
        number value = polynom->valueAtPoint(point);
        output = QString::fromStdString(value.to_str());
    }
    valueAtPointLabel->setText(output);
}

void Tinterface::printWithRoots() {
    QString output;
    polynom = Polynom().fill(An, roots, rootsAmount + 1);
    std::string out = polynom->polynomWithRoots();
    output = QString::fromStdString(out);
    outputLabel->setText(output);
}

void Tinterface::printWithDegrees() {
    QString output;
    polynom = Polynom().fill(An, roots, rootsAmount + 1);
    std::string out = polynom->polynomWithDegrees();
    output = QString::fromStdString(out);
    outputLabel->setText(output);
}


