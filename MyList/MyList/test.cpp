#define _CRT_SECURE_NO_WARNINGS 1
#include"MyList.hpp"

int main() {
	MyList<int> lt;//无参构造
	lt.push_back(1);//尾插
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	lt.push_front(6);//头插
	lt.push_front(7);
	lt.push_front(8);

	lt.pop_back();//尾删
	lt.pop_back();

	lt.pop_front();//头删
	lt.pop_front();

	MyList<int> lt1(lt);//拷贝构造

	MyList<int> lt2 = lt;//赋值运算

	lt.insert(lt.begin(), 9);//插入测试
	lt.insert(lt.end(), 10);

	cout << "size = " << lt.size() << endl;
	cout << "front = " << lt.front() << endl;
	cout << "back = " << lt.back() << endl;
	cout << "empty = " << lt.empty() << endl;

	for (_list_iterator<int> it = lt.begin(); it != lt.end(); ++it) {
		cout << *it << " ";
	}
	cout << endl;
	cout << endl;

	lt.erase(lt.begin());//删除测试
	lt.erase(lt.end());

	lt.clear();//清除测试
	cout << "清理过后: " << endl;
	cout << "empty = " << lt.empty() << endl;


	return 0;
}