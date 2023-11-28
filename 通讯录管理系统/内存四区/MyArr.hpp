#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class MyArry
{

public:
	T* pAddress;

	int m_Capacity;

	int m_Size;

public:
	MyArry(int Capacity)
	{
		cout<<"construct"<<endl;
		this->m_Capacity = Capacity;
		this->m_Size = 0;
		this->pAddress = new T[this->m_Capacity];

	}
	MyArry(const MyArry& arr)
	{
		cout << "copy construct" << endl;
		this->m_Capacity = arr.m_Capacity;
		this->m_Size = arr.m_Size;
		//���TΪ���󣬶��һ�����ָ�룬������Ҫ���� = ����������Ϊ����ȺŲ��� ���� ���Ǹ�ֵ��
		// ��ͨ���Ϳ���ֱ��= ����ָ��������Ҫ���
		this->pAddress = new T[arr.m_Capacity];

		for (int i = 0;i<this->m_Size;i++)
		{
			this->pAddress[i] = arr.pAddress[i];
		}
	}

	MyArry& operator=(MyArry& p)
	{
		if (this->pAddress != NULL )
		{
			delete this->pAddress;
			this->pAddress = NULL;
			this->m_Capacity = 0;
			this->m_Size = 0;
		}
		this->m_Capacity = p.m_Capacity;
		this->m_Size = p.m_Size;
		this->pAddress = new T[p.m_Capacity];
		for (int i = 0;i<this->m_Size;i++)
		{
			this->pAddress[i] = p.pAddress[i];
		}
		return *this;
	}
	~MyArry()
	{
		cout << "����" << endl;
		if (this->pAddress != NULL )
		{
			delete[] this->pAddress;
			this->pAddress = NULL;
		}
	}
	void Push_Back(const T& val)
	{
		//�ж������Ƿ���װ��
		if (this->m_Capacity == this->m_Size)
		{
			cout << "װ����" << endl;
			return;
		}
		this->pAddress[this->m_Size] = val;//�������ĩβ����
		this->m_Size++;
	}
	void Pop_Back(const T& val)
	{
		if (this->m_Size == 0)
		{
			cout << "û��Ԫ��"<<endl;
				return;
		}
		for (int i =1;i<val;i++)
		{
			this->m_Size--;
		}
		
	}
	T& operator[](int index)
	{
		return this->pAddress[index];
	}
	int getCapacity()
	{
		return this->m_Capacity;
	}
	int getSize()
	{
		return this->m_Size;
	}
};
