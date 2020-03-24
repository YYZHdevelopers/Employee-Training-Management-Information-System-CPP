#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Boss:public Worker
{
public:

	//构造函数
	Boss(int id,string name,int Did);

	//显示信息
	virtual void ShowInfo();

	//岗位信息
	virtual string GetDepartmentName();

};