#include "MyWidget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    system("chcp 65001");
	// aӦ�ó��������Qt�У�Ӧ�ó���������ҽ���һ��
    QApplication a(argc, argv);
	// ���ڶ���mywidget����D->Qwidget
    MyWidget w;
	//���ڶ���Ĭ�ϲ�����ʾ������Ҫ����show������ʾ����
    w.show();
    //��Ӧ�ó�����������Ϣѭ�����ô�������������
    return a.exec();
}
