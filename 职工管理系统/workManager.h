#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class WorkManager
{
public:

	//���캯��
	WorkManager();

	//�˵�չʾ
	void Show_Menu();

	//�˳�����
	void ExitSystem();

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//�����ļ�
	void Save();

	//��¼ְ������
	int m_EmpNum;

	//�ж��ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	//ְ�������ļ�¼
	int get_EmpNum();

	//��ʼ��Ա��
	void init_Emp();

	//��ʾְ��
	void Show_Emp();

	//ɾ��ְ��
	void Del_Emp();

	//�ж�ְ���Ƿ���� ������ڷ���ְ�����������λ�ã������ڷ���-1
	int IsExit(int id);

	//�ж�ְ������Ƿ��ظ�
	int IsSample(int id);

	//�޸�ְ����Ϣ
	void Mod_Emp();

	//����Ա��
	void Find_Emp();

	//������
	void Sort_Emp();

	//����ĵ�
	void Clean_File();

	//��������
	~WorkManager();
};
