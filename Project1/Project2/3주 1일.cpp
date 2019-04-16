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
#include<thread>

#include<random>

#include"save.h"

using namespace std;

// 클래스 복습
// 메모리를 소모하는 MemoryMonster 클래스가 있다.
// 정수를 인자로 받아 그 숫자만큼 메모리(byte) 를 HEAP에서 확보한다.
// main()이 문제가 없도록 클래스를 만들어라


// 생성시 자원을 확보하는 클래스인 경우에만 
// 1. 생성자에서 new자원을 확보한다.
// 2. 소멸장서 delete로 해제한다.
// 3. 복사생성자에서 깊은 복사가 되도록 한다.
// 4. 복사할당연산자에서 깊은 복사가 되도록 한다.
//
// C++ 11의 이동의미론(move semantics) 을 적용하려면
//
// 5. 이동생성자를 만든다.
// 6. 이동할당연산자를 만든다.




class MemoryMoster
{
public:

	int getNum() const {
		return num;
	};

	void reset(int n)
	{
		num = n;
		p = new char[num];	// 메모리
		for (int i = 0; i < num; i++)
			p[i] = i + 1;
	}

	MemoryMoster() = default;

	//생성자
	MemoryMoster(int n): num{n}{
		p = new char[num];	// 메모리
		for ( int i = 0; i < num; i++)
			p[i] = i + 1;
	};
	~MemoryMoster(){
		//cout << "소멸자 - " << this << endl;
		if (p != nullptr)
			delete[] p;
	};

	//깊은 복사 ==========================
	// 복사 생성자
	MemoryMoster(const MemoryMoster& other) : num(other.num){
		p = new char[num];
		memcpy(p, other.p, num);
	}
	//복사할당연산자
	MemoryMoster& operator=(const MemoryMoster& other){
		if (this == &other)
			return *this;
		delete[] p;

		p = new char[num];
		memcpy(p, other.p, num);
		return *this;
	}
	//깊은 복사 ==========================


	//이동================================
	//이동생성자
	MemoryMoster(MemoryMoster&& other) : num{other.num} {
		p = other.p;
		other.p = nullptr;
		other.num = 0;
	}
	//이동할당연산자
	MemoryMoster& operator=(MemoryMoster&& other){
		delete[] p;
		num = other.num;
		p = other.p;
		other.p = nullptr;
		other.num = 0;
		return *this;
	}
	//이동================================

	friend ostream& operator<<(ostream&, const MemoryMoster&);



private:
	int num{0};
	char* p{nullptr};

};

ostream& operator<<(ostream& os, const MemoryMoster& mm)
{
	for (int i = 0; i < mm.num; i++)
		os << static_cast<int>(mm.p[i]) << ' ';
	return os;
}




//int main()
//{
//	cout << sizeof(MemoryMoster)<<endl;
//
//	MemoryMoster a { 123 };	// HEAP에서 123 바이트를 확보한 후
//							// 메모리의 값은 1부터 123까지가 되도록 설정한다.
//	MemoryMoster b = move(a);	//가능하면 이동 해주겠는가? 라는뜻	지금 깊은 복사가 일어나는중
//
//	save("3주 1일.cpp");
//}

int main()
{
	//100마리의 몬스터를 만들고
	MemoryMoster monster[100];

	//각 몬스터의 num 수치를 uid(dre) 범위(1~128) 값으로 설정하라
	uniform_int_distribution<> uid(1,128);
	default_random_engine dre;

	for (MemoryMoster& d : monster)
		d.reset(uid(dre));

	// 몬스터의 num 오름차순으로 정렬하라.
	sort(begin(monster), end(monster), [](const MemoryMoster& a,const MemoryMoster& b) {
		return a.getNum() < b.getNum();
	});

	// 정렬된 몬스터를 출력하라.
	for (MemoryMoster& d : monster)
	{
		cout << d << endl;
	}


}