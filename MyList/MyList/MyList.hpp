#pragma once
#include<iostream>

using namespace std;

//类模板的使用，需要将函数声明和实现写在一个文件中，
//并且文件后缀改为.hpp，在使用时包含头文件。

/////////////C++实现list  带头双向循环链表////////////////////

////节点模板
template<class T>
class ListNode {
public:
	ListNode<T>* _prev;
	T _val;
	ListNode<T>* _next;

	ListNode(const T& val) : _prev(nullptr), _val(val), _next(nullptr){}
};

/////list迭代器的定义，并不只是简单的类型指针，它的下一位置是_next
template<class T>
struct _list_iterator//参数模板Ref，指针模板Ptr
{
	typedef _list_iterator <T> self;
	typedef ListNode<T> Node;

	Node* _node;

	//构造函数
	_list_iterator(Node* node)
		:_node(node)
	{}
	//重载解引用
	T operator*()
	{
		return _node->_val;
	}
	//重载++和--
	self operator++()
	{
		this->_node = this->_node->_next;
		return *this;
	}
	self operator--()
	{
		this->_node = this->_node->_prev;
		return *this;
	}
	//重载==和！=
	bool operator==(const self& it) const {
		return _node == it._node;
	}

	bool operator!=(const self& it) const {
		return _node != it._node;
	}
};

///list模板类的实现 维护一个头节点指针，且头仅做连接作用，不存数据
template<class T>
class MyList {
	typedef ListNode<T> Node;
	typedef _list_iterator<T> list_iterator;
private:
	Node* _head;
public:
	//无参构造
	MyList() {//带头节点的，不实际用
		_head = new Node(0);
		_head->_next = _head;
		_head->_prev = _head;
	}
	//拷贝构造
	MyList(MyList<T>& Lt) {
		_head = new Node(0);
		_head->_next = _head;
		_head->_prev = _head;
		Node* cur = Lt._head->_next;
		while (cur != Lt._head) {
			this->push_back(cur->_val);
			cur = cur->_next;
		}
	}
	//重载赋值
	MyList<T>& operator=(MyList<T>& Lt) {
		this->_head = Lt._head;
		return *this;
	}
	
	//成员函数
	void push_back(T val);
	void push_front(T val);
	void pop_back();
	void pop_front();
	void insert(list_iterator pos, T val);
	void erase(list_iterator pos);
	int size();
	bool empty();
	T front();//获取头部元素
	T back();//获取尾部元素
	void clear();//清除除了头节点以外的所有节点

	//迭代器iterator的模拟  头尾的迭代器
	list_iterator begin() {//在前一个位置插入节点insert 头插和尾插
		return _head->_next;//实际的头位置
	}
	list_iterator end() {
		return _head;//尾的下一个位置是头
	}

	//析构函数
	~MyList() {
		this->clear();//释放其他节点
		delete _head;//释放头节点
		_head = NULL;
	}
};

template<class T>
void MyList<T>::push_back(T val) {
	//Node* tail = _head->_prev;
	//Node* new_node = new Node(val);

	//tail->_next = new_node;
	//new_node->_prev = tail;
	//new_node->_next = _head;
	//_head->_prev = new_node;

	this->insert(this->end(), val);
}

template<class T>
void MyList<T>::push_front(T val) {
	//Node* next = _head->_next;
	//Node* new_node = new Node(val);

	//new_node->_next = next;
	//next->_prev = new_node;
	//new_node->_prev = _head;
	//_head->_next = new_node;
	this->insert(this->begin(), val);
}

template<class T>
void MyList<T>::pop_back() {
	/*if (_head->_next == _head) {
		cout << "已经删除完毕了，不能再删了！！" << endl;
		return;
	}
	Node* tail = _head->_prev;
	Node* tailprev = tail->_prev;
	delete tail;
	tail = NULL;
	tailprev->_next = _head;
	_head->_prev = tailprev;*/
	this->erase(this->end());
}

template<class T>
void MyList<T>::pop_front() {
	/*if (_head->_next == _head) {
		cout << "已经删除完毕了，不能再删了！！" << endl;
		return;
	}
	Node* front = _head->_next;
	Node* next = front->_next;
	delete front;
	_head->_next = next;
	next->_prev = _head;*/
	this->erase(this->begin());
}

template<class T>
void MyList<T>::insert(list_iterator pos, T val) {
	Node* prev = pos._node->_prev;
	Node* new_node = new Node(val);
	prev->_next = new_node;
	new_node->_prev = prev;
	new_node->_next = pos._node;
	pos._node->_prev = new_node;
}

template<class T>
void MyList<T>::erase(list_iterator pos) {
	if (_head->_next == _head) {
		cout << "已经删除完毕了，不能再删了！！" << endl;
		return;
	}
	if (pos._node == _head) {//防止删除头部
		Node* prev = pos._node->_prev;
		Node* pprev = prev->_prev;
		pprev->_next = _head;
		_head->_prev = pprev;
		return;
	}
	Node* prev = pos._node->_prev;
	Node* next = pos._node->_next;
	prev->_next = next;
	next->_prev = prev;
	delete pos._node;
}

template<class T>
int MyList<T>::size() {
	int count = 0;
	Node* cur = _head->_next;
	while (cur != _head) {
		count++;
		cur = cur->_next;
	}
	return count;
}

template<class T>
bool MyList<T>::empty() {
	return this->size() == 0;
}

template<class T>
T MyList<T>::front() {
	return _head->_next->_val;
}

template<class T>
T MyList<T>::back() {
	return _head->_prev->_val;
}

template<class T>
void MyList<T>::clear() {
	//释放除了头节点以外的全部节点
	while (_head->_next != _head) {
		this->erase(this->begin());
	}
}

