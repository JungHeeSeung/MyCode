// deque : double-ended queue, "��"�̶� �д´�.
// ó�� �ð��� ����ð��̴�.

#include <iostream>
#include <list>
#include <string>
#include "MemoryMonster.h"

using namespace std;

// deque�� MemoryMonster {10, 20, 30}�� �߰��غ���
// deque�� ���Ҹ� ȭ�鿡 ����غ���
// �ӵ��� ����ϰ� ���Ǽ��� �����..
// �޸� ��ϵ��� �� �ڷ� �����Ѵ�

// �ҽ�.cpp
// deque�� �����ϰ�
// ȭ�� �ڿ������� ����϶�


// list�� MemoryMonster 3���� �߰�
// �� ���Ҹ� ���

int main()
{
	list<MemoryMonster> monsters;

	// ����Ʈ���� ���̰� 10���� ���� ���Ҹ� �����϶�.
	// monsters.remove_if(); �� ����ؼ� ��������

	auto p = monsters.begin();
	p = monsters.emplace(p, 10);
	p = monsters.emplace(p, 20);
	p = monsters.emplace(p, 30);

	for (MemoryMonster & d : monsters)
	{
		cout << d << endl;
	}
}

// list
// list ������ �����̳ʴ� ���Һ��� �� ū �޸𸮸� ����Ѵ�
// �޸𸮸� ���� �� ������
// ���԰� ������ ����ð� ��ŭ �ɸ�