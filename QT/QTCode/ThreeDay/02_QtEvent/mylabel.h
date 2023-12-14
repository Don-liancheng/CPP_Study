#pragma once

#include <QObject>
#include <QEnterEvent>
#include <QEvent>
#include <QDebug>
#include <QLabel>
#include <QMouseEvent>

class mylabel  : public QLabel
{
	Q_OBJECT

public:
	mylabel(QWidget* parent);
	~mylabel();
	//������
	void enterEvent(QEnterEvent* event);
	//����뿪
	void leaveEvent(QEvent* event);
	//��갴��
	void mousePressEvent(QMouseEvent* ev);
	//����ͷ�
	void mouseReleaseEvent(QMouseEvent* ev);
	//����ƶ�
	void mouseMoveEvent(QMouseEvent* ev);

	//ͨ��Event�¼��ַ���������갴���¼�
	bool event(QEvent *e);
};
