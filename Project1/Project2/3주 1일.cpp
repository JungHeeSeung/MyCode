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
#include<thread>

#include<random>

#include"save.h"

using namespace std;

// Ŭ���� ����
// �޸𸮸� �Ҹ��ϴ� MemoryMonster Ŭ������ �ִ�.
// ������ ���ڷ� �޾� �� ���ڸ�ŭ �޸�(byte) �� HEAP���� Ȯ���Ѵ�.
// main()�� ������ ������ Ŭ������ ������


// ������ �ڿ��� Ȯ���ϴ� Ŭ������ ��쿡�� 
// 1. �����ڿ��� new�ڿ��� Ȯ���Ѵ�.
// 2. �Ҹ��弭 delete�� �����Ѵ�.
// 3. ��������ڿ��� ���� ���簡 �ǵ��� �Ѵ�.
// 4. �����Ҵ翬���ڿ��� ���� ���簡 �ǵ��� �Ѵ�.
//
// C++ 11�� �̵��ǹ̷�(move semantics) �� �����Ϸ���
//
// 5. �̵������ڸ� �����.
// 6. �̵��Ҵ翬���ڸ� �����.




class MemoryMoster
{
public:

	int getNum() const {
		return num;
	};

	void reset(int n)
	{
		num = n;
		p = new char[num];	// �޸�
		for (int i = 0; i < num; i++)
			p[i] = i + 1;
	}

	MemoryMoster() = default;

	//������
	MemoryMoster(int n): num{n}{
		p = new char[num];	// �޸�
		for ( int i = 0; i < num; i++)
			p[i] = i + 1;
	};
	~MemoryMoster(){
		//cout << "�Ҹ��� - " << this << endl;
		if (p != nullptr)
			delete[] p;
	};

	//���� ���� ==========================
	// ���� ������
	MemoryMoster(const MemoryMoster& other) : num(other.num){
		p = new char[num];
		memcpy(p, other.p, num);
	}
	//�����Ҵ翬����
	MemoryMoster& operator=(const MemoryMoster& other){
		if (this == &other)
			return *this;
		delete[] p;

		p = new char[num];
		memcpy(p, other.p, num);
		return *this;
	}
	//���� ���� ==========================


	//�̵�================================
	//�̵�������
	MemoryMoster(MemoryMoster&& other) : num{other.num} {
		p = other.p;
		other.p = nullptr;
		other.num = 0;
	}
	//�̵��Ҵ翬����
	MemoryMoster& operator=(MemoryMoster&& other){
		delete[] p;
		num = other.num;
		p = other.p;
		other.p = nullptr;
		other.num = 0;
		return *this;
	}
	//�̵�================================

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
//	MemoryMoster a { 123 };	// HEAP���� 123 ����Ʈ�� Ȯ���� ��
//							// �޸��� ���� 1���� 123������ �ǵ��� �����Ѵ�.
//	MemoryMoster b = move(a);	//�����ϸ� �̵� ���ְڴ°�? ��¶�	���� ���� ���簡 �Ͼ����
//
//	save("3�� 1��.cpp");
//}

int main()
{
	//100������ ���͸� �����
	MemoryMoster monster[100];

	//�� ������ num ��ġ�� uid(dre) ����(1~128) ������ �����϶�
	uniform_int_distribution<> uid(1,128);
	default_random_engine dre;

	for (MemoryMoster& d : monster)
		d.reset(uid(dre));

	// ������ num ������������ �����϶�.
	sort(begin(monster), end(monster), [](const MemoryMoster& a,const MemoryMoster& b) {
		return a.getNum() < b.getNum();
	});

	// ���ĵ� ���͸� ����϶�.
	for (MemoryMoster& d : monster)
	{
		cout << d << endl;
	}


}