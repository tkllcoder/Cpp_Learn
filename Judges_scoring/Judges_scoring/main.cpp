#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <cstdlib>
#include <ctime>
#include<deque>

using namespace std;
//10个评委对五个选手ABCDEF进行打分，去掉一个最高分和最低分，
//并求平均成绩作为最终成绩
#define A 60 //随机数的上下限
#define B 100
class Person//类
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
		string name = "选手";
		name += nameSeed[i];//"选手A"
		Person p(name, score);
		v.push_back(p);//尾插
	}
}

void GetScore(vector<Person>& v)//分数插入到deque容器 并排序容器，去除最大最小值，求出平均分，放回到v中
{
	for (int i = 0; i < 5; i++)
	{
		//分数插入到deque容器
		deque<float>s;
		for (int j = 0; j < 10; j++)
		{
			s.push_back(A + static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / (B - A))));
		}
		//排序
		sort(s.begin(), s.end());
		//去除最大最小值
		s.pop_back();
		s.pop_front();
		//遍历求和取平均
		float sum = 0.0;
		float avg = 0.0;
		for (deque<float>::iterator st = s.begin(); st < s.end(); st++)
		{
			sum += *st;
		}
		avg = sum / 8;
		//平均数放到v[i]中
		v[i].m_Avg = avg;
	}
}

void PrintVector(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it < v.end(); it++)
	{
		cout << it->m_Name << "的平均成绩为：" << it->m_Avg << endl;
	}
	cout << endl;
}
int main()
{
	srand(static_cast <unsigned> (time(0)));

	//创建容器  
	vector<Person>v;
	//1.初始化容器
	CreatPerson(v);
	//2.输入分数 获得平均值
	GetScore(v);
	//3.打印数据
	PrintVector(v);

	return 0;
}