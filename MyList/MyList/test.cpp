#define _CRT_SECURE_NO_WARNINGS 1
#include"MyList.hpp"

int main() {
	MyList<int> lt;//�޲ι���
	lt.push_back(1);//β��
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	lt.push_front(6);//ͷ��
	lt.push_front(7);
	lt.push_front(8);

	lt.pop_back();//βɾ
	lt.pop_back();

	lt.pop_front();//ͷɾ
	lt.pop_front();

	MyList<int> lt1(lt);//��������

	MyList<int> lt2 = lt;//��ֵ����

	lt.insert(lt.begin(), 9);//�������
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

	lt.erase(lt.begin());//ɾ������
	lt.erase(lt.end());

	lt.clear();//�������
	cout << "�������: " << endl;
	cout << "empty = " << lt.empty() << endl;


	return 0;
}