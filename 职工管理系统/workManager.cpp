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
	//�ļ�������
	ifstream ifs;
	ifs.open(FILENAME,ios::in);//���ļ�

	if (!ifs.is_open())
	{
		//cout << "�ļ�������" << endl;
		//��ʼ������
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//2���ļ����ڵ�����Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//�ļ�Ϊ��
		//cout << "�ļ�Ϊ��" << endl;
		//��ʼ����¼����
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		//��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//3���ļ�������������
	int num = this->get_EmpNum();
//	cout << "ְ������Ϊ��" << num << endl;
	this->m_EmpNum = num;

	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];

		//���ļ��е����ݴ��뵽������
		this->init_Emp();

	/*	for (int i = 0;i < this->m_EmpNum;i++)
		{
			cout << "ְ����ţ� " << this->m_EmpArray[i]->m_ID<<" "
				<< "������ " << this->m_EmpArray[i]->m_Name<<" "
				<< "���ű�ţ� " << this->m_EmpArray[i]->m_DepitId << endl;
		}*/

		//��ʼ������
	//this->m_EmpNum = 0;

	//this->m_EmpArray = NULL;
}

//�˵���ʾ
void WorkManager::Show_Menu()
{
	cout << "--------------------------------------------" << endl;
	cout << "------------��ӭʹ��ְ������ϵͳ------------" << endl;
	cout << "---------------0.�˳�����ϵͳ---------------" << endl;
	cout << "---------------1.����ְ����Ϣ---------------" << endl;
	cout << "---------------2.��ʾְ����Ϣ---------------" << endl;
	cout << "---------------3.ɾ����ְְ��---------------" << endl;
	cout << "---------------4.�޸�ְ����Ϣ---------------" << endl;
	cout << "---------------5.����ְ����Ϣ---------------" << endl;
	cout << "---------------6.���ձ������---------------" << endl;
	cout << "---------------7.��������ĵ�---------------" << endl;
	cout << "--------------------------------------------" << endl;
}

//�˳�
 void WorkManager::ExitSystem()
{
	 cout << "��ӭ���´�ʹ��" << endl;
	 system("pause");
	 exit(0);
}


 //���ְ��
 void WorkManager::Add_Emp()
 {
	 while (1)
	 {
		 cout << "���������ְ������" << endl;

		 int addNum = 0;//�����û�����������
		 cin >> addNum;

		 if (addNum > 0)
		 {
			 //��������¿ռ�Ĵ�С
			 int newSize = this->m_EmpNum + addNum;//�¿ռ�����=ԭ�еĿռ�����+�¼ӵ�����

			 //�����¿ռ�
			 Worker** newSpace = new Worker * [newSize];

			 //��ԭ���ռ��µ����ݿ������µĿռ���
			 if (this->m_EmpArray != NULL)
			 {
				 for (int i = 0;i < this->m_EmpNum;i++)
				 {
					 newSpace[i] = this->m_EmpArray[i];
				 }
			 }
			 //�������������

			 for (int i = 0;i < addNum;i++)
			 {
				 int id;
				 string  name;
				 int dSelect;

				 while (1)
				 {
					 cout << "�������" << i + 1 << "��ְ���ı��" << endl;
					 cin >> id;
					 int ret = IsExit(id);
					 if (ret == -1)
					 {

						 break;
					 }
					 else
					 {
						 cout << "������ı���Ѵ��ڣ����������룡" << endl;
					 }
				 }
				 cout << "�������" << i + 1 << "��ְ��������" << endl;
				 cin >> name;

				 cout << "��ѡ���ְ���ĸ�λ��" << endl;
				 cout << "1����ͨԱ��" << endl;
				 cout << "2������" << endl;
				 cout << "3���ϰ�" << endl;
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
				 //������ְ��ָ�뱣�浽������
				 newSpace[this->m_EmpNum + i] = worker;

			 }
			 //ɾ��ԭ������ռ�
			 delete[] m_EmpArray;

			 //�����¿ռ��ָ��
			 this->m_EmpArray = newSpace;

			 //�����µ�����
			 this->m_EmpNum = newSize;

			 //����ְ����Ϊ��
			 this->m_FileIsEmpty = false;

			 //��ʾ��Ϣ
			 cout << "�ɹ����" << addNum << "����ְ��" << endl;

			 Save();
			 break;
		 }
		 else
		 {
			 cout << "��������" << endl;
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
		 /*ofs << "Ա����ţ�" << m_EmpArray[i]->m_ID
			 << "\tԱ��������" << m_EmpArray[i]->m_Name
			 << "\t���ű�ţ�" << m_EmpArray[i]->m_DepitId << endl;*/
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

	 int num=0;//��¼ְ������
	 while (ifs >> id && ifs >> name && ifs >> departid)
	 {
		 num++;
	 }

	 ifs.close();
	 return num;

 }

 //��ʼ��Ա��
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
		 if (departid == 1)//��ͨԱ��
		 {
			 worker = new Employee(id, name, departid);
		 }
		 else if (departid == 2)//����
		 {
			 worker = new Manager(id, name, departid);
		 }
		 else//�ϰ�
		 {
			 worker = new Boss(id, name, departid);
		 }
		 this->m_EmpArray[index] = worker;
		 index++;
	 }
	 ifs.close();
 }

 //��ʾְ��
 void WorkManager::Show_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
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
		 cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	 else
	 {
		 cout << "������Ҫɾ��ְ���ı�ţ�" << endl;
		 int user_Enter = 0;//��¼�û�����ı��
		 cin >> user_Enter;
		 int ret = IsExit(user_Enter);

		 if (ret != -1)
		 {
			 for (int i = ret;i < this->m_EmpNum-1;i++)
			 {
				 this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			 }

			 //����������ְ���ĸ���
			 this->m_EmpNum--;

			 //ͬ�����浽�ļ���
			 this->Save();

			 cout << "ɾ���ɹ���" << endl;
		 }
		 else
		 {
			 cout << "δ�ҵ���ְ���������Ϣ��" << endl;
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
			 //�ҵ���
			 index = i;
			 break;
		 }

	 }
	 return index;
 }

 //�޸�ְ����Ϣ
 void WorkManager::Mod_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	 }
	 else
	 {
		 cout << "��������Ҫ�޸ĵ�ְ���ı�ţ�" << endl;
		 int id = 0;
		 cin >> id;
		 int ret = this->IsExit(id);
		 
		 if (ret != -1)
		 {
			 //�ҵ���

			 //ɾ��ԭְ�����������Ϊ
			 delete this->m_EmpArray[ret];

			 int newId = 0;
			 string newName = " ";
			 int dSelect = 0;

			 cout << "���ҵ���ţ�" << id << " ��ְ��" << endl;
			
			 cout << "*******************************************" << endl;
			 cout << "������ԭ��ţ�"<<id<<" ְ�����±�ţ�"<< endl;
			 cin >> newId;

			 cout << "������ԭ��ţ�" << id << " ְ������������" << endl;
			 cin >> newName;

			 cout << "������ԭ��ţ�" << id << " ְ�����¸�λ��" << endl;
			 cout << "1����ְͨ��" << endl;
			 cout << "2������" << endl;
			 cout << "3���ϰ�" << endl;
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

			 //��ְ��ָ�뱣�浽ԭ����λ����
			 this->m_EmpArray[ret] = worker;

			 cout << "�޸ĳɹ���" << endl;
			 this->Save();
		 }
		 else
		 {
			 cout << "�޸�ʧ�ܣ����޴��ˣ�" << endl;
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

 //����ְ��
 void WorkManager::Find_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	 }
	 else
	 {
		 
		 int user_Select;
		 cout << "��ѡ���ѯ��ʽ:" << endl;
		 cout << "1������ְ����Ų�ѯ" << endl;
		 cout << "2������ְ��������ѯ" << endl;
		 while (1)
		 {
			 cin >> user_Select;

			 
			 if (user_Select == 1)
			 {
				 cout << "������Ҫ��ѯ��ְ����ţ�" << endl;
				 int user_id;
				 cin >> user_id;
				 int ret = IsExit(user_id);
				 if (ret != -1)
				 {
					 cout << "�Ѳ鵽ְ�����Ϊ " << this->m_EmpArray[ret]->m_ID << " ��ְ����Ϣ�����£�" << endl;
					 this->m_EmpArray[ret]->ShowInfo();
				 }
				 else
				 {
					 cout << "���޴���" << endl;
				 }
				 break;
			 }
			 else if (user_Select == 2)
			 {
				 bool flag = false;
				 string user_name;
				 cout << "������Ҫ��ѯ��ְ��������" << endl;
				 cin >> user_name;
				 for (int i = 0;i < this->m_EmpNum;i++)
				 {
					 if (this->m_EmpArray[i]->m_Name == user_name)
					 {
						 cout << "�Ѳ鵽����Ϊ " << this->m_EmpArray[i]->m_Name << " ְ������Ϣ�����£�" << endl;
						 this->m_EmpArray[i]->ShowInfo();
						 flag = true;
					 }
				 }
				 if (flag == false)
				 {
					 cout << "���޴��ˣ���" << endl;
				 }
				 break;
			 }
			 else
			 {
				 cout << "�����������������룡" << endl;
			 }
		 }


	 }
	 system("pause");
	 system("cls");
 }

 //����
 void WorkManager::Sort_Emp()
 {
	 if (this->m_FileIsEmpty)
	 {
		 cout << "�ļ������ڻ��¼Ϊ�գ���" << endl;
		 system("pause");
		 system("cls");
	 }
	 else
	 {
		 cout << "��ѡ������ʽ��" << endl;
		 cout << "1����ְ���Ž�������" << endl;
		 cout << "2����ְ���Ž��н���" << endl;
		 int user_Select = 0;
		 cin >> user_Select;

		
		 for (int i = 0;i < m_EmpNum;i++)
		 {
			 int minOrMax = i;
			 for (int j = i + 1;j < m_EmpNum;j++)
			 {
				 if (user_Select == 1)//����
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
		 cout << "����ɹ����������" << endl;
		 this->Save();
		 this->Show_Emp();
	 }
 }

 void WorkManager::Clean_File()
 {
	 cout << "ȷ��Ҫȫ�������" << endl;
	 cout << "1��ȷ��" << endl;
	 cout << "2��ȡ��" << endl;
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

			 //ɾ����������ָ��
			 delete[] this->m_EmpArray;
			 this->m_EmpArray = NULL;
			 this->m_EmpNum = 0;
			 this->m_FileIsEmpty = true;
		 }
		 cout << "��ճɹ�����" << endl;
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