#pragma once

#include <QObject>
#include <QPushButton>
#include <QTimer>

class MyCoin  : public QPushButton
{
	Q_OBJECT

public:
	/*MyCoin(QWidget *parent);*/
	~MyCoin();
	//��ʾ���ǽ�һ�������
	MyCoin(QString btnImg);

	int posX;//x����λ��
	int posY;//y����λ��
	bool flag;//������־


	//�ı��־�ķ���
	void changeFlag();
	QTimer *timer1;
	QTimer *timer2;

	int min =1;
	int max = 8;

	//ִ�ж����ı�׼
	bool isAnimation = false;

	//��д�����¼�
	void mousePressEvent(QMouseEvent *e);

	//ʤ�����ܵ��
	bool Canclick = true;
};
