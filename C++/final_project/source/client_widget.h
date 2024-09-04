#ifndef CLIENT_WIDGET_H
#define CLIENT_WIDGET_H

#include <QWidget>
#include<QtNetwork/QTcpSocket>
#include <QtNetwork/QNetworkInterface>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QEvent>
#include<QKeyEvent>

class client_widget : public QWidget
{
    Q_OBJECT
public:
    explicit client_widget(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *event);
    void show_message(const QString &message);

private slots:
    void connect_to_server();
    void connected_to_server();
    void disconnect_from_server();
    void disconnected_from_server();      
    void show_error(const QString &error);
    void send_message();
    void readyRead_handler();

private:
    QLineEdit *server_address=NULL;//要链接的服务器地址
    QLineEdit *server_port=NULL;//对应服务器端口

    QPushButton *button_connect=NULL;//请求连接
    QPushButton *button_disconnect=NULL;//断开连接

    QTextEdit *communicationLog=NULL;//聊天框
    QLineEdit *message_line=NULL;//聊天信息输入栏
    QPushButton *button_send=NULL;//发送按钮

    QLabel *connectionStatusLabel=NULL;//显示连接状态
    QTcpSocket *socket=NULL;//关键通信媒介

};

#endif // CLIENT_WIDGET_H
