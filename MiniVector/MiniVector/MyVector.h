#pragma once
#include<iostream>
#include<algorithm>
#include<numeric>

using namespace std;
#define InitCapacity 8

//创建vector类模板
template<typename T>
class vector {
public:
	typedef T dataType;//把类型换个名字
	typedef T* iterator;//vector中迭代器的含义

public:
	dataType* _data;//vector属性  存放数据的空间
	int _size;//存放数据的数量
	int _capacity;//已开辟空间的大小

public:
	vector();//无参构造函数 初始化
	vector(const vector& vec);//拷贝构造函数
	vector& operator=(const vector& vec)//赋值运算符重载
	{
		//释放原来的空间  深拷贝
		delete[] this->_data;
		//重新拷贝过来
		this->_capacity = vec._capacity;
		this->_data = new dataType[this->_capacity];
		for (int i = 0; i < vec._size; i++) {
			this->_data[i] = vec._data[i];
		}
		this->_size = vec._size;
		return *this;
	}
	bool operator==(const vector& vec)//等号关系运算符重载
	{
		if (this->_size != vec._size)
			return false;
		for (int i = 0; i < vec._size; i++) {
			if (this->_data[i] != vec._data[i])
				return false;
		}
		return true;
	}
	dataType& operator[](size_t i)//[]运算符重载
	{
		return this->_data[i];
	}
	void check_capacity();//检查容量
	void push_back(dataType val);//尾插一个元素val
	void insert(iterator pos, dataType val);//在某个位置插入元素val
	void pop_back();//尾删
	void erase(iterator pos);//删除某一位置元素
	dataType front();//获取头部元素
	dataType back();//获取尾部元素
	iterator begin();//头指针
	iterator end();//尾指针
	int size();//元素个数
	int capacity();//容量大小
	bool empty();//是否为空

	~vector();//析构函数 释放

};
