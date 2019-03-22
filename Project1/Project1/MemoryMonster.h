#pragma once

// 클래스 복습
// 메모리를 소모하는 MemoryMonster 클래스가 있다.
// 정수를 인자로 받아 그 숫자만큼 메모리(byte)를 HEAP에서 확보한다.
// main()이 문제가 없도록 클래스를 만들어라
// #include "MemoryMonsster.h" 로 만들기

#include <iostream>

using namespace std;

class MemoryMonster
{
private:
	int num = 0;
	char * p{ nullptr };

public:

	int get() const;

	void set(int n);

	MemoryMonster() = default;

	MemoryMonster(int n);

	~MemoryMonster();

	MemoryMonster(const MemoryMonster& other);

	MemoryMonster& operator=(const MemoryMonster& other);

	MemoryMonster(MemoryMonster&& other);

	MemoryMonster* operator=(MemoryMonster&& other);


	friend ostream& operator<<(ostream&, const MemoryMonster&);

};
