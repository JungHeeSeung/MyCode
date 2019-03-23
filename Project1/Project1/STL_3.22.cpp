#include "MemoryMonster.h"
#include <algorithm>
#include <random>
#include <string>

using namespace std;

// ������ �Է��� �޾� MemoryMonster�� �����϶�
// ������ ������ (10 ~ 70)�� �϶�
// num ������������ ������ �� ȭ�鿡 ����϶�

int main()
{
	cout << "���� ������ �Է��ϼ���: ";
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


//	unique_ptr - �ڿ��� �����Ѵ�		
//	�ʱ�ȭ�� �����ϳ� �����̳� ����� ������� ����
//	���� ���� Ȯ���ϰ� �ڿ��� �����ϰ� ������

//	shared_ptr - �ڿ��� �����Ѵ�(�ڿ��� ���ϴ�)

//int main()
//{
//	// MemoryMonster 5�� ����� ���� �� ���
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


//	62��
//	std::string ��ü�� �� �迭�� �����ϰ�, �ڽ��� ������ �ܾ��� �ʱ�ȭ�� ��
//	�ݺ��ڸ� ����� �迭�� ������ �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��϶�
//	�ݺ��ڶ�? ������ ���� �� �ϳ���	

//int main()
//{
//	string s[5]{"3��", "22��", "MT", "���Ÿ��", "�̼���������"};				//RAII
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