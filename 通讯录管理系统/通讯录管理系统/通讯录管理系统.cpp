#include<iostream>
#include <string>
#define Max 1000
using namespace std;

struct Person 
{
	string m_Name; //����
	int m_Sex; //�Ա�1�� 2Ů
	int m_Age; //����
	string m_Phone; //�绰
	string m_Addr; //סַ
};



struct Addressbooks 
{
	struct Person personArray[Max];
	int m_Size;
};


void Addperson(Addressbooks* abs)
{
	if (abs->m_Size == 1000)
	{
		cout<<"���Ѿ�����"<<endl;
		return ;
	}
	else
	{
		string Name;
		cout<<"����������"<<endl;
		cin>>Name;
		abs->personArray[abs->m_Size].m_Name = Name;

		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;

		int sex = 0;
		while (true)
		{
			cin>>sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			else
			{
				cout<<"��������"<<endl;
			}
		}

		//����
		cout << "���������䣺" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		//��ϵ�绰
		cout << "��������ϵ�绰��" << endl;
		string phone;
		cin>>phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		//��ͥסַ
		cout << "�������ͥסַ��" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		//����ͨѶ¼����
		abs->m_Size++;

		cout << "��ӳɹ�" << endl;
		system("pause");
		system("cls");
	}
}


void ShowPerson(Addressbooks* abs)
{
	if (abs->m_Size==0)
	{
		cout<<"no body"<<endl;
	}
	else
	{
		for (int i = 0;i<abs->m_Size;i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << (abs->personArray[i].m_Sex ==1 ? "��":"Ů") << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

int CheckPerson(Addressbooks* abs,string Name)
{
	
	for (int i=0;i<abs->m_Size;i++)
	{
		if (abs->personArray[i].m_Name == Name)
		{
			return i;
		}
	}

	return -1;
}

void  DeletePerson(Addressbooks* abs)
{
	string Name;
	cout << "������ɾ��������" << endl;
	cin >> Name;
	int index = CheckPerson(abs, Name);
	if (index != -1)
	{
		for (int i = index;i<abs->m_Size;i++)
		{
			abs->personArray[i] = abs->personArray[i+1];
		}
		abs->m_Size--;
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout<<"���޴���"<<endl;
	}
	system("pause");
	system("cls");

}
void CheckAndShowPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int Index = CheckPerson(abs,name);
	if (Index != -1)
	{
		cout << "������" << abs->personArray[Index].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[Index].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[Index].m_Age << "\t";
		cout << "�绰��" << abs->personArray[Index].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[Index].m_Addr << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");

}
void ChangePerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��" << endl;
	string name;
	cin >> name;
	int Index = CheckPerson(abs, name);
	if (Index != -1)
	{
		while (true)
		{
			int select = 0;
			cout << "*****  1���޸�����  *****" << endl;
			cout << "*****  2���޸��Ա� *****" << endl;
			cout << "*****  3���޸�����  *****" << endl;
			cout << "*****  4���޸ĵ绰  *****" << endl;
			cout << "*****  5���޸ĵ�ַ  *****" << endl;
			cout << "*****  0���޸����  *****" << endl;
			cin >> select;
			string change_name;
			int sex;
			int age;
			string phone;
			string addr;
			switch (select)
			{
			case 1:
				cout << "����������" << endl;
				cin >> change_name;
				abs->personArray[Index].m_Name = change_name;
				break;
			case 2:
				cout << "�������Ա�" << endl;
				cin >> sex;
				abs->personArray[Index].m_Sex = sex;
				break;
			case 3:
				cout << "����������" << endl;
				cin >> age;
				abs->personArray[Index].m_Age = age;
				break;
			case 4:
				cout << "������绰" << endl;
				cin >> phone;
				abs->personArray[Index].m_Phone = phone;
				break;
			case 5:
				cout << "�������ַ" << endl;
				cin >> addr;
				abs->personArray[Index].m_Addr = addr;
				break;
			case 0:
				cout << "�޸����" << endl;
				system("pause");
				system("cls");
				return;
				break;
			default:
				break;
			}
		}
	}
	else
	{
		cout << "���޴���" << endl;
	}

	system("pause");
	system("cls");


}
void CleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼�����" << endl;
	system("pause");
	system("cls");
}
void ShowMenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}

int main()
{	
	//����ͨѶ¼
	Addressbooks abs;
	//��ʼ��ͨѶ¼������
	abs.m_Size = 0;

	int select = 0;
	
	while (true)
	{
		ShowMenu();
		cin>>select;

		switch (select)
		{
		case 1:  //�����ϵ��
			Addperson(&abs);
			break;
		case 2:  //��ʾ��ϵ��
			ShowPerson(&abs);
			break;
		case 3:  //ɾ����ϵ��
			DeletePerson(&abs);
			break;
		case 4:  //������ϵ��
			CheckAndShowPerson(&abs);
			break;
		case 5:  //�޸���ϵ��
			ChangePerson(&abs);
			break;
		case 6:  //�����ϵ��
			break;
		case 0:  //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}


	}
	system("pause");
	return 0;

}