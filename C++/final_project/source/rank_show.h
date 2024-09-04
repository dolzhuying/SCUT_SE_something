#ifndef RANK_SHOW_H
#define RANK_SHOW_H

#include<QObject>
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
#include<QTableView>
#include<QStandardItem>
#include<QStandardItemModel>
#include<QHeaderView>
#include"userbase.h"


class rank_show : public QWidget
{
    Q_OBJECT
public:
    explicit rank_show(QWidget *parent = nullptr);

    bool issersempty();
    void show_rank();

private:
    QPushButton*button_back=NULL;//返回
    QPushButton*button_common=NULL;//练习模式
    QPushButton*button_boss=NULL;//比赛模式
    QPushButton*button_id=NULL;//按id排序
    QPushButton*button_pass_time=NULL;//按通关次数排序
    QPushButton*button_timeuse=NULL;//按最短用时牌序

    QStandardItemModel*usermodel=NULL;//存放用户数据条目，由tableview管理
    QTableView*tableview=NULL;//排行榜显示设置

    QVBoxLayout*vlayout1=NULL;
    QHBoxLayout*hlayout1=NULL;
    QHBoxLayout*hlayout2=NULL;
    QHBoxLayout*hlayout3=NULL;

    QVector<userbase>users;//从排行榜文件读取用户数据并存储



signals:
    void back();

private slots:
    void returntomain();

    void choose_common();
    void choose_boss();
    void choose_id();
    void choose_pass_time();
    void choose_timeuse();
};

#endif // RANK_SHOW_H
