#define _CRT_SECURE_NO_WARNINGS 1
#include"MyVector.h"
#include"MyVector.cpp"

int main() {
	vector<string> vec;//无参构造
	vec.push_back(string("xiaoming"));//尾插
	vec.push_back(string("xiojun"));
	vec.push_back(string("xiaomei"));
	vec.push_back(string("xiaoxin"));

	vector<string> vec1(vec);//拷贝构造
	if (vec == vec1) {//重载==运算符
		cout << "vec vec1两个顺序表相等" << endl;
	}
	vector<string> vec2 = vec;//重载=运算符
	if (vec1 == vec2) {
		cout << "vec1 vec2两个顺序表相等" << endl;
	}
	cout << "元素为vec[1] = " << vec[1] << endl;//重载[]运算符

	vec.insert(vec._data, string("xiaofang"));//某个位置插入，迭代器传参

	vec.pop_back();//尾删
	vec.pop_back();

	vec.erase(vec._data);//删除元素

	cout << "第一个元素为：" << vec.front() << endl;
	vec.push_back(string("xiaocao"));
	vec.push_back(string("xiaotang"));
	cout << "最后一个个元素为：" << vec.back() << endl;
	cout << "元素个数为：" << vec.size() << endl;
	cout << "空间容量为：" << vec.capacity() << endl;
	cout << "是否为空：" << vec.empty() << endl;
	cout << "遍历整个顺序表************************" << endl;
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}