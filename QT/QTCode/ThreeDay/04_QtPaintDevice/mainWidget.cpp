#include "mainWidget.h"


mainWidget::mainWidget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    
    ////pixmap��ͼ�豸
    //QPixmap pix(300,300);

    ////��䱳����ɫ
    //pix.fill(Qt::white);

    ////��������
    //QPainter painter(&pix);
    //painter.setPen(QPen(Qt::green));
    //painter.drawEllipse(QPoint(150,150),100,100);

    ////����
    //pix.save("E:\\pix.png");

 //-----------------------------------------------------------

 //   //QImage��ͼ
 //   QImage img( 300, 300, QImage::Format_RGB32);
 //   img.fill(Qt::yellow);

	////��������
	//QPainter painter(&img);
	//painter.setPen(QPen(Qt::red));
	//painter.drawEllipse(QPoint(150,150),100,100);

	////����
	//img.save("E:\\img.png");


    //QPicter��ͼ�豸�����Լ�¼�����»�ͼָ��
    QPicture pic;
    QPainter painter;
    painter.begin(&pic); //��ʼ���ϻ�
	painter.setPen(QPen(Qt::cyan));
	painter.drawEllipse(QPoint(150, 150), 100, 100);
    painter.end();//��������

    //�����ڴ���
    pic.save("E:\\pic.zt");




}

mainWidget::~mainWidget()
{}

void mainWidget::paintEvent(QPaintEvent*)
{
    ////��ͼ����
    //QPainter painter(this);

    ////����QImage�޸�����
    //QImage img;
    //img.load(":Image/butterfly.png");

    ////�޸����ص�
    //for (int i = 50; i<100;i++)
    //{
    //    for (int j = 50; j<100;j++)
    //    {
    //        //�������ص��ֵ
    //        QRgb value = qRgb(255,0,0);
    //        img.setPixel(i,j,value);
    //    }
    //}
    //painter.drawImage(0,0,img);



    QPainter painter(this);
    //����QPictureָ��
    QPicture pic;
    pic.load("E:\\pic.zt");
    painter.drawPicture(0,0,pic);

}
