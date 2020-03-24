#include"Boss.h"

Boss::Boss(int id ,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Boss::ShowInfo()
{
	cout << "员工编号： " << this->m_ID
		<< "\t员工姓名： " << this->m_Name
		<< "\t\t岗位： " << this->GetDepartmentName()
		<< "\t职责：管理公司的整体事务 " << endl;
}

string Boss::GetDepartmentName()
{
	return string("老板");
}
