//-----------------------------------------------------------------
//
// MemmoryMonster.h
// ������ ���ڷ� �޾� �� ���ڸ�ŭ �޸� �� heap�� �Ҵ��Ѵ�.
//
//-----------------------------------------------------------------

#pragma once

#include<iostream>
#include <string>

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
private:
	int num{ 0 };
	char* p{ nullptr };
};

