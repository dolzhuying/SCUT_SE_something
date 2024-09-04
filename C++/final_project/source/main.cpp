#include "qlwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qlwindow w;
    w.setWindowTitle(QString("植此青绿"));
    w.show();
    return a.exec();
}
