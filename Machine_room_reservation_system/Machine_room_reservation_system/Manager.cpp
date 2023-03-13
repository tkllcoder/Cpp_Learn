#define _CRT_SECURE_NO_WARNINGS 1
#include"Manager.h"

//Ĭ�Ϲ���
Manager::Manager()
{

}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;
	this->initVector();
}

//��ʼ���ļ���Ϣ
void Manager::initVector()
{
	//��ȡѧ����Ϣ
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	vStu.clear();
	vTea.clear();
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		this->vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ: " << vStu.size() << endl;
	ifs.close();

	//��ȡ��ʦ��Ϣ
	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		this->vTea.push_back(t);
	}
	cout << "��ǰ��ʦ����Ϊ: " << vTea.size() << endl;
	ifs.close();

	//������ʼ��
	this->comR.clear();
	computerRoom com;
	ifs.open(COMPUTER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	while (ifs >> com.m_ComId && ifs >> com.m_MaxNum)
	{
		this->comR.push_back(com);
	}
	cout << "��ǰ��������Ϊ: " << comR.size() << endl;
	ifs.close();
}

//ѡ��˵�
void Manager::UserMenu()
{
	cout << "��ӭ����Ա��" << this->m_Name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����Ա�˵�
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//����Ա�˵�
		manager->UserMenu();

		Manager* man = (Manager*)manager;
		int select = 0;

		cin >> select;

		if (select == 1)  //����˺�
		{
			cout << "����˺�" << endl;
			man->addPerson();
		}
		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}
		else if (select == 3) //�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4) //���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//����ظ�
bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if ((*it).m_Id == id)
			{
				return true;
			}
		}
	}
	else
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if ((*it).m_EmpId == id)
			{
				return true;
			}
		}
	}
	return false;
}

//����˺�  
void Manager::addPerson()
{
	cout << "--------      �˺�����    ------------" << endl;
	cout << "--------     1��ѧ���˺�   -------------" << endl;
	cout << "--------     2����ʦ�˺�   -------------" << endl;
	cout << "---------------------------------------" << endl;
	cout << "����������˺����ͣ�" ;
	int select = 0;
	cin >> select;
	int id = 0;
	string name;
	string pwd;
	string filename;
	while (true)//����ظ�
	{
		bool ret;
		if (select == 1)
		{
			cout << "������ѧ��ѧ�ţ�" << endl;
			cin >> id;
			filename = STUDENT_FILE;
		}
		else
		{
			cout << "������ְ����ţ�" << endl;
			cin >> id;
			filename = TEACHER_FILE;
		}
		if (!(ret = this->checkRepeat(id, select)))
		{
			break;
		}
		cout << "����ѧ���Ѵ��ڣ����������룡��" << endl;
	}
	
	cout << "������������" << endl;
	cin >> name;
	cout << "���������룺" << endl;
	cin >> pwd;
	ofstream ofs;
	ofs.open(filename, ios::out | ios::app);
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ�" << endl;
	//�����ɺ����³�ʼ��������ʹ����ӵĳ�Ա������
	this->initVector();
	system("pause");
	system("cls");
	ofs.close();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ� " << s.m_Id << " ������ " << s.m_Name << " ���룺" << s.m_Pwd << endl;
}
void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.m_EmpId << " ������ " << t.m_Name << " ���룺" << t.m_Pwd << endl;
}

//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select = 0;

	cin >> select;

	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£� " << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);
	}
	else
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<computerRoom>::iterator it = comR.begin(); it != comR.end(); it++)
	{
		cout << "�������Ϊ��" << it->m_ComId << " �����������Ϊ��" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}