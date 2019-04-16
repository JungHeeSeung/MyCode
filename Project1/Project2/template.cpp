#include<iostream>
#include<string>

//generic 하다 - 데이터 타입에 상관이 없다.


class X
{
	int num;
public:
	X(int x) : num(x){};	// 이게 뭐지??
	friend std::ostream& operator<<(std::ostream& os, const X& x);
};

std::ostream& operator<<(std::ostream& os, const X& x)
{
	os << x.num;
	return os;
}

//void change(X &a, X& b)	// X 자료형만 바꿀 수 있는 함수
//{
//	X temp{ a };
//	a = b;
//	b = temp;
//};

template<typename T>	// templete으로 어떤 자료형이든 가능하게 만들었다.

void change(T &a, T&b)
{
	T temp{ a };
	a = b;
	b = temp;
};

#include<algorithm>
int main()
{
	//X a{ 1 }; // a를 1로 초기화
	//X b{ 2 };
	//
	//change(a, b);
	//
	//std::string c{ "하세요" };
	//std::string d{ "안녕" };
	//
	//change(c, d);
	//
	//std::cout << a << ", " << b << std::endl;
	//std::cout << c << ", " << d << std::endl;

	int a[]{ 1, 8, 3, 4, 2, 5, 7, 9 };

	std::sort(std::begin(a), std::end(a));

	for (int d : a)
		std::cout << d << ", ";
	std::cout << std::endl;


}


