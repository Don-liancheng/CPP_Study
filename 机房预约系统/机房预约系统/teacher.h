#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include "globaFile.h"
#include "orderFile.h"
#include "teacher.h"
#include <vector>

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();
	
	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int m_EmpId; //��ʦ���
};