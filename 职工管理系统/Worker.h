#pragma once
#include<iostream>
#include<string>
using namespace std;

//Ա����
class Worker
{
public:

	//��ʾԱ����Ϣ
	virtual void ShowInfo() = 0;

	//Ա����λ
	virtual string GetDepartmentName() = 0;

	int m_ID;//Ա�����
	string m_Name;//Ա������
	int m_DepitId;//���ű��
};
