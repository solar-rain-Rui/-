#include<iostream>
using namespace std;
#include"workerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"boss.h"
int main()
{
	////����
	//Worker* worker = NULL;
	//worker = new(Employee)(1, "����", 1);
	//worker->showInfo();//���ֶ�̬,һ���ӿڶ�����̬
	//delete worker;

	//worker = new(Manager)(2, "����", 2);
	//worker->showInfo();
	//delete worker;

	//worker = new(boss)(3, "����", 3);
	//worker->showInfo();
	//delete worker;


	//ʵ���������߶���
	WorkerManager wm;
	int choice=0;
	while (true)
	{
		wm.Show_Menu();
		cout << "���������ѡ��" << endl;
		cin >> choice;//�����û���ѡ��
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