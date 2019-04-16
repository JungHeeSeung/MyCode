#include "MemoryMonster.h"

#include<random>	// cpp�� ������ ��������� �� �ʿ䰡 ��� ��������
	
std::default_random_engine dre;
std::uniform_int_distribution<> uid('a', 'z');


//������
MemoryMonster::MemoryMonster(int n) : num{ n }
{
	p = new char[num];	// �޸�
	for (int i = 0; i < num; i++)
		p[i] = uid(dre);
	std::cout << "������(int) - " << this << ", �Ҵ� �޸� - " << (void*)p <<std::endl;
}


MemoryMonster::~MemoryMonster()
{
	std::cout << "�Ҹ��� - " << this << ", �Ҵ� �޸� - " << (void*)p << std::endl;
	//std::cout << "�Ҹ���: " << this << std::endl;
	if (p != nullptr)
		delete[] p;
}

//����================================

// ���� ������
MemoryMonster::MemoryMonster(const MemoryMonster& other) : num(other.num) {
	p = new char[num];
	memcpy(p, other.p, num);
	std::cout << "��������� - " << this 
		<< " ���� - "<< &other << ", �Ҵ� �޸� - " << (void*)p << std::endl;
}

//�����Ҵ翬����
MemoryMonster& MemoryMonster::operator=(const MemoryMonster& other) {
	std::cout << "�����Ҵ� ������" << std::endl;
	if (this == &other)
		return *this;
	delete[] p;

	p = new char[num];
	memcpy(p, other.p, num);
	return *this;
}

//�̵�================================

//�̵�������
MemoryMonster::MemoryMonster(MemoryMonster&& other) : num{ other.num } {
	p = other.p;
	other.p = nullptr;
	other.num = 0;
	std::cout << "�̵������� - " << this
		<< " ���� - " << &other << ", �Ҵ� �޸� - " << (void*)p << std::endl;
}

//�̵��Ҵ翬����
MemoryMonster& MemoryMonster::operator=(MemoryMonster&& other) {
	std::cout << "�̵��Ҵ� ������" << std::endl;
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
	//�̹� Ȯ���� �޸𸮴� �����Ѵ�.
	if (p != nullptr)
		delete[] p;

	num = n;
	p = new char[num];	// �޸�
	for (int i = 0; i < num; i++)
		p[i] = uid(dre);
}

char * MemoryMonster::getData() const
{
	return p;
}
