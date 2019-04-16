// deque : double-ended queue, "덱"이라 읽는다.
// 처리 시간이 상수시간이다.

#include <iostream>
#include <list>
#include <string>
#include "MemoryMonster.h"

using namespace std;

// deque에 MemoryMonster {10, 20, 30}을 추가해보자
// deque의 원소를 화면에 출력해보자
// 속도를 희생하고 편의성을 얻었다..
// 메모리 블록들을 앞 뒤로 연결한다

// 소스.cpp
// deque에 저장하고
// 화면 뒤에서부터 출력하라


// list에 MemoryMonster 3개를 추가
// 각 원소를 출력

int main()
{
	list<MemoryMonster> monsters;

	// 리스트에서 길이가 10보다 작은 원소를 제거하라.
	// monsters.remove_if(); 를 사용해서 제거하자

	auto p = monsters.begin();
	p = monsters.emplace(p, 10);
	p = monsters.emplace(p, 20);
	p = monsters.emplace(p, 30);

	for (MemoryMonster & d : monsters)
	{
		cout << d << endl;
	}
}

// list
// list 이후의 컨테이너는 원소보다 더 큰 메모리를 사용한다
// 메모리를 조금 더 쓰지만
// 삽입과 삭제에 상수시간 만큼 걸림