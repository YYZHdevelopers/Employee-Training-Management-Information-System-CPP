#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Manager :public Worker
{
public:
	//���캯��
	Manager(int id, string name, int Did);

	//��ʾ��Ϣ
	virtual void ShowInfo();

	//��λ����
	virtual string GetDepartmentName();
};
