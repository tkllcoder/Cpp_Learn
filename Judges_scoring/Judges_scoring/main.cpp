#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cstdlib>
#include <ctime>
#include<deque>

using namespace std;
//10����ί�����ѡ��ABCDEF���д�֣�ȥ��һ����߷ֺ���ͷ֣�
//����ƽ���ɼ���Ϊ���ճɼ�
#define A 60 //�������������
#define B 100
class Person//��
{
public:
	Person(string name, float avg)
	{
		this->m_Name = name;
		this->m_Avg = avg;
	}
	string m_Name;
	float m_Avg;
};

void CreatPerson(vector<Person>& v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		float score = 0;
		string name = "ѡ��";
		name += nameSeed[i];//"ѡ��A"
		Person p(name, score);
		v.push_back(p);//β��
	}
}

void GetScore(vector<Person>& v)//�������뵽deque���� ������������ȥ�������Сֵ�����ƽ���֣��Żص�v��
{
	for (int i = 0; i < 5; i++)
	{
		//�������뵽deque����
		deque<float>s;
		for (int j = 0; j < 10; j++)
		{
			s.push_back(A + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (B - A))));
		}
		//����
		sort(s.begin(), s.end());
		//ȥ�������Сֵ
		s.pop_back();
		s.pop_front();
		//�������ȡƽ��
		float sum = 0.0;
		float avg = 0.0;
		for (deque<float>::iterator st = s.begin(); st < s.end(); st++)
		{
			sum += *st;
		}
		avg = sum / 8;
		//ƽ�����ŵ�v[i]��
		v[i].m_Avg = avg;
	}
}

void PrintVector(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << it->m_Name << "��ƽ���ɼ�Ϊ��" << it->m_Avg << endl;
	}
	cout << endl;
}
int main()
{
	srand(static_cast <unsigned> (time(0)));

	//��������  
	vector<Person>v;
	//1.��ʼ������
	CreatPerson(v);
	//2.������� ���ƽ��ֵ
	GetScore(v);
	//3.��ӡ����
	PrintVector(v);

	return 0;
}