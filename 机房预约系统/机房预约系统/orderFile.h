#pragma once
#include <iostream>
using namespace std;
#include <map>
#include <fstream>
#include "globaFile.h"

class OrderFile
{
public:
	//���캯��
	OrderFile();

	//����ԤԼ��¼
	void updateOrder();

	//��¼������int��������value�Ǽ�¼�ļ�ֵ��
	map<int,map<string, string>> m_orderData;

	//��¼����
	int m_Size;
};