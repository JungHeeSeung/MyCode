//		�˰��� �ð� ��� ���
//		callable type�� ǥ���ϴ� Ŭ����
//		smart pointer
//		�ڿ��� Ȯ���ϴ� Ŭ���� ����� �α�(�̵�, STL�� ����� �� Ŭ����)



/*														�ð� ��� �ڵ�

//#include <iostream>
//#include <thread>
//#include <chrono>
//
//using namespace std;
//
//
////�ð� ���
//
//int main()
//{
//	using namespace std::chrono;
//
//	auto b = chrono::steady_clock::now();
//	// �ð� ��� ����
//
//	//	�ð� ����� �ڵ�
//
//
//
//
//	cout << duration_cast<milliseconds>(steady_clock::now() - b).count() << "�� �ɸ�" << endl;
//	//�ð� ���
//}




*/


#include <iostream>

using namespace std;

//	ȣ�Ⱑ�� Ÿ��

int sq(int a) { return a * a; }

class Dog {
public:
	void operator()() {
		cout << "��" << endl;
	}

	void bark() {	// ��� ��� ������ ���� �ڽ��� ���� ������ ���� ���⼭�� Ŭ������ Dog �� �޾���
		cout << "��������ھ�" << endl;
	}
};

int main()
{
	// 1. �Ϲ� �Լ�
	int (*f1)(int) = sq;

	cout << f1(3) << endl;
	cout << typeid(f1).name() << endl;

	// 2. ����(lambda) �Լ�
	auto f2 = []() { cout << " �ȳ� �� ���ٶ�� �� " << endl; };
	f2();
	cout << typeid(f2).name() << endl;


	//	3.�Լ���ü ~ �Լ�ȣ�⿬���ڸ� �����ε��� Ŭ������ ��ü
	Dog d;
	d();
	cout << typeid(d).name() << endl;

	//	4.����Լ� 
	void (Dog::*f4)() = &Dog::bark;		// ��� �Լ��� ������ �����ϱ�
	f4();
}
