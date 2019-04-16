//===================================
//
//2019 STL 3.22 금23		(3주 2일)
//
//	자원을 확보하는 클래스 만들어 두기(이동, STL에 사용할 내 클래스)
//	smart Pointer
//	
//	숙제 : #include"MemoryMonster.h"로 만든다.
//
//===================================


#include<iostream>
#include<random>
#include"save.h"
#include"MemoryMonster.h"

using namespace std;

// 정수를 입력을 받아 MemoryMonster 를 생성하라
// 글자의 갯수는 (10~70)로 하라
// num 오름차순으로 정렬한 후 화면에 출력하라

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
//	cout << "몬스터 수를 입력하시오: ";
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
//	// 정렬된 몬스터를 출력하라.
//	for (int i = 0; i < MM_NUM; ++i)	//&를 쓰지 않으면 복사생성이 된다.
//	{
//		cout << p_memoryMonster[i] << endl;
//	}
//
//	delete[] p_memoryMonster;
//	}
//
//
//}