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

	MemoryMonster(int );

	~MemoryMonster();

	MemoryMonster(const MemoryMonster& );

	MemoryMonster& operator=(const MemoryMonster& );

	MemoryMonster(MemoryMonster&& );

	MemoryMonster& operator=(MemoryMonster&& );
	
	bool operator<(const MemoryMonster& right);

	friend ostream& operator<<(ostream&, const MemoryMonster&);

};
