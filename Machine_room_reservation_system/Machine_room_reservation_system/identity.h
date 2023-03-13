#pragma once
#include<iostream>
#include<string>
using namespace std;

//创建身份基类
class Identity
{
public:
	//操作菜单
	virtual void UserMenu() = 0;

	string m_Name;
	string m_Pwd;
};

