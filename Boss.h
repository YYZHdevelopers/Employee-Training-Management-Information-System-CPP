#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Boss:public Worker
{
public:

	//���캯��
	Boss(int id,string name,int Did);

	//��ʾ��Ϣ
	virtual void ShowInfo();

	//��λ��Ϣ
	virtual string GetDepartmentName();

};