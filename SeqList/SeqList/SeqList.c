#define _CRT_SECURE_NO_WARNINGS 1
#include"SeqList.h"

//˳����ʼ��
void SeqListInit(SL* ps)
{
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//����������
void SeqListCheckCapacity(SL* ps)
{
	//û�п��ٿռ���߿ռ�����
	if (ps->size == ps->capacity)
	{
		//�¿ռ�Ĵ�С��������ο������ĸ������������������
		int newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(ps->arr, newcapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			printf("realloc fail!!\n");
			exit(-1);//�쳣�˳�
		}
		ps->arr = tmp;
		ps->capacity = newcapacity;
	}
}

//˳���β���������� ��������
void SeqListPushBack(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);//�������
	ps->arr[ps->size] = x;
	ps->size++;
}

//˳����ӡ
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

//˳����˳��ͷ�
void SeqListDestroy(SL* ps)
{
	free(ps->arr);
	ps->arr = NULL;
	ps->size = ps->capacity = 0;
}

//˳���βɾ ɾ��0
void SeqListPopBack(SL* ps)
{
	//����1 ע��size����С��0�����������Ƿ�����
	//if (ps->size > 0)
	//{
	//	ps->size--;//˳�����size���Ա�ʾ���е����ݣ���1��ʾɾ����������

	//}
	//else
	//{
	//	ps->size = 0;
	//}

	//����2
	assert(ps->size > 0);
	ps->size--;
}

//˳���ͷ��
void SeqListPushFront(SL* ps, SLDataType x)
{
	SeqListCheckCapacity(ps);//�������

	//1.�Ѻ�����������Ųһ��
	for (int i = ps->size; i > 0; i--)
	{
		ps->arr[i] = ps->arr[i - 1];
	}
	//2.��Ҫ��������ݷŵ���һ��λ��
	ps->arr[0] = x;
	//3.size++
	ps->size++;
}

//˳���ͷɾ
void SeqListPopFront(SL* ps)
{
	//ɾ������Ҫ���Ƿ�ɾ��
	assert(ps->size > 0);
	//1.�Ѻ����������ǰ����һ�� 
	for (int i = 0; i < ps->size; i++)
	{
		ps->arr[i] = ps->arr[i + 1];
	}
	//2.size--
	ps->size--;
}

//����ĳ������x���ҵ��˷����±꣬û�ҵ�����-1
int SeqListFind(SL* ps, SLDataType x)
{
	assert(ps->size > 0);//��������Ҫ������
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->arr[i] == x)
		{
			return i;
		}
	}
	return -1;
}

//��pos�±�λ�ò���x  ����ͷ���β��
void SeqListInsert(SL* ps, int pos, SLDataType x)
{
	//��������Ҫ�������
	SeqListCheckCapacity(ps);//�������
	//1.����pos >= 0 && pos <= ps->size���ܲ���
	assert(pos >= 0 && pos <= ps->size);
	//2.��pos���������������Ųһ��
	int end = 0;
	for (end = ps->size; end > pos; end--)
	{
		ps->arr[end] = ps->arr[end - 1];
	}
	//3.��x���ǵ�posλ��
	ps->arr[end] = x;
	//4.ps->size++
	ps->size++;
}

//ɾ��ĳ��pos�±�λ�õ�����  ����ͷɾ��βɾ
void SeqListErase(SL* ps, int pos)
{
	assert(ps->size >= 0);
	assert(pos >= 0 && pos < ps->size);
	//1.��pos���������������ͷŲһ�񣬸���posλ�á�
	int start = 0;
	for (start = pos; start < ps->size-1; start++)
	{
		ps->arr[start] = ps->arr[start + 1];
	}
	//2.ps->size--
	ps->size--;
}