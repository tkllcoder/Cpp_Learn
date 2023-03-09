#pragma once
#include<iostream>
#include<fstream>
#include"worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
using namespace std;

#define FILENAME "empFile.txt"

//������ �ܿ�����
class WorkerManager
{
public:

	//���캯��
	WorkerManager();

	void Show_Menu();//�˵�����
	void exitSystem();//�˳�����
	void Add_Emp();//����ְ��
	void save();//���浽�ļ�
	int get_EmpNum();//��ȡԱ������
	void init_Emp();//��ʼ��ְ������
	void Show_Emp();//��ʾְ��
	void Del_Emp();//ɾ��ְ��
	int IsExist(int id);//�Ա���ж�ְ���Ƿ����
	void Mod_Emp();//�޸�ְ����Ϣ
	void Find_Emp();//����ְ��
	void Sort_Emp();//����ְ��
	void Clean_File();//����ļ�

	//��¼�ļ��е���������
	int m_EmpNum;
	//Ա�������ָ��
	Worker** m_EmpArray;
	bool m_FilelsEmpty;//�ļ��Ƿ�Ϊ��

	//��������
	~WorkerManager();
};