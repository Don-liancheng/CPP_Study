#pragma once

#include <QObject>
#include <QPushButton>
class MyCoin  : public QPushButton
{
	Q_OBJECT

public:
	/*MyCoin(QWidget *parent);*/
	~MyCoin();
	//��ʾ���ǽ�һ�������
	MyCoin(QString btnImg);
};
