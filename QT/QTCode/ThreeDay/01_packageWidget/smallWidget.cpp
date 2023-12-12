#include "smallWidget.h"

smallWidget::smallWidget(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	//QspinxBox�ƶ���QSlider�����ƶ� ���ֲᣬû�оͲ鸸��
	connect(ui.spinBox,&QSpinBox::valueChanged,ui.horizontalSlider,&QSlider::setValue);
	//QSilder�ƶ���QspinxBox�����ƶ�
	connect(ui.horizontalSlider, &QSlider::sliderMoved,ui.spinBox, &QSpinBox::setValue);
}

smallWidget::~smallWidget()
{}

void smallWidget::setNumber(int value)
{
	//����ֵ
	ui.spinBox->setValue(value);
}

int smallWidget::getNumber()
{
	//����ֵ
	return ui.spinBox->value();
}
