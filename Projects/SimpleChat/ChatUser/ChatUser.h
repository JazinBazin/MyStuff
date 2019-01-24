#pragma once
#include <QWidget>
#include <QTextEdit>
#include <QLineEdit>
#include <QSpinBox>
#include <QTcpSocket>

class ChatUser : public QWidget
{
    Q_OBJECT
public:
    ChatUser(QWidget *parent = nullptr);

private:
    void sendMessage(const QString &message);

private:
    QSpinBox *spinPortNumber;
    QTextEdit *txtChat;
    QLineEdit *lineMessage;
    QTcpSocket *userSocket;
    quint16 blockSize;

signals:

private slots:
    void slotBtnPortNumberClicked();
    void slotBtnSendMessageClicked();
    void slotConnected();
    void slotError(QAbstractSocket::SocketError error);
    void slotReadyRead();
};
