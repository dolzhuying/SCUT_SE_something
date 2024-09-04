#ifndef EXERMODE_H
#define EXERMODE_H

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
#include<QDir>
#include"level1.h"


class level1;


class exermode : public QWidget
{
    Q_OBJECT
public:
    explicit exermode(QWidget *parent = nullptr);

    void to_level1();
    void to_level2();
    void to_level3();
    void to_level4();
    void to_level5();
    void to_random();

    ~exermode();

private slots:
    void returntomain();
    void from_level1_to_this();


private:

    QHBoxLayout*hlayout=NULL;
    QVBoxLayout*vlayout1=NULL;
    QVBoxLayout*vlayout2=NULL;
    QPushButton*buttonback=NULL;

    QPushButton*round1=NULL;
    QPushButton*round2=NULL;
    QPushButton*round3=NULL;
    QPushButton*round4=NULL;
    QPushButton*round5=NULL;
    QPushButton*roundrandom=NULL;

    level1*page1=NULL;


signals:
    void back();
};

#endif // EXERMODE_H
