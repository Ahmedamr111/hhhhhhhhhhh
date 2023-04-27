#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_InfoWindow.h"

class InfoWindow : public QMainWindow
{
    Q_OBJECT

public:
    InfoWindow(QWidget *parent = nullptr);
    ~InfoWindow();

private:
    Ui::InfoWindowClass ui;
};
