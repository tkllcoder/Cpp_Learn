#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//ʵ�����˵�����ʽ
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
//		printf("����������ѡ��");
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
//		default:printf("�����������������!!!\n");
//		}
//	} while (n);
//	
//}

//˳������
void SeqListTest1()
{
	SL sl;

	//��ַ����
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

	//���Ҳ���
	printf("����ֵΪ%d\n", SeqListFind(&sl, 5));

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






	SeqListDestroy(&sl);//�ͷ�ʱ�����Խ����ʵļ��
}
int main()
{
	SeqListTest1();
	return 0;
}