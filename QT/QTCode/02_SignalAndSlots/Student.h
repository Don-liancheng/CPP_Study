#pragma once

#include <QObject>
#include <QDebug>

class Student  : public QObject
{
public:
	Student(QObject *parent);
	~Student();
public slots:
	//����ֵvoid ����Ҫ������Ҳ��Ҫʵ��
	//�����в��������Է�������
	void treat();
};
