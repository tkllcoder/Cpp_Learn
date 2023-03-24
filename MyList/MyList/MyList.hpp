#pragma once
#include<iostream>

using namespace std;

//��ģ���ʹ�ã���Ҫ������������ʵ��д��һ���ļ��У�
//�����ļ���׺��Ϊ.hpp����ʹ��ʱ����ͷ�ļ���

/////////////C++ʵ��list  ��ͷ˫��ѭ������////////////////////

////�ڵ�ģ��
template<class T>
class ListNode {
public:
	ListNode<T>* _prev;
	T _val;
	ListNode<T>* _next;

	ListNode(const T& val) : _prev(nullptr), _val(val), _next(nullptr){}
};

/////list�������Ķ��壬����ֻ�Ǽ򵥵�����ָ�룬������һλ����_next
template<class T>
struct _list_iterator//����ģ��Ref��ָ��ģ��Ptr
{
	typedef _list_iterator <T> self;
	typedef ListNode<T> Node;

	Node* _node;

	//���캯��
	_list_iterator(Node* node)
		:_node(node)
	{}
	//���ؽ�����
	T operator*()
	{
		return _node->_val;
	}
	//����++��--
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
	//����==�ͣ�=
	bool operator==(const self& it) const {
		return _node == it._node;
	}

	bool operator!=(const self& it) const {
		return _node != it._node;
	}
};

///listģ�����ʵ�� ά��һ��ͷ�ڵ�ָ�룬��ͷ�����������ã���������
template<class T>
class MyList {
	typedef ListNode<T> Node;
	typedef _list_iterator<T> list_iterator;
private:
	Node* _head;
public:
	//�޲ι���
	MyList() {//��ͷ�ڵ�ģ���ʵ����
		_head = new Node(0);
		_head->_next = _head;
		_head->_prev = _head;
	}
	//��������
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
	//���ظ�ֵ
	MyList<T>& operator=(MyList<T>& Lt) {
		this->_head = Lt._head;
		return *this;
	}
	
	//��Ա����
	void push_back(T val);
	void push_front(T val);
	void pop_back();
	void pop_front();
	void insert(list_iterator pos, T val);
	void erase(list_iterator pos);
	int size();
	bool empty();
	T front();//��ȡͷ��Ԫ��
	T back();//��ȡβ��Ԫ��
	void clear();//�������ͷ�ڵ���������нڵ�

	//������iterator��ģ��  ͷβ�ĵ�����
	list_iterator begin() {//��ǰһ��λ�ò���ڵ�insert ͷ���β��
		return _head->_next;//ʵ�ʵ�ͷλ��
	}
	list_iterator end() {
		return _head;//β����һ��λ����ͷ
	}

	//��������
	~MyList() {
		this->clear();//�ͷ������ڵ�
		delete _head;//�ͷ�ͷ�ڵ�
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
		cout << "�Ѿ�ɾ������ˣ�������ɾ�ˣ���" << endl;
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
		cout << "�Ѿ�ɾ������ˣ�������ɾ�ˣ���" << endl;
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
		cout << "�Ѿ�ɾ������ˣ�������ɾ�ˣ���" << endl;
		return;
	}
	if (pos._node == _head) {//��ֹɾ��ͷ��
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
	//�ͷų���ͷ�ڵ������ȫ���ڵ�
	while (_head->_next != _head) {
		this->erase(this->begin());
	}
}

