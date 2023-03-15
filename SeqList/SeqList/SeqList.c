#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//顺序表初始化
void SeqListInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//检查增容情况
void SeqListCheckCapacity(SL* ps)
{
	//没有开辟空间或者空间已满
	if (ps->size == ps->capacity)
	{
		//新空间的大小，如果初次开辟则四个容量，否则二倍开辟
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail!!\n");
			exit(-1);//异常退出
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//顺序表尾部插入数据 考虑容量
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);//检查增容
	ps->arr[ps->size] = x;
	ps->size++;
}

//顺序表打印
void SeqListPrint(SL* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	printf("\n");
	printf("size = %d\n", ps->size);
	printf("capacity = %d\n", ps->capacity);
}

//顺序表退出释放
void SeqListDestroy(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//顺序表尾删 删到0
void SeqListPopBack(SL* ps)
{
	//方法1 注意size不能小于0，否则会引起非法访问
	//if (ps->size > 0)
	//{
	//	ps->size--;//顺序表中size可以标示已有的数据，减1表示删除两个数据

	//}
	//else
	//{
	//	ps->size = 0;
	//}

	//方法2
	assert(ps->size > 0);
	ps->size--;
}

//顺序表头插
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);//检查增容

	//1.把后面的数据向后挪一格
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	//2.需要插入的数据放到第一个位置
	ps->arr[0] = x;
	//3.size++
	ps->size++;
}

//顺序表头删
void SeqListPopFront(SL* ps)
{
	//删除数据要看是否删完
	assert(ps->size > 0);
	//1.把后面的依次往前覆盖一格 
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	//2.size--
	ps->size--;
}

//查找某个数据x，找到了返回下标，没找到返回-1
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps->size > 0);//查找数据要有数据
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//在pos下标位置插入x  包含头插和尾插
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//插入数据要容量检查
	SeqListCheckCapacity(ps);//检查增容
	//1.断言pos >= 0 && pos <= ps->size才能插入
	assert(pos >= 0 && pos <= ps->size);
	//2.把pos及后面的数据往后挪一格
	int end = 0;
	for (end = ps->size; end > pos; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	//3.把x覆盖到pos位置
	ps->arr[end] = x;
	//4.ps->size++
	ps->size++;
}

//删除某个pos下标位置的数据  包含头删和尾删
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size >= 0);
	assert(pos >= 0 && pos < ps->size);
	//1.把pos后面的数据依次向头挪一格，覆盖pos位置。
	int start = 0;
	for (start = pos; start < ps->size-1; start++)
	{
		ps->arr[start] = ps->arr[start + 1];
	}
	//2.ps->size--
	ps->size--;
}