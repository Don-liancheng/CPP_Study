#pragma once

#include <QWidget>
#include "ui_smallWidget.h"
#include <QSpinBox>
#include <QSlider>
class smallWidget : public QWidget
{
	Q_OBJECT

public:
	smallWidget(QWidget *parent = nullptr);
	~smallWidget();
	//����ֵ
	void setNumber(int value);
	//�õ�ֵ
	int getNumber();
	
private:
	Ui::smallWidgetClass ui;
};
