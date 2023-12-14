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

	//��label1��װ�¼�������
	//1����װ�¼�������
	ui.label1->installEventFilter(this);
	//2����д�¼�
}

//2����д�¼�,obj���ǿؼ�
bool mainWidget::eventFilter(QObject* watched, QEvent* event)
{
	if (watched == ui.label1)
	{
		if (event->type() == QEvent::MouseButtonPress)
		{
			//����ת����e��ev�ĸ���
			QMouseEvent* ev = static_cast<QMouseEvent*>(event);
			QString str = QString("�¼���������갴�� x =%1  y =%2 globalx=%3 ").arg(ev->pos().x()).arg(ev->pos().y()).arg(ev->globalPosition().toPoint().x());
			qDebug() << str;
		}
	}
	//Ĭ�Ͻ������ദ��
	return QWidget::eventFilter(watched,event);
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
