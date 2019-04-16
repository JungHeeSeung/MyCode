//===================================

//2019 STL 3.8 금23		(1주 2일)
//
// - 강의 내용을 저장하자
//		저장하는 함수를 만든다.
// - 많은 수의 자료를 다루는 것을 생각해 보자
//		많은 수를 어떻게 다루는가?
//		자료는 어디에 있는가?
//		- 정수 1000만개를 랜덤하게 생성한다.
//		- 정렬하여 파일에 기록한다.
//		- binary I/O 
//

//===================================


#include<iostream>
#include<algorithm>
#include<random>
#include"save.h"

using namespace std;

//a 는 전역변수이다. - 어디에 (실행파일의 어디에) 저장되나?
// 지역변수와 차이점은 무엇인가?
// a 는 실행파일에서 어떻게 기록되는가?
int a[100'0000];	//지역변수는 메모리 총량이 제한되어있어서 1000만개는 못한다.

int main()
{
	// 정수 1000,000개를 생성하여 정렬해 보자
	//int a[] {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};	//unitform initializer

	uniform_int_distribution<> uid(0,1000);
	default_random_engine dre;


	for (int& d : a){
		//a[i] = 분포(엔진);
		d = uid(dre);
	}

	//sort(어디부터, 어디까지, 어떻게(처리 할 함수의 시작번지));
	std::sort( begin(a), end(a), [](int a, int b){
		return a < b;
	});

	for (int d : a) //????
		cout << d << ", ";
	cout << endl;

	// Ascending order - 오름차순
	// Descending order - 내림차순


	save("소스1.cpp");	// 안의 문자열은 전역변수라서 data 세그먼트에 들어간다.
}

// main 안에 있는 a[10000] 변수는 지역 변수이다. 이 프로그램이 돌아가려면 전역으로 뺀다.