//#include <iostream>
//#include <list>
//#include <string>
//#include <algorithm>
//#include "MemoryMonster.h"
//
//using namespace std;
//
//// 
//
//int main()
//{
//	list<MemoryMonster> monsters1{ 9, 3, 1, 7, 5, 1, 1, 1, 1 };
//	list<MemoryMonster> monsters2{ 6, 2, 8, 4, 10, 4, 4, 4, 4, 4};
//	
//	// merge�� ���ĵ� list�� �� �ǹ��ִ� ������
//	monsters1.sort([](const MemoryMonster& a, const MemoryMonster& b) {
//		return a.get() < b.get();
//	});
//	monsters2.sort([](const MemoryMonster& a, const MemoryMonster& b) {
//		return a.get() < b.get();
//	});
//
//	// monsters1�� 2�� merge�ؼ� �� ����� monsters1�� �����϶�
//
//	/*�ؿ�ó�� ��������
//	auto p = remove_if(monsters.begin(), monsters.end(), [](const MemoryMonster a) {
//		return a.get() < 10;
//	});
//	monsters.erase(p, monsters.end());*/
//
//	/*monsters.remove_if([](const MemoryMonster& a) {
//		return a.get() < 10;
//	});*/
//
//
//	monsters1.merge( monsters2 );
//
//
//
//	// �ߺ��� ���Ҵ� �������� - unique
//	cout << "----------------------------------------------------------" << endl;
//
//	for (MemoryMonster & d : monsters1)
//	{
//		cout << d << endl;
//	}
//
//	for (MemoryMonster & d : monsters2)
//	{
//		cout << d << endl;
//	}
//	cout << "---------------------------------------------------------" << endl;
//}

#include <iostream>
#include <fstream>
#include <algorithm>
#include <list>
#include <iterator>
#include <string>

using namespace std;

// copy�� container�� ���Ҹ� �о���� - �ݺ��� �����
// "�ҽ�.cpp"�� �ִ� �ܾ �о�
// ���� ������ �����Ѵ�.	(������ Ư���� ����� ������ ���������̴�.)
// ���̰� 4�� �ܾ�� ���� ���� "����4.txt" ���Ͽ� �����Ѵ�
// *** �ܾ�� ���ڵ��� ���� / �������� ����

int main()
{
	ifstream in("STL_4.12.cpp");

	list<string> words;
	istream_iterator<string> p(in);

	while (p != istream_iterator<string>())
	{
		words.emplace(words.begin(), *p++);
	}

	words.sort([](const string& a, const string& b) {
		return a.length() < b.length();
	});

	auto pos4 = find_if(words.begin(), words.end(), [](const string& a) {
		return a.size() == 4;
	});

	auto pos5 = find_if(words.begin(), words.end(), [](const string& a) {
		return a.size() == 5;
	});

	if (pos4 == words.end())
		cout << "�׷����� ���µ�" << endl;

	/*for (auto i = pos4; i != pos5; ++i)
		cout << *i << endl;*/

	list<string> words_4;
	words_4.splice(words_4.begin(), words, pos4, pos5);

	ofstream out("����4.txt");

	// copy �� �ӳ� ��ü�� ������
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, " >\n< "));
}