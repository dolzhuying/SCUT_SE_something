#include "server_widget.h"

server_widget::server_widget(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(750,600);
    setWindowTitle(QString("服务端"));
    setWindowIcon(QIcon(":/images/resources/images/title1.jpg"));

    QImage background(":/images/resources/images/background7.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    QString hostAddress = get_localIP_address();
    host_adress = new QLineEdit(hostAddress, this);
    host_adress->setReadOnly(true);
    host_adress->setPlaceholderText("主机地址");

    port = new QLineEdit("1200", this);
    port->setReadOnly(true);
    port->setPlaceholderText("端口号");

    button_start = new QPushButton("开始监听", this);
    button_start->setObjectName("StartButton");
    connect(button_start,&QPushButton::clicked,this,&server_widget::start_Server);

    button_stop = new QPushButton("停止连接", this);
    button_stop->setEnabled(false);
    button_stop->setObjectName("StopButton");
    connect(button_stop,&QPushButton::clicked,this,&server_widget::stop_Server);

    communicationLog = new QTextEdit(this);
    communicationLog->setObjectName("CommunicationLog");
    communicationLog->setReadOnly(true);

    message_line = new QLineEdit(this);
    message_line->setFixedSize(500,10);
    message_line->setPlaceholderText("请输入");
    message_line->setMinimumHeight(50);
    message_line->installEventFilter(this);

    button_send = new QPushButton("发送", this);
    button_send->setEnabled(false);
    button_send->setObjectName("SendButton");
    connect(button_send,&QPushButton::clicked,this,&server_widget::send_message);

    serverStatusLabel = new QLabel("未开始监听", this);
    serverStatusLabel->setObjectName("ServerStatusLabel");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *hostLayout = new QHBoxLayout;
    hostLayout->addWidget(host_adress);
    hostLayout->addWidget(port);

    QHBoxLayout*textlayout=new QHBoxLayout;
    textlayout->addWidget(message_line);
    textlayout->addWidget(button_send);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button_start);
    buttonLayout->addWidget(button_stop);

    mainLayout->addLayout(hostLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(serverStatusLabel);
    mainLayout->addWidget(communicationLog);
    mainLayout->addLayout(textlayout);

    setStyleSheet(
        "#StartButton, #StopButton, #SendButton {"
        "   background-color: rgba(180, 180, 180, 0.7);"
        "   border: none;"
        "   color: white;"
        "   padding: 10px 20px;"
        "   text-align: center;"
        "   text-decoration: none;"
        "   display: inline-block;"
        "   font-size: 16px;"
        "   margin: 4px 2px;"
        "   cursor: pointer;"
        "   border-radius: 4px;"
        "}"
        "#StartButton:hover, #StopButton:hover, #SendButton:hover {"
        "   background-color: rgba(180, 180, 180, 0.7);"
        "}"
        "#CommunicationLog {"
        "   background-color: rgba(180, 180, 180, 0.7);"
        "   color: #000;"
        "   border: 1px solid #ccc;"
        "   border-radius: 4px;"
        "   padding: 5px;"
        "}"
        "#ServerStatusLabel {"
        "   font-size: 18px;"
        "}"
        "#StartButton, #StopButton, #SendButton:hover {"
        "   background-color: rgba(255, 255, 255, 0.7);"
        "}"
        );

    server = new QTcpServer(this);
    connect(server, &QTcpServer::newConnection, this, &server_widget::incomingConnection);

}

server_widget::~server_widget()
{
    if (server) {
        stop_Server();
        delete server;
    }
}

void server_widget::start_Server()
{
    QString hostaddress=host_adress->text();//获取本机地址
    quint16 port_=port->text().toInt();//本机端口号
    //监听是否有请求连接本机的客户端，有则更改控件权限
    if(server->listen(QHostAddress(hostaddress), port_))
    {
        button_start->setEnabled(false);
        button_stop->setEnabled(true);
        button_send->setEnabled(true);
        serverStatusLabel->setText("正在监听: " + hostaddress + ":" + QString::number(port_));
    }
    else
    {
        communicationLog->append("无法启动: " + server->errorString());
    }

}

void server_widget::stop_Server()
{
    server->close();
    button_start->setEnabled(true);
    button_stop->setEnabled(false);
    button_send->setEnabled(false);
    serverStatusLabel->setText("未开始监听");
    communicationLog->clear();
}

void server_widget::send_message()
{
    QString message=message_line->text();//获取信息文本
    if(!message.isEmpty())
    {
        QByteArray data=message.toUtf8();//转为utf-8编码
        for (QTcpSocket *clientSocket : clients)//遍历每个客户端连接
        {
            clientSocket->write(data);//向每个客户端写入数据
        }
        show_message("服务端: " + message);
        message_line->clear();
    }
}

void server_widget::show_message(const QString &message)
{
    communicationLog->append(message);
}

bool server_widget::eventFilter(QObject *obj, QEvent *event)
{
    if (obj == message_line && event->type() == QEvent::KeyPress)
    {
        QKeyEvent *keyEvent = static_cast<QKeyEvent*>(event);
        if ((keyEvent->key() == Qt::Key_Return || keyEvent->key() == Qt::Key_Enter)&&(button_send->isEnabled()))
        {
            send_message();
            return true;
        }
    }
    return QWidget::eventFilter(obj, event);
}

QString server_widget::get_localIP_address()
{
    const QList<QHostAddress> &addresses = QNetworkInterface::allAddresses();//获取网络接口地址列表
    for (const QHostAddress &address : addresses)//遍历列表
    {
        if (address.protocol() == QAbstractSocket::IPv4Protocol && address != QHostAddress::LocalHost) {
            return address.toString();//找到第一个非回环IPV4地址并返回
        }
    }
    return "127.0.0.1";//回环地址
}

void server_widget::incomingConnection()
{
    while(server->hasPendingConnections())//有连接请求
    {
        QTcpSocket*clientsocket=server->nextPendingConnection();//创建QTcpSocket对象进入列表管理
        clients.append(clientsocket);
        connect(clientsocket,&QTcpSocket::readyRead,this,&server_widget::readyReadHandler);//处理该链接的读取信息
        connect(clientsocket,&QTcpSocket::disconnected,this,&server_widget::disconnectedHandler);//处理该链接的断连
        show_message("新客户端连接成功: " + clientsocket->peerAddress().toString());
    }

}

void server_widget::readyReadHandler()
{
    QTcpSocket *clientsocket = qobject_cast<QTcpSocket*>(sender());//指针转化为QTcpSocket类型
    if (!clientsocket)
    {
        return;
    }
    while (clientsocket->bytesAvailable() > 0)//该特定链接的读缓冲区有数据
    {
        QByteArray data = clientsocket->readAll();
        QString message = QString::fromUtf8(data);
        show_message("客户端:"+ message);
    }
}

void server_widget::disconnectedHandler()
{
    QTcpSocket *clientsocket = qobject_cast<QTcpSocket*>(sender());//指针转化
    if (!clientsocket)
        return;
    clients.removeOne(clientsocket);//删除列表里的对象，即对应链接
    delete clientsocket;//释放资源
    clientsocket=NULL;
}




