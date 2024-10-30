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
    //connect(addRootBTN, SIGNAL(clicked(bool)), this, SLOT(addRoot(reCoeffsLE, imCoeffsLE)));

    changeRootBTN = new QPushButton("Изменить корень с индексом", this);
    changeRootBTN->setGeometry(250, 50, 200, 30);
    changeRootLineEdit = new QLineEdit(this);
    changeRootLineEdit->setGeometry(455, 50, 30, 30);
    //connect(changeRootBTN, SIGNAL())

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
    //connect(addLeadCoeffBTN, SIGNAL())

    calculateValueAtPoint = new QLabel("Вычислить значение в точке x =", this);
    calculateValueAtPoint->setGeometry(50, 150, 280, 25);
    valueAtPointLE = new QLineEdit(this);
    valueAtPointLE->setGeometry(230, 150, 25, 25);
    calculateValueAtPointBTN = new QPushButton("Вычислить", this);
    calculateValueAtPointBTN->setGeometry(50, 180, 100, 30);
    //connect(calculateValueAtPointBTN, SIGNAL())

    printWithRootsBTN = new QPushButton("Показать с корнями", this);
    printWithRootsBTN->setGeometry(50, 250, 220, 30);
    //connect(printWithRootsBTN, SIGNAL(clicked()), this, SLOT(printWithRoots()));

    printCanonBtn = new QPushButton("Показать в каноническом виде", this);
    printCanonBtn->setGeometry(280, 250, 220, 30);
//    connect(printCanonBtn, SIGNAL(clicked()), this, SLOT(printWithDegrees()));

    outputLabel = new QLabel("Вывод:", this);
    outputLabel->setGeometry(50, 300, 100, 25);

    connect(addRootBTN, SIGNAL(pressed()), this, SLOT(addRoot()));
    connect(changeRootBTN, SIGNAL(pressed()), this, SLOT(changeRoot()));
    connect(addLeadCoeffBTN, SIGNAL(pressed()), this, SLOT(addLeadCoeff()));
    connect(calculateValueAtPointBTN, SIGNAL(pressed()), this, SLOT(addLeadCoeff()));
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

void Tinterface::addRoot() {
    QLineEdit *re = reCoeffsLE;
    string real = re->text().toStdString();
    QLineEdit *im = reCoeffsLE;
    string imag = im->text().toStdString();
    TComplex root(stod(real), stod(imag));
    roots.pushBack(root);
}

void Tinterface::changeRoot() {
    int index = changeRootLineEdit->text().toInt();
    if ( index > 0 && index < roots.getLength() ) {
        string re = reCoeffsLE->text().toStdString();
        string im = imCoeffsLE->text().toStdString();
        number root(stod(re), stod(im));
        roots.changeElement(index, root);
    }
}


void Tinterface::addLeadCoeff() {
    double re = stod(reLeadCoeff->text().toStdString());
    double im = stod(imLeadCoeff->text().toStdString());
    An = TComplex(re, im);
}

void Tinterface::valueAtPoint() {
    //realization
}

void Tinterface::printWithRoots() {
    QString output;
    polynom = Polynom().fill(An, roots, roots.getLength())
    std::string out = polynom->polynomWithRoots();
    QString::fromStdString(out);
    outputLabel->setText(output);
}

void Tinterface::printWithDegrees() {
    QString output;
    std::string out = polynom->polynomWithDegrees();
    QString::fromStdString(out);
    outputLabel->setText(output);
}


