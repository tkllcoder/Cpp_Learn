#define _CRT_SECURE_NO_WARNINGS 1
#include"Student.h"

//Ĭ�Ϲ���
Student::Student()
{

}

//�вι���(ѧ�š�����������)
Student::Student(int id, string name, string pwd)
{
	this->m_Id = id;
	this->m_Name = name;
	this->m_Pwd = pwd;

	//������ʼ��
	ifstream ifs;
	this->comr.clear();
	computerroom com;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (ifs >> com.m_comId && ifs >> com.m_maxNum)
	{
		this->comr.push_back(com);
	}
	ifs.close();
}

//

//�˵�����
void Student::UserMenu()
{
	cout << "��ӭѧ����" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����ԤԼ        |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.ȡ��ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

void StudentMenu(Identity*& student)
{
	while (true)
	{
		student->UserMenu();
		Student* stu = (Student*)student;
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			cout << "����ԤԼ:" << endl;
			stu->applyOrder();
			break;
		case 2:
			cout << "�ҵ�ԤԼ:" << endl;
			stu->showMyOrder();
			break; 
		case 3:
			stu->showAllOrder();
			cout << "����ԤԼ" << endl;
			break; 
		case 4:
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
			break;
		case 0:
			delete stu;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ԤԼ
void Student::applyOrder()
{
	int date = 0;//�ܼ�
	int interval = 0;//���绹������
	int stuId = 0;
	string stuName;
	int roomId = 0;
	int status = 0;//����״̬

	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;
	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}


	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}
	
	cout << "��ѡ�������" << endl;
	for (vector<computerroom>::iterator it = this->comr.begin(); it != this->comr.end(); it++)
	{
		cout << "�������Ϊ��" << it->m_comId << " �����������Ϊ��" << it->m_maxNum << endl;
	}
	while (true)
	{
		cin >> roomId;
		if (roomId >= 1 && roomId <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs;
	ofs.open(ORDER_FILE, ios::out | ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->m_Id << " ";
	ofs << "stuName:" << this->m_Name << " ";
	ofs << "roomId:" << roomId << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");

}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
			cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
			cout << " ������" << of.m_orderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
			if (of.m_orderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.m_orderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.m_orderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;

		}
	}

	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "�� ";

		cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.m_orderData[i]["stuId"];
		cout << " ������" << of.m_orderData[i]["stuName"];
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	system("pause");
	system("cls");
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.m_Size; i++)
	{
		if (atoi(of.m_orderData[i]["stuId"].c_str()) == this->m_Id)
		{
			if (of.m_orderData[i]["status"] == "1" || of.m_orderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << "�� ";
				cout << "ԤԼ���ڣ� ��" << of.m_orderData[i]["date"];
				cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.m_orderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ  -1 ԤԼʧ��
				if (of.m_orderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.m_orderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;

			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if (select == 0)
			{
				break;
			}
			else
			{
				//	cout << "��¼����λ�ã� " << v[select - 1] << endl;
				of.m_orderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}

	system("pause");
	system("cls");
}