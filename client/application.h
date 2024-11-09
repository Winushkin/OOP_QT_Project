#ifndef OOPPRACTICE_APPLICATION_H
#define OOPPRACTICE_APPLICATION_H

#include <QObject>
#include <QApplication>


#include "interface.h"
#include "../common/communicator.h"


class ClientApplication : public QApplication{
    Q_OBJECT

    TCommunicator *comm;
    Tinterface *interface;

public:
    ClientApplication(int, char**);

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);
};

#endif //OOPPRACTICE_APPLICATION_H
