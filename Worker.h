#pragma once
#include<iostream>
#include<string>
using namespace std;

//员工类
class Worker
{
public:

	//显示员工信息
	virtual void ShowInfo() = 0;

	//员工岗位
	virtual string GetDepartmentName() = 0;

	int m_ID;//员工编号
	string m_Name;//员工姓名
	int m_DepitId;//部门编号
};
