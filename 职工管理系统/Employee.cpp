#include"employee.h"

Employee::Employee(int id,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Employee::ShowInfo()
{
	cout << "员工编号： " << this->m_ID
		<< "\t员工姓名： " << this->m_Name
		<< "\t\t岗位： " << this->GetDepartmentName()
		<< "\t职责：完成经理交给的职责 " << endl;
}

string Employee::GetDepartmentName()
{
	return string("员工");
}
