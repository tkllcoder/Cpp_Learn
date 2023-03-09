#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

//管理类 总控制类
class WorkerManager
{
public:

	//构造函数
	WorkerManager();

	void Show_Menu();//菜单函数
	void exitSystem();//退出函数
	void Add_Emp();//增加职工
	void save();//保存到文件
	int get_EmpNum();//获取员工个数
	void init_Emp();//初始化职工代码
	void Show_Emp();//显示职工
	void Del_Emp();//删除职工
	int IsExist(int id);//以编号判断职工是否存在
	void Mod_Emp();//修改职工信息
	void Find_Emp();//查找职工
	void Sort_Emp();//排序职工
	void Clean_File();//清空文件

	//记录文件中的人数个数
	int m_EmpNum;
	//员工数组的指针
	Worker** m_EmpArray;
	bool m_FilelsEmpty;//文件是否为空

	//析构函数
	~WorkerManager();
};