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
	////���԰���
	//Worker* work = NULL;
	//work = new Employee(1,"����",1);
	//work->ShowInfo();
	//delete work;

	//work = new Manager(2,"����",1);
	//work->ShowInfo();
	//delete work;

	//work = new Boss(3, "����", 1);
	//work->ShowInfo();
	//delete work;

}

int main()
{
	
	//ʵ����һ�������߶���
	WorkManager wm;

	int choice = 0;//����û��Ĳ���ѡ��

	while (1)
	{
		//���ò˵���ʾ����
		wm.Show_Menu();
		
		cout << "����������ѡ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0://�˳�
			wm.ExitSystem();
			break;
		case 1://����ְ����Ϣ
			wm.Add_Emp();
			break;
		case 2://��ʾְ����Ϣ
			wm.Show_Emp();
			break;
		case 3://ɾ����ְְ��
			wm.Del_Emp();
			break;
		case 4://�޸�ְ����Ϣ
			wm.Mod_Emp();
			break;
		case 5://����ְ����Ϣ
			wm.Find_Emp();
			break;
		case 6://���������
			wm.Sort_Emp();
			break;
		case 7://��������ĵ�
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