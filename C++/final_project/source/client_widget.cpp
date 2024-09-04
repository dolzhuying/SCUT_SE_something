#include "client_widget.h"
client_widget::client_widget(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(750,600);
    setWindowTitle(QString("客户端"));
    setWindowIcon(QIcon(":/images/resources/images/title1.jpg"));

    QImage background(":/images/resources/images/background7.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    server_address = new QLineEdit("", this);
    server_address->setPlaceholderText("服务器地址");
    server_port = new QLineEdit("1200", this);
    server_port->setPlaceholderText("服务器端口");

    button_connect=new QPushButton("开始连接",this);
    button_connect->setObjectName("ConnectButton");
    connect(button_connect,&QPushButton::clicked,this,&client_widget::connect_to_server);

    button_disconnect = new QPushButton("取消连接", this);
    button_disconnect->setObjectName("DisconnectButton");
    button_disconnect->setEnabled(false);
    connect(button_disconnect,&QPushButton::clicked,this,&client_widget::disconnect_from_server);

    communicationLog = new QTextEdit(this);
    communicationLog->setObjectName("CommunicationLog");
    communicationLog->setReadOnly(true);

    message_line = new QLineEdit(this);
    message_line->setFixedSize(500,10);
    message_line->setPlaceholderText("请输入");
    message_line->setMinimumHeight(50);
    message_line->installEventFilter(this);

    button_send = new QPushButton("发送", this);
    button_send->setObjectName("SendButton");
    button_send->setEnabled(false);
    connect(button_send,&QPushButton::clicked,this,&client_widget::send_message);

    connectionStatusLabel = new QLabel("未连接", this);
    connectionStatusLabel->setObjectName("ConnectionStatusLabel");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *serverLayout = new QHBoxLayout;
    serverLayout->addWidget(server_address);
    serverLayout->addWidget(server_port);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(button_connect);
    buttonLayout->addWidget(button_disconnect);

    QHBoxLayout*textlayout=new QHBoxLayout;
    textlayout->addWidget(message_line);
    textlayout->addWidget(button_send);

    mainLayout->addLayout(serverLayout);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addWidget(connectionStatusLabel);
    mainLayout->addWidget(communicationLog);
    mainLayout->addLayout(textlayout);


    setStyleSheet(
        "#ConnectButton, #DisconnectButton, #SendButton {"
        "   background-color: rgba(190, 190, 190, 0.7);"
        "   border: none;"
        "   color: white;"
        "   padding: 10px 20px;"
        "   text-align: center;"
        "   text-decoration: none;"
        "   display: inline-block;"
        "   font-size: 16px;"
        "   margin: 5px 3px;"
        "   cursor: pointer;"
        "   border-radius: 4px;"
        "}"
        "#ConnectButton:hover, #DisconnectButton:hover, #SendButton:hover {"
        "   background-color: rgba(190, 190, 190, 0.7);"
        "}"
        "#CommunicationLog {"
        "   background-color: rgba(190, 190, 190, 0.7);"
        "   color: #000;"
        "   border: 1px solid #ccc;"
        "   border-radius: 4px;"
        "   padding: 5px;"
        "}"
        "#ConnectionStatusLabel {"
        "   font-size: 18px;"
        "}"
        "#ConnectButton:hover, #DisconnectButton:hover, #SendButton:hover {"
        "   background-color: rgba(255, 255, 255, 0.7);"
        "}"
        );

    socket=new QTcpSocket;
    connect(socket, &QTcpSocket::connected, this, &client_widget::connected_to_server);
    connect(socket, &QTcpSocket::disconnected, this, &client_widget::disconnected_from_server);
    connect(socket, &QTcpSocket::readyRead, this, &client_widget::readyRead_handler);

}

void client_widget::connect_to_server()
{
    QString hostaddress=server_address->text();//获取服务器地址
    quint16 port=server_port->text().toUShort();//获取服务器端口号
    socket->connectToHost(hostaddress,port);//发起连接请求
}

void client_widget::connected_to_server()
{
    button_connect->setEnabled(false);//“开始连接”不可在触发
    button_disconnect->setEnabled(true);//设置为可触发
    button_send->setEnabled(true);
    connectionStatusLabel->setText("已连接");//更改状态显示
}

void client_widget::disconnect_from_server()
{
    socket->disconnectFromHost();//断开连接
    communicationLog->clear();//清空聊天框
}

void client_widget::disconnected_from_server()
{
    button_connect->setEnabled(true);
    button_disconnect->setEnabled(false);
    button_send->setEnabled(false);
    connectionStatusLabel->setText("未连接");
}

void client_widget::send_message()
{
    QString message=message_line->text();//获取信息文本
    if(!message.isEmpty())//信息非空
    {
        QByteArray data=message.toUtf8();//转化为utf—8格式编码
        socket->write(data);//将数据写入系统的写缓冲区
        message_line->clear();
        show_message("我:"+message);//聊天框显示信息
    }
}

void client_widget::show_message(const QString &message)
{
    communicationLog->append(message);//添加信息显示
}

void client_widget::show_error(const QString &error)
{
    communicationLog->append("错误："+error);
}

bool client_widget::eventFilter(QObject *obj, QEvent *event)
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

void client_widget::readyRead_handler()
{
    while (socket->bytesAvailable() > 0)//缓冲区有数据可读
    {
        QByteArray data = socket->readAll();//读取数据
        QString message = QString::fromUtf8(data);//从utf-8编码转为字符串
        show_message("服务端: " + message);//显示文本信息
    }
}
