#define _CRT_SECURE_NO_WARNINGS 1
#include"speech_contest.h"

//���캯��
ManageSystem::ManageSystem()
{
	this->SpeechInit();//��ʼ��
	this->LoadRecord();//�����ļ�
	this->CreatSpeaker();//����ѡ��
}

void ManageSystem::ShowMenu()//չʾ���˵�
{
	cout << "*********************************************" << endl;
	cout << "**********     ��ӭ�μ��ݽ�����    **********" << endl;
	cout << "**********      1.��ʼ�ݽ�����     **********" << endl;
	cout << "**********      2.�鿴�����¼     **********" << endl;
	cout << "**********      3.��ձ�����¼     **********" << endl;
	cout << "**********      0.�˳���������     **********" << endl;
	cout << "*********************************************" << endl;
	cout << endl;
}

void ManageSystem::SpeechInit()
{
	this->v1.clear();
	this->v2.clear();
	this->v_Victory.clear();
	this->m_Speaker.clear();
	this->m_Index = 1;
	this->m_Record.clear();
}

void ManageSystem::CreatSpeaker()
{
	string NameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "ѡ��";
		name += NameSeed[i];
		Speaker sp;
		sp.m_Name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.m_Score[j] = 0;
		}
		this->v1.push_back(10001 + i);
		this->m_Speaker.insert(make_pair(10001 + i, sp));
	}
}

void ManageSystem::SpeechDraw()
{
	cout << "��" << this->m_Index << "��ѡ�����ڳ�ǩ" << endl;
	cout << "��ǩ˳�����£�" << endl;
	if (this->m_Index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
}

void ManageSystem::SpeechContest()
{
	cout << "------------- ��" << this->m_Index << "����ʽ������ʼ��------------- " << endl;

	multimap<double, int, greater<double>> groupScore; //��ʱ����������key���� value ѡ�ֱ��

	int num = 0; //��¼��Ա����6��Ϊ1��

	vector <int>v_Src;   //��������Ա����
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//�������в���ѡ��
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//��ί���
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//����
		d.pop_front();												//ȥ����߷�
		d.pop_back();												//ȥ����ͷ�

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//��ȡ�ܷ�
		double avg = sum / (double)d.size();									//��ȡƽ����

		//ÿ����ƽ����
		//cout << "��ţ� " << *it  << " ѡ�֣� " << this->m_Speaker[*it].m_Name << " ��ȡƽ����Ϊ�� " << avg << endl;  //��ӡ����
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//6����һ�飬����ʱ��������
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "��" << num / 6 << "С��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "���: " << it->second << " ������ " << this->m_Speaker[it->second].m_Name << " �ɼ��� " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;
			//ȡǰ����
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end() && count < 3; it++, count++)
			{
				if (this->m_Index == 1)
				{
					v2.push_back((*it).second);
				}
				else
				{
					v_Victory.push_back((*it).second);
				}
			}

			groupScore.clear();

			cout << endl;

		}
	}
	cout << "------------- ��" << this->m_Index << "�ֱ������  ------------- " << endl;
	system("pause");
}

void ManageSystem::ShowScore()
{
	cout << "------------- ��" << this->m_Index << "�ֱ�������ѡ��  ------------- " << endl;
	if (this->m_Index == 1)
	{
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)//v���ţ�m_speaker���ź�������Ϣ���ҿ��б�ŷ�����Ϣ
		{
			cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " �ɼ���" << this->m_Speaker[*it].m_Score[this->m_Index-1] << endl;
		}
	}
	else
	{
		for (vector<int>::iterator it = this->v_Victory.begin(); it != this->v_Victory.end(); it++)//v���ţ�m_speaker���ź�������Ϣ���ҿ��б�ŷ�����Ϣ
		{
			cout << "��ţ�" << *it << " ������" << this->m_Speaker[*it].m_Name << " �ɼ���" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
		}
	}
}

void ManageSystem::SaveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out|ios::app);
	for (vector<int>::iterator it = this->v_Victory.begin(); it != this->v_Victory.end(); it++)//v���ţ�m_speaker���ź�������Ϣ���ҿ��б�ŷ�����Ϣ
	{
		ofs << *it <<"," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "����ɼ�����ɹ�" << endl;
}

void ManageSystem::BeginSpeech()//��ʼ�ݽ�
{
	//��һ�ֱ���
	//1����ǩ
	this->SpeechDraw();
	cout << endl;
	//2������
	this->SpeechContest();
	cout << endl;
	//3����ʾ�������
	this->ShowScore();
	cout << endl;
	//�ڶ��ֱ���
	this->m_Index++;
	//1����ǩ
	cout << endl;
	this->SpeechDraw();
	//2������
	cout << endl;
	this->SpeechContest();
	//3����ʾ���ս��
	cout << endl;
	cout << endl;
	this->ShowScore();
	//4���������
	this->SaveRecord();
	this->FileIsEmpty = false;//�ļ���Ϊ����

	//���ñ��� ��ʼ������
	this->SpeechInit();
	this->CreatSpeaker();
	this->LoadRecord();//ʹ�����¼���ؽ�ȥ
}

void ManageSystem::LoadRecord()
{
	//�ļ��ж�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ��" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ������Ҳ�Ϊ��
	this->FileIsEmpty = false;
	ifs.putback(ch);
	
	int index = 0;//����
	string data;//��ȡһ���ַ���
	while (ifs >> data)
	{
		vector<string>v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",", start);
			if (pos == -1)
			{
				break;
			}
			else
			{
				string temp = data.substr(start, pos - start);//��ʼλ�ã�����
				v.push_back(temp);
				start = pos + 1;
			}
		}
		this->m_Record.insert(make_pair(index, v));
		index++;
	}
	ifs.close();
}

void ManageSystem::ShowHistory()
{
	if (this->FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "��" << i + 1 << "��������Ϊ" << endl;
			cout << "�ھ���ţ�" << this->m_Record[i][0] << " �÷֣�"
				<< this->m_Record[i][1]
				<< " �Ǿ���ţ�" << this->m_Record[i][2] << " �÷֣�" << this->m_Record[i][3]
				<< " ������ţ�" << this->m_Record[i][4] << " �÷֣�" << this->m_Record[i][5] << endl;
			cout << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void ManageSystem::ClearRecord()
{
	int select = 0;
	cout << "�Ƿ���ռ�¼��" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cin >> select;
	if (select != 1)
	{
		return;
	}
	else
	{
		ofstream ofs;
		ofs.open(FILENAME, ios::trunc);
		ofs.close();
		this->SpeechInit();
		this->CreatSpeaker();
		this->LoadRecord();
	}
	cout << "��ճɹ�" << endl;
	system("pause");
	system("cls");
}

void ManageSystem::ExitSystem()//�˳�ϵͳ
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}

//��������
ManageSystem::~ManageSystem()
{

}