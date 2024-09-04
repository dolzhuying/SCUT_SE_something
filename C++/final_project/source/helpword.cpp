#include "helpword.h"

helpword::helpword(QWidget *parent)
    : QWidget{parent}
{
    setFixedSize(700,600);

    QImage background(":/images/resources/images/background3.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);

    setWindowIcon(QIcon(":/images/resources/images/title2.jpg"));
    setWindowTitle(QString("规则"));

    vlayout=new QVBoxLayout(this);
    vlayout->setAlignment(Qt::AlignCenter);
    vlayout->setSpacing(10);
    for(int i=0;i<4;i++)
    {
        QHBoxLayout*hlayout=new QHBoxLayout;

        QLabel*label1=new QLabel(this);
        QLabel*label2=new QLabel(this);
        label1->setFixedSize(55,55);
        if(i==0)
        {
            label1->setPixmap(QPixmap(":/images/resources/images/tree0.jpg"));
            label1->setScaledContents(true);


            label2->setFixedSize(400,55);
            label2->setFont(QFont("黑体",15));
            label2->setText("代表当前格子上种了0棵树(仅在练习模式存在)");
            label2->setWordWrap(true);

            hlayout->addWidget(label1);
            hlayout->addWidget(label2);
            vlayout->addLayout(hlayout);

        }
        else if(i==1)
        {
            label1->setPixmap(QPixmap(":/images/resources/images/tree13.jpg"));
            label1->setScaledContents(true);


            label2->setFixedSize(400,55);
            label2->setFont(QFont("黑体",15));
            label2->setText("代表当前格子上种了1棵树或3棵树");
            label2->setWordWrap(true);

            hlayout->addWidget(label1);
            hlayout->addWidget(label2);
            vlayout->addLayout(hlayout);
        }
        else if(i==2)
        {
            label1->setPixmap(QPixmap(":/images/resources/images/tree2.jpg"));
            label1->setScaledContents(true);


            label2->setFixedSize(400,55);
            label2->setFont(QFont("黑体",15));
            label2->setText("代表当前格子上种了2棵树或0棵树（比赛模式）");
            label2->setWordWrap(true);

            hlayout->addWidget(label1);
            hlayout->addWidget(label2);
            vlayout->addLayout(hlayout);
        }
        else if(i==3)
        {
            label1->setPixmap(QPixmap(":/images/resources/images/tree4.jpg"));
            label1->setScaledContents(true);


            label2->setFixedSize(400,55);
            label2->setFont(QFont("黑体",15));
            label2->setText("代表当前格子上种了4棵树");
            label2->setWordWrap(true);


            hlayout->addWidget(label1);
            hlayout->addWidget(label2);
            vlayout->addLayout(hlayout);
        }
    }
    QLabel*label3=new QLabel(this);
    label3->setFixedSize(500,100);
    label3->setText("在本游戏中，你需要点击格子来选定种树区域的左上角作为起点，然后选择种树区域的大小来给该区域每个格子种上一棵树，当所有可选择的种树矩阵被用完后，提交答案并判定是否每一个格子都种上了对应数量的树");
    label3->setFont(QFont("黑体",15));
    label3->setWordWrap(true);

    QLabel*label4=new QLabel(this);
    label4->setFixedSize(500,100);
    label4->setText("游戏支持撤回和重置操作，成绩以用时少者为优。注：在练习模式中重置操作将恢复关卡初始状态，在比赛模式中重置操作将重新生成游戏地图");
    label4->setFont(QFont("黑体",15));
    label4->setWordWrap(true);

    vlayout->addWidget(label3);
    vlayout->addWidget(label4);


}
