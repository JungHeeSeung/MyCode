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
//	// merge는 정렬된 list일 때 의미있는 동작임
//	monsters1.sort([](const MemoryMonster& a, const MemoryMonster& b) {
//		return a.get() < b.get();
//	});
//	monsters2.sort([](const MemoryMonster& a, const MemoryMonster& b) {
//		return a.get() < b.get();
//	});
//
//	// monsters1과 2를 merge해서 그 결과는 monsters1에 저장하라
//
//	/*밑에처럼 쓰지마라
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
//	// 중복된 원소는 삭제하자 - unique
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

// copy로 container에 원소를 읽어오기 - 반복자 어댑터
// "소스.cpp"에 있는 단어를 읽어
// 길이 순으로 정렬한다.	(정렬은 특별한 언급이 없으면 오름차순이다.)
// 길이가 4인 단어는 따로 빼서 "길이4.txt" 파일에 저장한다
// *** 단어는 문자들의 집합 / 공백으로 구분

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
		cout << "그럴리가 없는데" << endl;

	/*for (auto i = pos4; i != pos5; ++i)
		cout << *i << endl;*/

	list<string> words_4;
	words_4.splice(words_4.begin(), words, pos4, pos5);

	ofstream out("길이4.txt");

	// copy 넌 머냐 정체를 밝혀라
	copy(words_4.begin(), words_4.end(), ostream_iterator<string>(out, " >\n< "));
}