#include<iostream>
#include<vector>
#include<algorithm>
#include"MemoryMonster.h"
using namespace std;

//������ ���Ұ� �߰��� ��������
// ������ ���Ҹ� ���ﶧ
int main()
{
	vector<MemoryMonster> v;
	v.reserve(10);

	v.emplace_back(10);
	v.emplace_back(30);
	v.emplace_back(40);

	//for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;

	//cout << "�߰��� 20�� �ֱ� ��" << endl;
	////10�� 30 ���̿� 20�� ������.
	//v.emplace(v.begin() + 1, 20);
	//cout << "�߰��� 20�� ���� ��" << endl;

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	cout << "20���ڸ� �����ϱ� ��" << endl;
	//20���ڸ� ��������
	remove(v.begin(), v.end(), 20);		//�� ������δ� ���ͳ��� ���Ҹ� ����� �ǰ� �޸𸮴� ���� �� ����.

	//// �̷��� �ϸ� ���� ������ �ذ� �����ϴ�.
	//// erase - remove idiom
	//auto p = remove(v.begin(), v.end(), 20);
	//v.erase(p, v.end()-1);

	cout << "20���ڸ� �����ϱ� ��" << endl;


	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;


}