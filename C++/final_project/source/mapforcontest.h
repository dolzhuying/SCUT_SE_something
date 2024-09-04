#ifndef MAPFORCONTEST_H
#define MAPFORCONTEST_H


#include<QObject>
#include <QWidget>
#include<QVector>
#include<QThread>
#include<QTime>
#include<QRandomGenerator>
#include<QCoreApplication>
class mapforcontest:public QObject
{
    Q_OBJECT;
public:
    mapforcontest();
    void generatingmap_forcontest();
    bool check_fit_map();
    void stop();
private:
    bool ifover=false;
    QVector<QVector<int>>valuestorage;
    int size=6;
signals:
    void finish_mapgenerating(const QVector<QVector<int>>&map);
    void stop_out1();
    void stop_out2();


};

#endif // MAPFORCONTEST_H
