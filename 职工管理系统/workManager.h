#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class WorkManager
{
public:

	//构造函数
	WorkManager();

	//菜单展示
	void Show_Menu();

	//退出功能
	void ExitSystem();

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存文件
	void Save();

	//记录职工人数
	int m_EmpNum;

	//判断文件是否为空
	bool m_FileIsEmpty;

	//职工人数的记录
	int get_EmpNum();

	//初始化员工
	void init_Emp();

	//显示职工
	void Show_Emp();

	//删除职工
	void Del_Emp();

	//判断职工是否存在 如果存在返回职工所在数组的位置，不存在返回-1
	int IsExit(int id);

	//判断职工编号是否重复
	int IsSample(int id);

	//修改职工信息
	void Mod_Emp();

	//查找员工
	void Find_Emp();

	//排序函数
	void Sort_Emp();

	//清空文档
	void Clean_File();

	//析构函数
	~WorkManager();
};
