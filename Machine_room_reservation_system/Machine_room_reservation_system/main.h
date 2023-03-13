#pragma once
#include"identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"globalFile.h"
#include<fstream>

//菜单
void Menu()
{
	cout << "======================  欢迎来到传智播客机房预约系统  ====================="
		<< endl;
	cout << endl << "请输入您的身份" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.学生代表           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.老    师           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.管 理 员           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.退    出           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "输入您的选择: ";
}

//登录系统
void LoginIn(string fileName, int type)
{
	Identity* person;//父类指针，多态使用
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	//判断类型
	if (type == 1)//学生登录
	{
		cout << "请输入你的学号" << endl;
		cin >> id;
	}
	else if (type == 2)//教师登录
	{
		cout << "请输入你的职工号" << endl;
		cin >> id;
	}
	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;
	if (type == 1)
	{
		//学生登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师登录验证
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	while (ifs >> fName && ifs >> fPwd)
	{
		if (fName == name && fPwd == pwd)
		{
			cout << "管理员验证登录成功" << endl;
			//进入管理员子菜单
			system("pause");
			system("cls");
			person = new Manager(name, pwd);
			managerMenu(person);
			return;
		}
	}

	cout << "验证登录失败!" << endl;

	system("pause");
	system("cls");
}

//退出系统
void ExitSystem()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}