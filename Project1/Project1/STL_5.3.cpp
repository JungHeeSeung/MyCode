//	set 
//	어떻게 내 객체를 정렬해 놓도록 set에 알려주는가?
//	multimap과 multiset에서 equal_range의 사용법을 알아보자
//
//반복자만들기
//컨테이너 만들기
//알고리즘 함수 만들기

#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>							
#include"MemoryMonster.h"

using namespace std;

// set에 정수를 몇 개 넣어 보고 관찰해 보자
// set 의 반복자는 모두 const 다
// cbegin 이나 begin 이나 차이가 없다
// auto i = s.begin();
// *i = 100 은 불가능하다

struct X
{
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

//template <> // template specialization을 하면 가능하다
//struct less<MemoryMonster> {
//	bool operator() (const MemoryMonster& a, const MemoryMonster& b)
//	{
//		return a.getNum() < b.getNum();
//	}
//};



int main()
{
	// 앨리스.txt의 모든 단어를 multiset에 읽어라.

	ifstream in("앨리스.txt");
	multiset<string> words {istream_iterator<string>(in), istream_iterator<string>()};
	multimap<int, string, greater<int>> mm;
	// 단어와 갯수를 출력하라

	vector<pair<string, int>> v;
	v.reserve(words.size());

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		mm.emplace( words.count(*i), *i);

	auto p = mm.begin();
	for (int i = 0; i < 20; ++i, ++p)
	{
		cout << p->second << " -- > " << p->first << endl;
	}
	
	/*sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	for (int i = 0; i < 20; ++i)
	{
		cout << v[i].first << " - " << v[i].second << endl;
	}*/
	// 갯수가 가장 많은 단어부터 20개 출력해보자
}
