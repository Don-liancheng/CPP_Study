#include "mainWidget.h"

mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //�����ȡֵ
    connect(ui.btn1,&QPushButton::clicked,[=](){
       qDebug()<< ui.widget->getNumber();
    });
    //�������ֵ
	connect(ui.btn2, &QPushButton::clicked, [=]() {
        ui.widget->setNumber(50);
		qDebug() << ui.widget->getNumber();
	});
}

mainWidget::~mainWidget()
{}
