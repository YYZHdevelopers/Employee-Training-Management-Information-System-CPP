#include"employee.h"

Employee::Employee(int id,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Employee::ShowInfo()
{
	cout << "Ա����ţ� " << this->m_ID
		<< "\tԱ�������� " << this->m_Name
		<< "\t\t��λ�� " << this->GetDepartmentName()
		<< "\tְ����ɾ�������ְ�� " << endl;
}

string Employee::GetDepartmentName()
{
	return string("Ա��");
}
