#pragma once//��ֹͷ�ļ��ظ�����
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();//����

	//չʾ�˵�
	void Show_Menu();
	//�˳�ϵͳ
	void ExitSystem();
	~WorkerManager();//����

	int m_EmpNum;//ְ������
	Worker** m_EmpArray;//Ա�������ָ��

	//���ְ��
	void Add_Emp();
	//�����ļ�
	void save();
	//�ļ��Ƿ���ڱ�־
	bool m_FileIsEmpty;
	//��ȡ��¼��ְ������
	int get_Num();
	//��ʼ��ְ��
	void Init_Emp();
	//��ʾְ��
	void Show_Emp();
	//�ж�ְ���Ƿ����
	int IsExist(int id);
	//ɾ��ְ��
	void DelEmp();
	//�޸�ְ����Ϣ
	void ModEmp();
	//����ְ��
	void FindEmp();
	//��ְ���������
	void SortEmp();
	//����ļ�
	void CleanFile();
};