#pragma once
#include<iostream>
#include"Worker.h"
#include<string>
using namespace std;

class Employee :public Worker
{
public:
	//构造函数
	Employee(int id ,string name,int Did);

	//显示信息
	virtual void ShowInfo();

	//岗位名称
	virtual string GetDepartmentName();
};
