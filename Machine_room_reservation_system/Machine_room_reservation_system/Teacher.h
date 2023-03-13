#pragma once
#include"identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include<vector>

class Teacher : public Identity
{
public:
	//默认构造
	Teacher();
	Teacher(int empId, string name, string pwd);//有参构造 (职工编号，姓名，密码)

	virtual void UserMenu();//菜单界面
	void showAllOrder();//查看所有预约
	void validOrder();//审核预约

	int m_EmpId;
};

void TeacherMenu(Identity*& teacher);
