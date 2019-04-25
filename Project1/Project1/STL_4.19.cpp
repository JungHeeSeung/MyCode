//-----------------------------------------------------------------------------------
// 컨테이너의 정의
// 반복자의 정의
// 교재 3장의 힙 내용은 매우 중요하다
// 꼭 읽어보자
// 
// Associative Containner (연관 컨테이너)
//		map - dictionary <ket, value> 쌍이 원소
//		set - <key>가 원소
//
// Unordered Associative Container (순서없는 연관 컨테이너, Hash)
//		unordered_map
//		unordered_set
//		메모리를 희생하고 찾는 시간을 극단적으로 줄이려고 노력함
//-----------------------------------------------------------------------------------

//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <iterator>
//#include <string>
//#include "MemoryMonster.h"
//
//using namespace std;
//
//// 아이돌그룹의 이름과 멤버 수
//// 맵에 입력하고 출력해보자
//int main()
//{
//	map<string, int> idols;		// map은 tree 이기 때문에 push_back 같은 위치에
//	// operator<() 가 3번째 인자로 숨어 있음 // 원소를 넣는 행위는 허용하지 않음
//	idols.insert(pair<string, int>("핑크레이디", 5));
//	idols.insert(make_pair("있지", 5));
//	idols.insert(make_pair("아이즈원", 12));
//	idols.insert(make_pair("워너원", 11));
//	idols.insert(make_pair("모모랜드", 9));
//	idols.insert(make_pair("블랙핑크", 4));
//	idols.insert(make_pair("트와이스", 9));
//	idols.insert(make_pair("세븐틴", 13));
//	idols.insert(make_pair("방탄소년단", 7));
//
//	// 맵은 원소를 빨리 찾기  ( O(log n)) 위한 컨테이너이다
//	// 사용자가 원하느느 그룹의 인원수를 출력하는 프로그램을 작성하라
//
//	cout << idols["방탄소년단"];		// Associative Array 처럼 사용 가능
//	idols["방탄소녀단"] = 10;
//}
//


// 소스.cpp에 각 알파벳이 몇 번 사용되었나 출력하라
// 다음 시간에는 소설책을 읽어보자

#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include "MemoryMonster.h"

using namespace std;

int main()
{
	map<char, int> cb;

	ifstream in("STL_4.19.cpp");
	
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
		if (isalpha(*i))
			cb[tolower(*i)]++;

	auto p = cb.cbegin();
	for (int i = 0; i < cb.size(); ++i, ++p)
		cout << "[" << p->first << "] --> " << p->second << endl;
}