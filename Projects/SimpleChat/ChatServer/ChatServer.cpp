#include "ChatServer.h"
#include <QBoxLayout>
#include <QPushButton>
#include <QLabel>
#include <QMessageBox>
#include <QDataStream>

void ChatServer::slotBtnStartServerClicked() {
    quint16 portNumber = static_cast<quint16>(spinPortNumber->value());
    if(chatServer->isListening()) {
        if(chatServer->serverPort() == portNumber)
            return;
        else
            this->stopServer();
    }
    if(!chatServer->listen(QHostAddress::Any, portNumber)) {
        QMessageBox::critical(this, "Server error", "Unable to start the server: " +
                              chatServer->errorString());
        return;
    }
    txtInfo->append("Server has started. Port: " + QString::number(portNumber));
}

void ChatServer::slotBtnStopServerClicked() {
    this->stopServer();
}

void ChatServer::stopServer() {
    chatServer->close();
    txtInfo->append("Server has stopped");
}

void ChatServer::slotNewConnection() {
    quint64 clientID;
    if(freeClientsIDs->isEmpty()) {
        lastClientID += 1;
        clientID = lastClientID;
    }
    else {
        clientID = freeClientsIDs->back();
        freeClientsIDs->pop_back();
    }
    QTcpSocket *socketForClient = chatServer->nextPendingConnection();
    ServerClient *serverClient = new ServerClient(clientID, socketForClient);

    QObject::connect(serverClient, &ServerClient::signalReadyRead,
                     this, &ChatServer::slotGetClientMessage);
    QObject::connect(serverClient, &ServerClient::signalDisconnected,
                     this, &ChatServer::slotClientDisconected);

    serverClients->insert(serverClient);
    sendMessageToAllClients("Client " + QString::number(clientID) + " has connected");
}

void ChatServer::slotClientDisconected() {
    ServerClient *serverClient = dynamic_cast<ServerClient*>(sender());
    freeClientsIDs->push(serverClient->ID);
    serverClients->remove(serverClient);
    sendMessageToAllClients("Client " + QString::number(serverClient->ID) + " has disconnected");
}

void ChatServer::slotGetClientMessage() {
    ServerClient *serverClient = dynamic_cast<ServerClient*>(sender());
    if(serverClient) {
        QTcpSocket *clientSocket = serverClient->socket;
        quint16 &blockSize = serverClient->blockSize;
        QDataStream in(clientSocket);
        while(true) {
            if(blockSize == 0) {
                if(static_cast<quint16>(clientSocket->bytesAvailable()) < sizeof(quint16))
                    break;
                in >> blockSize;
            }
            if(static_cast<quint16>(clientSocket->bytesAvailable()) < blockSize)
                break;
            QString message;
            in >> message;
            serverClient->blockSize = 0;
            QString messageWithID = "Client " +
                    QString::number(serverClient->ID) +
                    ": " + message;
            sendMessageToAllClients(messageWithID);
        }
    }
}

void ChatServer::sendMessageToAllClients(const QString &message) {
    QByteArray bytesBlock;
    QDataStream out(&bytesBlock, QIODevice::WriteOnly);
    out << quint16(0) << message;
    out.device()->seek(0);
    out << static_cast<quint16>(bytesBlock.size() - sizeof(quint16));
    for(auto servetClientIter = serverClients->begin();
        servetClientIter != serverClients->end();
        ++servetClientIter) {
        QTcpSocket *clientSocket = (*servetClientIter)->socket;
        clientSocket->write(bytesBlock);
    }
}

ChatServer::ChatServer(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Chat server");

    freeClientsIDs = new QStack<quint64>();
    lastClientID  = 0;
    serverClients = new QSet<ServerClient*>();

    chatServer = new QTcpServer(this);
    QObject::connect(chatServer, &QTcpServer::newConnection,
                     this, &ChatServer::slotNewConnection);

    txtInfo = new QTextEdit();
    txtInfo->setReadOnly(true);

    QLabel *lblPortNumber = new QLabel("Port number:");

    spinPortNumber = new QSpinBox();
    spinPortNumber->setMinimum(0);
    spinPortNumber->setMaximum((1 << 16) - 1);
    spinPortNumber->setValue(5000);
    spinPortNumber->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

    QPushButton *btnStartServer = new QPushButton("Start server");
    QPushButton *btnStopServer = new QPushButton("Stop server");
    QObject::connect(btnStartServer, &QPushButton::clicked,
                     this, &ChatServer::slotBtnStartServerClicked);
    QObject::connect(btnStopServer, &QPushButton::clicked,
                     this, &ChatServer::slotBtnStopServerClicked);

    QHBoxLayout *layoutPortNumber = new QHBoxLayout();
    layoutPortNumber->addWidget(lblPortNumber);
    layoutPortNumber->addWidget(spinPortNumber);

    QHBoxLayout *layoutControlButtons = new QHBoxLayout();
    layoutControlButtons->addWidget(btnStartServer);
    layoutControlButtons->addWidget(btnStopServer);

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addWidget(txtInfo);
    layoutMain->addLayout(layoutPortNumber);
    layoutMain->addLayout(layoutControlButtons);

    this->setLayout(layoutMain);
}

ChatServer::~ChatServer() {
    delete freeClientsIDs;
    delete serverClients;
}
