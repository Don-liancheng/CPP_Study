#include "manager.h"

Manager::Manager(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Manager::ShowInfo()
{
	cout << "ְ����ţ� " << this->m_ID
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->GetDeptName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << endl;
}

string Manager::GetDeptName()
{
	return string("����");
}
