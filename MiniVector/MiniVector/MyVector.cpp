#define _CRT_SECURE_NO_WARNINGS 1
#include"MyVector.h"

template<typename T>//��ģ���Ա��������ʵ�ֱ���Ҫ��ģ���ʶ
vector<T>::vector() {
	this->_data = NULL;
	this->_size = 0;
	this->_capacity = 0;
}

template<typename T>//��ÿһ����Ա������Ҫ��ģ���ʶ ������ʹ��ʱ�����ٰ���.cpp�ļ�
vector<T>::~vector() {
	delete[] this->_data;
	this->_data = NULL;
	this->_capacity = 0;
	this->_size = 0;
}

template<typename T> //�������캯��
vector<T>::vector(const vector& vec) {
	this->_capacity = vec._capacity;
	this->_data = new dataType[this->_capacity];
	for (int i = 0; i < vec._size; i++) {
		this->_data[i] = vec._data[i];
	}
	this->_size = vec._size;
}

template<typename T>
void vector<T>::check_capacity() {//�������
	if (0 == this->_capacity) {//�ʼ��
		this->_capacity = InitCapacity;
		this->_data = new dataType[this->_capacity];
		return;
	}
	if (this->_size == this->_capacity) {//�Ѿ�������
		this->_capacity *= 2;
		dataType* tmp = new dataType[this->_capacity];//����һ����ʱ�Ŀռ�����ǰ������
		for (int i = 0; i < this->_size; i++) {
			tmp[i] = this->_data[i];
		}
		delete[] this->_data;//�ͷ�ԭ���Ŀռ�
		this->_data = tmp;//����ָ���´����Ŀռ�
	}
}

template<typename T>
void vector<T>::push_back(dataType val)//β��һ��Ԫ��val  ������Ҫ�ж�����
{
	this->check_capacity();//�ж�����
	this->_data[this->_size] = val;
	this->_size++;
}

template<typename T>
void vector<T>::insert(iterator pos, dataType val)//��ĳ��λ�ò���Ԫ��val
{
	this->check_capacity();//�ж�����
	int index = pos - this->_data;
	for (int i = this->_size - 1; i >= index; i--) {
		this->_data[i + 1] = this->_data[i];
	}
	this->_data[index] = val;
	this->_size++;
}

template<typename T>
void vector<T>::pop_back()//βɾ
{
	this->_size--;
}

template<typename T>
void vector<T>::erase(iterator pos)//ɾ��ĳһλ��Ԫ��
{
	int index = pos - this->_data;
	for (int i = index; i < this->_size - 1; i++) {
		this->_data[i] = this->_data[i + 1];
	}
	this->_size--;
}

template<typename T>
T vector<T>::front()//��ȡͷ��Ԫ��
{
	return this->_data[0];
}

template<typename T>
T vector<T>::back()//��ȡβ��Ԫ��
{
	return this->_data[this->_size - 1];
}

template<typename T>
T* vector<T>::begin()//ͷָ��
{
	return this->_data;
}

template<typename T>
T* vector<T>::end()//βָ��
{
	return this->_data + this->_size;
}

template<typename T>
int vector<T>::size()//Ԫ�ظ���
{
	return this->_size;
}

template<typename T>
int vector<T>::capacity()//������С
{
	return this->_capacity;
}

template<typename T>
bool vector<T>::empty()//�Ƿ�Ϊ��
{
	return this->_size == 0;
}



