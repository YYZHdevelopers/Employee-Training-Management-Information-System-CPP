#include<iostream>
#include<process.h>
#include"workManager.h"
#include"Worker.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
using namespace std;

void test01()
{
	////测试案例
	//Worker* work = NULL;
	//work = new Employee(1,"张三",1);
	//work->ShowInfo();
	//delete work;

	//work = new Manager(2,"李四",1);
	//work->ShowInfo();
	//delete work;

	//work = new Boss(3, "王五", 1);
	//work->ShowInfo();
	//delete work;

}

int main()
{
	
	//实例化一个管理者对象
	WorkManager wm;

	int choice = 0;//存放用户的操作选择

	while (1)
	{
		//调用菜单显示函数
		wm.Show_Menu();
		
		cout << "请输入您的选择：" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://退出
			wm.ExitSystem();
			break;
		case 1://增加职工信息
			wm.Add_Emp();
			break;
		case 2://显示职工信息
			wm.Show_Emp();
			break;
		case 3://删除离职职工
			wm.Del_Emp();
			break;
		case 4://修改职工信息
			wm.Mod_Emp();
			break;
		case 5://查找职工信息
			wm.Find_Emp();
			break;
		case 6://按编号排序
			wm.Sort_Emp();
			break;
		case 7://清空所有文档
			wm.Clean_File();
			break;


		default:
			system("cls");

			break;
		}
	}
	

	system("pause");
	return 0;
}