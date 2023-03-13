#define _CRT_SECURE_NO_WARNINGS 1
#include"Manager.h"

//默认构造
Manager::Manager()
{

}

//有参构造
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//初始化文件信息
void Manager::initVector()
{
	//读取学生信息
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "当前学生数量为: " << vStu.size() << endl;
	ifs.close();

	//读取老师信息
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "当前老师数量为: " << vTea.size() << endl;
	ifs.close();

	//机房初始化
	this->comR.clear();
	computerRoom com;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件读取失败" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		this->comR.push_back(com);
	}
	cout << "当前机房数量为: " << comR.size() << endl;
	ifs.close();
}

//选择菜单
void Manager::UserMenu()
{
	cout << "欢迎管理员：" << this->m_Name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//管理员菜单
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//管理员菜单
		manager->UserMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //添加账号
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}
		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}
		else if (select == 3) //查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4) //清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//检查重复
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if ((*it).m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if ((*it).m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

//添加账号  
void Manager::addPerson()
{
	cout << "--------      账号类型    ------------" << endl;
	cout << "--------     1、学生账号   -------------" << endl;
	cout << "--------     2、教师账号   -------------" << endl;
	cout << "---------------------------------------" << endl;
	cout << "请输入添加账号类型：" ;
	int select = 0;
	cin >> select;
	int id = 0;
	string name;
	string pwd;
	string filename;
	while (true)//检查重复
	{
		bool ret;
		if (select == 1)
		{
			cout << "请输入学生学号：" << endl;
			cin >> id;
			filename = STUDENT_FILE;
		}
		else
		{
			cout << "请输入职工编号：" << endl;
			cin >> id;
			filename = TEACHER_FILE;
		}
		if (!(ret = this->checkRepeat(id, select)))
		{
			break;
		}
		cout << "输入学号已存在，请重新输入！！" << endl;
	}
	
	cout << "请输入姓名：" << endl;
	cin >> name;
	cout << "请输入密码：" << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "添加成功" << endl;
	//添加完成后重新初始化容器，使新添加的成员被索引
	this->initVector();
	system("pause");
	system("cls");
	ofs.close();
}

void printStudent(Student& s)
{
	cout << "学号： " << s.m_Id << " 姓名： " << s.m_Name << " 密码：" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "职工号： " << t.m_EmpId << " 姓名： " << t.m_Name << " 密码：" << t.m_Pwd << endl;
}

//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "所有学生信息如下： " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "所有老师信息如下： " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下：" << endl;
	for (vector<computerRoom>::iterator it = comR.begin(); it != comR.end(); it++)
	{
		cout << "机房编号为：" << it->m_ComId << " 机房最大容量为：" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "清空成功！" << endl;
	system("pause");
	system("cls");
}