#pragma once
#include<iostream>
#include"Worker.h"
#include<string>
using namespace std;

class Employee :public Worker
{
public:
	//���캯��
	Employee(int id ,string name,int Did);

	//��ʾ��Ϣ
	virtual void ShowInfo();

	//��λ����
	virtual string GetDepartmentName();
};
