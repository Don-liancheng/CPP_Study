#include "employee.h"
#include <string>



Employee::Employee(int id, string name, int did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DeptID = did;
}

void Employee::ShowInfo()
{	
	cout << "ְ����ţ� " << this->m_ID
		<< " \tְ�������� " << this->m_Name
		<< " \t��λ��" << this->GetDeptName()
		<< " \t��λְ����ɾ�����������" << endl;
	
}

string Employee::GetDeptName()
{
	return string("Ա��");
}
