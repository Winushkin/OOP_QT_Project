#ifndef OOP_QT_PROJECT_APPLICATION_H
#define OOP_QT_PROJECT_APPLICATION_H
#include <QObject>
#include <QCoreApplication>
#include "polynom.h"

#include "../common/communicator.h"
#include "../common/common.h"



class ServerApplication : public QCoreApplication {
Q_OBJECT

    TCommunicator *comm;

    Polynom* polynom = new Polynom;

    number* roots;

    number An = 0;

    int rootsAmount = 0;

public:
    number* pushBack(number *arr, number elem);
    ServerApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};

#endif //OOP_QT_PROJECT_APPLICATION_H