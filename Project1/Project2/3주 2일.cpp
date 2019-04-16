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

#include<memory>
// unique_ptr - 자원을 독점한다.
// shared_ptr - 자원을 공유한다.(자원이 귀하다.)

int main()
{
	//MemoryMonster* a = new MemoryMonster;
	//MemoryMonster* b = new MemoryMonster;
	//delete a;
	//delete b;

	//==================================================================
	// 스마트 포인터
	// 함수가 끝날때 알아서 소멸시킨다.
	// 초기화만 가능하고 후에 변경하려는 문법은 사용 불가능
	//==================================================================

	//unique_ptr<MemoryMonster> a(new MemoryMonster);	
	//unique_ptr<MemoryMonster> b(new MemoryMonster);
	
	//==================================================================
	// 위의 스마트 포인터를 쓰면 new 만있고 delete가 없는 모양이라 좀 찝찝하다
	// new 를 안쓰고 만들려면 make_unique 함수를 쓴다.
	//==================================================================

	//auto c = make_unique<MemoryMonster>(10);	//약식
	//unique_ptr<MemoryMonster> d = make_unique<MemoryMonster>(50);	//정확한 표현



	//unique_ptr<MemoryMonster[]>p(new MemoryMonster[5]);	//여러개를 쓸때는 []를 붙여준다
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
	

	shared_ptr<MemoryMonster> p{ new MemoryMonster };	//있다만 알아라?





}