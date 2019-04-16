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

#include<memory>
// unique_ptr - �ڿ��� �����Ѵ�.
// shared_ptr - �ڿ��� �����Ѵ�.(�ڿ��� ���ϴ�.)

int main()
{
	//MemoryMonster* a = new MemoryMonster;
	//MemoryMonster* b = new MemoryMonster;
	//delete a;
	//delete b;

	//==================================================================
	// ����Ʈ ������
	// �Լ��� ������ �˾Ƽ� �Ҹ��Ų��.
	// �ʱ�ȭ�� �����ϰ� �Ŀ� �����Ϸ��� ������ ��� �Ұ���
	//==================================================================

	//unique_ptr<MemoryMonster> a(new MemoryMonster);	
	//unique_ptr<MemoryMonster> b(new MemoryMonster);
	
	//==================================================================
	// ���� ����Ʈ �����͸� ���� new ���ְ� delete�� ���� ����̶� �� �����ϴ�
	// new �� �Ⱦ��� ������� make_unique �Լ��� ����.
	//==================================================================

	//auto c = make_unique<MemoryMonster>(10);	//���
	//unique_ptr<MemoryMonster> d = make_unique<MemoryMonster>(50);	//��Ȯ�� ǥ��



	//unique_ptr<MemoryMonster[]>p(new MemoryMonster[5]);	//�������� ������ []�� �ٿ��ش�
	unique_ptr<MemoryMonster[]> p = make_unique<MemoryMonster[]>(5);	//make_unique

	for (size_t i = 0; i < 5; i++)
	{
		p[i].reset(i+10);
	}
	
	sort(&p[0],&p[5],[](const MemoryMonster& x, const MemoryMonster& y){
		return x.getNum() < y.getNum();
	});

	for (int i = 0; i < 5; i++)
	{
		cout << p[i] << endl;
	}
	

	shared_ptr<MemoryMonster> p{ new MemoryMonster };	//�ִٸ� �˾ƶ�?





}