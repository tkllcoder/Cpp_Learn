#define _CRT_SECURE_NO_WARNINGS 1
#include"speech_contest.h"

void test()
{
	srand((unsigned int)time(NULL));
	ManageSystem ms;
	/*for (map<int, Speaker>::iterator it = ms.m_Speaker.begin(); it != ms.m_Speaker.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << it->first
			<< " ������ " << it->second.m_Name
			<< " �ɼ��� " << it->second.m_Score[0] << endl;
	}*/
	int select;
	while (true)
	{
		ms.ShowMenu();
		cout << "���������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1://�����ݽ�����
			ms.BeginSpeech();
			break;
		case 2://�鿴�����¼
			ms.ShowHistory();
			break;
		case 3://��ձ�����¼
			ms.ClearRecord();
			break;
		case 0://�˳�����ϵͳ
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