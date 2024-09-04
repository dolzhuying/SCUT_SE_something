#ifndef CONTEST_H
#define CONTEST_H

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
#include<QRandomGenerator>
#include <QDir>
#include <QStringList>
#include<QFileInfoList>
#include"userbase.h"
#include"usertool.h"

class rangedot
{
public:
    int sx,sy,fx,fy;
    rangedot(int a,int b,int c,int d):sx(a),sy(b),fx(c),fy(d){}
};


class contest : public QWidget
{
    Q_OBJECT
public:
    explicit contest(QWidget *parent = nullptr);

    void mousePressEvent(QMouseEvent*event);
    bool check_fit_map();

    void adddot(int sx,int sy,int width,int height);
    void find_legal_range(int width,int height);
    void add_legal_range(int sx,int sy,int fx,int fy,int width,int height);
    bool check_if_more_3(int sx,int sy,int fx,int fy);
    bool check_if_3(int sx,int sy,int width,int height);

    void reset_time();
    void initmap();

    void writefile();




private slots:
    void return_to_main();

    void choose_1();
    void choose_2();
    void choose_3();
    void choose_4();
    void choose_cancel();
    void choose_submit();
    void choose_reset();
    void show_time();
    void choose_tips();

    void generatingmap();

signals:
    void back();
private:
    QPushButton*buttonback=NULL;

    QVector<QVector<QLabel*>>matrix1;
    QVector<QVector<QLabel*>>matrix2;
    QVector<userbase>users;

    QVector<QLabel*>choices;

    QLabel*selectedlabel=NULL;
    int selectedlabel_x=0,selectedlabel_y=0;

    QTimer timer;
    QLabel*label_time=NULL;
    int time_total=0;

    int size=6;

    QVBoxLayout*vlayout1=NULL;
    QVBoxLayout*vlayout2=NULL;
    QGridLayout*glayout=NULL;
    QHBoxLayout*hlayout1=NULL;
    QHBoxLayout*hlayout2=NULL;
    QHBoxLayout*hlayout3=NULL;
    QHBoxLayout*hlayout_total=NULL;

    QPushButton*button1=NULL;
    QPushButton*button2=NULL;
    QPushButton*button3=NULL;
    QPushButton*button4=NULL;
    QPushButton*button_cancel=NULL;
    QPushButton*button_submit=NULL;
    QPushButton*button_reset=NULL;
    QPushButton*button_tips=NULL;

    QStack<cancelbox>cancelboxer;

    QVector<QVector<int>>valuestorage;//存储生成的地图
    QVector<rangedot>dot_legel_range;//存储每种矩阵可放置的合法区间
    QVector<int>candimap={4,3,3,2,2,1,1};//矩阵边长大小
    bool have_four=false;//生成时是否已经出现4
    int sum=0;

    QVariant sx4,sy4;//已经出现4的左上角坐标

};

#endif // CONTEST_H
