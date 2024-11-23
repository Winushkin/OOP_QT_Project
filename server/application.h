#ifndef OOP_QT_PROJECT_APPLICATION_H
#define OOP_QT_PROJECT_APPLICATION_H
#include <QObject>
#include <QCoreApplication>
#include "polynom.h"

#include "../common/communicator.h"
#include "../common/common.h"
#include "complex.h"



class ServerApplication : public QCoreApplication {
Q_OBJECT

    TCommunicator *comm;

    Polynom<TComplex>* polynom = new Polynom<TComplex>;
    Polynom<float>* floatPolynom = new Polynom<float>;

    TComplex* roots;
    float* floatRoots;

    TComplex An = 0;
    float floatAn = 0;

    int rootsAmount = 0;

public:
    TComplex* pushBack(TComplex *arr, TComplex elem);
    float* pushBack(float *arr, float elem);
    ServerApplication(int, char**);

signals:

public slots:

    void recieve(QByteArray);

};

#endif //OOP_QT_PROJECT_APPLICATION_H