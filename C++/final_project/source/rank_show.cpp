#include "rank_show.h"

rank_show::rank_show(QWidget *parent)
    : QWidget{parent}
{
    setMaximumSize(863,600);
    setMinimumSize(863,600);

    setWindowIcon(QIcon(":/images/resources/images/rank.png"));
    setWindowTitle(QString("排行榜"));

    QImage background(":/images/resources/images/background4.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    button_back=new QPushButton("返回",this);
    button_back->setFont(QFont("华文彩云",15));
    button_back->setMaximumSize(100,25);
    button_back->setMinimumSize(100,25);
    button_back->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    button_common=new QPushButton("普通模式",this);
    button_common->setFont(QFont("华文彩云",15));
    button_common->setMaximumSize(100,25);
    button_common->setMinimumSize(100,25);
    button_common->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    button_boss=new QPushButton("比赛模式",this);
    button_boss->setFont(QFont("华文彩云",15));
    button_boss->setMaximumSize(100,25);
    button_boss->setMinimumSize(100,25);
    button_boss->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");


    hlayout1=new QHBoxLayout;
    hlayout1->setSpacing(200);
    hlayout1->setAlignment(Qt::AlignCenter);
    hlayout1->addWidget(button_back);
    hlayout1->addWidget(button_boss);
    hlayout1->addWidget(button_common);


    button_id=new QPushButton("按昵称",this);
    button_id->setFont(QFont("黑体",12));
    button_id->setMaximumSize(90,25);
    button_id->setMinimumSize(90,25);
    button_id->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    button_pass_time=new QPushButton("按通关次数",this);
    button_pass_time->setFont(QFont("黑体",12));
    button_pass_time->setMaximumSize(90,25);
    button_pass_time->setMinimumSize(90,25);
    button_pass_time->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    button_timeuse=new QPushButton("按最短用时",this);
    button_timeuse->setFont(QFont("黑体",12));
    button_timeuse->setMaximumSize(90,25);
    button_timeuse->setMinimumSize(90,25);
    button_timeuse->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");

    hlayout2=new QHBoxLayout;
    hlayout2->setSpacing(100);
    hlayout2->setAlignment(Qt::AlignCenter);
    hlayout2->addWidget(button_id);
    hlayout2->addWidget(button_pass_time);
    hlayout2->addWidget(button_timeuse);


    tableview=new QTableView(this);
    tableview->setShowGrid(false); // 不显示网格线
    tableview->horizontalHeader()->setHighlightSections(false); // 不高亮选中列
    tableview->verticalHeader()->setVisible(false); // 隐藏垂直表头（通常包含行号）
    tableview->horizontalHeader()->setDefaultSectionSize(192);
    tableview->horizontalHeader()->setFont(QFont("黑体",15,QFont::Normal));
    tableview->horizontalHeader()->setStyleSheet(R"(
    QHeaderView::section {
        background-color: transparent;
        color: #000000;
        text-align: center;
    }
)");
    tableview->setStyleSheet(
        " background-color: transparent;"
        "border:none;"
        );

    usermodel=new QStandardItemModel;
    usermodel->setColumnCount(4);
    usermodel->setHeaderData(0,Qt::Horizontal,tr("排名"));
    usermodel->setHeaderData(1,Qt::Horizontal,tr("昵称"));
    usermodel->setHeaderData(2,Qt::Horizontal,tr("最短用时/秒"));
    usermodel->setHeaderData(3,Qt::Horizontal,tr("通关次数"));
    tableview->setModel(usermodel);

    hlayout3=new QHBoxLayout;
    hlayout3->addWidget(tableview);


    vlayout1=new QVBoxLayout(this);
    vlayout1->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    vlayout1->addLayout(hlayout1);
    vlayout1->addLayout(hlayout2);
    vlayout1->addLayout(hlayout3);


    connect(button_back,&QPushButton::clicked,this,&rank_show::returntomain);
    connect(button_common,&QPushButton::clicked,this,&rank_show::choose_common);
    connect(button_boss,&QPushButton::clicked,this,&rank_show::choose_boss);
    connect(button_id,&QPushButton::clicked,this,&rank_show::choose_id);
    connect(button_timeuse,&QPushButton::clicked,this,&rank_show::choose_timeuse);
    connect(button_pass_time,&QPushButton::clicked,this,&rank_show::choose_pass_time);

}

void rank_show::returntomain()
{
    emit back();
}

void rank_show:: choose_common()//练习模式排行榜
{
    users=userbase::loadUsersFromJson("./rank/common.json");
}

void rank_show::choose_boss()//比赛模式排行榜
{
     users=userbase::loadUsersFromJson("./rank/boss.json");
}

bool rank_show::issersempty()//没有读取文件时的提示
{
    if(users.empty())
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);
        messageBox.setText("未选定模式");
        if(messageBox.exec()==QMessageBox::Ok)
        {
            return true;
        }
    }
    else return false;
}

void rank_show::show_rank()
{
    //设置表头
    usermodel->setColumnCount(4);
    usermodel->setHeaderData(0,Qt::Horizontal,tr("排名"));
    usermodel->setHeaderData(1,Qt::Horizontal,tr("昵称"));
    usermodel->setHeaderData(2,Qt::Horizontal,tr("最短用时/秒"));
    usermodel->setHeaderData(3,Qt::Horizontal,tr("通关次数"));
    for(int i=0;i<users.size();i++)//逐条信息进行设置
    {
        QStandardItem*rankitem=new QStandardItem(QString::number(i+1));//排名
        rankitem->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
        rankitem->setFont(QFont("黑体",15,QFont::Normal));

        QStandardItem*iditem= new QStandardItem(QString(users[i].get_id()));//用户名id
        iditem->setFont(QFont("黑体",15,QFont::Normal));
        iditem->setData(Qt::AlignCenter, Qt::TextAlignmentRole);

        QStandardItem*timeitem=new QStandardItem(QString::number(users[i].get_time()));//最短时间
        timeitem->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
        timeitem->setFont(QFont("黑体",15,QFont::Normal));

        QStandardItem*passtimeitem=new QStandardItem(QString::number(users[i].get_pass_time()));//通关次数
        passtimeitem->setData(Qt::AlignCenter, Qt::TextAlignmentRole);
        passtimeitem->setFont(QFont("黑体",15,QFont::Normal));

        usermodel->setItem(i,0,rankitem);
        usermodel->setItem(i,1,iditem);
        usermodel->setItem(i,2,timeitem);
        usermodel->setItem(i,3,passtimeitem);
    }
}

void rank_show::choose_id()//按id排序
{
    if(issersempty())return;
    else
    {
        usermodel->clear();
        std::sort(users.begin(),users.end(),[](const userbase&a,const userbase&b){return a.get_id()<b.get_id();});

        show_rank();
    }
}

void rank_show::choose_timeuse()//按最短用时排序
{
    if(issersempty())return;
    else
    {
        usermodel->clear();
        std::sort(users.begin(),users.end(),[](const userbase&a,const userbase&b)
        {if(a.get_time()!=b.get_time())
        return a.get_time()<b.get_time();
        else return a.get_id()<b.get_id();});

        show_rank();
    }
}

void rank_show::choose_pass_time()//按通关次数排序
{
    if(issersempty())return;
    else
    {
        usermodel->clear();
        std::sort(users.begin(),users.end(),[](const userbase&a,const userbase&b)
        {if(a.get_pass_time()!=b.get_pass_time())
        return a.get_pass_time()>b.get_pass_time();
        else return a.get_id()<b.get_id();});

        show_rank();
    }
}
