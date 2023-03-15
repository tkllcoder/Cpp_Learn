#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//实现主菜单的形式
//void menu()
//{
//	int n = 0;
//	do 
//	{
//		printf("*********************************\n");
//		printf("********  0...     1.... ********\n");
//		printf("********  0...     1.... ********\n");
//		printf("********  0...     1.... ********\n");
//		printf("********  0...     1.... ********\n");
//		printf("*********************************\n");
//		
//		printf("请输入您的选择：");
//		scanf("%d", &n);
//		switch (n)
//		{
//		case 0:break;
//		case 1:break;
//		case 2:break;
//		case 3:break;
//		case 4:break;
//		case 5:break;
//		case 6:break;
//		case 7:break;
//		default:printf("输入错误，请重新输入!!!\n");
//		}
//	} while (n);
//	
//}

//顺序表测试
void SeqListTest1()
{
	SL sl;

	//传址调用
	SeqListInit(&sl);
	SeqListPushBack(&sl, 0);
	SeqListPushBack(&sl, 1); 
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	//SeqListPopBack(&sl);
	SeqListPrint(&sl);

	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPrint(&sl);

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 7);
	SeqListPushFront(&sl, 7);
	SeqListPrint(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPopFront(&sl);
	SeqListPrint(&sl);

	//查找测试
	printf("返回值为%d\n", SeqListFind(&sl, 5));

	SeqListPushFront(&sl, 5);
	SeqListPushFront(&sl, 6);
	SeqListPushFront(&sl, 7);
	SeqListPrint(&sl);

	SeqListInsert(&sl, 3, 8);
	SeqListPrint(&sl);

	SeqListErase(&sl, 2);
	SeqListErase(&sl, 2);
	SeqListErase(&sl, 3);
	SeqListPrint(&sl);






	SeqListDestroy(&sl);//释放时会进行越界访问的检查
}
int main()
{
	SeqListTest1();
	return 0;
}