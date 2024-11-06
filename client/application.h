#ifndef OOPPRACTICE_APPLICATION_H
#define OOPPRACTICE_APPLICATION_H

#include <QObject>
#include <QApplication>


#include "interface.h"
#include "../common/communicator.h"


class TApplication : public QApplication{

    Q_OBJECT

    TCommunicator *comm;
    Tinterface *interface;

public:
    TApplication(int, char**);

public slots:
    void fromCommunicator(QByteArray);
    void toCommunicator(QString);


};

#endif //OOPPRACTICE_APPLICATION_H
