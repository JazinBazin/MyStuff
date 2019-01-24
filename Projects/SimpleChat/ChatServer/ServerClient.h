#pragma once
#include <QObject>
#include <QTcpSocket>

class ServerClient : public QObject
{
    Q_OBJECT
public:
    ServerClient(quint64 clientID, QTcpSocket *serverSocketForClient, QObject *parent = nullptr);
    ~ServerClient();

public:
    quint64 ID;
    QTcpSocket *socket;
    quint16 blockSize;

signals:
    void signalReadyRead();
    void signalDisconnected();
private slots:
    void slotReadyRead();
    void slotDisconnected();
};
