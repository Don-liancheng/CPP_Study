#pragma once

#include <QtWidgets/QWidget>
#include "ui_mainWidget.h"
#include <QPixmap>
#include <QPainter>
#include <QPen>
#include <QImage>
#include <QPicture>

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
