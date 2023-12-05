#include <iostream>
#include <string>
using namespace std;
#include "Identity.h"
#include <fstream>
#include "globaFile.h"
#include "manager.h"
#include "student.h"
#include "teacher.h"



void managerMenu(Identity* &manager)
{
	 while (true)
	 {
		//���ù���Ա�Ӳ˵�
		manager->operMenu();

		//������ָ��ת��Ϊ����ָ�룬���������������ӿ�
		Manager* man = (Manager*)manager;

		int select = 0;
		cin>>select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	 }
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		//ѧ���˵�
		student->operMenu();

		//������ָ��ת��Ϊ����ָ�룬���������������ӿ�
		Student* stu = (Student*)student;

		int select = 0;

		cin >> select;

		if (select == 1) //����ԤԼ
		{
			stu->applyOrder();
		}
		else if (select == 2) //�鿴����ԤԼ
		{
			stu->showMyOrder();
		}
		else if (select == 3) //�鿴����ԤԼ
		{
			stu->showAllOrder();
		}
		else if (select == 4) //ȡ��ԤԼ
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}
void teacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		//�޸�Ϊ����ָ��
		Teacher* teac = (Teacher*)teacher;

		int select = 0;
		cin>>select;
		if (select == 1)
		{
			teac->showAllOrder();
		}
		else if (select == 2)
		{
			teac->validOrder();
		}
		else
		{
			delete teacher;
			cout<<"ע���ɹ�"<<endl;
			system("pause");
			system("cls");
			return;
		}

	}
	


}

void LoginIn(string FileName, int type)
{
	//����ָ�룬����ָ���������
	Identity* person = NULL;

	ifstream ifs;
	ifs.open(FileName,ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
		
	}
	int id = 0;
	string name;
	string password;

	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2) //��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}

	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> password;

	if (type == 1)
	{
		//ѧ����¼��֤
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs>>fName && ifs>>fPwd)
		{
			if (fID == id && fName == name && fPwd == password)
			{
				cout<<"ѧ����֤�ɹ�"<<endl;
				system("pause");
				system("cls");
				person = new Student(id,name,password);

				//����˵��ӽ���
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		int fID;
		string fName;
		string fPwd;

		while (ifs >> fID && ifs >> fName && ifs >> fPwd)
		{
			if (fID == id && fName == name && fPwd == password)
			{
				cout << "��ʦ��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, password);
				//�����Ӳ˵�
				teacherMenu(person);
				return ;
			}
		}
	}
	else if (type == 3)
	{
		//����Ա��¼��֤
		string fName;
		string fPwd;

		while ( ifs >> fName && ifs >> fPwd)
		{
			if ( fName == name && fPwd == password)
			{
				cout << "����Ա��֤�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, password);

				//����˵��ӽ���
				managerMenu(person);
				return;
			}
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
	return;
}


int main() {

	int select = 0;
	
	while (true)
	{
		cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
			<< endl;
		cout << endl << "�������������" << endl;
		cout << "\t\t -------------------------------\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          1.ѧ������           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          2.��    ʦ           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          3.�� �� Ա           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t|          0.��    ��           |\n";
		cout << "\t\t|                               |\n";
		cout << "\t\t -------------------------------\n";
		cout << "��������ѡ��: ";
		cin >> select;

		switch (select)
		{
		case 1://student
			LoginIn(STUDENT_FILE,1);
			break;
		case 2://teacher
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3://manager
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0://exit
			cout << "��ӭ��һ��ʹ��" << endl;
			system("pause");
			exit(0);
			return 0;
			break;
		default:
			cout << "��������������ѡ��" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");

	return 0;
}