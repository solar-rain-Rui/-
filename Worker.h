#pragma once
#include<iostream>
using namespace std;
#include<string>
//
class Worker
{
public:
	virtual void showInfo()=0;//��ʾ��λ������Ϣ
	virtual string getDeptName() = 0;//��ȡ��λ����

	int m_Id;//ְ�����
	string m_Name;//ְ������
	int m_DeptId;//ְ�����ű��
};