////	2019 STL 3.8 금23
////
////	강의 내용을 저장하자
////	저장하는 함수를 만들고 file을 분리하자
////
////	-많은 수의 자료를 다루는 것을 생각해 보자
////		많은 수를 어떻게 다루는가?
//			자료에 어디에 있는가?
//		
//		-정수 1만개를 랜덤하게 생성한다
//			정렬하여 파일에 기록한다
//			binary I/O 

////	-책은 다음 주 부터
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include <iterator>
//#include <chrono>
//
//
//void save(std::string);
//
//int main()
//{
//	save("20190308STL.cpp");	//data 세그먼트에 저장됨
//}
//
//void save(std::string fname)
//{
//	//	fname을 읽기 모드로 연다
//	std::ifstream in( fname );
//	// if (!in) 처럼 안 열릴 상황을 예외처리 하면 좋다
//
//	//	하드디스크에 저장할 파일을 덧붙여쓰기 모드로 연다
//	std::ofstream out(" 2019 STL 화56금23 강의저장.txt", std::ios::app);
//
//	//	저장한 시간도 기록한다
//	//	1970 이후의 틱수를 얻어온다
//	auto tick = std::chrono::system_clock::now();
//
//	//	time 형식으로 변환한다
//	auto time = std::chrono::system_clock::to_time_t(tick);
//
//	//	글자로 바꾼다
//	std::string date(ctime(&time));
//
//	out << std::endl << std::endl;
//	out << "==========================" << std::endl;
//	out << " " << date;;
//	out << "==========================" << std::endl;
//	out << std::endl;
//
//
//	//	읽은 모든 내용을 쓴다
//	copy(std::istreambuf_iterator<char>(in),
//		std::istreambuf_iterator<char>(),
//		std::ostreambuf_iterator<char>(out));		//copy(어디부터, 어디까지, 어디로) copy 함수의 인자
//}

#include <iostream>
#include <random>
#include "save.h"

using namespace std;

// {1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };   이니셜라이저 리스트


//a는 전역 변수이다 = 어디에 (실행 파일의 어디에) 저장이 되는가?
//지역변수와 차이점은 무엇인가?
//a는 실행파일에서 어떻게 기록되는가?


//int a[1000'0000];
//int a[1000'0000] = {1};
//이 두 경우에 실행파일(*exe)의 크기는 매우 다르다. 왜 그런지 알아보자


//지역 변수를 크게 만들면 오류가 남

int main()
{
	// 정수 10000000개를 생성하여 정렬해 보자
	//int a[] { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 }; // 일관된 초기화
	
	int * a;
	int num;

	cout << "원하는 만큼 정수를 동적하랑하여 정렬 후 앞에서 100게를 출력합니다." << endl;
	cout << "1000 이상 정수를 입력하세요 : ";
	cin >> num;

	a = new int[num];

	uniform_int_distribution<> uid;
	default_random_engine dre;

	for (int i = 0; i < num; i++)
		a[i] = uid(dre);


	// sort(어디부터, 어디까지, 어떻게);	어떻게 = 함수의 시작번지	알고리즘 함수니까 알고리즘 헤더파일 추가하자
	sort(a, a + num, [](int a, int b) {
		return a < b;
	});
	//	begin(a) = &a[0]   end(a) = &a[10], end는 마지막 변수 다음까지다

	for (int i = 0; i<1000; i++)
		cout << a[i] << ' ';
	cout << endl;

	//save("소스.cpp");
}