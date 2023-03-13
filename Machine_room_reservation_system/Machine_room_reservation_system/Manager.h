#pragma once
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include<vector>
#include<cstdbool>
#include<algorithm>

//机房类
class computerRoom
{
public:
	int m_ComId;
	int m_MaxNum;
};

class Manager : public Identity
{
public:
	//默认构造
	Manager();
	//有参构造  管理员姓名，密码
	Manager(string name, string pwd);

	void initVector();//初始化文件信息
	virtual void UserMenu();//选择菜单
	void addPerson();//添加账号 
	bool checkRepeat(int id, int type);//检查重复
	void showPerson();//查看账号
	void showComputer();//查看机房信息
	void cleanFile();//清空预约记录
	
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<computerRoom> comR;
};

//管理员菜单
void managerMenu(Identity*& manager);
