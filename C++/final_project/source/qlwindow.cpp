#include "qlwindow.h"
#include "./ui_qlwindow.h"

qlwindow::qlwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::qlwindow)
{

    page1=new exermode;
    page2=new helpword;
    page4=new rank_show;
    page3=new contest;
    page5=new client_widget;
    page6=new server_widget;

    setMaximumSize(863,600);
    setMinimumSize(863,600);

    setWindowIcon(QIcon(":/images/resources/images/title1.jpg"));

    button1=new QPushButton("练习模式",this);
    button1->setFont(QFont("华文彩云",15));
    button1->setMaximumSize(100,50);
    button1->setMinimumSize(100,50);
    button1->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    button2=new QPushButton("比赛模式",this);
    button2->setFont(QFont("华文彩云",15));
    button2->setMaximumSize(100,50);
    button2->setMinimumSize(100,50);
    button2->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    button3=new QPushButton("排行榜",this);
    button3->setFont(QFont("华文彩云",15));
    button3->setMaximumSize(100,50);
    button3->setMinimumSize(100,50);
    button3->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    button4=new QPushButton("帮助",this);
    button4->setFont(QFont("华文彩云",15));
    button4->setMaximumSize(100,50);
    button4->setMinimumSize(100,50);
    button4->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    button_client=new QPushButton("客户端",this);
    button_client->setFont(QFont("华文彩云",15));
    button_client->setMaximumSize(100,50);
    button_client->setMinimumSize(100,50);
    button_client->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    button_server=new QPushButton("服务端",this);
    button_server->setFont(QFont("华文彩云",15));
    button_server->setMaximumSize(100,50);
    button_server->setMinimumSize(100,50);
    button_server->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:#AFBFCF;");

    hlayout1=new QHBoxLayout;
    hlayout1->setSpacing(100);
    hlayout1->addWidget(button_client);
    hlayout1->addWidget(button_server);

    hlayout=new QHBoxLayout;
    hlayout->setSpacing(60);
    hlayout->addWidget(button1);
    hlayout->addWidget(button2);
    hlayout->addWidget(button3);
    hlayout->addWidget(button4);

    vlayout=new QVBoxLayout(this);
    vlayout->setAlignment(Qt::AlignBottom|Qt::AlignCenter);
    vlayout->setSpacing(20);
    vlayout->addLayout(hlayout);
    vlayout->addLayout(hlayout1);
    vlayout->setContentsMargins(0,0,0,75);


    QImage background(":/images/resources/images/background.png");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    mapforcontest.resize(6,QVector<int>(6,0));

    connect(button1,&QPushButton::clicked,this,&qlwindow::to_exermode);
    connect(page1,SIGNAL(back()),this,SLOT(fromexer_returntothis()));

    connect(button3,&QPushButton::clicked,this,&qlwindow::to_rank);
    connect(page4,SIGNAL(back()),this,SLOT(fromrank_returntothis()));

    connect(button4,&QPushButton::clicked,this,&qlwindow::to_help);

    connect(button2,&QPushButton::clicked,this,&qlwindow::to_contest);
    connect(page3,SIGNAL(back()),this,SLOT(fromcontest_returntothis()));

    connect(button_client,&QPushButton::clicked,this,&qlwindow::to_client);
    connect(button_server,&QPushButton::clicked,this,&qlwindow::to_server);

    ui->setupUi(this);
}

qlwindow::~qlwindow()
{
    delete ui;
}

void qlwindow::to_exermode()//前往练习模式
{
    this->close();
    page1->show();
}

void qlwindow::fromexer_returntothis()//练习模式返回主页面
{
    page1->close();
    this->show();
}

void qlwindow::to_help()
{
    page2->show();
}

void qlwindow::to_rank()
{
    this->close();
    page4->show();
}

void qlwindow::fromrank_returntothis()
{
    page4->close();
    this->show();
}

void qlwindow::to_contest()
{

    page3->reset_time();
    page3->initmap();
    this->close();
    page3->show();
}

void qlwindow::fromcontest_returntothis()
{
    page3->close();
    this->show();
}

void qlwindow::to_server()
{
    page6->show();
}

void qlwindow::to_client()
{
    page5->show();
}

