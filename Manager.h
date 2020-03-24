#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Manager :public Worker
{
public:
	//构造函数
	Manager(int id, string name, int Did);

	//显示信息
	virtual void ShowInfo();

	//岗位名称
	virtual string GetDepartmentName();
};
