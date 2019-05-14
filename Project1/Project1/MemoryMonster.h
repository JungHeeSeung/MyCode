//-----------------------------------------------------------------
//
// MemmoryMonster.h
// 정수를 인자로 받아 그 숫자만큼 메모리 를 heap에 할당한다.
//
//2019.5.14 - 표준 STL 컨테이너처럼 동작하게 한다
//
//-----------------------------------------------------------------

#pragma once

#include <iostream>
#include <iterator>
#include <string>

class MemoryMonster;

// 내가 만들었던 MemoryMonster의 역반복자를
// 표준 반복자로 만들려면 반복자에 필요한 타입 5가지를 정의 하여야 한다
// 표준 반복자를 상속받는 것이 편하다.

class revIter : public std::iterator<std::random_access_iterator_tag, char> {
	char * p;

public:
	//revIter(typename MemoryMonster::iterator p) : p{ p } { };
	revIter(char * p) : p{ p } { };
	 
	revIter& operator++() {
		--p;
		return *this;
	};

	revIter operator++(int) {
		revIter temp{ *this };
		--p;
		return temp;
	};

	revIter& operator--() {
		++p;
		return *this;
	};

	revIter operator--(int) {
		revIter temp{ *this };
		++p;
		return temp;
	};

	bool operator!=(const revIter& other) const {
		return p != other.p;
	}

	//MemoryMonster::value_type operator*()
	char operator*() {
		return *(p-1);
	}

	std::ptrdiff_t operator-(const revIter& other) const {
		return p - other.p;
	}

	char* operator+(std::ptrdiff_t n) const {
		return p + n;
	}

	char* operator-(std::ptrdiff_t n) const {
		return p - n;
	}

	bool operator<(const revIter& other) const {
		return *p < *(other.p);
	}

	bool operator==(const revIter& other) const {
		return p == other.p;
	}
};

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

	//------------------------------
	//typedef char* iterator;

	using iterator = char*;
	using reverse_iterator = revIter;
	using value_type = char;

	iterator begin();
	iterator end();

	reverse_iterator rbegin();
	reverse_iterator rend();

private:
	int num{ 0 };
	char* p{ nullptr };
};

