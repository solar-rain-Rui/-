#pragma once//防止头文件重复包含
#include<iostream>
#include"Worker.h"
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;

class WorkerManager
{
public:
	WorkerManager();//构造

	//展示菜单
	void Show_Menu();
	//退出系统
	void ExitSystem();
	~WorkerManager();//析构

	int m_EmpNum;//职工人数
	Worker** m_EmpArray;//员工数组的指针

	//添加职工
	void Add_Emp();
	//保存文件
	void save();
	//文件是否存在标志
	bool m_FileIsEmpty;
	//获取记录的职工人数
	int get_Num();
	//初始化职工
	void Init_Emp();
	//显示职工
	void Show_Emp();
	//判断职工是否存在
	int IsExist(int id);
	//删除职工
	void DelEmp();
	//修改职工信息
	void ModEmp();
	//查找职工
	void FindEmp();
	//按职工编号排序
	void SortEmp();
	//清空文件
	void CleanFile();
};