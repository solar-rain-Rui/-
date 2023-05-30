#include<iostream>
using namespace std;
#include"workerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"boss.h"
int main()
{
	////测试
	//Worker* worker = NULL;
	//worker = new(Employee)(1, "张三", 1);
	//worker->showInfo();//体现多态,一个接口多种形态
	//delete worker;

	//worker = new(Manager)(2, "李四", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new(boss)(3, "王五", 3);
	//worker->showInfo();
	//delete worker;


	//实例化管理者对象
	WorkerManager wm;
	int choice=0;
	while (true)
	{
		wm.Show_Menu();
		cout << "请输入你的选择" << endl;
		cin >> choice;//接收用户的选项
		switch (choice)
		{
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.DelEmp();
			break;
		case 4:
			wm.ModEmp();
			break;
		case 5:
			wm.FindEmp();
			break;
		case 6:
			wm.SortEmp();
			break;
		case 7:
			wm.CleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	return 0;
}