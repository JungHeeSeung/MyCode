#include "MemoryMonster.h"
#include <algorithm>
#include <random>
#include <string>

using namespace std;

// 정수를 입력을 받아 MemoryMonster를 생성하라
// 글자의 갯수는 (10 ~ 70)로 하라
// num 오름차순으로 정렬한 후 화면에 출력하라

int main()
{
	cout << "만들 갯수를 입력하세요: ";
	int num;
	cin >> num;

	default_random_engine dre;
	uniform_int_distribution<> uid(10, 70);

	MemoryMonster * p = new MemoryMonster[num];


	for (int i = 0; i < num; i++)
	{
		p[i].set(uid(dre));
	}

	sort(p, p + num, [](const MemoryMonster& a, const MemoryMonster& b) {
		return a.get() < b.get();
	});

	for (int i = 0; i < num; i++)
	{
		cout << p[i] << endl;
	}

	delete[] p;

}


//	unique_ptr - 자원을 독점한다		
//	초기화는 가능하나 대입이나 복사는 허용하지 않음
//	만들 때는 확실하게 자원을 독점하게 만들자

//	shared_ptr - 자원을 공유한다(자원이 귀하다)

//int main()
//{
//	// MemoryMonster 5개 만들고 정렬 후 출력
//
//	auto p = make_unique<MemoryMonster[]>(5);
//
//
//	for (int i = 0; i < 5; i++)
//		p[i].set(i + 10);
//
//	sort(&p[0], &p[5], [](const MemoryMonster& a, const MemoryMonster& b) {
//		return a.get() > b.get();
//	});
//
//	for (int i = 0; i < 5; ++i)
//	{
//		cout << p[i] << endl;
//	}
//
//}


//	62쪽
//	std::string 객체로 된 배열을 정의하고, 자신이 선택한 단어들로 초기화한 후
//	반복자를 사용해 배열의 내용을 한 줄에 하나씩 출력하는 프로그램을 작성하라
//	반복자란? 디자인 패턴 중 하나임	

//int main()
//{
//	string s[5]{"3월", "22일", "MT", "베어스타운", "미세먼지없음"};				//RAII
//
//	auto b = rbegin(s);
//
//	while (b != rend(s)) {
//		cout << *b << endl;
//		++b;
//	}
//
//	
//}