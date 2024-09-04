#ifndef USERBASE_H
#define USERBASE_H

#include <QObject>
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
#include<QGraphicsScene>
#include<QGraphicsTextItem>
#include<QGraphicsPixmapItem>
#include<QGraphicsView>
#include<QDebug>
#include<QMessageBox>
#include<QVariant>
#include<QSTack>
#include<QFile>
#include<QTextStream>
#include<QTimer>
#include<QInputDialog>
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>



class userbase
{
public:
    userbase(QString a,int b,int c):id(a),timeuse(b),pass_time(c){}

    QJsonObject toJsonObject()const;
    static userbase fromJsonObject(const QJsonObject &obj) ;
    int get_time()const;
    QString get_id()const;
    int get_pass_time()const;
    void change_time(int time);
    void add_pass_time();

    static QVector<userbase> loadUsersFromJson(const QString& filePath);

private:
    QString id;
    int timeuse;
    int pass_time;
};

#endif // USERBASE_H
