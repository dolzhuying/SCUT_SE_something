#include "exermode.h"

exermode::exermode(QWidget *parent)
    : QWidget{parent}
{

    page1=new level1;


    setFixedSize(863,600);//固定大小使得页面不会随鼠标拖动而改变大小

    setWindowIcon(QIcon(":/images/resources/images/common.png"));//窗口图标
    setWindowTitle(QString("练习模式"));//窗口标题

    QImage background(":/images/resources/images/background1.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);//图片适应窗口大小
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);//使用调色板进行背景设置

    buttonback=new QPushButton("返回",this);
    buttonback->setFont(QFont("华文彩云",15));
    buttonback->setMaximumSize(50,25);
    buttonback->setMinimumSize(50,25);
    buttonback->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    round1=new QPushButton("关卡1",this);
    round1->setFont(QFont("华文彩云",15));
    round1->setMaximumSize(100,50);
    round1->setMinimumSize(100,50);
    round1->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    round2=new QPushButton("关卡2",this);
    round2->setFont(QFont("华文彩云",15));
    round2->setMaximumSize(100,50);
    round2->setMinimumSize(100,50);
    round2->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    round3=new QPushButton("关卡3",this);
    round3->setFont(QFont("华文彩云",15));
    round3->setMaximumSize(100,50);
    round3->setMinimumSize(100,50);
    round3->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    round4=new QPushButton("关卡4",this);
    round4->setFont(QFont("华文彩云",15));
    round4->setMaximumSize(100,50);
    round4->setMinimumSize(100,50);
    round4->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    round5=new QPushButton("关卡5",this);
    round5->setFont(QFont("华文彩云",15));
    round5->setMaximumSize(100,50);
    round5->setMinimumSize(100,50);
    round5->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    roundrandom=new QPushButton("题库随机关卡",this);
    roundrandom->setFont(QFont("华文彩云",12));
    roundrandom->setMaximumSize(100,50);
    roundrandom->setMinimumSize(100,50);
    roundrandom->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");


    vlayout1=new QVBoxLayout;
    vlayout1->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    vlayout1->addWidget(buttonback);

    vlayout2= new QVBoxLayout;
    vlayout2->setSpacing(40);
    vlayout2->setAlignment(Qt::AlignCenter);
    vlayout2->addWidget(round1);
    vlayout2->addWidget(round2);
    vlayout2->addWidget(round3);
    vlayout2->addWidget(round4);
    vlayout2->addWidget(round5);
    vlayout2->addWidget(roundrandom);

    hlayout=new QHBoxLayout(this);
    hlayout->setSpacing(300);
    hlayout->setAlignment(Qt::AlignLeft);
    hlayout->addLayout(vlayout1);
    hlayout->addLayout(vlayout2);

    connect(buttonback,&QPushButton::clicked,this,&exermode::returntomain);

    connect(round1,&QPushButton::clicked,this,&exermode::to_level1);
    connect(round2,&QPushButton::clicked,this,&exermode::to_level2);
    connect(round3,&QPushButton::clicked,this,&exermode::to_level3);
    connect(round4,&QPushButton::clicked,this,&exermode::to_level4);
    connect(round5,&QPushButton::clicked,this,&exermode::to_level5);
    connect(roundrandom,&QPushButton::clicked,this,&exermode::to_random);

    connect(this->page1,SIGNAL(back()),this,SLOT(from_level1_to_this()));
}

exermode::~exermode()
{

}

void exermode::returntomain()
{
    emit this->back();
}

void exermode::to_level1()
{
    this->page1->loadfile(":/maps/resources/maps/round1.txt");
    this->close();
    this->page1->show();
}

void exermode::to_level2()
{
    this->page1->loadfile(":/maps/resources/maps/round2.txt");
    this->close();
    this->page1->show();
}

void exermode::to_level3()
{
    this->page1->loadfile(":/maps/resources/maps/round3.txt");
    this->close();
    this->page1->show();
}

void exermode::to_level4()
{
    this->page1->loadfile(":/maps/resources/maps/round4.txt");
    this->close();
    this->page1->show();
}

void exermode::to_level5()
{
    this->page1->loadfile(":/maps/resources/maps/round5.txt");
    this->close();
    this->page1->show();
}

void exermode::to_random()
{
    QString folderPath = "./randommap";//随机题库文件夹
    QDir directory(folderPath);

    if (!directory.exists() || !directory.isReadable()) {
        qDebug() << "Folder not found or not readable.";
        return;
    }

    //获取目录下所有文件
    QStringList fileNames = directory.entryList(QDir::Files | QDir::NoDotAndDotDot);
    if (fileNames.isEmpty()) {
        qDebug() << "No files found in the folder.";
        return;
    }
    //根据文件数量随机生成读取的文件number
    int randomIndex = QRandomGenerator::global()->generate() % fileNames.size();
    QString filename = fileNames[randomIndex];
    QString filepath=directory.filePath(filename);//读取文件

    this->page1->loadfile(filepath);
    this->close();
    this->page1->show();
}

void exermode::from_level1_to_this()
{
    this->page1->close();
    this->show();
}
