//----------------------------------------------
//
//
//
//STL ǥ���� �����ϴ�
//		�ݺ��� �����
//		�����̳� �����
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
	// ���ڸ� �Ųٷ� �ﵵ�� ���ݺ��ڸ� �ڵ��϶�

	copy(m.begin(), m.end(), ostream_iterator<char>(cout));
	cout << endl;

	sort(m.rbegin(), m.rend());

	for (char c : m)
	{
		cout << c;
	}

	cout << endl;
}