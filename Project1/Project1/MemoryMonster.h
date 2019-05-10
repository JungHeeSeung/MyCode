//-----------------------------------------------------------------
//
// MemmoryMonster.h
// 정수를 인자로 받아 그 숫자만큼 메모리 를 heap에 할당한다.
//
//-----------------------------------------------------------------

#pragma once

#include<iostream>
#include <string>

class MemoryMonster
{
public:
	int getNum() const;			// 확보한 메모리 갯수를 알려준다.
	char* getData() const;		// 메모리의 위치를 알려준다.

	void reset(int n);			// 기존 메모리를 버리고 
								// n개 만큼 새 메모리를 확보한다.


	MemoryMonster() = default;

	//생성자
	MemoryMonster(int n);	// explicit - 반드시 객체를 만들려면 써야한다????
	~MemoryMonster();

	//복사================================
	// 복사 생성자
	MemoryMonster(const MemoryMonster& other);
	//복사할당연산자
	MemoryMonster& operator=(const MemoryMonster& other);


	//이동================================
	//이동생성자
	MemoryMonster(MemoryMonster&& other);
	//이동할당연산자
	MemoryMonster& operator=(MemoryMonster&& other);

	friend std::ostream& operator<<(std::ostream&, const MemoryMonster&);
	bool operator == (const MemoryMonster& rhs) const;
	bool operator< (const MemoryMonster& rhs) const;
private:
	int num{ 0 };
	char* p{ nullptr };
};

