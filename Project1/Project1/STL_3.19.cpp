

// 클래스 복습
// 메모리를 소모하는 MemoryMonster 클래스가 있다.
// 정수를 인자로 받아 그 숫자만큼 메모리(byte)를 HEAP에서 확보한다.
// main()이 문제가 없도록 클래스를 만들어라
// #include "MemoryMonsster.h" 로 만들기



//	생성시 자원을 확보하는 클래스인 경우에만
//	1. 생성자에서 new로 자원을 확보한다	(가장 대표적인 경우)
//	2. 소멸자에서 delete로 해제한다
//	3. 복사생성자에서 깊은 복사가 되도록 한다
//	4. 복사할당연산자에서 깊은 복사가 되도록 한다
//
//	c++11의 이동의미론(move semantics)을 적용하려면
//
//	5. 이동생성자를 만든다
//	6. 이동할당연산자를 만든다




#include <iostream>
#include <random>
#include <algorithm>
#include "MemoryMonster.h"




int main()
{
	//	100마리의 몬스터를 만들고

	MemoryMonster monster[100];


	// 각 몬스터의 num 수치를 uid(dre) 범위(1~128) 값으로 설정하라.
	uniform_int_distribution<> uid(1, 128);
	default_random_engine dre;

	for (MemoryMonster& d : monster)
	{
		d.set(uid(dre));
	}

	// 몬스터의 num 오름차순으로 정렬하라
	sort(begin(monster), end(monster),
		[](const MemoryMonster& a, const MemoryMonster& b) { return a.get() < b.get();
	});


	// 정렬된 몬스터를 출력하라
	for (MemoryMonster& d : monster)
	{
		cout << d << endl;
	}
}



//MemoryMonster a{ 123 };	//	HEAP에서 123바이트를 확보한 후
//						//	메모리의 값은 1부터 123까지가 되도록 설정한다

//MemoryMonster b = move(a);		// 이동할 방법을 가르쳐주지 않았다. 그렇기에 이 문장은 MemoryMonster b = {a}; 와 다른 게 없다
