

// Ŭ���� ����
// �޸𸮸� �Ҹ��ϴ� MemoryMonster Ŭ������ �ִ�.
// ������ ���ڷ� �޾� �� ���ڸ�ŭ �޸�(byte)�� HEAP���� Ȯ���Ѵ�.
// main()�� ������ ������ Ŭ������ ������
// #include "MemoryMonsster.h" �� �����



//	������ �ڿ��� Ȯ���ϴ� Ŭ������ ��쿡��
//	1. �����ڿ��� new�� �ڿ��� Ȯ���Ѵ�	(���� ��ǥ���� ���)
//	2. �Ҹ��ڿ��� delete�� �����Ѵ�
//	3. ��������ڿ��� ���� ���簡 �ǵ��� �Ѵ�
//	4. �����Ҵ翬���ڿ��� ���� ���簡 �ǵ��� �Ѵ�
//
//	c++11�� �̵��ǹ̷�(move semantics)�� �����Ϸ���
//
//	5. �̵������ڸ� �����
//	6. �̵��Ҵ翬���ڸ� �����




#include <iostream>
#include <random>
#include <algorithm>
#include "MemoryMonster.h"




int main()
{
	//	100������ ���͸� �����

	MemoryMonster monster[100];


	// �� ������ num ��ġ�� uid(dre) ����(1~128) ������ �����϶�.
	uniform_int_distribution<> uid(1, 128);
	default_random_engine dre;

	for (MemoryMonster& d : monster)
	{
		d.set(uid(dre));
	}

	// ������ num ������������ �����϶�
	sort(begin(monster), end(monster),
		[](const MemoryMonster& a, const MemoryMonster& b) { return a.get() < b.get();
	});


	// ���ĵ� ���͸� ����϶�
	for (MemoryMonster& d : monster)
	{
		cout << d << endl;
	}
}



//MemoryMonster a{ 123 };	//	HEAP���� 123����Ʈ�� Ȯ���� ��
//						//	�޸��� ���� 1���� 123������ �ǵ��� �����Ѵ�

//MemoryMonster b = move(a);		// �̵��� ����� ���������� �ʾҴ�. �׷��⿡ �� ������ MemoryMonster b = {a}; �� �ٸ� �� ����
