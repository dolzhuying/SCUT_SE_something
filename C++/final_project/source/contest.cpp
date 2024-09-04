#include "contest.h"

contest::contest(QWidget *parent)
    : QWidget{parent}
{
    setMaximumSize(863,600);
    setMinimumSize(863,600);
    setWindowIcon(QIcon(":/images/resources/images/boss1.png"));
    setWindowTitle(QString("比赛模式"));

    QImage background(":/images/resources/images/background6.jpg");
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
    hlayout3->setSpacing(40);
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

    button_tips=new QPushButton("提示",this);
    button_tips->setStyleSheet("border: 2px solid black; border-radius: 5px;background-color:white;");
    button_tips->setFont(QFont("黑体",12));
    button_tips->setFixedSize(50,20);
    hlayout3->addWidget(button_tips);

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

    connect(buttonback,&QPushButton::clicked,this,&contest::return_to_main);
    connect(button1,&QPushButton::clicked,this,&contest::choose_1);
    connect(button2,&QPushButton::clicked,this,&contest::choose_2);
    connect(button3,&QPushButton::clicked,this,&contest::choose_3);
    connect(button4,&QPushButton::clicked,this,&contest::choose_4);
    connect(button_cancel,&QPushButton::clicked,this,&contest::choose_cancel);
    connect(button_submit,&QPushButton::clicked,this,&contest::choose_submit);
    connect(button_reset,&QPushButton::clicked,this,&contest::choose_reset);
    connect(button_tips,&QPushButton::clicked,this,&contest::choose_tips);
    connect(&timer,&QTimer::timeout,this,&contest::show_time);


}

void contest::reset_time()
{
     if(!timer.isActive())
     {
        timer.start(1000);
        label_time->setText("0.00s");
     }
}

void contest::choose_tips()//提示4*4矩阵左上角坐标
{
    QMessageBox messageBox;
    messageBox.setIcon(QMessageBox::Information);
    messageBox.setWindowTitle("提示");
    messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
    messageBox.setText("4*4矩阵的左上角坐标是: ("+sx4.toString()+","+sy4.toString()+")");
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);

    messageBox.exec();
}

void contest::return_to_main()
{
    emit this->back();
    cancelboxer.clear();
    if(timer.isActive())
    {
        timer.stop();
        time_total=0;
        label_time->setText("0.00s");
    }

}

void contest::choose_1()
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
            messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
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
        messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void contest::choose_2()
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
            messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
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
        messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void contest::choose_3()
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
            messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
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
        messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void contest::choose_4()
{
    if(selectedlabel!=NULL)
    {
        QVariant value1=choices[3]->property("rest_num");
        int cur=value1.toInt();
        if(selectedlabel_x+3<size&&selectedlabel_y+3<size&&cur!=0)
        {
            for(int i=selectedlabel_x;i<=selectedlabel_x+3;i++)
            {
                for(int j=selectedlabel_y;j<=selectedlabel_y+3;j++)
                {
                    QVariant curvalue=matrix2[i][j]->property("now_num");
                    int data=curvalue.toInt();
                    data+=1;
                    matrix2[i][j]->setProperty("now_num",QVariant(data));
                    QVariant storedvalue=matrix2[i][j]->property("now_num");
                    matrix2[i][j]->setText(storedvalue.toString());
                }
            }
            cancelbox box(selectedlabel,selectedlabel_x,selectedlabel_y,4);
            cancelboxer.push((box));
            selectedlabel=NULL;

            QVariant value=choices[3]->property("rest_num");
            int now=value.toInt();
            now-=1;
            choices[3]->setProperty("rest_num",QVariant(now));
            choices[3]->setText(QString::number(now));
        }
        else
        {
            QMessageBox messageBox;
            messageBox.setIcon(QMessageBox::Information);
            messageBox.setWindowTitle("提示");
            messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
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
        messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
        messageBox.setText("未选定起点");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
}

void contest::choose_cancel()
{
    if(cancelboxer.empty())
    {
        QMessageBox messageBox;
        messageBox.setIcon(QMessageBox::Information);
        messageBox.setWindowTitle("提示");
        messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
        messageBox.setText("无效操作");
        messageBox.setStandardButtons(QMessageBox::Ok);
        messageBox.setDefaultButton(QMessageBox::Ok);

        messageBox.exec();
    }
    else
    {
        cancelbox box=cancelboxer.top();
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
        }
        QVariant value=choices[box.size-1]->property("rest_num");
        int now=value.toInt();
        now+=1;
        choices[box.size-1]->setProperty("rest_num",QVariant(now));
        choices[box.size-1]->setText(QString::number(now));
    }
}

void contest::mousePressEvent(QMouseEvent*event)
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

void contest::choose_submit()
{
    cancelboxer.clear();
    bool flag=true;
    for(int i=0;i<size;i++)
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
    messageBox.setWindowIcon(QIcon(":/images/resources/images/boss.png"));
    messageBox.setStandardButtons(QMessageBox::Ok);
    messageBox.setDefaultButton(QMessageBox::Ok);
    if(flag)
    {
        QString timetotal=QString::number(time_total/1000.0);
        messageBox.setInformativeText("你成功了！用时："+timetotal+".00s");
        bool ok;
        QString id = QInputDialog::getText(nullptr,           // 父窗口，可以传入实际的窗口指针
                                           "用户登录",     // 对话框标题
                                           "请输入用户ID：",      // 输入提示
                                           QLineEdit::Normal, // 输入模式（普通、密码等）
                                           "",                // 初始文本
                                           &ok);

        if(ok)
        {
            if(messageBox.exec()==QMessageBox::Ok)
            {
                emit this->back();


                QFile fileread("./rank/boss.json");
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

                    QFile filewrite("./rank/boss.json");
                    if (!filewrite.open(QIODevice::WriteOnly|QIODevice::Truncate )) {
                        qDebug() << "Failed to open file for writing: 111" ;
                    }
                    filewrite.write(docwrite.toJson());
                    filewrite.close();
                }

                //文件不为空，写过数据
                else //if(!docread.isNull())
                {
                    users=userbase::loadUsersFromJson("./rank/boss.json");
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

                        QFile filewrite("./rank/boss.json");
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

                        QFile filewrite("./rank/boss.json");
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

void contest::show_time()
{
    time_total+=timer.interval();
    label_time->setText(QString::number(time_total/1000.0,'f',2)+'s');
}

bool contest::check_fit_map()//地图合法条件：有且仅有一个四，所有数字不得大于四，地图数字和为44
{
    bool flag=true;int num_4=0;
    for(int i=0;i<size&&flag;i++)
    {
        for(int j=0;j<size;j++)
        {
            sum+=valuestorage[i][j];
            if(valuestorage[i][j]==4)num_4++;
            if(valuestorage[i][j]>4||num_4>1)
            {
                flag=false;
                break;
            }
        }
    }
    if(flag&&num_4==1&&sum==44)return true;
    else
    {
        sum=0;
        qDebug() << "fail to generate";
        return false;
    }
}

void contest::adddot(int sx,int sy,int width,int height)//区间加一
{
    for(int i=sx;i<sx+width;i++)
    {
        for(int j=sy;j<sy+height;j++)
        {
            valuestorage[i][j]++;
            if(valuestorage[i][j]==4)
                have_four=true;
        }
    }
    qDebug() << "add dot over";
}

bool contest::check_if_more_3(int sx,int sy,int width,int height)//没有四的时候区间内至多一个三
{
    int num_3=0;
    for(int i=sx;i<sx+width;i++)
    {
        for(int j=sy;j<sy+height;j++)
        {
            if(valuestorage[i][j]==3)num_3++;
        }
    }
    if(num_3>1)
    {
         qDebug() << "check1false";
        return true;
    }
    else
    {
         qDebug() << "check1ok";
        return false;
    }
}
bool contest::check_if_3(int sx,int sy,int width,int height)//有四的时候区间内不能有三
{
    bool flag=true;
    for(int i=sx;i<sx+width&&flag;i++)
    {
        for(int j=sy;j<sy+height;j++)
        {
            if(valuestorage[i][j]==3)
            {
                flag=false;
                break;
            }
        }
    }
    if(flag)
    {
         qDebug() << "check2ok";
        return true;
    }
    else
    {
         qDebug() << "check2false";
        return false;
    }
}

void contest::add_legal_range(int sx,int sy,int fx,int fy,int width,int height)//在一块区域内寻找对width*height的矩阵合适的所有区间
{
    if(sx+width-1>fx||sy+height-1>fy)//判断是否越界
    {
        qDebug() << "add range false";
        return;
    }
    for(int i=sx;i+width-1<=fx;i++)
    {
        for(int j=sy;j+height-1<=fy;j++)
        {
            if((!have_four)?(!check_if_more_3(i,j,width,height)):(!check_if_3(i,j,width,height)))//分情况进行区间检查
            {
                dot_legel_range.push_back(rangedot(i,j,i+width-1,j+height-1));
            }
        }
    }

}

void contest::find_legal_range(int width,int height)
{
    //没有四的时候对全局进行搜索
    if(!have_four)
    {
        add_legal_range(0,0,size-1,size-1,width,height);
        qDebug() << "find1ok";
    }
    else
    {
        //已经有4的时候，先找到4的坐标
        int x4,y4;bool is4=true;
        for(int i=0;i<size&&is4;i++)
        {
            for(int j=0;j<size;j++)
            {
                if(valuestorage[i][j]==4)
                {
                    x4=i;y4=j;
                    is4=false;
                    break;                }
            }
        }
        //搜索包围着4的“回”字的四条边
        add_legal_range(0,0,std::min(x4-1,0),size-1,width,height);
        add_legal_range(0,0,size-1,std::min(y4-1,0),width,height);
        add_legal_range(std::max(x4+1,size-1),0,size-1,size-1,width,height);
        add_legal_range(0,std::max(y4+1,size-1),size-1,size-1,width,height);
        qDebug() << "find2ok";

    }
}

void contest::generatingmap()
{

    srand(QTime(0,0,0).secsTo(QTime::currentTime()));//随机数种子
    valuestorage.resize(size,QVector<int>(size,0));//先初始化为0防止访问非法内存
    qDebug() << "resize over start generating";
    for(int k=0;k<1e4;k++)//足够多的循环次数保证找出解
    {
        for(int i=0;i<candimap.length();i++)//逐个取出矩阵，进行合法区间寻找和放置
        {

            int border=candimap[i];
            int border_width=std::min(border,size);
            int border_height=std::min(border,size);

            find_legal_range(border_width,border_height);
            if(dot_legel_range.length()==0)
            {
                break;
            }
            int selectmap_num=std::rand()%dot_legel_range.length();
            //从该矩阵的所有合法区间进行随机选取然后放置

            adddot(dot_legel_range[selectmap_num].sx,dot_legel_range[selectmap_num].sy,border_width,border_height);
            if(border_height==4&&border_width==4)//单独为4*4矩阵设置提示功能
            {
                sx4=dot_legel_range[selectmap_num].sx+1;
                sy4=dot_legel_range[selectmap_num].sy+1;
            }
            dot_legel_range.clear();
        }
        if(check_fit_map())//本次地图合法就结束循环
        {
            qDebug() << "OK";
            break;
        }
        else//本次地图不合法就重新生成
        {
            valuestorage.clear();
            valuestorage.resize(size,QVector<int>(size,0));
            have_four=false;
            qDebug() << "failed";
        }
    }

    for(int i=0;i<size;i++)//同练习模式，但是图标有变化
    {
        for(int j=0;j<size;j++)
        {
            if(valuestorage[i][j]==0||valuestorage[i][j]==2)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree2.jpg"));
            else if(valuestorage[i][j]==1||valuestorage[i][j]==3)matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree13.jpg"));
            else matrix1[i][j]->setPixmap(QPixmap(":/images/resources/images/tree4.jpg"));
            matrix1[i][j]->setScaledContents(true);

            int now=0;
            matrix2[i][j]->setProperty("now_num",QVariant(now));
            matrix2[i][j]->setProperty("storedvalue",QVariant(valuestorage[i][j]));
            QVariant stored=matrix2[i][j]->property("now_num");
            matrix2[i][j]->setText(stored.toString());
        }
    }

    if(!timer.isActive())
    {
        label_time->setText("0.00s");
        timer.start(1000);
    }
    else
    {
        label_time->setText("0.00s");
        time_total=0;
    }

    writefile();
}

void contest::choose_reset()
{
    generatingmap();

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

void contest::initmap()
{
    generatingmap();

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

void contest::writefile()//将随机地图写入文件
{
    QString folderPath = "./randommap";//打开文件夹
    QDir directory(folderPath);
    if (!directory.exists() ) {
        qDebug() << "Folder not found";
        return;
    }
    directory.setNameFilters(QStringList());//获取目录下所有文件
    QFileInfoList fileList = directory.entryInfoList();
    int filenum=fileList.count();
    //根据已有文件数量来微信文件命名
    QString fileName = "maze%1.txt";
    QString filename=fileName.arg(++filenum);
    QString filePath = folderPath + "/" + filename;//新文件路径

    QFile file(filePath);
    if (file.exists()) {
        file.remove();
    }
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "Failed to open the file for writing: " << file.errorString();
        return;
    }
    QTextStream out(&file);
    //逐个数据写入文件
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            out<<valuestorage[i][j];
            out<<' ';
        }
        out<<'\n';
    }
    file.flush();
    file.close();

}
