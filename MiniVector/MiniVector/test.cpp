#define _CRT_SECURE_NO_WARNINGS 1
#include"MyVector.h"
#include"MyVector.cpp"

int main() {
	vector<string> vec;//�޲ι���
	vec.push_back(string("xiaoming"));//β��
	vec.push_back(string("xiojun"));
	vec.push_back(string("xiaomei"));
	vec.push_back(string("xiaoxin"));

	vector<string> vec1(vec);//��������
	if (vec == vec1) {//����==�����
		cout << "vec vec1����˳������" << endl;
	}
	vector<string> vec2 = vec;//����=�����
	if (vec1 == vec2) {
		cout << "vec1 vec2����˳������" << endl;
	}
	cout << "Ԫ��Ϊvec[1] = " << vec[1] << endl;//����[]�����

	vec.insert(vec._data, string("xiaofang"));//ĳ��λ�ò��룬����������

	vec.pop_back();//βɾ
	vec.pop_back();

	vec.erase(vec._data);//ɾ��Ԫ��

	cout << "��һ��Ԫ��Ϊ��" << vec.front() << endl;
	vec.push_back(string("xiaocao"));
	vec.push_back(string("xiaotang"));
	cout << "���һ����Ԫ��Ϊ��" << vec.back() << endl;
	cout << "Ԫ�ظ���Ϊ��" << vec.size() << endl;
	cout << "�ռ�����Ϊ��" << vec.capacity() << endl;
	cout << "�Ƿ�Ϊ�գ�" << vec.empty() << endl;
	cout << "��������˳���************************" << endl;
	for (vector<string>::iterator it = vec.begin(); it != vec.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;

	return 0;
}