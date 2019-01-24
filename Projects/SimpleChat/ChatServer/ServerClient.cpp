#include "ServerClient.h"

void ServerClient::slotReadyRead() {
    emit signalReadyRead();
}

void ServerClient::slotDisconnected() {
    emit signalDisconnected();
    this->deleteLater();
}

ServerClient::ServerClient(quint64 clientID, QTcpSocket *serverSocketForClient, QObject *parent)
    : QObject(parent)
{
    ID = clientID;
    socket = serverSocketForClient;
    blockSize = 0;

    QObject::connect(socket, &QTcpSocket::disconnected,
                     this, &ServerClient::slotDisconnected);
    QObject::connect(socket, &QTcpSocket::readyRead,
                     this, &ServerClient::slotReadyRead);
}

ServerClient::~ServerClient() {
    delete socket;
}

