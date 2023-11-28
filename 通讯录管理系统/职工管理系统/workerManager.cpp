#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//1���ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//2���ļ����ڵ�Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//3���ļ�������������
	int num = this->get_EmpNum();
	/*cout<<"ְ������Ϊ"<<num<<endl;*/
	this->m_EmpNum = num;

	//����ְ������������
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ʼ��ְ��
	this->init_Emp();

	////���Դ���
	//for (int i = 0;i<this->m_EmpNum;i++)
	//{
	//	cout << "ְ���ţ� " << this->m_EmpArray[i]->m_ID
	//		<< " ְ�������� " << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptID << endl;
	//}

}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete this->m_EmpArray;
	}
}

void WorkerManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitManager()
{
	cout << "�˳���ӭʹ��" << endl;
	system("pause");
	exit(0);
}

void WorkerManager::Add_Emp()
{
	cout << "����������ְ��������" << endl;
	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{	//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;

			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;

			}

			newSpace[this->m_EmpNum + i] = worker;
			//�ͷ�ԭ�пռ�
			delete[] this->m_EmpArray;
			this->m_EmpArray = newSpace;
			this->m_EmpNum = newSize;
			this->m_FileIsEmpty = false;
			//��ʾ��Ϣ
			cout << "�ɹ����" << addNum << "����ְ����" << endl;
			this->save();

		}

	}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_ID << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptID << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	int id;
	string name;
	int dId;
	int num = 0;
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//>> Ĭ�ϻᰴ�տո񡢻��з��ȿհ��ַ����зָ�
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, dId);
			break;
		case 2:
			worker = new Manager(id, name, dId);
			break;
		case 3:
			worker = new Boss(id, name, dId);
			break;
		default:
			break;
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����б�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->ShowInfo();
		}
		system("pause");
		system("cls");
	}
}

void WorkerManager::Del_Emp()
{
	int id;
	cout << "��������Ҫɾ����ְ��id" << endl;
	cin >> id;
	int index = this->IsExist(id);
	if (index == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		for (int i = index; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "ɾ���ɹ�" << endl;
	}
}

int WorkerManager::IsExist(int id)
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ����б�Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (id == this->m_EmpArray[i]->m_ID)
			{
				return i;
			}
		}
		return -1;
	}

}

void WorkerManager::Mod_Emp()
{
	int id;
	cout << "��������Ҫ�޸ĵ�ְ��id" << endl;
	cin >> id;
	int index = this->IsExist(id);
	if (index == -1)
	{
		cout << "���޴���" << endl;
	}
	else
	{
		delete this->m_EmpArray[index];
		int newId = 0;
		string newName = "";
		int dSelect = 0;
		cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
		cin >> newId;

		cout << "�������������� " << endl;
		cin >> newName;

		cout << "�������λ�� " << endl;
		cout << "1����ְͨ��" << endl;
		cout << "2������" << endl;
		cout << "3���ϰ�" << endl;
		cin >> dSelect;

		Worker* worker = NULL;
		switch (dSelect)
		{
		case 1 :
			worker = new Employee(newId,newName,dSelect);
		case 2:
			worker = new Manager(newId, newName, dSelect);
		case 3:
			worker = new Boss(newId, newName, dSelect);
		default:
			break;
		}
		this->m_EmpArray[index] = worker;
		cout<<"�޸ĳɹ�"<<endl;
		this->save();	
	}
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout<<"�ļ������ڻ��¼Ϊ��"<<endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select = 0;
		cin >> select;

		if (select == 1)
		{
			int id;
			cout << "��������ҵ�ְ�����" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�" << endl;
				this->m_EmpArray[index]->ShowInfo();
			}
			else
			{
				cout << "no that people" << endl;
			}
		}
		else if (select == 2)
		{
			cout << "please input people,s name" << endl;
			string name;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;
					cout << "���ҳɹ�,ְ�����Ϊ��"
						<< m_EmpArray[i]->m_ID
						<< " �ŵ���Ϣ���£�" << endl;
					this->m_EmpArray[i]->ShowInfo();
				}
			}
			if (flag == false)
			{
				//���޴���
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;
		int select = 0;
		cin >> select;

		for (int i = 0;i<this->m_EmpNum;i++)
		{
			int MinOrMax = i;
			for (int j = i+1;j<this->m_EmpNum;j++)
			{
				if (select ==1)
				{
					if (m_EmpArray[MinOrMax]->m_ID > m_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}
				else
				{
					if (m_EmpArray[MinOrMax]->m_ID < m_EmpArray[j]->m_ID)
					{
						MinOrMax = j;
					}
				}
			}
			if (i != MinOrMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[MinOrMax];
				m_EmpArray[MinOrMax] = temp;

			}
		}
		cout << "����ɹ�,�������Ϊ��" << endl;
		this->save();
		this->Show_Emp();
	}

}

void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{	
		//��ģʽ ios::trunc �������ɾ���ļ������´���
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0;i<this->m_EmpNum;i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FileIsEmpty  = true;
		}

	}
}


