#pragma once
#include<iostream>
#include<string>
using namespace std;

//������ݻ���
class Identity
{
public:
	//�����˵�
	virtual void UserMenu() = 0;

	string m_Name;
	string m_Pwd;
};

