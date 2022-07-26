#ifndef TCPSERVER_HPP
#define TCPSERVER_HPP

#include <QObject>
#include <QTcpServer>
#include <vector>
#include <QTcpSocket>
using namespace std;
class TcpServer : public QObject
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr);

signals:
    void newMessage(const QByteArray &ba);


private slots:
    void onNewConnection();
    void onReadyRead();
    void onClientDisconnected();
    void onNewMessage(const QByteArray &ba);
public:
    void adduser(QString&s,QTcpSocket*socket);
    void Disconnect(QTcpSocket*socket);
    vector<pair<QString,QTcpSocket*>>getUsers();
    static TcpServer& getInstance();
    static void destroyInstance();
private:
    static TcpServer*instance;
    QTcpSocket*actualsocket;
private:
    QTcpServer _server;
    vector<pair<QString, QTcpSocket*>> _clients;
};

#endif // TCPSERVER_HPP
