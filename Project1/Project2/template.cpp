#include<iostream>
#include<string>

//generic �ϴ� - ������ Ÿ�Կ� ����� ����.


class X
{
	int num;
public:
	X(int x) : num(x){};	// �̰� ����??
	friend std::ostream& operator<<(std::ostream& os, const X& x);
};

std::ostream& operator<<(std::ostream& os, const X& x)
{
	os << x.num;
	return os;
}

//void change(X &a, X& b)	// X �ڷ����� �ٲ� �� �ִ� �Լ�
//{
//	X temp{ a };
//	a = b;
//	b = temp;
//};

template<typename T>	// templete���� � �ڷ����̵� �����ϰ� �������.

void change(T &a, T&b)
{
	T temp{ a };
	a = b;
	b = temp;
};

#include<algorithm>
int main()
{
	//X a{ 1 }; // a�� 1�� �ʱ�ȭ
	//X b{ 2 };
	//
	//change(a, b);
	//
	//std::string c{ "�ϼ���" };
	//std::string d{ "�ȳ�" };
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


