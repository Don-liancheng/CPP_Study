#include <iostream>
using namespace std;
#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

//void test() 
//{
//	Worker* worker = NULL;
//	worker = new Eployee(1,"����",1);
//	worker->ShowInfo();
//	delete worker;
//
//	worker = new Manager(2, "����", 2);
//	worker->ShowInfo();
//	delete worker;
//
//	worker = new Boss(3, "����", 3);
//	worker->ShowInfo();
//	delete worker;
//}


int main()
{
	WorkerManager mm;
	

	int choice = 0;
	while (true)
	{
		mm.showMenu();
		cout<<"������ѡ��"<<endl;
		cin>>choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			mm.exitManager();
			break;
		case 1: //���ְ��
			mm.Add_Emp();
			break;
		case 2: //��ʾְ��
			mm.Show_Emp();
			break;
		case 3: //ɾ��ְ��
			mm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			mm.Mod_Emp();
			break;
		case 5: //����ְ��
			mm.Find_Emp();
			break;
		case 6: //����ְ��
			mm.Sort_Emp();
			break;
		case 7: //����ļ�
		mm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}


	system("pause");
	return 0;
}