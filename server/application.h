#ifndef OOP_QT_PROJECT_APPLICATION_H
#define OOP_QT_PROJECT_APPLICATION_H
#include <QObject>
#include <QCoreApplication>

#include "../common/communicator.h"
#include "../common/common.h"
#include "../common/common.cpp"



class TApplication : public QCoreApplication
{
Q_OBJECT

    TCommunicator *comm;

public:

    TApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};

#endif //OOP_QT_PROJECT_APPLICATION_H
