//===================================
//
//2019 STL 3.22 ��23		(3�� 2��)
//
//	�ڿ��� Ȯ���ϴ� Ŭ���� ����� �α�(�̵�, STL�� ����� �� Ŭ����)
//	smart Pointer
//	
//	���� : #include"MemoryMonster.h"�� �����.
//
//===================================


#include<iostream>
#include<random>
#include"save.h"
#include"MemoryMonster.h"

using namespace std;

// ������ �Է��� �޾� MemoryMonster �� �����϶�
// ������ ������ (10~70)�� �϶�
// num ������������ ������ �� ȭ�鿡 ����϶�

//constexpr int iasdf{ 10 };
//const int asdf{ 10 };
//#define	ASDF 10;
//int a[asdf];

//int main()
//{
//	int MM_NUM {0};
//
//
//	while (true)
//	{
//
//	cout << "���� ���� �Է��Ͻÿ�: ";
//	cin >> MM_NUM;
//
//	MemoryMonster* p_memoryMonster = new MemoryMonster[MM_NUM];
//
//	default_random_engine dre;
//	uniform_int_distribution<> uid(10, 70);
//
//	for (int i = 0; i < MM_NUM; i++)
//	{
//		p_memoryMonster[i].reset(uid(dre));
//	}
//
//	sort(p_memoryMonster, p_memoryMonster + MM_NUM,
//		[](const MemoryMonster& a, const MemoryMonster& b)
//	{
//		return a.getNum() < b.getNum();
//	});
//
//	// ���ĵ� ���͸� ����϶�.
//	for (int i = 0; i < MM_NUM; ++i)	//&�� ���� ������ ��������� �ȴ�.
//	{
//		cout << p_memoryMonster[i] << endl;
//	}
//
//	delete[] p_memoryMonster;
//	}
//
//
//}