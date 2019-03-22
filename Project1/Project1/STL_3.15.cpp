//		알고리즘 시간 재는 방법
//		callable type을 표현하는 클래스
//		smart pointer
//		자원을 확보하는 클래스 만들어 두기(이동, STL에 사용할 내 클래스)



/*														시간 재는 코드

//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//
////시간 재기
//
//int main()
//{
//	using namespace std::chrono;
//
//	auto b = chrono::steady_clock::now();
//	// 시간 재기 시작
//
//	//	시간 재야할 코드
//
//
//
//
//	cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << "가 걸림" << endl;
//	//시간 출력
//}




*/


#include <iostream>

using namespace std;

//	호출가능 타입

int sq(int a) { return a * a; }

class Dog {
public:
	void operator()() {
		cout << "멍" << endl;
	}

	void bark() {	// 모든 멤버 변수는 본인 자신을 인자 값으로 받음 여기서는 클래스인 Dog 를 받았음
		cout << "물어버리겠어" << endl;
	}
};

int main()
{
	// 1. 일반 함수
	int (*f1)(int) = sq;

	cout << f1(3) << endl;
	cout << typeid(f1).name() << endl;

	// 2. 람다(lambda) 함수
	auto f2 = []() { cout << " 안녕 난 람다라고 해 " << endl; };
	f2();
	cout << typeid(f2).name() << endl;


	//	3.함수객체 ~ 함수호출연산자를 오버로딩한 클래스의 객체
	Dog d;
	d();
	cout << typeid(d).name() << endl;

	//	4.멤버함수 
	void (Dog::*f4)() = &Dog::bark;		// 멤버 함수의 포인터 선언하기
	f4();
}
