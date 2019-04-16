//===================================
//
//2019 STL 3.15 ��23		(2�� 2��)
//
//	�˰��� �ð� ��� ���
//	callable type�� ǥ���ϴ� Ŭ����
//	smart pointer
//	�ڿ��� Ȯ���ϴ� Ŭ���� ����� �α�(�̵�, STL�� ����� �� Ŭ����)
//
//===================================


#include<iostream>
#include<thread>

#include<functional>//????

#include"save.h"

using namespace std;



// �ð����

//int main()
//{
//	// �ð� ��� ����
//	auto b = chrono::steady_clock::now();
//
//	// �ð��� �ɸ��� �ڵ�
//	// 123�и��� �ð��� ���
//	this_thread::sleep_for(123ms);
//
//	// �ð� ��� ��
//
//	//�Ʒ� �Լ��� ���ٷ� ����
//	cout << chrono::duration_cast<chrono::milliseconds>(chrono::steady_clock::now() - b).count() << "�� �ɷȴ�." << endl;
//
//
//	//auto e = chrono::steady_clock::now();
//
//	//auto d = e - b;	//�ð� ����
//
//	//auto t = chrono::duration_cast<chrono::milliseconds>(d);	//����s �������� ������ ������ �ٲ��ִ� �Լ�
//
//	//cout << t.count() << "�� �ɷȴ�." << endl;
//}



//ȣ�Ⱑ�� Ÿ��
void f()
{
	cout << "�� �θ���" << endl;
}

void g()
{
	cout << "���� �ҷ���" << endl;
}

int sq(int a) { return a * a; }

class Dog
{
public:
	void operator()(){
		cout << "��?";
	}

	void bark() {	// �Լ� ���ڿ� �׻� �ڱ��ڽ��� ����ִ�. 
	// ���� void bark(Dog* this) �ε� �����ִ�.
		cout << "���� ����";
	}

};

int main()
{
	//auto x = f;
	//x = g;
	//f();

	// ===(��ȯ�� �Լ� ����)=== *********************************(***********************
	//void(*x)() = f;	//�Լ� ������ ���� ǥ���		<- ȣ�� ���� �Լ�????
	//x(); �� ����������.

	//int i = 0;
	//while (true)
	//{
	//	x();
	//	if (i++ & 1)
	//		x = f;
	//	else
	//		x = g;
	//}



	//function<���ϰ�(����)>	//ȣ�� Ÿ���� ���� ��Ű�� ���� �Լ��̴�.

	//1. �Ϲ� �Լ�

	int(*f1)(int) = sq;
	//f1(3);
	
	function<int(int)>f1_1 = sq;

	cout << f1(3) <<endl;

	//2.lambda	-	auto ����
	//[]() {};
	//auto f2 = []() {cout << "�ȳ� �� ���ٶ�� ��" << endl; };
	
	function<void(void)>f2 = []() {cout << "�ȳ� �� ���ٶ�� ��" << endl; };

	cout << typeid(f2).name() << endl;


	//3. �Լ� ��ü - �Լ�ȣ�� �����ڸ� �����ε��� Ŭ������ ��ü
	Dog d;
	//d();	//d.operator()() �� ����.
	function<void(Dog*)>f3 = &Dog::operator();

	cout << typeid(d).name() << endl;



	//4. �ɹ��Լ�		????????
	//���1
	Dog dog;
	//auto f4 = &Dog::bark;
	void(Dog::*f4_1)(void) = &Dog::bark;
	(dog.*f4_1)();		//?????????????????
	//���2
	Dog* dog2 = new Dog;
	void(Dog::*f4_2)(void) = &Dog::bark;
	(dog2->*f4_2)();	//?????????????????


	function<void(Dog* const)>f4 = &Dog::bark;	//���ڰ� ���°� ������ ��� ��� ������ �ڱ��ڽ��� ���ڷ� ������ ������
												//�̷������� ����.	3���� ����


	//����Լ� ������ �˻��غ���



}

