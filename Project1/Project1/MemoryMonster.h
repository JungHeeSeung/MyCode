//-----------------------------------------------------------------
//
// MemmoryMonster.h
// ������ ���ڷ� �޾� �� ���ڸ�ŭ �޸� �� heap�� �Ҵ��Ѵ�.
//
//2019.5.14 - ǥ�� STL �����̳�ó�� �����ϰ� �Ѵ�
//
//-----------------------------------------------------------------

#pragma once

#include <iostream>
#include <iterator>
#include <string>

class MemoryMonster;

// ���� ������� MemoryMonster�� ���ݺ��ڸ�
// ǥ�� �ݺ��ڷ� ������� �ݺ��ڿ� �ʿ��� Ÿ�� 5������ ���� �Ͽ��� �Ѵ�
// ǥ�� �ݺ��ڸ� ��ӹ޴� ���� ���ϴ�.

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
	int getNum() const;			// Ȯ���� �޸� ������ �˷��ش�.
	char* getData() const;		// �޸��� ��ġ�� �˷��ش�.

	void reset(int n);			// ���� �޸𸮸� ������ 
								// n�� ��ŭ �� �޸𸮸� Ȯ���Ѵ�.

	MemoryMonster() = default;

	//������
	MemoryMonster(int n);	// explicit - �ݵ�� ��ü�� ������� ����Ѵ�????
	~MemoryMonster();

	//����================================
	// ���� ������
	MemoryMonster(const MemoryMonster& other);
	//�����Ҵ翬����
	MemoryMonster& operator=(const MemoryMonster& other);


	//�̵�================================
	//�̵�������
	MemoryMonster(MemoryMonster&& other);
	//�̵��Ҵ翬����
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

