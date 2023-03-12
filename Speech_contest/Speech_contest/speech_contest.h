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

//1.�����������������ϵͳ����
class ManageSystem
{
public:
	//���캯��
	ManageSystem();
	void ShowMenu();//չʾ���˵�
	void SpeechInit();//��ʼ��
	void CreatSpeaker();//����ѡ��
	void SpeechDraw();//��ǩ
	void SpeechContest();//����
	void ShowScore();//��ʾ���
	void BeginSpeech();//��ʼ�ݽ�
	void SaveRecord();//�����¼
	void LoadRecord();//���ؼ�¼
	void ShowHistory();//��ʾ������Ϣ
	void ClearRecord();//����ĵ�����
	void ExitSystem();//�˳�ϵͳ

	vector<int>v1;//ѡ��12��
	vector<int>v2;//��һ�ֽ���6��
	vector<int>v_Victory;//ʤ��3��
	map<int, Speaker>m_Speaker;//��ű�ż���Ӧ��ѡ��  map�ɸ��ݱ�Ų��ҵ�����
	int m_Index;//��������
	bool FileIsEmpty;//�ж��ļ��Ƿ�Ϊ��
	map<int, vector<string>>m_Record;//��¼�ڼ���;�����Ϣ
	//��������
	~ManageSystem();
};