#include "mainWidget.h"
#include <QTimer>
mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //������ʱ��
    id1 = startTimer(1000);//��λ���룬ÿ��һ����ú���

    id2 = startTimer(2000);//��λ���룬ÿ��2����ú���

	//��ʱ���ĵڶ��ַ�ʽ
	QTimer* timer = new QTimer(this);
	//������ʱ��
	timer->start(500);

	connect(timer,&QTimer::timeout,[=](){
		static int num2 = 1;
		ui.label3->setText(QString::number(num2++));
	});
	//�����ť��ͣ
	connect(ui.btn1,&QPushButton::clicked,[=](){
		timer->stop();
	});
}

mainWidget::~mainWidget()
{}

void mainWidget::timerEvent(QTimerEvent * event)
{

	if (event->timerId() == id1)
	{
		static int num = 1;
		ui.label2->setText(QString::number(num++));
	}
 //   //������һ��
	//if (event->timerId() == id2)
	//{
	//	static int num2 = 1;
	//	ui.label3->setText(QString::number(num2++));
	//}
    
}
