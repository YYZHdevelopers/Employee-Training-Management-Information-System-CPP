#include"Boss.h"

Boss::Boss(int id ,string name,int Did)
{
	this->m_ID = id;
	this->m_Name = name;
	this->m_DepitId = Did;
}

void Boss::ShowInfo()
{
	cout << "Ա����ţ� " << this->m_ID
		<< "\tԱ�������� " << this->m_Name
		<< "\t\t��λ�� " << this->GetDepartmentName()
		<< "\tְ�𣺹���˾���������� " << endl;
}

string Boss::GetDepartmentName()
{
	return string("�ϰ�");
}
