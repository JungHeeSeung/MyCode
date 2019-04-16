//===================================
//
//2019 STL 3.19 화56		(3주 1일)
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

//확보한 메모리를 소문자로 채우자??


int main()
{
	//100마리의 몬스터를 만들고
	MemoryMonster monster[10000];

	//각 몬스터의 num 수치를 uid(dre) 범위(1~128) 값으로 설정하라

	uniform_int_distribution<> uid(1,80);
	default_random_engine dre;

	for (MemoryMonster& d : monster)
		d.reset(uid(dre));

	// 몬스터의 num 오름차순으로 정렬하라.
	sort(begin(monster), end(monster), 
		[](const MemoryMonster& a, const MemoryMonster& b) {	//&를 안붙이면 객체가 생겨서 안좋다??? 큰일
		return a.getNum() < b.getNum();
	});



	// 정렬된 몬스터를 출력하라.
	for (MemoryMonster& d : monster)	//&를 쓰지 않으면 복사생성이 된다.
	{
		cout << d << endl;
	}


}