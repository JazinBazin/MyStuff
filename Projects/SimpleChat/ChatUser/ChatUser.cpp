#include "ChatUser.h"
#include <QLabel>
#include <QPushButton>
#include <QBoxLayout>
#include <QHostAddress>
#include <QEventLoop>

void ChatUser::slotBtnPortNumberClicked() {
    quint16 portNumber = static_cast<quint16>(spinPortNumber->value());
    if(userSocket->state() == QAbstractSocket::SocketState::ConnectedState) {
        if(userSocket->peerPort() == portNumber)
            return;
        else {
            userSocket->disconnectFromHost();
            while(userSocket->state() == QAbstractSocket::SocketState::ConnectedState)
                userSocket->waitForDisconnected(30);
        }
    }
    userSocket->connectToHost(QHostAddress::LocalHost, portNumber);
}

void ChatUser::slotBtnSendMessageClicked() {
    QString message = lineMessage->text();
    if(message.isEmpty())
        return;
    this->sendMessage(message);
}

void ChatUser::slotConnected() {
    txtChat->append("Connected to port: " + QString::number(userSocket->peerPort()));
}

void ChatUser::slotError(QAbstractSocket::SocketError error) {
    QString errorDescription = "Error: " +
            (error == QAbstractSocket::HostNotFoundError
             ? "The host was not found"
             : error == QAbstractSocket::RemoteHostClosedError
               ? "The remote host is closed"
               : error == QAbstractSocket::ConnectionRefusedError
                 ? "The connection was refused"
                 : userSocket->errorString());
    txtChat->append(errorDescription);
}

void ChatUser::slotReadyRead() {
    QDataStream in(userSocket);
    while(true) {
        if(blockSize == 0) {
            if(static_cast<quint64>(userSocket->bytesAvailable()) < sizeof(blockSize))
                break;
            in >> blockSize;
        }
        if(static_cast<quint64>(userSocket->bytesAvailable()) < blockSize)
            break;
        QString message;
        in >> message;
        blockSize = 0;
        txtChat->append(message);
    }
}

void ChatUser::sendMessage(const QString &message) {
    QByteArray bytesBlock;
    QDataStream out(&bytesBlock, QIODevice::WriteOnly);
    out << quint16(0) << message;
    out.device()->seek(0);
    out << static_cast<quint16>(bytesBlock.size() - sizeof(quint16));
    userSocket->write(bytesBlock);
    lineMessage->clear();
}

ChatUser::ChatUser(QWidget *parent)
    : QWidget(parent)
{
    this->setWindowTitle("Chat");

    blockSize = 0;
    userSocket = new QTcpSocket(this);
    QObject::connect(userSocket, &QTcpSocket::connected,
                     this, &ChatUser::slotConnected);
    QObject::connect(userSocket, static_cast<void (QTcpSocket::*)(QAbstractSocket::SocketError)>(&QTcpSocket::error),
                     this, &ChatUser::slotError);
    QObject::connect(userSocket, &QTcpSocket::readyRead,
                     this, &ChatUser::slotReadyRead);

    QLabel *lblPortNumber = new QLabel("Port number:");

    spinPortNumber = new QSpinBox();
    spinPortNumber->setMinimum(0);
    spinPortNumber->setMaximum((1 << 16) - 1);
    spinPortNumber->setValue(5000);

    QPushButton *btnPortNumber = new QPushButton("Connect");
    btnPortNumber->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    QObject::connect(btnPortNumber, &QPushButton::clicked,
                     this, &ChatUser::slotBtnPortNumberClicked);

    QLabel *lblChat = new QLabel("Chat:");

    txtChat = new QTextEdit();
    txtChat->setReadOnly(true);

    QLabel *lblMessage = new QLabel("Message:");

    lineMessage = new QLineEdit();
    QObject::connect(lineMessage, &QLineEdit::returnPressed,
                     this, &ChatUser::slotBtnSendMessageClicked);

    QPushButton *btnSendMessage = new QPushButton("Send");
    btnSendMessage->setSizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
    QObject::connect(btnSendMessage, &QPushButton::clicked,
                     this, &ChatUser::slotBtnSendMessageClicked);

    QHBoxLayout *layoutPortNumber = new QHBoxLayout();
    layoutPortNumber->addWidget(spinPortNumber);
    layoutPortNumber->addWidget(btnPortNumber);

    QHBoxLayout *layoutMessage = new QHBoxLayout();
    layoutMessage->addWidget(lineMessage);
    layoutMessage->addWidget(btnSendMessage);

    QVBoxLayout *layoutMain = new QVBoxLayout();
    layoutMain->addWidget(lblPortNumber);
    layoutMain->addLayout(layoutPortNumber);
    layoutMain->addWidget(lblChat);
    layoutMain->addWidget(txtChat);
    layoutMain->addWidget(lblMessage);
    layoutMain->addLayout(layoutMessage);

    this->setLayout(layoutMain);
}
