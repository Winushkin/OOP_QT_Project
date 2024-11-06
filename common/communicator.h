#include <QObject>
#include <QByteArray>

#include <QtNetwork/QUdpSocket>
#include <QtNetwork/QHostAddress>
#ifndef OOP_QT_PROJECT_COMMUNICATOR_H
#define OOP_QT_PROJECT_COMMUNICATOR_H


struct TCommParams
{
    QHostAddress rHost;
    quint16      rPort;
    QHostAddress sHost;
    quint16      sPort;
};

class TCommunicator : public QUdpSocket
{
Q_OBJECT

    bool         ready;
    TCommParams  params;

public:
    TCommunicator(TCommParams&,QObject *parent = nullptr);
    bool isReady();

signals:
    void recieved(QByteArray);

public slots:
    void send(QByteArray);

private slots:
    void recieve();
};



#endif //OOP_QT_PROJECT_LOCALNEW_COMMUNICATOR_H
