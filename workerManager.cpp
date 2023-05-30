#include"workerManager.h"
#include"Employee.h"
#include"Manager.h"
#include"boss.h"
WorkerManager::WorkerManager()
{
	//this->m_EmpNum = 0;
	//this->m_EmpArray = NULL;//初始化
	ifstream ifs;
	//文件不存在
	if (!ifs.is_open())
	{
		//cout << "文件不存在" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在,记录为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		//cout << "文件为空" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在,保存了职工数据
	int num = get_Num();
	cout << "职工个数为: " << num << endl;
	this->m_EmpNum = num;//更新人数
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//将文件中数据保存到数组
	this->Init_Emp();

}

//显示职工

void WorkerManager::Show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空!" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			this->m_EmpArray[i]->showInfo();
		}

	}
	system("pause");
	system("cls");
}


int WorkerManager::get_Num()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;
	}
	ifs.close();
	return num;
}

//初始化职工
void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
			worker = new Employee(id, name, dId);
		else if (dId == 2)
			worker = new Manager(id, name, dId);
		else 
			worker = new boss(id, name, dId);
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();

}
//判断是否存在
int WorkerManager::IsExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
//删除职工
void WorkerManager::DelEmp()
{
	//判断文件
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		//按编号删除
		int id = 0;
		cin >> id;
		int index = IsExist(id);
		if (index != -1)//说明需要删除
		{
			for (int i = index; i < this->m_EmpNum - 1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败,未找到职工" << endl;
		}

	}
	system("pause");
	system("cls");
}

//添加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入添加数量" << endl;
	int addNum=0;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_EmpNum + addNum;//数量
		Worker** newSpace = new Worker* [newSize];
		//原空间数据拷贝到新空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;//岗位选择
			cout << "请输入第" << i + 1 << "个新职工编号" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个新职工姓名" << endl;
			cin >> name;
			cout << "请选择新职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new(Employee)(id, name, 1);
				break;
			case 2:
				worker = new(Manager)(id, name, 2);
				break;
			case 3:
				worker = new(boss)(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//释放原有空间
		delete[] m_EmpArray;
		//更改新空间指向
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;//更新人数
		//更新文件不为空
		this->m_FileIsEmpty = false;
		//提示
		cout << "成功添加了" << addNum << "个职工" << endl;	
		this->save();
	}
	else
	{
		cout << "输入错误" << endl;
	}
	//按任意键清屏并回到上级目录
	system("pause");
	system("cls");
}
//修改职工
void WorkerManager::ModEmp()
{
	//判断文件
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else {
		//按编号删除
		cout << "请输入修改职工的编号" << endl;
		int id = 0;
		cin >> id;
		int ret = IsExist(id);
		if (ret != -1)
		{
			//查找到该编号的员工
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = " ";
			int dSelect = 0;
			cout << "查到: " << id << "号职工,请输入新职工号: " << endl;
			cin >> newId;
			cout << "请输入新姓名: " << endl;
			cin >> newName;
			cout << "请选择新职工岗位" << endl;
			cout << "1.普通职工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new(Employee)(newId, newName, dSelect);
				break;
			case 2:
				worker = new(Manager)(newId, newName, dSelect);
				break;
			case 3:
				worker = new(boss)(newId, newName, dSelect); 
				break;
			default:
				break;
			}
			//更改数据到数组中
			this->m_EmpArray[ret] = worker;
			cout << "修改成功" << this->m_EmpArray[ret]->m_DeptId << endl;
			this->save();
		}
		else
		{
			cout << "修改失败,查无此人" << endl;
		}
	}
	//按任意键,清屏
	system("pause");
	system("cls");
}
//查找职工
void WorkerManager::FindEmp()
{
	//判断文件
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		cout << "请输入查找的方式: " << endl;
		cout << "1.按职工编号查找" << endl;
		cout << "2.按姓名查找" << endl;

		int select;
		cin >> select;
		if (select == 1)//按职工号查找
		{
			int id;
			cout << "请输入查找的编号: " << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1)
			{
				cout << "查找成功,该职工信息如下: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else
			{
				cout << "查找失败,查无此人" << endl;
			}
		}
		else if (select == 2)//按姓名查找
		{
			string name;
			cout << "请输入查找的姓名: " << endl;
			cin >> name;
			bool flag = false;//查找到的标志
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工编号为: " << m_EmpArray[i]->m_Id
						<< "号的信息如下: " << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
				
			}
			if (flag == false)
			{
				cout << "查找失败,查无此人" << endl;
			}
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
	system("pause");
	system("cls");
}

//按职工编号排序
void WorkerManager::SortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空" <<endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式" << endl;
		cout << "1.按职工号进行升序排序" << endl;
		cout << "2.按职工号进行降序排序" << endl;
		int select;
		cin >> select;    
		for (int i = 0; i < m_EmpNum; i++)//比较的轮数
		{
			int minorMax = i;//最小值或最大值
			for (int j = i + 1; j < m_EmpNum; j++)//j是每一轮比较的次数
			{
				if (select == 1)//升序
				{
					if (m_EmpArray[minorMax]->m_Id > m_EmpArray[j]->m_Id)
					{
						minorMax = j;//最小值
					}

				}
				else//降序
				{
					if (m_EmpArray[minorMax]->m_Id < m_EmpArray[j]->m_Id)
					{
						minorMax = j;
					}
				}
			}
			if (i != minorMax)
			{
				Worker* temp = m_EmpArray[i];
				m_EmpArray[i] = m_EmpArray[minorMax];
				m_EmpArray[minorMax] = temp;
			}
			
		}
		cout << "排序成功,排序后结果为: " << endl;
		this->save();
		this->Show_Emp();
	}
}

//清空文件
void WorkerManager::CleanFile()
{
	cout << "确定清空?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		//清空文件
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);//删除文件后重新创建
		ofs.close();
		if (this->m_EmpArray != NULL)
		{
			//删除堆区的每个对象
			for (int i = 0; i < m_EmpNum; i++)
			{
				delete m_EmpArray[i];
				m_EmpArray[i] = NULL;
			}
			//删除堆区的数组指针
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功" << endl;

	}
	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();

	
}

void WorkerManager::Show_Menu()
{
	cout << "**************************" << endl;
	cout << "****欢迎使用职工管理系统****" << endl;
	cout << "****0.退出管理程序****" << endl;
	cout << "****1.增加职工信息****" << endl;
	cout << "****2.显示职工信息****" << endl;
	cout << "****3.删除离职职工****" << endl;
	cout << "****4.修改职工信息****" << endl;
	cout << "****5.查找职工信息****" << endl;
	cout << "****6.按照编号排序****" << endl;
	cout << "****7.清空所有文档****" << endl;
	cout << "**************************" << endl;
	cout << endl;
}
//退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			delete m_EmpArray[i];
			m_EmpArray[i] = NULL;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
	}
}