#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include "MyPushButton.h"
class chooselevelsene  : public QMainWindow
{
	Q_OBJECT

public:
	chooselevelsene(QWidget *parent);
	~chooselevelsene();

	//��д��ͼ�¼���������ͼ
	void paintEvent(QPaintEvent*);
};
