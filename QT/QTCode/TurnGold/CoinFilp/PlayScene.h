#pragma once

#include <QMainWindow>
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QPainter>
#include <QPixmap>
#include "MyPushButton.h"
#include <QLabel>
#include "MyCoin.h"
class PlayScene  : public QMainWindow
{
	Q_OBJECT

public:
	/*PlayScene(QObject *parent);*/
	~PlayScene();

	//��д����
	PlayScene(int level);

	int levelindex ;
	//��д��ͼ�¼���ӱ���
	void paintEvent(QPaintEvent *event);

signals:
	//дһ���Զ����źţ�����ѡ�񳡾�������˷���
	void levelSceneBack();
};
