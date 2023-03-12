#pragma once
#include<iostream>
#include<string>
#include<deque>
#include<algorithm>
#include<ctime>
#include<vector>
#include<map>
#include<numeric>
#include<fstream>

using namespace std;
#define FILENAME "record.txt"

class Speaker
{
public:
	string m_Name;
	double m_Score[2];
};

//1.创建管理类管理整个系统流程
class ManageSystem
{
public:
	//构造函数
	ManageSystem();
	void ShowMenu();//展示主菜单
	void SpeechInit();//初始化
	void CreatSpeaker();//创建选手
	void SpeechDraw();//抽签
	void SpeechContest();//比赛
	void ShowScore();//显示结果
	void BeginSpeech();//开始演讲
	void SaveRecord();//保存记录
	void LoadRecord();//加载记录
	void ShowHistory();//显示往届信息
	void ClearRecord();//清空文档数据
	void ExitSystem();//退出系统

	vector<int>v1;//选手12人
	vector<int>v2;//第一轮晋级6人
	vector<int>v_Victory;//胜利3人
	map<int, Speaker>m_Speaker;//存放编号及对应的选手  map可根据编号查找到内容
	int m_Index;//比赛轮数
	bool FileIsEmpty;//判断文件是否为空
	map<int, vector<string>>m_Record;//记录第几届和具体信息
	//析构函数
	~ManageSystem();
};