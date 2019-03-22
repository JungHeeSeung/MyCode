// 정수 만 개를 기록하려면 몇 바이트가 필요하지? (40000 바이트)
// 파일은 2가지 모드로 열 수 있다(text, binary) 공부해보자
// 
// 객체를 쓰고 정렬하고 읽어오자
// smart_pointer
//
//
//
//
//
//
//
//

/* 공간을 낭비하지 않고 저장한다면 10000 * sizeof(int) 가 필요하다
	   연속된 공간을 한 번에 저장하는 명령을 사용한다*/

#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Dog
{
	char name[11];			//이름을 10글자까지 허용하겠다
	int age;
};

//		아스키 코드 값
//		97 ~ 122   a ~ z
//		65 ~ 90    A ~ Z

int main()
{
	// Dog 1000마리를 생성하자
	// 이름은 임의의 알파벳으로 10글자 채우기
	// 나이는 (0 ~ 20) 까지 값으로 uid(dre) 이용하여 채우기

	// 이름은 오름차순으로 정렬하기
	// 결과를 "DogNameAscend.dat", 바이너리 모드 로 저장하자
	// 파일의 크기가 sizeof(Dog) * 1000 임을 확인하자
	//		--> 그렇지 않다면 컴퓨터 갖다 버리자

	//{
	//	// DogNameAscend.dat 를 읽어 화면에 써보자
	//	//for (int i = 0; i < 1000)
	//	//{
	//	//	cout << dog[i] << end;				// "이름 : wefdascx 나이 : 17"
	//	//}
	//}
}

//int main(void)
//{
//	// 파일에는 정수가 10000개가 binary mode로 저장되어 있다.
//	// "정수만개정렬.dat"을 읽어 화면에 출력하라
//	ifstream in("정수만개정렬.dat", ios::binary);
//
//	int * a = new int[10000];
//
//	in.read((char*)a, sizeof(int) * 10000);
//
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << a[i] << ' ';
//	}
//	
//	delete[] a;
//}