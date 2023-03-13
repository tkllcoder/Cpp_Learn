#pragma once
#include"identity.h"
#include"Student.h"
#include"Teacher.h"
#include"Manager.h"
#include"globalFile.h"
#include<fstream>

//�˵�
void Menu()
{
	cout << "======================  ��ӭ�������ǲ��ͻ���ԤԼϵͳ  ====================="
		<< endl;
	cout << endl << "�������������" << endl;
	cout << "\t\t -------------------------------\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          1.ѧ������           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          2.��    ʦ           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          3.�� �� Ա           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t|          0.��    ��           |\n";
	cout << "\t\t|                               |\n";
	cout << "\t\t -------------------------------\n";
	cout << "��������ѡ��: ";
}

//��¼ϵͳ
void LoginIn(string fileName, int type)
{
	Identity* person;//����ָ�룬��̬ʹ��
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;

	//�ж�����
	if (type == 1)//ѧ����¼
	{
		cout << "���������ѧ��" << endl;
		cin >> id;
	}
	else if (type == 2)//��ʦ��¼
	{
		cout << "���������ְ����" << endl;
		cin >> id;
	}
	cout << "�������û�����" << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	int fId;
	string fName;
	string fPwd;
	if (type == 1)
	{
		//ѧ����¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "ѧ����֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				StudentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//��ʦ��¼��֤
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "��ʦ��֤��¼�ɹ�" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				TeacherMenu(person);
				return;
			}
		}
	}
	while (ifs >> fName && ifs >> fPwd)
	{
		if (fName == name && fPwd == pwd)
		{
			cout << "����Ա��֤��¼�ɹ�" << endl;
			//�������Ա�Ӳ˵�
			system("pause");
			system("cls");
			person = new Manager(name, pwd);
			managerMenu(person);
			return;
		}
	}

	cout << "��֤��¼ʧ��!" << endl;

	system("pause");
	system("cls");
}

//�˳�ϵͳ
void ExitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}