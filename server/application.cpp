#include "application.h"
#include "polynom.h"

TApplication::TApplication(int argc, char *argv[])
        : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}


void TApplication::recieve(QByteArray msg){
    QString answer, s;
    TComplex complex;
    msg >> complex;

    int pos = msg.indexOf(separator.toLatin1());
    int t = msg.left(pos).toInt();
    switch (t) {
        case PRINT_CLASSIC_REQUEST:
            break;
        case PRINT_CANONIC_REQUEST:
            break;
        case ADD_ROOT_REQUEST:
            break;
        case ADD_COEFFICIENT_REQUEST:
            break;
        case CHANGE_ROOT_REQUEST:
            break;
        case VALUE_AT_POINT_REQUEST:
            break;
        default: return;
    }
    comm->send(QByteArray().append(answer.toLatin1()));
}