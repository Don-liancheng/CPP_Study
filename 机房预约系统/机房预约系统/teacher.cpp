#include "teacher.h"

#include"teacher.h"

//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι��� (ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Password = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0;i<of.m_Size;i++)
	{
		cout << i + 1 << "�� ";
		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" <<(of.m_orderData[i]["interval"] == "1" ? "����":"����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = "״̬��";
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout<<status<<endl;	
	}
	system("pause");
	system("cls");
}

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	vector<int> v;
	int index = 0;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (of.m_orderData[i]["status"] == "1")
		{
			v.push_back(i);
			cout << index + 1 << "�� ";
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
			cout << " ������" << of.m_orderData[i]["stuName"];
			cout << " ������" << of.m_orderData[i]["roomId"];
			cout << "״̬�������" << endl;
			index++;
		}
			
	}
	cout << "��������˵�ԤԼ��¼,0������" << endl;
	index = 0;
	int select;
	while (true)
	{
		cin>> index;
		if (index >=0 && index <= of.m_Size)
		{
			if (index == 0)
			{
				break;
			}
			cout << "��������˽��" << endl;
			cout << "1��ͨ��" << endl;
			cout << "2����ͨ��" << endl;
			cin >> select;
			if (select == 1)
			{
				of.m_orderData[v[index - 1]]["status"] = "2";
				cout << "�޸ĳɹ�" << endl;
				break;
			}
			else if (select == 2)
			{
				of.m_orderData[v[index - 1]]["status"] = "-1";
				cout << "�޸ĳɹ�" << endl;
				break;
			}
			
		}
		else
		{
			cout << "������������������" << endl;
		}
	}
	of.updateOrder();
	system("pause");
	system("cls");

}
