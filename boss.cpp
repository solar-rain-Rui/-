#include"boss.h"

boss::boss(int id,string name,int dId)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void boss::showInfo()
{
	cout << "ְ�����: " << this->m_Id
		<< "\tְ������: " << this->m_Name
		<< "\tְ����λ: " << this->getDeptName()
		<< "\t��λְ��: ����˾��������" << endl;
}

string boss::getDeptName()
{
	return string("�ܲ�");
}