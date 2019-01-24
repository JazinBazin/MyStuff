#pragma once
#include <QWidget>
#include <QTcpServer>
#include <QTextEdit>
#include <QSpinBox>
#include <QTcpSocket>
#include <QStack>
#include <QSet>
#include "ServerClient.h"

class ChatServer : public QWidget
{
    Q_OBJECT
public:
    ChatServer(QWidget *parent = nullptr);
    ~ChatServer();

private:
    void sendMessageToAllClients(const QString &message);
    void stopServer();

private:
    QTcpServer *chatServer;
    QTextEdit *txtInfo;
    QSpinBox *spinPortNumber;
    quint64 lastClientID;
    QStack<quint64> *freeClientsIDs;
    QSet<ServerClient*> *serverClients;

private slots:
    void slotBtnStartServerClicked();
    void slotBtnStopServerClicked();
    void slotNewConnection();
    void slotGetClientMessage();
    void slotClientDisconected();
};
