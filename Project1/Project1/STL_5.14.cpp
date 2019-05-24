//----------------------------------------------
//
//
//
//STL 표준을 만족하는
//		반복자 만들기
//		컨테이너 만들기
//
//
//
//----------------------------------------------


#include <iostream>
#include <algorithm>
#include <iterator>
#include "MemoryMonster.h"

using namespace std;

int main()
{
	MemoryMonster m{ 33 };
	// 글자를 거꾸로 찍도록 역반복자를 코딩하라

	copy(m.begin(), m.end(), ostream_iterator<char>(cout));
	cout << endl;

	sort(m.rbegin(), m.rend());

	for (char c : m)
	{
		cout << c;
	}

	cout << endl;
}