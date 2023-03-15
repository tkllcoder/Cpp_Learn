#pragma once
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>


//��̬˳���������˾Ͳ��ò���
//ȱ�㣺Ҳ��������

//��̬˳�����������

typedef int SLDataType;//���Ͷ���

typedef struct SeqList
{
	SLDataType* arr;//ָ��
	int size;//�����д洢�˶������� Ҳ��������һ����λ�õ��±ꡣ
	int capacity;//˳������� ��̬
}SL;//�����ض���

//�ӿں����������ݽṹ���в��� ��ָ�룬����ַ
void SeqListInit(SL* ps);//˳����ʼ��
void SeqListCheckCapacity(SL* ps);//����������

void SeqListPushBack(SL* ps, SLDataType x);//˳���β����
void SeqListPrint(SL* ps);//˳����ӡ
void SeqListDestroy(SL* ps);//˳����˳��ͷ�
void SeqListPopBack(SL* ps);//˳���βɾ

void SeqListPushFront(SL* ps, SLDataType x);//˳���ͷ��
void SeqListPopFront(SL* ps);//˳���ͷɾ
//...ȡ�� STL �������


int SeqListFind(SL* ps, SLDataType x);//����ĳ������x���ҵ��˷����±꣬û�ҵ�����-1
void SeqListInsert(SL* ps, int pos, SLDataType x);//��pos�±�λ�ò���x
void SeqListErase(SL* ps, int pos);//ɾ��ĳ��pos�±�λ�õ�����