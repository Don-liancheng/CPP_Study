#include "widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //����һ����ʦ����,�ұߵ�this�����ø�����������
    this->te = new Teacher(this);

    //����һ��ѧ������
    this->st = new Student(this);
    //����ӣ�Ҫ�������ڴ����ź�
    connect(te,&Teacher::hungry,st,&Student::treat);

    classisover();
}

widget::~widget()
{
    
}

void widget::classisover()
{
    //�¿κ��������ú������ʦ���˵��ź�
    emit te->hungry();
}
