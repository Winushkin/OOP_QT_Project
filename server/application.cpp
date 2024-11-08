#include "application.h"

number* ServerApplication::pushBack(number *arr, number elem){
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

ServerApplication::ServerApplication(int argc, char *argv[]): QCoreApplication(argc,argv) {
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}


void ServerApplication::recieve(QByteArray msg) {
    QString answer;
    std::string out;
    TComplex complex;

    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    switch (t) {
        case PRINT_CLASSIC_REQUEST:
            out = polynom->polynomWithDegrees().str();
            answer = QString::fromStdString(out);
            break;
        case PRINT_CANONIC_REQUEST:
            out = polynom->polynomWithRoots().str();
            answer = QString::fromStdString(out);
            break;
        case ADD_ROOT_REQUEST:
            msg >> complex;
            number root = complex;
            if ( rootsAmount == 0 ){
                roots = new number[0];
            }
            roots = pushBack(roots, root);
            polynom = Polynom().fill(An, roots, rootsAmount+1);
            break;
        case ADD_COEFFICIENT_REQUEST:
            msg >> complex;
            An = complex;
            polynom = Polynom().fill(An, roots, rootsAmount+1);
            break;
        case CHANGE_ROOT_REQUEST:
            msg.erase(msg.cend());
            int index = msg.toInt();
            if ( index >= 0 && index < rootsAmount ) {
                double re = reCoeffsLE->text().toDouble();
                double im = imCoeffsLE->text().toDouble();
                number root(re, im);
                roots[index] = root;
                polynom = Polynom().fill(An, roots, rootsAmount+1);
            }else{
                outputLabel->setText("Неправильно введен индекс");
            }
            break;
        case VALUE_AT_POINT_REQUEST:
            break;
        default:
            return;
    }
    comm->send(QByteArray().append(answer.toLatin1()));
}