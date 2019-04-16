//===================================
//
//2019 STL 3.26 화56		(4주 2일)
//
//	2장 순차 컨테이너 (sequence container, (homogeneous data type 만 담는다.))
//	- array : smart 한 배열, []를 완벽하게 대치한다.
//	- vector
//	- deque
//	- list
//	- forward_list
//
//===================================

// 순차 컨테이너지만 순서가 있는 컨테이너가 아니다.
// 각각 include 해야 사용 가능

#include<iostream>
#include<vector>
#include"MemoryMonster.h"

using namespace std;


// <> 안에는 어떤 자료형이든 들어 갈 수 있다.
// vector<> 본인도 자료형이다??
// 개수를 늘려도 똑같이 12byte 로 나온다. 
// 가지고 있는 원소의 개수, 메모리의 주소, 메모리의 크기를 가지고 있다. - 3개 해서 12byte

// 원소가 늘어나면 메모리의 크기를 비교해서 늘어나는걸 파악하고 새로운 공간을 줘서 자료를 옮긴다.
// 메모리가 늘어날때 크기는 원래 크기의 1.5배로 잡는다.

//int main()
//{
//	vector<MemoryMonster> v {10,20,30,40,50,6};
//	
//	while (true)
//	{
//
//	cout << "현재 원소 갯수		- " << v.size() << endl;
//	cout << "담을 수 있는 갯수	- " << v.capacity() << endl;
//	cout << "확보한 메모리 위치	- " << v.data() << endl<<endl;
//	
//	//cout << sizeof(v) << endl;
//
//	char c;
//	cin >> c;
//	v.push_back(1);
//
//	}
//
//}




//===================================

// MemoryMonster 20개를 만들어 vector에 넣어라
// 초기값을 uid(10,70)로 만들어라
// vector를 .gerNum() 오름차순으로 정렬하여라
// 결과를 화면 출력한다.

//===================================

#include<random>
#include<algorithm>
int main()
{
	uniform_int_distribution<> uid(10, 70);
	default_random_engine dre;

	vector<MemoryMonster> v;
	v.reserve(20);	// 공간을 미리 예약하는 함수 *******************

	// 공간을 잡았다가 이동했다가를 반복해서 좋지 않다.
	for (size_t i = 0; i < 20; ++i)
		v.push_back(uid(dre));

	cout << "현재 원소 갯수		- " << v.size() << endl;
	cout << "담을 수 있는 갯수	- " << v.capacity() << endl;
	cout << "확보한 메모리 위치	- " << v.data() << endl << endl;

	sort(v.begin(), v.end(),[](const MemoryMonster& a, const MemoryMonster& b ){
		return a.getNum() < b.getNum();
	});

	//for (auto i = v.begin(); i != v.end(); ++i)
	//	cout <<  *i << endl;

	for (const MemoryMonster& a : v)
		cout << a << endl;
}