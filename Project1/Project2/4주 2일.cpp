//===================================
//
//2019 STL 3.26 ȭ56		(4�� 2��)
//
//	2�� ���� �����̳� (sequence container, (homogeneous data type �� ��´�.))
//	- array : smart �� �迭, []�� �Ϻ��ϰ� ��ġ�Ѵ�.
//	- vector
//	- deque
//	- list
//	- forward_list
//
//===================================

// ���� �����̳����� ������ �ִ� �����̳ʰ� �ƴϴ�.
// ���� include �ؾ� ��� ����

#include<iostream>
#include<vector>
#include"MemoryMonster.h"

using namespace std;


// <> �ȿ��� � �ڷ����̵� ��� �� �� �ִ�.
// vector<> ���ε� �ڷ����̴�??
// ������ �÷��� �Ȱ��� 12byte �� ���´�. 
// ������ �ִ� ������ ����, �޸��� �ּ�, �޸��� ũ�⸦ ������ �ִ�. - 3�� �ؼ� 12byte

// ���Ұ� �þ�� �޸��� ũ�⸦ ���ؼ� �þ�°� �ľ��ϰ� ���ο� ������ �༭ �ڷḦ �ű��.
// �޸𸮰� �þ�� ũ��� ���� ũ���� 1.5��� ��´�.

//int main()
//{
//	vector<MemoryMonster> v {10,20,30,40,50,6};
//	
//	while (true)
//	{
//
//	cout << "���� ���� ����		- " << v.size() << endl;
//	cout << "���� �� �ִ� ����	- " << v.capacity() << endl;
//	cout << "Ȯ���� �޸� ��ġ	- " << v.data() << endl<<endl;
//	
//	//cout << sizeof(v) << endl;
//
//	char c;
//	cin >> c;
//	v.push_back(1);
//
//	}
//
//}




//===================================

// MemoryMonster 20���� ����� vector�� �־��
// �ʱⰪ�� uid(10,70)�� ������
// vector�� .gerNum() ������������ �����Ͽ���
// ����� ȭ�� ����Ѵ�.

//===================================

#include<random>
#include<algorithm>
int main()
{
	uniform_int_distribution<> uid(10, 70);
	default_random_engine dre;

	vector<MemoryMonster> v;
	v.reserve(20);	// ������ �̸� �����ϴ� �Լ� *******************

	// ������ ��Ҵٰ� �̵��ߴٰ��� �ݺ��ؼ� ���� �ʴ�.
	for (size_t i = 0; i < 20; ++i)
		v.push_back(uid(dre));

	cout << "���� ���� ����		- " << v.size() << endl;
	cout << "���� �� �ִ� ����	- " << v.capacity() << endl;
	cout << "Ȯ���� �޸� ��ġ	- " << v.data() << endl << endl;

	sort(v.begin(), v.end(),[](const MemoryMonster& a, const MemoryMonster& b ){
		return a.getNum() < b.getNum();
	});

	//for (auto i = v.begin(); i != v.end(); ++i)
	//	cout <<  *i << endl;

	for (const MemoryMonster& a : v)
		cout << a << endl;
}