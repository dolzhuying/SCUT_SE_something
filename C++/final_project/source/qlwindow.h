#ifndef QLWINDOW_H
#define QLWINDOW_H

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
#include"exermode.h"
#include"helpword.h"
#include"rank_show.h"
#include"contest.h"
#include"client_widget.h"
#include"server_widget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class qlwindow;
}
QT_END_NAMESPACE

class exermode;
class helpword;
class rank_show;
class contest;
class client_widget;
class server_widget;


class qlwindow : public QWidget
{
    Q_OBJECT

public:
    qlwindow(QWidget *parent = nullptr);
    ~qlwindow();

    void generatingmap_forcontest();
    bool check_fit_mapforcontest();

private slots:
    void to_exermode();
    void fromexer_returntothis();

    void to_help();

    void to_rank();
    void fromrank_returntothis();

    void to_contest();
    void fromcontest_returntothis();

    void to_client();
    void to_server();

private:
    Ui::qlwindow *ui;
    QVBoxLayout*vlayout=NULL;
    QHBoxLayout*hlayout=NULL;
    QHBoxLayout*hlayout1=NULL;

    QPushButton*button1=NULL;
    QPushButton*button2=NULL;
    QPushButton*button3=NULL;
    QPushButton*button4=NULL;

    QPushButton*button_server=NULL;
    QPushButton*button_client=NULL;

    exermode*page1=NULL;
    helpword*page2=NULL;
    rank_show*page4=NULL;
    contest*page3=NULL;
    client_widget*page5=NULL;
    server_widget*page6=NULL;

    QVector<QVector<int>>mapforcontest;
};
#endif // QLWINDOW_H
