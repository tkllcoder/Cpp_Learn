#pragma once
#include"identity.h"
#include"globalFile.h"
#include"orderFile.h"
#include<vector>

class Teacher : public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();
	Teacher(int empId, string name, string pwd);//�вι��� (ְ����ţ�����������)

	virtual void UserMenu();//�˵�����
	void showAllOrder();//�鿴����ԤԼ
	void validOrder();//���ԤԼ

	int m_EmpId;
};

void TeacherMenu(Identity*& teacher);
