//===================================
//
//2019 STL 3.19 ȭ56		(3�� 1��)
//
//	�ڿ��� Ȯ���ϴ� Ŭ���� ����� �α�(�̵�, STL�� ����� �� Ŭ����)
//	smart Pointer
//	
//	���� : #include"MemoryMonster.h"�� �����.
//
//===================================


#include<iostream>
#include<random>
#include"save.h"
#include"MemoryMonster.h"

using namespace std;

//Ȯ���� �޸𸮸� �ҹ��ڷ� ä����??


int main()
{
	//100������ ���͸� �����
	MemoryMonster monster[10000];

	//�� ������ num ��ġ�� uid(dre) ����(1~128) ������ �����϶�

	uniform_int_distribution<> uid(1,80);
	default_random_engine dre;

	for (MemoryMonster& d : monster)
		d.reset(uid(dre));

	// ������ num ������������ �����϶�.
	sort(begin(monster), end(monster), 
		[](const MemoryMonster& a, const MemoryMonster& b) {	//&�� �Ⱥ��̸� ��ü�� ���ܼ� ������??? ū��
		return a.getNum() < b.getNum();
	});



	// ���ĵ� ���͸� ����϶�.
	for (MemoryMonster& d : monster)	//&�� ���� ������ ��������� �ȴ�.
	{
		cout << d << endl;
	}


}