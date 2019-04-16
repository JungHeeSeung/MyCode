//===================================

//2019 STL 3.12 금23		(1주 2일)
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
// int a[1000'0000];
// int a[1000'0000] {1};
// 이 두경우에 실행 파일 (*.exe)의 크기는 매우 다르다. 왜 그런지 알아보자


int a[1000'0000];	//지역변수는 메모리 총량이 제한되어있어서 1000만개는 못한다.
// 용량이 너무 크다 포인터로 쓰자

int main()
{
	// 정수 1000,000개를 생성하여 정렬해 보자

	int *a;

	cout << "원하는 만큼 정수를 동적할당하여 정렬 후 앞에서 100개를 출력합니다." << endl;
	cout << "1000 이상의 정수를 입력하세요.";
	
	int num;
	cin >> num;

	a = new int[num];
	
	uniform_int_distribution<> uid(0, 10000);	//범위 정하기
	default_random_engine dre;

	// 범위기반 반복문인데 a가 포인터로 바뀌면서 범위가 사라져서 사용 할 수 없다.
	//for (int& d : a) {
	//	//a[i] = 분포(엔진);
	//	d = uid(dre);
	//}

	for (int i = 0; i < num; i++) {
		//a[i] = 분포(엔진);
		a[i] = uid(dre);
	}

	//sort(어디부터, 어디까지, 어떻게(처리 할 함수의 시작번지));
	//std::sort(begin(a), end(a));
	
	std::sort(a, a + num);



	for (int d = 0; d < 100; d++) //????
		cout << a[d] << ", ";
	cout << endl;

	// Ascending order - 오름차순
	// Descending order - 내림차순


	//save("소스2.cpp");	// 안의 문자열은 전역변수라서 data 세그먼트에 들어간다.
}

// main 안에 있는 a[10000] 변수는 지역 변수이다. 이 프로그램이 돌아가려면 전역으로 뺀다.