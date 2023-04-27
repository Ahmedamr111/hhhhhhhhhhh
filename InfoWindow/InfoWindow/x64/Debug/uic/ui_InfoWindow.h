/********************************************************************************
** Form generated from reading UI file 'InfoWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INFOWINDOW_H
#define UI_INFOWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InfoWindowClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *InfoWindowClass)
    {
        if (InfoWindowClass->objectName().isEmpty())
            InfoWindowClass->setObjectName(QString::fromUtf8("InfoWindowClass"));
        InfoWindowClass->resize(600, 400);
        menuBar = new QMenuBar(InfoWindowClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        InfoWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(InfoWindowClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        InfoWindowClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(InfoWindowClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        InfoWindowClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(InfoWindowClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        InfoWindowClass->setStatusBar(statusBar);

        retranslateUi(InfoWindowClass);

        QMetaObject::connectSlotsByName(InfoWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *InfoWindowClass)
    {
        InfoWindowClass->setWindowTitle(QCoreApplication::translate("InfoWindowClass", "InfoWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InfoWindowClass: public Ui_InfoWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INFOWINDOW_H
