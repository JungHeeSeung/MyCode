#pragma once

// Ŭ���� ����
// �޸𸮸� �Ҹ��ϴ� MemoryMonster Ŭ������ �ִ�.
// ������ ���ڷ� �޾� �� ���ڸ�ŭ �޸�(byte)�� HEAP���� Ȯ���Ѵ�.
// main()�� ������ ������ Ŭ������ ������
// #include "MemoryMonsster.h" �� �����

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
