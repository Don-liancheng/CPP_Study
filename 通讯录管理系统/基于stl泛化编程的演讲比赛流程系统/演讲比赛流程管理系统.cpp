#include<iostream>
#include <string>
using namespace std;
#include "speechManager.h"
#include <ctime>
int main() {

	SpeechManager sm;
	
	//���������
	srand((unsigned int)time(NULL));
	int choice = 0;

	while (true)
	{	
		
		/*system("cls");*/
		sm.showMenu();
		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��
		
		switch (choice)
		{
		case 1:  //��ʼ����
			sm.startSpeech();
			break;
		case 2:  //�鿴��¼
			sm.showRecord();
			break;
		case 3:  //��ռ�¼
			sm.cleanRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls"); //����
			break;
		}
	}
	system("pause");

	return 0;
}