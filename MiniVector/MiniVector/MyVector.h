#pragma once
#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;
#define InitCapacity 8

//����vector��ģ��
template<typename T>
class vector {
public:
	typedef T dataType;//�����ͻ�������
	typedef T* iterator;//vector�е������ĺ���

public:
	dataType* _data;//vector����  ������ݵĿռ�
	int _size;//������ݵ�����
	int _capacity;//�ѿ��ٿռ�Ĵ�С

public:
	vector();//�޲ι��캯�� ��ʼ��
	vector(const vector& vec);//�������캯��
	vector& operator=(const vector& vec)//��ֵ���������
	{
		//�ͷ�ԭ���Ŀռ�  ���
		delete[] this->_data;
		//���¿�������
		this->_capacity = vec._capacity;
		this->_data = new dataType[this->_capacity];
		for (int i = 0; i < vec._size; i++) {
			this->_data[i] = vec._data[i];
		}
		this->_size = vec._size;
		return *this;
	}
	bool operator==(const vector& vec)//�ȺŹ�ϵ���������
	{
		if (this->_size != vec._size)
			return false;
		for (int i = 0; i < vec._size; i++) {
			if (this->_data[i] != vec._data[i])
				return false;
		}
		return true;
	}
	dataType& operator[](size_t i)//[]���������
	{
		return this->_data[i];
	}
	void check_capacity();//�������
	void push_back(dataType val);//β��һ��Ԫ��val
	void insert(iterator pos, dataType val);//��ĳ��λ�ò���Ԫ��val
	void pop_back();//βɾ
	void erase(iterator pos);//ɾ��ĳһλ��Ԫ��
	dataType front();//��ȡͷ��Ԫ��
	dataType back();//��ȡβ��Ԫ��
	iterator begin();//ͷָ��
	iterator end();//βָ��
	int size();//Ԫ�ظ���
	int capacity();//������С
	bool empty();//�Ƿ�Ϊ��

	~vector();//�������� �ͷ�

};
