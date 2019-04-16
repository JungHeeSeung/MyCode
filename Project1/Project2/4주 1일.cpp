//===================================
//
//2019 STL 3.26 ȭ56		(4�� 1��)
//
//	2�� ���� �����̳�
//	- array : smart �� �迭
//	- vector : 
//	- deque
//	- list
//	- forward_list
//
//===================================

// ���� �����̳����� ������ �ִ� �����̳ʰ� �ƴϴ�.
// ���� include �ؾ� ��� ����

#include<iostream>
#include<array>

#include"MemoryMonster.h"

using namespace std;

//int main()
//{
//	array<int, 5> a {1,2,3,4,5};	//[][][][][]	
//	//���� - ����� �˷��� �ʿ䰡 ����?, �������� ������� �ľ� �� �� �ִ�.
//	//���� - �׳� ���� �� �׷��� ���� ����.
//
//	//a[-100]; // debug������ �ɸ����� release ������ �ƹ��� ���� ��������.
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << endl;
//	}
//
//	int num;
//	cout << "����� ���� ���ϳ�?";
//	cin >> num;
//	
//	
//	try {
//		cout << a.at(num) << endl;
//	}
//	catch(exception& e){
//		cout << e.what() << endl;
//	}
//
//}

#include<algorithm>


int main()
{
	array<MemoryMonster, 5> a {10,3,30,7,20};

	//for (auto p = begin(a); p != end(a); ++p)
	//{
	//	cout << *p << endl;
	//}


	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
	cout << "-===========���ĺ�=============-" << endl;
	// a�� �� ���Ҹ� ������������ �����غ��ÿ�


	//char *p = a[0].getData();
	//sort(p, p + a[0].getNum());

	for (int i = 0; i < a.size(); ++i)
		sort(a[i].getData(), a[i].getData() + a[i].getNum());

	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;

}