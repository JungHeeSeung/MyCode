#include "MemoryMonster.h"

#include<random>	// cpp에 적으면 헤더재정의 할 필요가 없어서 빨라진다
	
std::default_random_engine dre;
std::uniform_int_distribution<> uid('a', 'z');


//생성자
MemoryMonster::MemoryMonster(int n) : num{ n }
{
	p = new char[num];	// 메모리
	for (int i = 0; i < num; i++)
		p[i] = uid(dre);
	std::cout << "생성자(int) - " << this << ", 할당 메모리 - " << (void*)p <<std::endl;
}


MemoryMonster::~MemoryMonster()
{
	std::cout << "소멸자 - " << this << ", 할당 메모리 - " << (void*)p << std::endl;
	//std::cout << "소멸자: " << this << std::endl;
	if (p != nullptr)
		delete[] p;
}

//복사================================

// 복사 생성자
MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num) {
	p = new char[num];
	memcpy(p, other.p, num);
	std::cout << "복사생성자 - " << this 
		<< " 원본 - "<< &other << ", 할당 메모리 - " << (void*)p << std::endl;
}

//복사할당연산자
MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other) {
	std::cout << "복사할당 연산자" << std::endl;
	if (this == &other)
		return *this;
	delete[] p;

	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

//이동================================

//이동생성자
MemoryMonster::MemoryMonster(MemoryMonster&& other) : num{ other.num } {
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	std::cout << "이동생성자 - " << this
		<< " 원본 - " << &other << ", 할당 메모리 - " << (void*)p << std::endl;
}

//이동할당연산자
MemoryMonster& MemoryMonster::operator=(MemoryMonster&& other) {
	std::cout << "이동할당 연산자" << std::endl;
	delete[] p;
	num = other.num;
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	return *this;
}

bool MemoryMonster::operator==(const MemoryMonster & rhs)
{
	if (num == rhs.num)
		return true;
	return false;
}

std::ostream& operator<<(std::ostream& os, const MemoryMonster& mm)
{
	for (int i = 0; i < mm.num; i++)
		//os << static_cast<int>(mm.p[i]) << ' ';
		os << mm.p[i];
	return os;
}

int MemoryMonster::getNum() const
{
	return num;
}


void MemoryMonster::reset(int n)
{
	//이미 확보한 메모리는 해제한다.
	if (p != nullptr)
		delete[] p;

	num = n;
	p = new char[num];	// 메모리
	for (int i = 0; i < num; i++)
		p[i] = uid(dre);
}

char * MemoryMonster::getData() const
{
	return p;
}
