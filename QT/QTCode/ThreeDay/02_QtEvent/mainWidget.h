#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainWidget.h"
#include <QLabel>

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

    //��д��ʱ���¼�
    void timerEvent(QTimerEvent *event);
     
    int id1;//��ʱ����id
    int id2;//��ʱ����id

private:
    Ui::mainWidgetClass ui;
};
