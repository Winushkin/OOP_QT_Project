#include "application.h"


ClientApplication::ClientApplication(int argc, char *argv[])
        : QApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10001,
                         QHostAddress("127.0.0.1"), 10000};
    comm = new TCommunicator(pars, this);

    interface = new Tinterface();
    interface->show();

    connect(comm,SIGNAL(recieved(QByteArray)),this,
            SLOT(fromCommunicator(QByteArray)));
    connect(interface,SIGNAL(request(QString)),
            this,SLOT(toCommunicator(QString)));

}

void ClientApplication::fromCommunicator(QByteArray msg)
{
    interface->answer(QString(msg));
}

void ClientApplication::toCommunicator(QString msg)
{
    comm->send(QByteArray().append(msg.toUtf8()));
}
