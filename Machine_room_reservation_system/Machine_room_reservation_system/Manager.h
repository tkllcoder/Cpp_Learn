#pragma once
#include"identity.h"
#include"globalFile.h"
#include<fstream>
#include"Student.h"
#include"Teacher.h"
#include<vector>
#include<cstdbool>
#include<algorithm>

//������
class computerRoom
{
public:
	int m_ComId;
	int m_MaxNum;
};

class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();
	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	void initVector();//��ʼ���ļ���Ϣ
	virtual void UserMenu();//ѡ��˵�
	void addPerson();//����˺� 
	bool checkRepeat(int id, int type);//����ظ�
	void showPerson();//�鿴�˺�
	void showComputer();//�鿴������Ϣ
	void cleanFile();//���ԤԼ��¼
	
	vector<Student> vStu;
	vector<Teacher> vTea;
	vector<computerRoom> comR;
};

//����Ա�˵�
void managerMenu(Identity*& manager);
