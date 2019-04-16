//===================================

//2019 STL 3.12 화56		(2주 1일)
//
//		- 정렬하여 파일에 기록한다.
//			? 정수 만개를 기록하려면 몇 바이트 가 필요하지???? (40000 바이트)
//			? 파일은 2가지 모드(text, binary)로 열 수 있다. 공부 해보자
//
//
//		- binary I/O 
//
//		객체를 쓰고 정렬하고 읽어오자
//		smart_머ㅜ?
//===================================


#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
#include"save.h"

#include<iomanip>	//

//using namespace std;



int main()
{
	// 정수 만개를 생성하여 정렬 후 파일에 기록하라

	int* num = new int[1'0000];
	//std::sort(num, num + 10000);

	std::uniform_int_distribution<> uid(0,10000);
	std::default_random_engine dre;

	for (size_t i = 0; i < 10000; i++)
		num[i] = uid(dre);

	std::sort(num, num + 10000);

	//정렬된 a 를 파일에 써 보자

	std::ofstream out("정수만개정렬.dat",std::ios::binary);

	//for (int i = 0; i < 10000; i++)
	//{
	//	out<<num[i];
	//}
	//out.close();

	// 공간을 낭비하지 않고 저장한다면 10000개 * sizeof(int) 바이트가 필요하다
	// 연속된 공간을 한 번에 저장하는 명령을 사용한다.
	//out.write(reinterpret_cast<char*>(num), 10000 * sizeof(int));	//정식으로는 이거

	out.write((char*)num, 10000 * sizeof(int));
	delete[] num;


	//======================================================
	//binary 파일 읽어서 출력하기
	//======================================================



	// 파일에는 정수 10000개가 binary mode로 저장 되어있다.
	// "정수 만개 정렬.dat" 을 읽어 화면에 출력하라.
	int *a = new int[10000];
	std::ifstream in("정수만개정렬.dat", std::ios::binary);
	//in.read((char*)num, 10000 * sizeof(int));
	in.read((char*)a, 10000 * sizeof(int));

	for (size_t i = 0; i < 10000; i++)
	{
		std::cout <<std::setw(6) << a[i];
		if (i%5 ==0)
			std::cout << std::endl;
	}
	
	delete[] a;

	
	
	//save("소스3.cpp");	// 안의 문자열은 전역변수라서 data 세그먼트에 들어간다.


}

