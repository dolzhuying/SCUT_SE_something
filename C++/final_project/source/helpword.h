#ifndef HELPWORD_H
#define HELPWORD_H

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

class helpword : public QWidget
{
    Q_OBJECT


public:
    explicit helpword(QWidget *parent = nullptr);
private:
    QVBoxLayout*vlayout=NULL;


};

#endif // HELPWORD_H
