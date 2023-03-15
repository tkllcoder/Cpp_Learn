#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


//静态顺序表，如果满了就不让插入
//缺点：也是在这里

//动态顺序表，可以扩容

typedef int SLDataType;//类型定义

typedef struct SeqList
{
	SLDataType* arr;//指针
	int size;//数组中存储了多少数据 也可以是下一个空位置的下标。
	int capacity;//顺序表容量 动态
}SL;//类型重定义

//接口函数，对数据结构进行操作 用指针，传地址
void SeqListInit(SL* ps);//顺序表初始化
void SeqListCheckCapacity(SL* ps);//检查增容情况

void SeqListPushBack(SL* ps, SLDataType x);//顺序表尾插入
void SeqListPrint(SL* ps);//顺序表打印
void SeqListDestroy(SL* ps);//顺序表退出释放
void SeqListPopBack(SL* ps);//顺序表尾删

void SeqListPushFront(SL* ps, SLDataType x);//顺序表头插
void SeqListPopFront(SL* ps);//顺序表头删
//...取名 STL 命名风格


int SeqListFind(SL* ps, SLDataType x);//查找某个数据x，找到了返回下标，没找到返回-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//在pos下标位置插入x
void SeqListErase(SL* ps, int pos);//删除某个pos下标位置的数据