#define _CRT_SECURE_NO_WARNINGS 1
#include"speech_contest.h"

void test()
{
	srand((unsigned int)time(NULL));
	ManageSystem ms;
	/*for (map<int, Speaker>::iterator it = ms.m_Speaker.begin(); it != ms.m_Speaker.end(); it++)
	{
		cout << "选手编号：" << it->first
			<< " 姓名： " << it->second.m_Name
			<< " 成绩： " << it->second.m_Score[0] << endl;
	}*/
	int select;
	while (true)
	{
		ms.ShowMenu();
		cout << "请输入你的选择：";
		cin >> select;
		switch (select)
		{
		case 1://进行演讲比赛
			ms.BeginSpeech();
			break;
		case 2://查看往届记录
			ms.ShowHistory();
			break;
		case 3://清空比赛记录
			ms.ClearRecord();
			break;
		case 0://退出比赛系统
			ms.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	}
}
int main()
{
	test();
	system("pause");
	return 0;
}