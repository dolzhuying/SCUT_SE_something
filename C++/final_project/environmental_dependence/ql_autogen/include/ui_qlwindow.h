/********************************************************************************
** Form generated from reading UI file 'qlwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLWINDOW_H
#define UI_QLWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qlwindow
{
public:

    void setupUi(QWidget *qlwindow)
    {
        if (qlwindow->objectName().isEmpty())
            qlwindow->setObjectName("qlwindow");
        qlwindow->resize(800, 600);

        retranslateUi(qlwindow);

        QMetaObject::connectSlotsByName(qlwindow);
    } // setupUi

    void retranslateUi(QWidget *qlwindow)
    {
        qlwindow->setWindowTitle(QCoreApplication::translate("qlwindow", "qlwindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qlwindow: public Ui_qlwindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLWINDOW_H
