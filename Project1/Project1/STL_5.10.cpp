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
//// 컨테이너의 정의
//// 반복자의 정의
//// 교재 3장의 힙 내용은 매우 중요하다
//// 꼭 읽어보자
//// 
//// Associative Containner (연관 컨테이너)
////		map - dictionary <ket, value> 쌍이 원소	O(log n)
////		set - <key>가 원소
////
//// Unordered Associative Container (순서없는 연관 컨테이너, Hash) O(1)
////		unordered_map
////		unordered_set
////		메모리를 희생하고 찾는 시간을 극단적으로 줄이려고 노력함
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
////	// 이 문장을 실행하기 위한 몇 가지 방법이 있음
////	// vector<Dog> v{ "코코", "별이", "콩이" };
////	
////	// 1번
////	// {}는 initializer_list<string> names{ "코코", "별이", "콩이" }; 를 의미함
////	// vector<Dog> v( names.begin(), names.end() );
////	
////	// 2번 클래스 생성자를 템플릿으로 선언하자
////	//vector<Dog> v{ "코코", "별이", "콩이" };
////
////	// 3번 
////	// 	vector<Dog> v{ string("코코")}; 처럼 명시적으로 진행하자
////
////	unordered_map<Dog, int, hash<Dog>> m;
////	m.emplace("코코", 1);
////	m.emplace("별이", 2);
////	m.emplace("콩이", 3);
////
////	// "해피"라는 이름의 개가 Unordered Map m 에 있는지 찾아보자
////	m[Dog("해피")] = 100;
////	auto p = m.find( Dog("해피") );
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

// 정수 1000만개를 unordered_map과 map에 저장한다
// 임의의 정수 100만개가 컨테이너에 있는지 찾아본다.
// 각각 걸리는 시간을 측정한다.

int main()
{
	map<int, int> m;

	default_random_engine dre;
	uniform_int_distribution<> uid;

	int i{};

	while(m.size() != 1000'0000)
		m.emplace(uid(dre), ++i);
	
	cout << "맵 사이즈는 ??? --> "  << m.size() << endl;

	// map의 원소를 그대로 unordered_map에 넣는다.
	unordered_map<int, int> um{ m.begin(), m.end(), 1000'0000 };
	cout << "언오더드 맵 생성 - " << um.size() << endl;
	
	// 찾아볼 값 100만개를 vector에 저장
	cout << "벡터에 인덱스 100만개를 생성한다" << endl;
	vector<int> v;
	v.reserve(100'0000);
	for (int i = 0; i < 100'0000; ++i)
		v.push_back(uid(dre));

	{
		cout << "임의의 정수 100만개를 맵에서 찾기 시작" << endl;
		auto b = steady_clock::now();
		for (int i = 0; i < 100'0000; ++i)
			m.find( v[i] );
		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();
		cout << "걸린 시간 ---> " << d << endl;
	}
	
	{
		cout << "임의의 정수 100만개를 언오더드 맵에서 찾기 시작" << endl;
		auto b = steady_clock::now();
		for (int i = 0; i < 100'0000; ++i)
			um.find( v[i] );
		auto d = duration_cast<milliseconds>(steady_clock::now() - b).count();
		cout << "걸린 시간 ---> " << d << endl;
	}
}

	
