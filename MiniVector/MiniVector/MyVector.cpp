#define _CRT_SECURE_NO_WARNINGS 1
#include"MyVector.h"

template<typename T>//类模板成员函数类外实现必须要加模板标识
vector<T>::vector() {
	this->_data = NULL;
	this->_size = 0;
	this->_capacity = 0;
}

template<typename T>//且每一个成员函数都要加模板标识 而且在使用时必须再包含.cpp文件
vector<T>::~vector() {
	delete[] this->_data;
	this->_data = NULL;
	this->_capacity = 0;
	this->_size = 0;
}

template<typename T> //拷贝构造函数
vector<T>::vector(const vector& vec) {
	this->_capacity = vec._capacity;
	this->_data = new dataType[this->_capacity];
	for (int i = 0; i < vec._size; i++) {
		this->_data[i] = vec._data[i];
	}
	this->_size = vec._size;
}

template<typename T>
void vector<T>::check_capacity() {//检查容量
	if (0 == this->_capacity) {//最开始的
		this->_capacity = InitCapacity;
		this->_data = new dataType[this->_capacity];
		return;
	}
	if (this->_size == this->_capacity) {//已经填满了
		this->_capacity *= 2;
		dataType* tmp = new dataType[this->_capacity];//创建一个临时的空间存放以前的数据
		for (int i = 0; i < this->_size; i++) {
			tmp[i] = this->_data[i];
		}
		delete[] this->_data;//释放原来的空间
		this->_data = tmp;//现在指向新创建的空间
	}
}

template<typename T>
void vector<T>::push_back(dataType val)//尾插一个元素val  插入需要判断容量
{
	this->check_capacity();//判断容量
	this->_data[this->_size] = val;
	this->_size++;
}

template<typename T>
void vector<T>::insert(iterator pos, dataType val)//在某个位置插入元素val
{
	this->check_capacity();//判断容量
	int index = pos - this->_data;
	for (int i = this->_size - 1; i >= index; i--) {
		this->_data[i + 1] = this->_data[i];
	}
	this->_data[index] = val;
	this->_size++;
}

template<typename T>
void vector<T>::pop_back()//尾删
{
	this->_size--;
}

template<typename T>
void vector<T>::erase(iterator pos)//删除某一位置元素
{
	int index = pos - this->_data;
	for (int i = index; i < this->_size - 1; i++) {
		this->_data[i] = this->_data[i + 1];
	}
	this->_size--;
}

template<typename T>
T vector<T>::front()//获取头部元素
{
	return this->_data[0];
}

template<typename T>
T vector<T>::back()//获取尾部元素
{
	return this->_data[this->_size - 1];
}

template<typename T>
T* vector<T>::begin()//头指针
{
	return this->_data;
}

template<typename T>
T* vector<T>::end()//尾指针
{
	return this->_data + this->_size;
}

template<typename T>
int vector<T>::size()//元素个数
{
	return this->_size;
}

template<typename T>
int vector<T>::capacity()//容量大小
{
	return this->_capacity;
}

template<typename T>
bool vector<T>::empty()//是否为空
{
	return this->_size == 0;
}



