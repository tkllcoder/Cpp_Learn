#define _CRT_SECURE_NO_WARNINGS 1
#include"main.h"

int main()
{
	
	while (true)
	{
		Menu();
		int select = 0;
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TEACHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			ExitSystem();
			break;
		default:
			cout << "输入有误，请重新选择！！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	return 0;
}