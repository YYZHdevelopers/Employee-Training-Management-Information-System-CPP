#include"Manager.h"

Manager::Manager(int id ,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Manager::ShowInfo()
{
	cout << "Ա����ţ� " << this->m_ID
		<< "\tԱ�������� " << this->m_Name
		<< "\t\t��λ�� " << this->GetDepartmentName()
		<< "\tְ������ϰ彻�������񣬲��·������Ա�� "<< endl;
}

string Manager::GetDepartmentName()
{
	return string("����");
}