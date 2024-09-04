#ifndef LEVEL1_H
#define LEVEL1_H

#include<QObject>
#include<QByteArray>
#include <QWidget>
#include<QGridLayout>
#include<QLabel>
#include<qrandom.h>
#include<QVariant>
#include<QString>
#include<QVector>
#include<QLayout>
#include<QVariant>
#include<QPair>
#include<QVBoxLayout>
#include<QHBoxLayout>
#include<QMouseEvent>
#include<QDebug>
#include<QMessageBox>
#include<QPalette>
#include<QBrush>
#include<QPushButton>
#include<QFont>
#include<QImage>
#include<QTimer>
#include<QFile>
#include<QTextStream>
#include<QSpacerItem>
#include<QStack>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include"userbase.h"
#include"usertool.h"




class level1 : public QWidget
{
    Q_OBJECT
public:
    explicit level1(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent*event);
    void loadfile(const QString filePath);


    ~level1();

signals:
    void back();

private slots:
    void return_to_exermode();

    void choose_1();
    void choose_2();
    void choose_3();
    void choose_4();
    void choose_cancel();
    void choose_submit();
    void choose_reset();

    void show_time();

private:
    QPushButton*buttonback=NULL;//返回

    QVector<QVector<QLabel*>>matrix1;//存储格子的图片
    QVector<QVector<QLabel*>>matrix2;//存储格子的原本数据和用户放置数据
    QVector<userbase>users;//用户字段

    QVector<QLabel*>choices;//显示每种矩阵还剩多少

    QLabel*selectedlabel=NULL;//选中的起点
    int selectedlabel_x=0,selectedlabel_y=0;

    QChar char_;//读文件字符
    int size=6;

    QTimer timer;
    QLabel*label_time=NULL;
    int time_total=0;

    QVBoxLayout*vlayout1=NULL;
    QVBoxLayout*vlayout2=NULL;
    QGridLayout*glayout=NULL;
    QHBoxLayout*hlayout1=NULL;
    QHBoxLayout*hlayout2=NULL;
    QHBoxLayout*hlayout3=NULL;
    QHBoxLayout*hlayout_total=NULL;//总布局

    QPushButton*button1=NULL;//选1*1
    QPushButton*button2=NULL;
    QPushButton*button3=NULL;
    QPushButton*button4=NULL;
    QPushButton*button_cancel=NULL;//选撤回
    QPushButton*button_submit=NULL;//提交
    QPushButton*button_reset=NULL;//重置地图

    QStack<cancelbox>cancelboxer;//存储操作方便撤回

};

#endif // LEVEL1_H
