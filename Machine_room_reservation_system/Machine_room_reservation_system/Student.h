#pragma once
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"orderFile.h"

//机房类
class computerroom
{
public:
	int m_comId;
	int m_maxNum;
};

//创建学生类
class Student : public Identity
{
public:
	//默认构造
	Student();
	//有参构造函数
	Student(int id, string name, string pwd);

	virtual void UserMenu();//学生菜单页
	void applyOrder();//申请预约
	void showMyOrder();//查看我的预约
	void showAllOrder();//查看所有预约
	void cancelOrder();//取消预约

	int m_Id;
	vector<computerroom> comr;
};

void StudentMenu(Identity*& student);