#pragma once
#include <QObject>
class Teacher  : public QObject
{
	Q_OBJECT
public:
	Teacher(QObject *parent);
	~Teacher();
//�Զ����ź�д��signals��
//����ֵ��void ��ֻ��Ҫ����������Ҫʵ��
//�����в�������������
signals:
	void hungry();
};
