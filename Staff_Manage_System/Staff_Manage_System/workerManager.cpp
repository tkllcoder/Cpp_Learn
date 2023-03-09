#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//查看文件是否存在  1.文件不存在
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl; //测试输出
		//初始化人数
		this->m_EmpNum = 0;
		//初始化数组指针
		this->m_EmpArray = NULL;
		this->m_FilelsEmpty = true;
		ifs.close();
		return;
	}

	//2.文件存在，但数据为空 判断
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl; //测试输出
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FilelsEmpty = true;
		ifs.close();
		return;
	}

	//3.文件存在且不为空，先读出职工个数
	int num = this->get_EmpNum();
	//cout << "职工的个数为：" << num << endl; //测试输出
	//更新属性
	this->m_EmpNum = num;
	this->m_FilelsEmpty = false;
	//创建num个空间
	this->m_EmpArray = new Worker * [num];
	//初始化数据
	init_Emp();
	////测试读入是否成功
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "职工号： " << this->m_EmpArray[i]->m_Id
	//		<< " 职工姓名： " << this->m_EmpArray[i]->m_Name
	//		<< " 部门编号： " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//增加职工
void WorkerManager::Add_Emp()
{
	cout << "请输入增加职工数量： " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;

		//更改新空间的指向
		this->m_EmpArray = newSpace;

		//更新新的个数
		this->m_EmpNum = newSize;

		this->m_FilelsEmpty = false;//修改标志
		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else
	{
		cout << "输入有误" << endl;
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

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//记录人数
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//读入职工
	int id;
	string name;
	int dId;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1: //普通员工
			worker = new Employee(id, name, 1);
			break;
		case 2: //经理
			worker = new Manager(id, name, 2);
			break;
		case 3:  //老板
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		this->m_EmpArray[i++] = worker;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//调用多态的显示函数
		this->m_EmpArray[i]->showInfo();
	}
}

void WorkerManager::Del_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或数据为空，不能删除数据" << endl;
		return;
	}
	//删除数据
	int id = 0;
	cout << "输入删除职工的编号：" << endl;
	cin >> id;
	int index = this->IsExist(id);
	if (index == -1)
	{
		cout << "该职工不存在，删除失败" << endl;
	}
	else//从index开始从后往前覆盖
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "删除成功！" << endl;
		if (this->m_EmpNum == 0)
		{
			this->m_FilelsEmpty = true;
		}
	}

}

int WorkerManager::IsExist(int id)//有返回下标，没有返回-1
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或数据为空" << endl;
		return -1;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			return i;
		}
	}
	return -1;
}

//修改职工
void WorkerManager::Mod_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入修改职工的编号：" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//查找到编号的职工
			//修改职工数据
			//delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "查到： " << id << "号职工，请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//更改数据 到数组中
			this->m_EmpArray[ret] = worker;

			cout << "修改成功！" << endl;

			//保存到文件中
			this->save();
		}
		else
		{
			cout << "修改失败，查无此人" << endl;
		}
	}

	//按任意键 清屏
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	int select = 0;
	cout << "请输入查找方式： " << endl;
	cout << "1、按职工编号查找" << endl;
	cout << "2、按职工姓名查找" << endl;
	cin >> select;
	if (select == 1)
	{
		int id = 0;
		int index = 0;
		cout << "请输入职工编号：" << endl;
		cin >> id;
		index = this->IsExist(id);
		if (index >= 0)
		{
			cout << "查找成功，职工信息如下：" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "查无此人，查找失败" << endl;
		}
	}
	else if (select == 2)
	{
		string name;
		cout << "请输入职工姓名：" << endl;
		cin >> name;
		int index = -1;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				index = i;
				break;
			}
		}
		if (index >= 0)
		{
			cout << "查找成功，职工信息如下：" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "查无此人，查找失败" << endl;
		}
	}
	else
	{
		cout << "输入选项有误" << endl;
	}
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		return;
	}
	int select = 0;
	cout << "请输入排序方式： " << endl;
	cout << "1、按职工编号升序" << endl;
	cout << "2、按职工编号降序" << endl;
	cin >> select;
	if (select == 1)//假如冒泡排序
	{
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)//大的往后 所有内容交换
				{
					Worker* tmp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = tmp;
				}
			}
		}
		cout << "排序完成，排序结果为 " << endl;
		this->Show_Emp();
		this->save();
	}
	else if (select == 2)
	{
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)//小的往后交换
				{
					Worker* tmp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = tmp;
				}
			}
		}
		cout << "排序完成，排序结果为 " << endl;
		this->Show_Emp();
		this->save();
	}
	else
	{
		cout << "输入选项有误" << endl;
	}
}

//清空文件
void WorkerManager::Clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式 ios::trunc 如果存在 删除文件并重新创建
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FilelsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}