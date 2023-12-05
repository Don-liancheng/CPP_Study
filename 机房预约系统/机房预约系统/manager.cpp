#include "manager.h"
void printStudent(Student& s)
{
	cout << "ѧ�ţ� " << s.m_Id << " ������ " << s.m_Name << " ���룺" << s.m_Password << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_Password << endl;
}
void printCom(ComputeRoom& c)
{
	cout << "������ " << c.m_ComId << " ��������� " << c.m_MaxNum << endl;
}

class MYfindstu
{
public:

	int id;
	MYfindstu(int _id){id = _id;}
	bool operator()(Student& s) const
	{
		return s.m_Id == id;
	}
};
class MYfindtea
{
public:

	int id;
	MYfindtea(int _id) { id = _id; }
	bool operator()(Teacher& t) const
	{
		return t.m_EmpId == id;
	}
};
//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Password =pwd; 

	//��ʼ������
	initVector();

	//��ȡ������Ϣ
	ifstream ifs;
	ifs.open(COMPUTER_FILE,ios::in);

	ComputeRoom c;

	while (ifs >>c.m_ComId && ifs >>c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << vCom.size() << endl;

	ifs.close();

}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::addPerson()
{

	string filename;
	string tip;
	string Errotip;
	ofstream ofs;//�ļ���������

	int select = 0;
	while (select != 1 && select != 2)
	{
		cout << "����������˺ŵ�����" << endl;
		cout << "1�����ѧ��" << endl;
		cout << "2�������ʦ" << endl;
		
		cin >> select;
		switch (select)
		{
			case 1:
			{
				filename = STUDENT_FILE;
				tip = "������ѧ�ţ� ";
				Errotip = "ѧ���ظ�������������";
				break;
			}
			case 2:
			{
				filename = TEACHER_FILE;
				tip = "������ְ����ţ�";
				Errotip = "ְ�����ظ�������������";
				break;
			}
			default:
			{
				cout<< "������������������"<<endl;
				break;
			}
		}
	}
	//��׷�ӵķ�ʽд���ļ�
	ofs.open(filename,ios::out | ios::app);

	int id;
	string name;
	string pwd;

	cout<<tip<<endl;

	while (true)
	{
		cin>>id;
		bool is_repeat = this->checkRepeat(id, select);
		if (is_repeat)
		{
			cout<<Errotip<<endl;
		}
		else
		{
			break;
		}
	}
	

	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << endl;
	system("pause");
	system("cls");

	ofs.close();
	//���»�ȡ�ļ��е�����
	this->initVector();
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select;
	cin>>select;
	if (select ==1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(),vStu.end(),printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout<<"������Ϣ���£�"<<endl;
	for_each(vCom.begin(),vCom.end(), printCom);
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE,ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{	
	//��ȡѧ���ļ�
	ifstream ifs;
	ifs.open(STUDENT_FILE,ios::in);
	if (!ifs.is_open())
	{
		cout<<"ѧ���ļ�������"<<endl;
		return;
	}
	vStu.clear();
	vTea.clear();
	
	Student s;
	while (ifs>>s.m_Id && ifs>> s.m_Name && ifs>>s.m_Password)
	{
		vStu.push_back(s);
	}
	ifs.close();

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ�������" << endl;
		return;
	}

	Teacher t;

	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Password)
	{
		vTea.push_back(t);
	}
	ifs.close();
	
	

}

bool Manager::checkRepeat(int id, int type)
{
	//ѧ��
	if (type == 1)
	{
		vector<Student>::iterator pos = find_if(vStu.begin(),vStu.end(), MYfindstu(id));
		if (pos != vStu.end())
		{
			return true;
		}
	}
	else
	{
		vector<Teacher>::iterator pos = find_if(vTea.begin(), vTea.end(), MYfindtea(id));
		if (pos != vTea.end())
		{
			return true;
		}
	}
	
	return false;
}


