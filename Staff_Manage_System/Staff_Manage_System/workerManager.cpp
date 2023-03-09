#include "workerManager.h"

WorkerManager::WorkerManager()
{
	//�鿴�ļ��Ƿ����  1.�ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl; //�������
		//��ʼ������
		this->m_EmpNum = 0;
		//��ʼ������ָ��
		this->m_EmpArray = NULL;
		this->m_FilelsEmpty = true;
		ifs.close();
		return;
	}

	//2.�ļ����ڣ�������Ϊ�� �ж�
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl; //�������
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FilelsEmpty = true;
		ifs.close();
		return;
	}

	//3.�ļ������Ҳ�Ϊ�գ��ȶ���ְ������
	int num = this->get_EmpNum();
	//cout << "ְ���ĸ���Ϊ��" << num << endl; //�������
	//��������
	this->m_EmpNum = num;
	this->m_FilelsEmpty = false;
	//����num���ռ�
	this->m_EmpArray = new Worker * [num];
	//��ʼ������
	init_Emp();
	////���Զ����Ƿ�ɹ�
	//for (int i = 0; i < m_EmpNum; i++)
	//{
	//	cout << "ְ���ţ� " << this->m_EmpArray[i]->m_Id
	//		<< " ְ�������� " << this->m_EmpArray[i]->m_Name
	//		<< " ���ű�ţ� " << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::Show_Menu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

void WorkerManager::exitSystem()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//����ְ��
void WorkerManager::Add_Emp()
{
	cout << "����������ְ�������� " << endl;

	int addNum = 0;
	cin >> addNum;

	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int dSelect;

			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;


			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}


			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;

		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		//�����µĸ���
		this->m_EmpNum = newSize;

		this->m_FilelsEmpty = false;//�޸ı�־
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else
	{
		cout << "��������" << endl;
	}

	system("pause");
	system("cls");
}

void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}

int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		num++;//��¼����
	}
	ifs.close();
	return num;
}

void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//����ְ��
	int id;
	string name;
	int dId;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		switch (dId)
		{
		case 1: //��ͨԱ��
			worker = new Employee(id, name, 1);
			break;
		case 2: //����
			worker = new Manager(id, name, 2);
			break;
		case 3:  //�ϰ�
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}
		this->m_EmpArray[i++] = worker;
	}
}

void WorkerManager::Show_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		return;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		//���ö�̬����ʾ����
		this->m_EmpArray[i]->showInfo();
	}
}

void WorkerManager::Del_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ�գ�����ɾ������" << endl;
		return;
	}
	//ɾ������
	int id = 0;
	cout << "����ɾ��ְ���ı�ţ�" << endl;
	cin >> id;
	int index = this->IsExist(id);
	if (index == -1)
	{
		cout << "��ְ�������ڣ�ɾ��ʧ��" << endl;
	}
	else//��index��ʼ�Ӻ���ǰ����
	{
		for (int i = index; i < this->m_EmpNum - 1; i++)
		{
			this->m_EmpArray[i] = this->m_EmpArray[i + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "ɾ���ɹ���" << endl;
		if (this->m_EmpNum == 0)
		{
			this->m_FilelsEmpty = true;
		}
	}

}

int WorkerManager::IsExist(int id)//�з����±꣬û�з���-1
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
		return -1;
	}
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			return i;
		}
	}
	return -1;
}

//�޸�ְ��
void WorkerManager::Mod_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "�������޸�ְ���ı�ţ�" << endl;
		int id;
		cin >> id;

		int ret = this->IsExist(id);
		if (ret != -1)
		{
			//���ҵ���ŵ�ְ��
			//�޸�ְ������
			//delete this->m_EmpArray[ret];

			int newId = 0;
			string newName = "";
			int dSelect = 0;

			cout << "�鵽�� " << id << "��ְ������������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
			cin >> dSelect;

			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}

			//�������� ��������
			this->m_EmpArray[ret] = worker;

			cout << "�޸ĳɹ���" << endl;

			//���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}

	//������� ����
	system("pause");
	system("cls");
}

void WorkerManager::Find_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	int select = 0;
	cout << "��������ҷ�ʽ�� " << endl;
	cout << "1����ְ����Ų���" << endl;
	cout << "2����ְ����������" << endl;
	cin >> select;
	if (select == 1)
	{
		int id = 0;
		int index = 0;
		cout << "������ְ����ţ�" << endl;
		cin >> id;
		index = this->IsExist(id);
		if (index >= 0)
		{
			cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "���޴��ˣ�����ʧ��" << endl;
		}
	}
	else if (select == 2)
	{
		string name;
		cout << "������ְ��������" << endl;
		cin >> name;
		int index = -1;
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				index = i;
				break;
			}
		}
		if (index >= 0)
		{
			cout << "���ҳɹ���ְ����Ϣ���£�" << endl;
			this->m_EmpArray[index]->showInfo();
		}
		else
		{
			cout << "���޴��ˣ�����ʧ��" << endl;
		}
	}
	else
	{
		cout << "����ѡ������" << endl;
	}
}

void WorkerManager::Sort_Emp()
{
	if (this->m_FilelsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		return;
	}
	int select = 0;
	cout << "����������ʽ�� " << endl;
	cout << "1����ְ���������" << endl;
	cout << "2����ְ����Ž���" << endl;
	cin >> select;
	if (select == 1)//����ð������
	{
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)//������� �������ݽ���
				{
					Worker* tmp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = tmp;
				}
			}
		}
		cout << "������ɣ�������Ϊ " << endl;
		this->Show_Emp();
		this->save();
	}
	else if (select == 2)
	{
		for (int i = 0; i < this->m_EmpNum - 1; i++)
		{
			for (int j = 0; j < this->m_EmpNum - 1 - i; j++)
			{
				if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)//С�����󽻻�
				{
					Worker* tmp = this->m_EmpArray[j];
					this->m_EmpArray[j] = this->m_EmpArray[j + 1];
					this->m_EmpArray[j + 1] = tmp;
				}
			}
		}
		cout << "������ɣ�������Ϊ " << endl;
		this->Show_Emp();
		this->save();
	}
	else
	{
		cout << "����ѡ������" << endl;
	}
}

//����ļ�
void WorkerManager::Clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽ ios::trunc ������� ɾ���ļ������´���
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i] != NULL)
				{
					delete this->m_EmpArray[i];
				}
			}
			this->m_EmpNum = 0;
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_FilelsEmpty = true;
		}
		cout << "��ճɹ���" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
	}
}