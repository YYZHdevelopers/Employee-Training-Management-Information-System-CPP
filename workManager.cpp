#include"workManager.h"
#include"employee.h"
#include"Manager.h"
#include"Boss.h"
#include"Worker.h"
#include<fstream>
#include<algorithm>
#define FILENAME "1.txt"


WorkManager::WorkManager()
{
	//文件不存在
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//读文件

	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		//初始化属性
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2、文件存在但数据为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//文件为空
		//cout << "文件为空" << endl;
		//初始化记录人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		//初始化文件是否为空
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3、文件存在且有数据
	int num = this->get_EmpNum();
//	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;

	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];

		//将文件中的数据存入到数组中
		this->init_Emp();

	/*	for (int i = 0;i < this->m_EmpNum;i++)
		{
			cout << "职工编号： " << this->m_EmpArray[i]->m_ID<<" "
				<< "姓名： " << this->m_EmpArray[i]->m_Name<<" "
				<< "部门编号： " << this->m_EmpArray[i]->m_DepitId << endl;
		}*/

		//初始化属性
	//this->m_EmpNum = 0;

	//this->m_EmpArray = NULL;
}

//菜单显示
void WorkManager::Show_Menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "------------欢迎使用职工管理系统------------" << endl;
	cout << "---------------0.退出管理系统---------------" << endl;
	cout << "---------------1.增加职工信息---------------" << endl;
	cout << "---------------2.显示职工信息---------------" << endl;
	cout << "---------------3.删除离职职工---------------" << endl;
	cout << "---------------4.修改职工信息---------------" << endl;
	cout << "---------------5.查找职工信息---------------" << endl;
	cout << "---------------6.按照编号排序---------------" << endl;
	cout << "---------------7.清空所有文档---------------" << endl;
	cout << "--------------------------------------------" << endl;
}

//退出
 void WorkManager::ExitSystem()
{
	 cout << "欢迎您下次使用" << endl;
	 system("pause");
	 exit(0);
}


 //添加职工
 void WorkManager::Add_Emp()
 {
	 while (1)
	 {
		 cout << "请输入添加职工数量" << endl;

		 int addNum = 0;//保存用户的输入数量
		 cin >> addNum;

		 if (addNum > 0)
		 {
			 //计算添加新空间的大小
			 int newSize = this->m_EmpNum + addNum;//新空间人数=原有的空间人数+新加的人数

			 //开辟新空间
			 Worker** newSpace = new Worker * [newSize];

			 //将原来空间下的数据拷贝到新的空间下
			 if (this->m_EmpArray != NULL)
			 {
				 for (int i = 0;i < this->m_EmpNum;i++)
				 {
					 newSpace[i] = this->m_EmpArray[i];
				 }
			 }
			 //批量添加新数据

			 for (int i = 0;i < addNum;i++)
			 {
				 int id;
				 string  name;
				 int dSelect;

				 while (1)
				 {
					 cout << "请输入第" << i + 1 << "个职工的编号" << endl;
					 cin >> id;
					 int ret = IsExit(id);
					 if (ret == -1)
					 {

						 break;
					 }
					 else
					 {
						 cout << "您输入的编号已存在，请重新输入！" << endl;
					 }
				 }
				 cout << "请输入第" << i + 1 << "个职工的姓名" << endl;
				 cin >> name;

				 cout << "请选择该职工的岗位：" << endl;
				 cout << "1、普通员工" << endl;
				 cout << "2、经理" << endl;
				 cout << "3、老板" << endl;
				 cin >> dSelect;

				 Worker* worker = NULL;
				 switch (dSelect)
				 {
				 case 1:
					 worker = new Employee(id, name, 1);
					 break;
				 case 2:
					 worker = new Manager(id, name, 2);
					 break;
				 case 3:
					 worker = new Boss(id, name, 3);
					 break;
				 default:
					 break;
				 }
				 //将创建职工指针保存到数组中
				 newSpace[this->m_EmpNum + i] = worker;

			 }
			 //删除原有数组空间
			 delete[] m_EmpArray;

			 //更改新空间的指向
			 this->m_EmpArray = newSpace;

			 //更新新的人数
			 this->m_EmpNum = newSize;

			 //更新职工不为空
			 this->m_FileIsEmpty = false;

			 //提示信息
			 cout << "成功添加" << addNum << "名新职工" << endl;

			 Save();
			 break;
		 }
		 else
		 {
			 cout << "输入有误" << endl;
			 break;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 void WorkManager::Save()
 {
	 ofstream ofs;
	 ofs.open(FILENAME,ios::out);
			
	 for (int i = 0;i < this->m_EmpNum;i++)
	 {
		 /*ofs << "员工编号：" << m_EmpArray[i]->m_ID
			 << "\t员工姓名：" << m_EmpArray[i]->m_Name
			 << "\t部门编号：" << m_EmpArray[i]->m_DepitId << endl;*/
		 ofs << this->m_EmpArray[i]->m_ID <<" "<< this->m_EmpArray[i]->m_Name << " "<<this->m_EmpArray[i]->m_DepitId << endl;
	 }
	 ofs.close();
 }

 int WorkManager::get_EmpNum()
 {
	 ifstream ifs;
	 ifs.open(FILENAME,ios::in);

	 int id;
	 string name;
	 int departid;

	 int num=0;//记录职工人数
	 while (ifs >> id && ifs >> name && ifs >> departid)
	 {
		 num++;
	 }

	 ifs.close();
	 return num;

 }

 //初始化员工
 void WorkManager::init_Emp()
 {
	 ifstream ifs;
	 ifs.open(FILENAME,ios::in);

	 int id;
	 string name;
	 int departid;

	 int index = 0;
	 while (ifs >> id && ifs >> name && ifs >> departid)
	 {
		 Worker* worker = NULL;
		 if (departid == 1)//普通员工
		 {
			 worker = new Employee(id, name, departid);
		 }
		 else if (departid == 2)//经理
		 {
			 worker = new Manager(id, name, departid);
		 }
		 else//老板
		 {
			 worker = new Boss(id, name, departid);
		 }
		 this->m_EmpArray[index] = worker;
		 index++;
	 }
	 ifs.close();
 }

 //显示职工
 void WorkManager::Show_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	 }
	 else
	 {
		 for (int i = 0;i < this->m_EmpNum;i++)
		 {
			 this->m_EmpArray[i]->ShowInfo();
		 }
	 }
	 system("pause");
	 system("cls");
}

 void WorkManager::Del_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空" << endl;
	}
	 else
	 {
		 cout << "请输入要删除职工的编号：" << endl;
		 int user_Enter = 0;//记录用户输入的编号
		 cin >> user_Enter;
		 int ret = IsExit(user_Enter);

		 if (ret != -1)
		 {
			 for (int i = ret;i < this->m_EmpNum-1;i++)
			 {
				 this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			 }

			 //更新数组中职工的个数
			 this->m_EmpNum--;

			 //同步保存到文件中
			 this->Save();

			 cout << "删除成功！" << endl;
		 }
		 else
		 {
			 cout << "未找到该职工的相关信息！" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 int WorkManager::IsExit(int id)
 {
	 int index = -1;
	 for (int i = 0;i < this->m_EmpNum;i++)
	 {
		 if (this->m_EmpArray[i]->m_ID == id)
		 {
			 //找到了
			 index = i;
			 break;
		 }

	 }
	 return index;
 }

 //修改职工信息
 void WorkManager::Mod_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空！" << endl;
	 }
	 else
	 {
		 cout << "请输入您要修改的职工的编号：" << endl;
		 int id = 0;
		 cin >> id;
		 int ret = this->IsExit(id);
		 
		 if (ret != -1)
		 {
			 //找到了

			 //删除原职工所在数组的为
			 delete this->m_EmpArray[ret];

			 int newId = 0;
			 string newName = " ";
			 int dSelect = 0;

			 cout << "已找到编号：" << id << " 的职工" << endl;
			
			 cout << "*******************************************" << endl;
			 cout << "请输入原编号："<<id<<" 职工的新编号："<< endl;
			 cin >> newId;

			 cout << "请输入原编号：" << id << " 职工的新姓名：" << endl;
			 cin >> newName;

			 cout << "请输入原编号：" << id << " 职工的新岗位：" << endl;
			 cout << "1、普通职工" << endl;
			 cout << "2、经理" << endl;
			 cout << "3、老板" << endl;
			 cin >> dSelect;


			 Worker *worker = NULL;
			 switch (dSelect)
			 {
			 case 1:
				 worker = new Employee(newId,newName,dSelect);
				 break;
			 case 2:
				 worker = new Manager(newId,newName,dSelect);
				 break;
			 case 3:
				 worker = new Boss(newId,newName,dSelect);
				 break;
			 default:
				 break;
			 }

			 //把职工指针保存到原数组位置中
			 this->m_EmpArray[ret] = worker;

			 cout << "修改成功！" << endl;
			 this->Save();
		 }
		 else
		 {
			 cout << "修改失败，查无此人！" << endl;
		 }
	 }
	 system("pause");
	 system("cls");
 }

 int WorkManager::IsSample(int id)
 {
	 int index = -1;
	 for (int i = 0;i < this->m_EmpNum;i++)
	 {
		 if (this->m_EmpArray[i]->m_ID == id)
		 {
			 index = 1;
			 break;
		 }
	 }
	 return index;
 }

 //查找职工
 void WorkManager::Find_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空！" << endl;
	 }
	 else
	 {
		 
		 int user_Select;
		 cout << "请选择查询方式:" << endl;
		 cout << "1、按照职工编号查询" << endl;
		 cout << "2、按照职工姓名查询" << endl;
		 while (1)
		 {
			 cin >> user_Select;

			 
			 if (user_Select == 1)
			 {
				 cout << "请输入要查询的职工编号：" << endl;
				 int user_id;
				 cin >> user_id;
				 int ret = IsExit(user_id);
				 if (ret != -1)
				 {
					 cout << "已查到职工编号为 " << this->m_EmpArray[ret]->m_ID << " 的职工信息，如下：" << endl;
					 this->m_EmpArray[ret]->ShowInfo();
				 }
				 else
				 {
					 cout << "查无此人" << endl;
				 }
				 break;
			 }
			 else if (user_Select == 2)
			 {
				 bool flag = false;
				 string user_name;
				 cout << "请输入要查询的职工姓名：" << endl;
				 cin >> user_name;
				 for (int i = 0;i < this->m_EmpNum;i++)
				 {
					 if (this->m_EmpArray[i]->m_Name == user_name)
					 {
						 cout << "已查到姓名为 " << this->m_EmpArray[i]->m_Name << " 职工的信息，如下：" << endl;
						 this->m_EmpArray[i]->ShowInfo();
						 flag = true;
					 }
				 }
				 if (flag == false)
				 {
					 cout << "查无此人！！" << endl;
				 }
				 break;
			 }
			 else
			 {
				 cout << "输入有误，请重新输入！" << endl;
			 }
		 }


	 }
	 system("pause");
	 system("cls");
 }

 //排序
 void WorkManager::Sort_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "文件不存在或记录为空！！" << endl;
		 system("pause");
		 system("cls");
	 }
	 else
	 {
		 cout << "请选择排序方式：" << endl;
		 cout << "1、按职工号进行升序" << endl;
		 cout << "2、按职工号进行降序" << endl;
		 int user_Select = 0;
		 cin >> user_Select;

		
		 for (int i = 0;i < m_EmpNum;i++)
		 {
			 int minOrMax = i;
			 for (int j = i + 1;j < m_EmpNum;j++)
			 {
				 if (user_Select == 1)//升序
				 {
					 if (m_EmpArray[minOrMax]->m_ID > m_EmpArray[j]->m_ID)
					 {
						 minOrMax = j;
					 }
				 }
				 else
				 {
					 if (m_EmpArray[minOrMax]->m_ID < m_EmpArray[j]->m_ID)
					 {
						 minOrMax = j;
					 }
				 }
			 }
			 if (i != minOrMax)
			 {
				 Worker* temp = m_EmpArray[i];
				 m_EmpArray[i] = m_EmpArray[minOrMax];
				 m_EmpArray[minOrMax] = temp;
			 }
		 }
		 cout << "排序成功！结果如下" << endl;
		 this->Save();
		 this->Show_Emp();
	 }
 }

 void WorkManager::Clean_File()
 {
	 cout << "确定要全部清空吗？" << endl;
	 cout << "1、确定" << endl;
	 cout << "2、取消" << endl;
	 int user_Select =0;
	 cin >> user_Select;
	 if (user_Select == 1)
	 {
		 ofstream ofs;
		 ofs.open(FILENAME,ios::trunc);
		 ofs.close();

		 if (this->m_EmpArray != NULL)
		 {
			 for (int i = 0;i < this->m_EmpNum;i++)
			 {
				 delete this->m_EmpArray[i];
				 this->m_EmpArray[i] = NULL;
			 }

			 //删除堆区数组指针
			 delete[] this->m_EmpArray;
			 this->m_EmpArray = NULL;
			 this->m_EmpNum = 0;
			 this->m_FileIsEmpty = true;
		 }
		 cout << "清空成功！！" << endl;
	 }
	 system("pause");
	 system("cls");
 }

WorkManager::~WorkManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0;i < this->m_EmpNum;i++)
		{
			if (this->m_EmpArray[i] != NULL)
			{
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		m_EmpArray = NULL;
	}
}