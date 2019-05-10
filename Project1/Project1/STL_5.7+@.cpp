#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include "MemoryMonster.h"

using namespace std;

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

class Dog {
	string name;

public:
	Dog(string f_name) : name(f_name)
	{
	}

	string getName() const
	{
		return name;
	}

	bool operator==(const Dog& rhs) const
	{
		return name == rhs.name;
	}
};

class X {

public:
	size_t operator()(const Dog& a) const {
		return hash<string>()(a.getName());
	}
};

template<>
struct hash<Dog>
{
	int operator()(const Dog& d)const {
		return hash<string>() (d.getName());
	}
};

int main()
{
	// 전화번호를 저장해 보자
	// map과 다른 점이 뭐냐?

	// hash 함수를 사용하는데
	// 기본 자료형 밖에 준비가 안 되어 있음
	// 따라서 따로 해쉬를 만들어야함

	unordered_map<Dog, int> dogs;

	dogs.emplace("멍멍이", 3);
	dogs.emplace("댕댕이", 5);
	dogs.emplace("킁킁이", 8);
	dogs.emplace("미샤", 1);

	for (int i = 0; i < dogs.bucket_count(); ++i)
	{
		cout << " [ " << i << " ] --- ";

		if (dogs.bucket_size(i))
		{
			for (auto b = dogs.begin(i); b != dogs.end(i); ++b)
				cout << b->second << " ";
		}
		cout << endl;
	}

	// 찾기
	// 이 문장이 왜 안 되는가?
	//dogs["멍멍이"];

	cout << dogs[string("멍멍이")] << endl;

}

// Key 값을 통해 위치를 만들고
// 그 위치에 Value 값을 넣는다
