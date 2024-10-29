#include "interface.h"
#include "polynom.h"
Tinterface::Tinterface(std::string title, QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle(QString::fromStdString(title));
    setFixedSize(700, 400);

    name_a = new QLabel("a =",this);
    name_a->setGeometry(50, 20, 30, 25);
    a_re = new QLineEdit("1",this);
    a_re->  setGeometry(90,20,50,25);
    delimeter_a = new QLabel("+i", this);
    delimeter_a->setGeometry (150,20,30,25);
    a_im = new QLineEdit("0",this);
    a_im->setGeometry (190,20,50,25);

    name_b = new QLabel("b =",this);
    name_b->setGeometry(50, 50, 30, 25);
    b_re = new QLineEdit("1",this);
    b_re->  setGeometry(90,50,50,25);
    delimeter_b = new QLabel("+i", this);
    delimeter_b->setGeometry (150,50,30,25);
    b_im = new QLineEdit("0",this);
    b_im->setGeometry (190,50,50,25);

    name_c = new QLabel("c =",this);
    name_c->setGeometry(50,80,30,25);
    c_re = new QLineEdit("1",this);
    c_re->  setGeometry(90,80,50,25);
    delimeter_c = new QLabel("+i", this);
    delimeter_c->setGeometry (150,80,30,25);
    c_im = new QLineEdit("0",this);
    c_im->setGeometry (190,80,50,25);

    name_x = new QLabel("x =",this);
    name_x->setGeometry(50,110, 30, 25);
    x_re = new QLineEdit("1",this);
    x_re->  setGeometry(90,110,50,25);
    delimeter_x = new QLabel("+i", this);
    delimeter_x->setGeometry (150,110,30,25);
    x_im = new QLineEdit("0",this);
    x_im->setGeometry (190,110,50,25) ;

    value_btn = new QPushButton ("знач.",this);
    value_btn->setGeometry (10,150,60,30) ;

    root_btn = new QPushButton ("корни", this) ;
    root_btn->setGeometry (80,150,60,30) ;

    print_classic_btn = new QPushButton ("класс. ", this);
    print_classic_btn->setGeometry (160,150,60,30) ;

    print_canonic_btn = new QPushButton ("канон.",this) ;
    print_canonic_btn->setGeometry (230,150,60,30) ;

    output = new QLabel("huy", this);
    output->setGeometry(10, 200, 280, 25);

    connect(print_canonic_btn, SIGNAL(pressed()), this, SLOT(printWithDegrees()));
    connect(print_classic_btn, SIGNAL(pressed()), this, SLOT(printWithRoots()));
}

Tinterface::~Tinterface() {
    delete name_a;
    delete delimeter_a;
    delete a_re;
    delete a_im;

    delete name_b;
    delete delimeter_b;
    delete b_re;
    delete b_im;

    delete name_c;
    delete delimeter_c;
    delete c_re;
    delete c_im;

    delete name_x;
    delete delimeter_x;
    delete x_re;
    delete x_im;

    delete output;
}

//void Tinterface::printWithDegrees() {
//
//    string output
//}

void Tinterface::value(){
    output->setText(x_re->text());
}
