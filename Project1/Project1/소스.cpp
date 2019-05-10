//#include <iostream>
//#include <unordered_map>
//#include <string>
//#include <map>
//#include <initializer_list>
//#include <algorithm>
//#include <vector>
//#include "MemoryMonster.h"
//
//using namespace std;
//
////-----------------------------------------------------------------------------------
//// �����̳��� ����
//// �ݺ����� ����
//// ���� 3���� �� ������ �ſ� �߿��ϴ�
//// �� �о��
//// 
//// Associative Containner (���� �����̳�)
////		map - dictionary <ket, value> ���� ����	O(log n)
////		set - <key>�� ����
////
//// Unordered Associative Container (�������� ���� �����̳�, Hash) O(1)
////		unordered_map
////		unordered_set
////		�޸𸮸� ����ϰ� ã�� �ð��� �ش������� ���̷��� �����
////-----------------------------------------------------------------------------------
//
////class Dog {
////	string name;
////
////public:
////	Dog(string f_name) : name(f_name) {}
////
////	string getName() const
////	{
////		return name;
////	}
////
////	bool operator==(const Dog& rhs) const
////	{
////		return name == rhs.name;
////	}
////};
////
////template<>
////struct hash<Dog>
////{
////	int operator()(const Dog& d) const {
////		return hash<string>() ( d.getName() );
////	}
////};
////
////int main()
////{
////	// �� ������ �����ϱ� ���� �� ���� ����� ����
////	// vector<Dog> v{ "����", "����", "����" };
////	
////	// 1��
////	// {}�� initializer_list<string> names{ "����", "����", "����" }; �� �ǹ���
////	// vector<Dog> v( names.begin(), names.end() );
////	
////	// 2�� Ŭ���� �����ڸ� ���ø����� ��������
////	//vector<Dog> v{ "����", "����", "����" };
////
////	// 3�� 
////	// 	vector<Dog> v{ string("����")}; ó�� ��������� ��������
////
////	unordered_map<Dog, int, hash<Dog>> m;
////	m.emplace("����", 1);
////	m.emplace("����", 2);
////	m.emplace("����", 3);
////
////	// "����"��� �̸��� ���� Unordered Map m �� �ִ��� ã�ƺ���
////	m[Dog("����")] = 100;
////	auto p = m.find( Dog("����") );
////	if (p != m.end())
////		cout << "found" << " ---> " << p->second << endl;
////	else
////		cout << "not found" << endl;
////}

#include <iostream>
#include <map>
#include <unordered_map>
#include <random>
#include <vector>
#include <chrono>
#include "MemoryMonster.h"

using namespace std;
using namespace std::chrono;

// ���� 1000������ unordered_map�� map�� �����Ѵ�
// ������ ���� 100������ �����̳ʿ� �ִ��� ã�ƺ���.
// ���� �ɸ��� �ð��� �����Ѵ�.

int main()
{
	map<int, int> m;

	default_random_engine dre;
	uniform_int_distribution<> uid;

	int i{};

	while(m.size() != 1000'0000)
		m.emplace(uid(dre), ++i);
	
	cout << "�� ������� ??? --> "  << m.size() << endl;

	// map�� ���Ҹ� �״�� unordered_map�� �ִ´�.
	unordered_map<int, int> um{ m.begin(), m.end(), 1000'0000 };
	cout << "������� �� ���� - " << um.size() << endl;
	
	// ã�ƺ� �� 100������ vector�� ����
	cout << "���Ϳ� �ε��� 100������ �����Ѵ�" << endl;
	vector<int> v;
	v.reserve(100'0000);
	for (int i = 0; i < 100'0000; ++i)
		v.push_back(uid(dre));

	{
		cout << "������ ���� 100������ �ʿ��� ã�� ����" << endl;
		auto b = steady_clock::now();
		for (int i = 0; i < 100'0000; ++i)
			m.find( v[i] );
		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();
		cout << "�ɸ� �ð� ---> " << d << endl;
	}
	
	{
		cout << "������ ���� 100������ ������� �ʿ��� ã�� ����" << endl;
		auto b = steady_clock::now();
		for (int i = 0; i < 100'0000; ++i)
			um.find( v[i] );
		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();
		cout << "�ɸ� �ð� ---> " << d << endl;
	}
}

	
