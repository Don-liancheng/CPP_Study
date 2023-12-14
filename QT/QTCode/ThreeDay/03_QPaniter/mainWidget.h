#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainWidget.h"
#include <QPaintEvent>
#include <QPainter>
#include <QPoint>

class mainWidget : public QWidget
{
    Q_OBJECT

public:
    mainWidget(QWidget *parent = nullptr);
    ~mainWidget();

    //��ͼ�¼�
    void paintEvent(QPaintEvent *);
private:
    Ui::mainWidgetClass ui;
};
