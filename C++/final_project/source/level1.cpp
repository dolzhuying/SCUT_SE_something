#include "level1.h"

level1::level1(QWidget *parent)
    : QWidget{parent}
{
    setMaximumSize(863,600);
    setMinimumSize(863,600);
    setWindowIcon(QIcon(":/images/resources/images/common.png"));
    setWindowTitle(QString("普通关卡"));

    QImage background(":/images/resources/images/background5.jpg");
    background=background.scaled(this->width(),this->height(),Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(this->backgroundRole(),QBrush(background));
    this->setPalette(palette);


    buttonback=new QPushButton("返回",this);
    buttonback->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    buttonback->setFont(QFont("华文彩云",15));
    buttonback->setMaximumSize(50,25);
    buttonback->setMinimumSize(50,25);


    vlayout1=new QVBoxLayout;
    vlayout1->setAlignment(Qt::AlignLeft|Qt::AlignTop);
    vlayout1->addWidget(buttonback);

    glayout=new QGridLayout;
    glayout->setSpacing(0);

    matrix1.resize(size,QVector<QLabel*>(size,NULL));
    matrix2.resize(size,QVector<QLabel*>(size,NULL));
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
                QLabel*l1=new QLabel;
                l1->setStyleSheet("QLabel {"
                                  "border: 2px solid black;"
                                  "border-radius: 5px; "
                                  "padding: 1px; "
                                  "}");
                l1->setFixedSize(55,55);
                matrix1[i][j]=l1;
                glayout->addWidget(l1,i,j);

                QLabel*l2=new QLabel;
                l2->setStyleSheet("QLabel {"
                                  "background-color: transparent; "

                                  "border-radius: 5px; "
                                  "padding: 5px; "
                                  "}");
                l2->setText("0");
                l2->setFixedSize(25,25);
                matrix2[i][j]=l2;
                glayout->addWidget(l2,i,j);
        }
    }

    hlayout1=new QHBoxLayout;
    hlayout1->setSpacing(40);
    hlayout2=new QHBoxLayout;
    hlayout2->setSpacing(40);

    choices.resize(4,NULL);
    for(int i=0;i<4;i++)
    {
        QLabel*label=new QLabel;
        label->setFixedSize(60,30);
        label->setStyleSheet("QLabel {"
                             "background-color: white; "
                             "border: 1px solid black;"
                             "border-radius: 4px; "
                             "padding: 5px; "
                             "}");
        hlayout1->addWidget(label);
        choices[i]=label;
    }

    button1=new QPushButton("1x1",this);
    button1->setFixedSize(50,20);
    button1->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button1->setFont(QFont("黑体",12));
    hlayout2->addWidget(button1);

    button2=new QPushButton("2x2",this);
    button2->setFixedSize(50,20);
    button2->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button2->setFont(QFont("黑体",12));
    hlayout2->addWidget(button2);

    button3=new QPushButton("3x3",this);
    button3->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button3->setFont(QFont("黑体",12));
    button3->setFixedSize(50,20);
    hlayout2->addWidget(button3);

    button4=new QPushButton("4x4",this);
    button4->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button4->setFont(QFont("黑体",12));
    button4->setFixedSize(50,20);
    hlayout2->addWidget(button4);

    hlayout3=new QHBoxLayout;
    hlayout3->setSpacing(50);
    hlayout3->setAlignment(Qt::AlignHCenter);

    button_cancel=new QPushButton("撤回",this);
    button_cancel->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button_cancel->setFont(QFont("黑体",12));
    button_cancel->setFixedSize(50,20);
    hlayout3->addWidget(button_cancel);

    button_reset=new QPushButton("重置",this);
    button_reset->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button_reset->setFont(QFont("黑体",12));
    button_reset->setFixedSize(50,20);
    hlayout3->addWidget(button_reset);

    label_time=new QLabel;
    label_time->setFixedSize(65,25);
    label_time->setText("0.00s");
    label_time->setStyleSheet("QLabel {"
                         "background-color: white; "
                         "border: 1px solid black;"
                         "border-radius: 4px; "
                         "padding: 5px; "
                         "}");
    hlayout3->addWidget(label_time);

    button_submit=new QPushButton("提交",this);
    button_submit->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button_submit->setFont(QFont("黑体",12));
    button_submit->setFixedSize(50,20);
    hlayout3->addWidget(button_submit);

    vlayout2=new QVBoxLayout;
    vlayout2->setAlignment(Qt::AlignTop|Qt::AlignCenter);
    vlayout2->setSpacing(20);

    vlayout2->addLayout(glayout);
    vlayout2->addLayout(hlayout1);
    vlayout2->addLayout(hlayout2);
    vlayout2->addLayout(hlayout3);

    QSpacerItem* spacer1 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QSpacerItem* spacer2 = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

    hlayout_total=new QHBoxLayout(this);
    hlayout_total->addLayout(vlayout1);
    hlayout_total->addItem(spacer1);
    hlayout_total->addLayout(vlayout2);
    hlayout_total->addItem(spacer2);


    connect(buttonback,&QPushButton::clicked,this,&level1::return_to_exermode);
    connect(button1,&QPushButton::clicked,this,&level1::choose_1);
    connect(button2,&QPushButton::clicked,this,&level1::choose_2);
    connect(button3,&QPushButton::clicked,this,&level1::choose_3);
    connect(button4,&QPushButton::clicked,this,&level1::choose_4);
    connect(button_cancel,&QPushButton::clicked,this,&level1::choose_cancel);
    connect(button_submit,&QPushButton::clicked,this,&level1::choose_submit);
    connect(button_reset,&QPushButton::clicked,this,&level1::choose_reset);
    connect(&timer,&QTimer::timeout,this,&level1::show_time);
}

void level1::return_to_exermode()
{
    emit this->back();
    cancelboxer.clear();
    if(timer.isActive())
    {
        timer.stop();
        time_total=0;
    }
    
}

level1::~level1()
{

}

void level1::choose_1()
{
    if(selectedlabel!=NULL)
    {
        QVariant value1=choices[0]->property("rest_num");
        int cur=value1.toInt();
        if(selectedlabel_x<size&&selectedlabel_y<size&&cur!=0)
        {
            QVariant curvalue=matrix2[selectedlabel_x][selectedlabel_y]->property("now_num");
            int data=curvalue.toInt();
            data+=1;
            matrix2[selectedlabel_x][selectedlabel_y]->setProperty("now_num",QVariant(data));
            QVariant storedvalue=matrix2[selectedlabel_x][selectedlabel_y]->property("now_num");
            matrix2[selectedlabel_x][selectedlabel_y]->setText(storedvalue.toString());

            cancelbox box(selectedlabel,selectedlabel_x,selectedlabel_y,1);
            cancelboxer.push((box));
            selectedlabel=NULL;

            QVariant value=choices[0]->property("rest_num");
            int now=value.toInt();
            now-=1;
            choices[0]->setProperty("rest_num",QVariant(now));
            choices[0]->setText(QString::number(now));
        }
        else
        {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Information);
            messageBox.setWindowTitle("提示");
            messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
            messageBox.setText("无效操作");
            messageBox.setStandardButtons(QMessageBox::Ok);
            messageBox.setDefaultButton(QMessageBox::Ok);

            messageBox.exec();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void level1::choose_2()
{
    if(selectedlabel!=NULL)
    {
        QVariant value1=choices[1]->property("rest_num");
        int cur=value1.toInt();
        if(selectedlabel_x+1<size&&selectedlabel_y+1<size&&cur!=0)
        {
            for(int i=selectedlabel_x;i<=selectedlabel_x+1;i++)
            {
                for(int j=selectedlabel_y;j<=selectedlabel_y+1;j++)
                {
                    QVariant curvalue=matrix2[i][j]->property("now_num");
                    int data=curvalue.toInt();
                    data+=1;
                    matrix2[i][j]->setProperty("now_num",QVariant(data));
                    QVariant storedvalue=matrix2[i][j]->property("now_num");
                    matrix2[i][j]->setText(storedvalue.toString());


                }
            }
            cancelbox box(selectedlabel,selectedlabel_x,selectedlabel_y,2);
            cancelboxer.push((box));
            selectedlabel=NULL;

            QVariant value=choices[1]->property("rest_num");
            int now=value.toInt();
            now-=1;
            choices[1]->setProperty("rest_num",QVariant(now));
            choices[1]->setText(QString::number(now));
        }
        else
        {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Information);
            messageBox.setWindowTitle("提示");
            messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
            messageBox.setText("无效操作");
            messageBox.setStandardButtons(QMessageBox::Ok);
            messageBox.setDefaultButton(QMessageBox::Ok);

            messageBox.exec();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void level1::choose_3()
{
    if(selectedlabel!=NULL)
    {
        QVariant value1=choices[2]->property("rest_num");
        int cur=value1.toInt();
        if(selectedlabel_x+2<size&&selectedlabel_y+2<size&&cur!=0)
        {
            for(int i=selectedlabel_x;i<=selectedlabel_x+2;i++)
            {
                for(int j=selectedlabel_y;j<=selectedlabel_y+2;j++)
                {
                    QVariant curvalue=matrix2[i][j]->property("now_num");
                    int data=curvalue.toInt();
                    data+=1;
                    matrix2[i][j]->setProperty("now_num",QVariant(data));
                    QVariant storedvalue=matrix2[i][j]->property("now_num");
                    matrix2[i][j]->setText(storedvalue.toString());
                }
            }
            cancelbox box(selectedlabel,selectedlabel_x,selectedlabel_y,3);
            cancelboxer.push((box));
            selectedlabel=NULL;

            QVariant value=choices[2]->property("rest_num");
            int now=value.toInt();
            now-=1;
            choices[2]->setProperty("rest_num",QVariant(now));
            choices[2]->setText(QString::number(now));
        }
        else
        {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Information);
            messageBox.setWindowTitle("提示");
            messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
            messageBox.setText("无效操作");
            messageBox.setStandardButtons(QMessageBox::Ok);
            messageBox.setDefaultButton(QMessageBox::Ok);

            messageBox.exec();
        }
    }
    else
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void level1::choose_4()
{
    if(selectedlabel!=NULL)//先判断是否selectedlabel为空
    {
        QVariant value1=choices[3]->property("rest_num");
        int cur=value1.toInt();
        if(selectedlabel_x+3<size&&selectedlabel_y+3<size&&cur!=0)//判断是否越界
        {
            for(int i=selectedlabel_x;i<=selectedlabel_x+3;i++)
            {
                for(int j=selectedlabel_y;j<=selectedlabel_y+3;j++)//区间加一
                {
                    QVariant curvalue=matrix2[i][j]->property("now_num");
                    int data=curvalue.toInt();
                    data+=1;
                    matrix2[i][j]->setProperty("now_num",QVariant(data));
                    QVariant storedvalue=matrix2[i][j]->property("now_num");
                    matrix2[i][j]->setText(storedvalue.toString());
                }
            }
            cancelbox box(selectedlabel,selectedlabel_x,selectedlabel_y,4);//存储操作
            cancelboxer.push((box));
            selectedlabel=NULL;

            //该矩阵剩余数量减一
            QVariant value=choices[3]->property("rest_num");
            int now=value.toInt();
            now-=1;
            choices[3]->setProperty("rest_num",QVariant(now));
            choices[3]->setText(QString::number(now));
        }
        else//越界则提示
        {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Information);
            messageBox.setWindowTitle("提示");
            messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
            messageBox.setText("无效操作");
            messageBox.setStandardButtons(QMessageBox::Ok);
            messageBox.setDefaultButton(QMessageBox::Ok);

            messageBox.exec();
        }
    }
    else//为空则提示无效
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void level1::choose_cancel()
{
    if(cancelboxer.empty())//操作为空
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
        messageBox.setText("无效操作");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
    else//操作不为空
    {
        cancelbox box=cancelboxer.top();//取出上一次操作
        cancelboxer.pop();
        for(int i=box.selectedlabel_x;i<=box.selectedlabel_x+box.size-1;i++)
        {
            for(int j=box.selectedlabel_y;j<=box.selectedlabel_y+box.size-1;j++)
            {
                QVariant curvalue=matrix2[i][j]->property("now_num");
                int data=curvalue.toInt();
                data-=1;
                matrix2[i][j]->setProperty("now_num",QVariant(data));
                QVariant nowvalue=matrix2[i][j]->property("now_num");
                matrix2[i][j]->setText(nowvalue.toString());

            }
        }//进行区间减一
        QVariant value=choices[box.size-1]->property("rest_num");
        int now=value.toInt();
        now+=1;//矩阵数量加一
        choices[box.size-1]->setProperty("rest_num",QVariant(now));
        choices[box.size-1]->setText(QString::number(now));
    }
}

void level1::mousePressEvent(QMouseEvent*event)
{
    if(event->button()==Qt::LeftButton)
    {
        for(int i=0;i<size;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(matrix1[i][j]->geometry().contains(event->pos()))
                {
                    selectedlabel=matrix2[i][j];
                    selectedlabel_x=i;selectedlabel_y=j;
                    return;
                }
            }
        }
    }
}

void level1::choose_submit()
{
    cancelboxer.clear();
    bool flag=true;
    for(int i=0;i<size;i++)//遍历判断正误
    {
        for(int j=0;j<size;j++)
        {
            QVariant curvalue=matrix2[i][j]->property("now_num");
            int data1=curvalue.toInt();
            QVariant storedvalue=matrix2[i][j]->property("storedvalue");
            int data2=storedvalue.toInt();
            if(data1!=data2)
            {
                flag=false;
                break;
            }
        }
    }

    if(timer.isActive())
    {
        timer.stop();

    }

    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setWindowTitle("提示");
    messageBox.setWindowIcon(QIcon(":/images/resources/images/common.png"));
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(flag)//正确则创建用户字段写入文件
    {
        QString timetotal=QString::number(time_total/1000.0);
        messageBox.setInformativeText("你成功了！用时："+timetotal+".00s");
        bool ok;
        QString id = QInputDialog::getText(nullptr,
                                           "用户登录",
                                           "请输入用户ID：",
                                           QLineEdit::Normal,
                                           "",
                                           &ok);

        if(ok)
        {
            if(messageBox.exec()==QMessageBox::Ok)
            {
                emit this->back();


                QFile fileread("./rank/common.json");
                if (!fileread.open(QIODevice::ReadOnly)) {
                    qDebug() << "Failed to open file for read: 111" ;
                }

                QByteArray jsonData = fileread.readAll();
                fileread.close();

                QJsonDocument docread = QJsonDocument::fromJson(jsonData);

                userbase usernow(id,time_total/1000,1);

                //表示文件为空，未写过数据
                if (docread.isNull()) {
                    QJsonArray usersArray=QJsonArray();
                    usersArray.append(usernow.toJsonObject());
                    QJsonDocument docwrite(usersArray);

                    QFile filewrite("./rank/common.json");
                    if (!filewrite.open(QIODevice::WriteOnly|QIODevice::Truncate )) {
                        qDebug() << "Failed to open file for writing: 111" ;
                    }
                    filewrite.write(docwrite.toJson());
                    filewrite.close();
                }

                //文件不为空，写过数据
                else //if(!docread.isNull())
                {
                    //先判断是否有重名
                    users=userbase::loadUsersFromJson("./rank/common.json");
                    bool check=true;
                    for(userbase& user:users)
                    {
                        if(user.get_id()==id)
                        {
                            user.change_time(std::min(user.get_time(),usernow.get_time()));
                            user.add_pass_time();
                            check=false;
                            break;
                        }
                    }

                    //找到重名的，直接改变原数据后再写入
                    if(!check)
                    {
                        QJsonArray userarray=QJsonArray();
                        for(const userbase&user:users)
                        {
                            userarray.append(user.toJsonObject());
                        }
                        QJsonDocument doc(userarray);

                        QFile filewrite("./rank/common.json");
                        if (!filewrite.open(QIODevice::WriteOnly|QIODevice::Truncate )) {
                            qDebug() << "Failed to open file for writing:222";

                        }
                        filewrite.write(doc.toJson());
                        filewrite.close();

                    }

                    //未找到重名的，在原数据后面写入新数据
                    else //if(check)
                    {
                        QJsonArray userarray=docread.array();
                        userarray.append(usernow.toJsonObject());
                        QJsonDocument doc(userarray);

                        QFile filewrite("./rank/common.json");
                        if (!filewrite.open(QIODevice::WriteOnly|QIODevice::Truncate )) {
                            qDebug() << "Failed to open file for writing:333";

                        }
                        filewrite.write(doc.toJson());
                        filewrite.close();

                    }
                }
                time_total=0;

            }
        }

    }

    else if(!flag)
    {
        messageBox.setText("你失败了！");
        if(messageBox.exec()==QMessageBox::Ok)
        {
            emit this->back();

            time_total=0;

        }
    }

}

void level1::loadfile(const QString filePath)//打开地图文件初始化
{
    QFile file(filePath);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qCritical() << "Failed to open file: " << file.errorString();
        exit(1);
    }
    QTextStream in(&file);

    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)//读取字符并根据地图数字来给格子贴图
        {
            while(!in.atEnd())
            {
                in>>char_;
                if(char_.isDigit())break;
            }
            if(char_.isDigit())
            {

                int data=char_.digitValue();
                if(data==0)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree0.jpg"));
                else if(data==1||data==3)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree13.jpg"));
                else if(data==2)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree2.jpg"));
                else if(data==4)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree4.jpg"));
                matrix1[i][j]->setScaledContents(true);

                int now=0;
                matrix2[i][j]->setProperty("now_num",QVariant(now));
                matrix2[i][j]->setProperty("storedvalue",QVariant(data));
                QVariant stored=matrix2[i][j]->property("now_num");
                matrix2[i][j]->setText(stored.toString());
            }
        }
    }
    file.close();

    choices[0]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue0=choices[0]->property("rest_num");
    choices[0]->setText(storedvalue0.toString());

    choices[1]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue1=choices[1]->property("rest_num");
    choices[1]->setText(storedvalue1.toString());

    choices[2]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue2=choices[2]->property("rest_num");
    choices[2]->setText(storedvalue2.toString());

    choices[3]->setProperty("rest_num",QVariant(1));
    QVariant storedvalue3=choices[3]->property("rest_num");
    choices[3]->setText(storedvalue3.toString());

    if(!timer.isActive())
    {
        label_time->setText("0.00s");
        timer.start(1000);
    }
}

void level1::show_time()
{
    time_total+=timer.interval();//获取当前时间
    label_time->setText(QString::number(time_total/1000.0,'f',2)+'s');//设置为xx.00s的样式
}

void level1::choose_reset()
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            matrix2[i][j]->setProperty("now_num",QVariant(0));
            QVariant nownum=matrix2[i][j]->property("now_num");
            matrix2[i][j]->setText(nownum.toString());
        }
    }

    cancelboxer.clear();

    choices[0]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue0=choices[0]->property("rest_num");
    choices[0]->setText(storedvalue0.toString());

    choices[1]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue1=choices[1]->property("rest_num");
    choices[1]->setText(storedvalue1.toString());

    choices[2]->setProperty("rest_num",QVariant(2));
    QVariant storedvalue2=choices[2]->property("rest_num");
    choices[2]->setText(storedvalue2.toString());

    choices[3]->setProperty("rest_num",QVariant(1));
    QVariant storedvalue3=choices[3]->property("rest_num");
    choices[3]->setText(storedvalue3.toString());
}
