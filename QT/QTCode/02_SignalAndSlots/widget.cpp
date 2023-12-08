#include "widget.h"

widget::widget(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);

    //����һ����ʦ����,�ұߵ�this�����ø�����������
    this->te = new Teacher(this);

    //����һ��ѧ������
    this->st = new Student(this);

    ////����ӣ�Ҫ�������ڴ����ź�
    //connect(te,&Teacher::hungry,st,&Student::treat);

    //classisover();

    //���ӵ����������źźͲ�
    //����ָ��ָ������ַ
    void (Teacher:: *teacherSignal)(QString) = &Teacher::hungry;
    void (Student:: *studentSlot)(QString) = &Student::treat;

    connect(te, teacherSignal, st, studentSlot);
    classisover();
}

widget::~widget()
{
    
}

void widget::classisover()
{
    //�¿κ��������ú������ʦ���˵��ź�
    emit te->hungry("gongbaojiding");
    
}
