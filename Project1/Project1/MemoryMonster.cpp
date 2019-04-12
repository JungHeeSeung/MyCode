#include <iostream>
#include <random>
#include "MemoryMonster.h"


using namespace std;

uniform_int_distribution<> uid('a', 'z');
default_random_engine dre;

void MemoryMonster::set(int n)
{
	num = n;
	p = new char[num];
	for (int i = 0; i < num; ++i)
	{
		p[i] = uid(dre);
	}
	cout << "持失切 - " << this << endl;
}

MemoryMonster::MemoryMonster(int n) : num(n)
{
	p = new char[num];
	for (int i = 0; i < num; ++i)
	{
		p[i] = uid(dre);
	}
}

MemoryMonster::~MemoryMonster()
{
	cout << "社瑚切 - " << this << endl;
	if (p != nullptr)
		delete[] p;
}

MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num)
{
	p = new char[num];
	memcpy(p, other.p, num);
}

MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other)
{
	if (this == &other)
	{
		return *this;
	}
	delete[] p;
	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

MemoryMonster::MemoryMonster(MemoryMonster&& other) : num(other.num)
{
	p = other.p;
	other.p = nullptr;
	other.num = 0;
}

MemoryMonster& MemoryMonster::operator=(MemoryMonster&& other)
{
	delete[] p;
	num = other.num;
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	return *this;
}

bool MemoryMonster::operator<(const MemoryMonster& right)
{
	return num < right.num;
}

int MemoryMonster::get() const
{
	return num;
}


ostream& operator<<(ostream& os, const MemoryMonster& mm)
{
	for (int i = 0; i < mm.num; ++i)
	{
		os << mm.p[i] ;
	}
	return os;
}
