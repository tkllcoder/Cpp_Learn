#pragma once
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include<vector>
#include"orderFile.h"

//������
class computerroom
{
public:
	int m_comId;
	int m_maxNum;
};

//����ѧ����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();
	//�вι��캯��
	Student(int id, string name, string pwd);

	virtual void UserMenu();//ѧ���˵�ҳ
	void applyOrder();//����ԤԼ
	void showMyOrder();//�鿴�ҵ�ԤԼ
	void showAllOrder();//�鿴����ԤԼ
	void cancelOrder();//ȡ��ԤԼ

	int m_Id;
	vector<computerroom> comr;
};

void StudentMenu(Identity*& student);