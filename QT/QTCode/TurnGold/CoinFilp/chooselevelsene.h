#pragma once

#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QPainter>
#include "MyPushButton.h"
#include <QLabel>
#include "PlayScene.h"
#include <QTimer>

class chooselevelsene  : public QMainWindow
{
	Q_OBJECT

public:
	chooselevelsene(QWidget *parent);
	~chooselevelsene();

	//��д��ͼ�¼���������ͼ
	void paintEvent(QPaintEvent*);

	//������Ϸ����ָ��
	PlayScene* play = NULL;

signals:
	//дһ���Զ����źţ�����������������˷���
	void chooseSceneBack();

};
