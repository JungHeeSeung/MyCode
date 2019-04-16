//===================================
//
//2019 STL 3.26 화56		(4주 1일)
//
//	2장 순차 컨테이너
//	- array : smart 한 배열
//	- vector : 
//	- deque
//	- list
//	- forward_list
//
//===================================

// 순차 컨테이너지만 순서가 있는 컨테이너가 아니다.
// 각각 include 해야 사용 가능

#include<iostream>
#include<array>

#include"MemoryMonster.h"

using namespace std;

//int main()
//{
//	array<int, 5> a {1,2,3,4,5};	//[][][][][]	
//	//장점 - 몇개인지 알려줄 필요가 없다?, 범위에서 벗어났는지 파악 할 수 있다.
//	//단점 - 그냥 보기 좀 그런거 빼고 없다.
//
//	//a[-100]; // debug에서는 걸리지만 release 에서는 아무일 없이 지나간다.
//
//	for (int i = 0; i < a.size(); i++)
//	{
//		cout << a[i] << endl;
//	}
//
//	int num;
//	cout << "몇번쨰 값을 원하나?";
//	cin >> num;
//	
//	
//	try {
//		cout << a.at(num) << endl;
//	}
//	catch(exception& e){
//		cout << e.what() << endl;
//	}
//
//}

#include<algorithm>


int main()
{
	array<MemoryMonster, 5> a {10,3,30,7,20};

	//for (auto p = begin(a); p != end(a); ++p)
	//{
	//	cout << *p << endl;
	//}


	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;
	cout << "-===========정렬빔=============-" << endl;
	// a의 각 원소를 오름차순으로 정렬해보시오


	//char *p = a[0].getData();
	//sort(p, p + a[0].getNum());

	for (int i = 0; i < a.size(); ++i)
		sort(a[i].getData(), a[i].getData() + a[i].getNum());

	for (int i = 0; i < a.size(); ++i)
		cout << a[i] << endl;

}