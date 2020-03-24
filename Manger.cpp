#include"Manager.h"

Manager::Manager(int id ,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Manager::ShowInfo()
{
	cout << "员工编号： " << this->m_ID
		<< "\t员工姓名： " << this->m_Name
		<< "\t\t岗位： " << this->GetDepartmentName()
		<< "\t职责：完成老板交给的任务，并下发任务给员工 "<< endl;
}

string Manager::GetDepartmentName()
{
	return string("经理");
}