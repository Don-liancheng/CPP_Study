#pragma once

#include <QObject>
#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>

class MyPushButton  : public QPushButton
{
	Q_OBJECT

public:
	MyPushButton(QWidget *parent);
	~MyPushButton();

	//���캯������1������ʾ��ͼƬ·���D����2���º���ʾ��ͼƬ·��
	MyPushButton(QString normaImg,QString pressImg = "");
	
	// ��Ա���Ա����û������Ĭ����ʾ·���Լ����º���ʾ��ͼƬ·��
	QString normaImgPath;
	QString pressImgPath; 

	//������Ч
	void zoom1(bool isup = false);


	//������갴�º��ͷŵ��¼�
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);

};
