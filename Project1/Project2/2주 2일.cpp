//===================================
//
//2019 STL 3.15 금23		(2주 2일)
//
//	알고리즘 시간 재는 방법
//	callable type을 표현하는 클래스
//	smart pointer
//	자원을 확보하는 클래스 만들어 두기(이동, STL에 사용할 내 클래스)
//
//===================================


#include<iostream>
#include<thread>

#include<functional>//????

#include"save.h"

using namespace std;



// 시간재기

//int main()
//{
//	// 시간 재기 시작
//	auto b = chrono::steady_clock::now();
//
//	// 시간이 걸리는 코드
//	// 123밀리초 시간을 써라
//	this_thread::sleep_for(123ms);
//
//	// 시간 재기 끝
//
//	//아래 함수를 한줄로 줄임
//	cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - b).count() << "가 걸렸다." << endl;
//
//
//	//auto e = chrono::steady_clock::now();
//
//	//auto d = e - b;	//시간 간격
//
//	//auto t = chrono::duration_cast<chrono::milliseconds>(d);	//나노s 단위까지 나오기 때문에 바꿔주는 함수
//
//	//cout << t.count() << "가 걸렸다." << endl;
//}



//호출가능 타입
void f()
{
	cout << "왜 부르냐" << endl;
}

void g()
{
	cout << "나도 불러줘" << endl;
}

int sq(int a) { return a * a; }

class Dog
{
public:
	void operator()(){
		cout << "멍?";
	}

	void bark() {	// 함수 인자에 항상 자기자신이 들어있다. 
	// 원래 void bark(Dog* this) 인데 숨어있다.
		cout << "문다 물어";
	}

};

int main()
{
	//auto x = f;
	//x = g;
	//f();

	// ===(반환형 함수 인자)=== *********************************(***********************
	//void(*x)() = f;	//함수 포인터 정식 표기법		<- 호출 가능 함수????
	//x(); 가 가능해진다.

	//int i = 0;
	//while (true)
	//{
	//	x();
	//	if (i++ & 1)
	//		x = f;
	//	else
	//		x = g;
	//}



	//function<리턴값(인자)>	//호출 타입을 통일 시키기 위한 함수이다.

	//1. 일반 함수

	int(*f1)(int) = sq;
	//f1(3);
	
	function<int(int)>f1_1 = sq;

	cout << f1(3) <<endl;

	//2.lambda	-	auto 쓰자
	//[]() {};
	//auto f2 = []() {cout << "안녕 난 람다라고 해" << endl; };
	
	function<void(void)>f2 = []() {cout << "안녕 난 람다라고 해" << endl; };

	cout << typeid(f2).name() << endl;


	//3. 함수 객체 - 함수호출 연산자를 오버로딩한 클래스의 객체
	Dog d;
	//d();	//d.operator()() 와 같다.
	function<void(Dog*)>f3 = &Dog::operator();

	cout << typeid(d).name() << endl;



	//4. 맴버함수		????????
	//방식1
	Dog dog;
	//auto f4 = &Dog::bark;
	void(Dog::*f4_1)(void) = &Dog::bark;
	(dog.*f4_1)();		//?????????????????
	//방식2
	Dog* dog2 = new Dog;
	void(Dog::*f4_2)(void) = &Dog::bark;
	(dog2->*f4_2)();	//?????????????????


	function<void(Dog* const)>f4 = &Dog::bark;	//인자가 없는것 같지만 모든 멤버 변수는 자기자신을 인자로 가지기 때문에
												//이런식으로 쓴다.	3번도 동일


	//멤버함수 포인터 검색해보자



}

