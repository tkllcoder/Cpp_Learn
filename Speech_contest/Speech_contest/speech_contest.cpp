#define _CRT_SECURE_NO_WARNINGS 1
#include"speech_contest.h"

//构造函数
ManageSystem::ManageSystem()
{
	this->SpeechInit();//初始化
	this->LoadRecord();//加载文件
	this->CreatSpeaker();//创建选手
}

void ManageSystem::ShowMenu()//展示主菜单
{
	cout << "*********************************************" << endl;
	cout << "**********     欢迎参加演讲比赛    **********" << endl;
	cout << "**********      1.开始演讲比赛     **********" << endl;
	cout << "**********      2.查看往届记录     **********" << endl;
	cout << "**********      3.清空比赛记录     **********" << endl;
	cout << "**********      0.退出比赛程序     **********" << endl;
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
		string name = "选手";
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
	cout << "第" << this->m_Index << "轮选手正在抽签" << endl;
	cout << "抽签顺序如下：" << endl;
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
	cout << "------------- 第" << this->m_Index << "轮正式比赛开始：------------- " << endl;

	multimap<double, int, greater<double>> groupScore; //临时容器，保存key分数 value 选手编号

	int num = 0; //记录人员数，6个为1组

	vector <int>v_Src;   //比赛的人员容器
	if (this->m_Index == 1)
	{
		v_Src = v1;
	}
	else
	{
		v_Src = v2;
	}

	//遍历所有参赛选手
	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;

		//评委打分
		deque<double>d;
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;  // 600 ~ 1000
			//cout << score << " ";
			d.push_back(score);
		}

		sort(d.begin(), d.end(), greater<double>());				//排序
		d.pop_front();												//去掉最高分
		d.pop_back();												//去掉最低分

		double sum = accumulate(d.begin(), d.end(), 0.0f);				//获取总分
		double avg = sum / (double)d.size();									//获取平均分

		//每个人平均分
		//cout << "编号： " << *it  << " 选手： " << this->m_Speaker[*it].m_Name << " 获取平均分为： " << avg << endl;  //打印分数
		this->m_Speaker[*it].m_Score[this->m_Index - 1] = avg;

		//6个人一组，用临时容器保存
		groupScore.insert(make_pair(avg, *it));
		if (num % 6 == 0)
		{

			cout << "第" << num / 6 << "小组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator it = groupScore.begin(); it != groupScore.end(); it++)
			{
				cout << "编号: " << it->second << " 姓名： " << this->m_Speaker[it->second].m_Name << " 成绩： " << this->m_Speaker[it->second].m_Score[this->m_Index - 1] << endl;
			}

			int count = 0;
			//取前三名
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
	cout << "------------- 第" << this->m_Index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}

void ManageSystem::ShowScore()
{
	cout << "------------- 第" << this->m_Index << "轮比赛晋级选手  ------------- " << endl;
	if (this->m_Index == 1)
	{
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)//v存编号，m_speaker存编号和其他信息，且可有编号访问信息
		{
			cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 成绩：" << this->m_Speaker[*it].m_Score[this->m_Index-1] << endl;
		}
	}
	else
	{
		for (vector<int>::iterator it = this->v_Victory.begin(); it != this->v_Victory.end(); it++)//v存编号，m_speaker存编号和其他信息，且可有编号访问信息
		{
			cout << "编号：" << *it << " 姓名：" << this->m_Speaker[*it].m_Name << " 成绩：" << this->m_Speaker[*it].m_Score[this->m_Index - 1] << endl;
		}
	}
}

void ManageSystem::SaveRecord()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out|ios::app);
	for (vector<int>::iterator it = this->v_Victory.begin(); it != this->v_Victory.end(); it++)//v存编号，m_speaker存编号和其他信息，且可有编号访问信息
	{
		ofs << *it <<"," << this->m_Speaker[*it].m_Score[1] << ",";
	}
	ofs << endl;
	ofs.close();
	cout << "本届成绩保存成功" << endl;
}

void ManageSystem::BeginSpeech()//开始演讲
{
	//第一轮比赛
	//1、抽签
	this->SpeechDraw();
	cout << endl;
	//2、比赛
	this->SpeechContest();
	cout << endl;
	//3、显示晋级结果
	this->ShowScore();
	cout << endl;
	//第二轮比赛
	this->m_Index++;
	//1、抽签
	cout << endl;
	this->SpeechDraw();
	//2、比赛
	cout << endl;
	this->SpeechContest();
	//3、显示最终结果
	cout << endl;
	cout << endl;
	this->ShowScore();
	//4、保存分数
	this->SaveRecord();
	this->FileIsEmpty = false;//文件不为空了

	//重置比赛 初始化属性
	this->SpeechInit();
	this->CreatSpeaker();
	this->LoadRecord();//使本届记录加载进去
}

void ManageSystem::LoadRecord()
{
	//文件判断
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空" << endl;
		this->FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在且不为空
	this->FileIsEmpty = false;
	ifs.putback(ch);
	
	int index = 0;//届数
	string data;//获取一行字符串
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
				string temp = data.substr(start, pos - start);//起始位置，长度
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
		cout << "文件不存在或记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_Record.size(); i++)
		{
			cout << "第" << i + 1 << "届比赛结果为" << endl;
			cout << "冠军编号：" << this->m_Record[i][0] << " 得分："
				<< this->m_Record[i][1]
				<< " 亚军编号：" << this->m_Record[i][2] << " 得分：" << this->m_Record[i][3]
				<< " 季军编号：" << this->m_Record[i][4] << " 得分：" << this->m_Record[i][5] << endl;
			cout << endl;
		}
	}
	
	system("pause");
	system("cls");
}

void ManageSystem::ClearRecord()
{
	int select = 0;
	cout << "是否清空记录？" << endl;
	cout << "1.确认" << endl;
	cout << "2.返回" << endl;
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
	cout << "清空成功" << endl;
	system("pause");
	system("cls");
}

void ManageSystem::ExitSystem()//退出系统
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}

//析构函数
ManageSystem::~ManageSystem()
{

}