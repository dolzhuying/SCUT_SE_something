#ifndef SERVER_WIDGET_H
#define SERVER_WIDGET_H

#include <QWidget>
#include<QtNetwork/QTcpSocket>
#include<QtNetwork/QTcpServer>
#include <QtNetwork/QNetworkInterface>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QLabel>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QEvent>
#include<QKeyEvent>
#include <QVBoxLayout>
#include <QHBoxLayout>


class server_widget : public QWidget
{
    Q_OBJECT
public:
    explicit server_widget(QWidget *parent = nullptr);
    bool eventFilter(QObject *obj, QEvent *event);
    QString get_localIP_address();
    void show_message(const QString &message);
    ~server_widget();

private slots:
    void start_Server();
    void stop_Server();
    void send_message();
    void incomingConnection();
    void readyReadHandler();
    void disconnectedHandler();

private:
    QLineEdit *port=NULL;//端口号
    QLineEdit *host_adress=NULL;//主机地址

    QPushButton *button_start=NULL;//开始监听
    QPushButton *button_stop=NULL;//停止监听

    QTextEdit *communicationLog=NULL;//聊天框
    QLineEdit *message_line=NULL;//信息输入栏
    QPushButton *button_send=NULL;//发送按钮

    QLabel *serverStatusLabel=NULL;//连接状态
    QTcpServer *server=NULL;//服务器
    QList<QTcpSocket*> clients;//与主机建立了连接的客户端




signals:
};

#endif // SERVER_WIDGET_H
