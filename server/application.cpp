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
    QString answer = "";
    std::string out;
    number root;
    TComplex complex;
    number point;

    int index;
    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    msg.remove(0, 2);
    switch (t) {
        case PRINT_CLASSIC_REQUEST:
            answer << QString().setNum(PRINT_POLYNOM_ANSWER);
            out = polynom->polynomWithRoots().str();
            answer << QString::fromStdString(out);
            break;

        case PRINT_CANONIC_REQUEST:
            answer << QString().setNum(PRINT_POLYNOM_ANSWER);
            out = polynom->polynomWithDegrees().str();
            answer << QString::fromStdString(out);
            break;

        case ADD_ROOT_REQUEST:
            msg >> complex;
            root = complex;
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
            pos = msg.indexOf(separator.toLatin1());
            index = msg.left(pos).toInt();
            msg.remove(0, pos + 1);
            msg >> complex;
            roots[index] = complex;
            polynom = Polynom().fill(An, roots, rootsAmount+1);
            break;
        case VALUE_AT_POINT_REQUEST:
            answer << QString().setNum(VALUE_AT_POINT_ANSWER);
            msg >> point;
            answer += "p(" + point.to_str() + ") = ";
            if ( rootsAmount == 0 ){
                answer << QString::fromStdString(An.to_str());
            }else{
                number value = polynom->valueAtPoint(point);
                answer << QString::fromStdString(value.to_str());
            }
            break;
        default:
            return;
    }
    comm->send(QByteArray().append(answer.toLatin1()));
}