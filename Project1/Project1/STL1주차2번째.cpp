////	2019 STL 3.8 ��23
////
////	���� ������ ��������
////	�����ϴ� �Լ��� ����� file�� �и�����
////
////	-���� ���� �ڷḦ �ٷ�� ���� ������ ����
////		���� ���� ��� �ٷ�°�?
//			�ڷῡ ��� �ִ°�?
//		
//		-���� 1������ �����ϰ� �����Ѵ�
//			�����Ͽ� ���Ͽ� ����Ѵ�
//			binary I/O 

////	-å�� ���� �� ����
//
//#include <iostream>
//#include <string>
//#include <fstream>
//#include <algorithm>
//#include <iterator>
//#include <chrono>
//
//
//void save(std::string);
//
//int main()
//{
//	save("20190308STL.cpp");	//data ���׸�Ʈ�� �����
//}
//
//void save(std::string fname)
//{
//	//	fname�� �б� ���� ����
//	std::ifstream in( fname );
//	// if (!in) ó�� �� ���� ��Ȳ�� ����ó�� �ϸ� ����
//
//	//	�ϵ��ũ�� ������ ������ ���ٿ����� ���� ����
//	std::ofstream out(" 2019 STL ȭ56��23 ��������.txt", std::ios::app);
//
//	//	������ �ð��� ����Ѵ�
//	//	1970 ������ ƽ���� ���´�
//	auto tick = std::chrono::system_clock::now();
//
//	//	time �������� ��ȯ�Ѵ�
//	auto time = std::chrono::system_clock::to_time_t(tick);
//
//	//	���ڷ� �ٲ۴�
//	std::string date(ctime(&time));
//
//	out << std::endl << std::endl;
//	out << "==========================" << std::endl;
//	out << " " << date;;
//	out << "==========================" << std::endl;
//	out << std::endl;
//
//
//	//	���� ��� ������ ����
//	copy(std::istreambuf_iterator<char>(in),
//		std::istreambuf_iterator<char>(),
//		std::ostreambuf_iterator<char>(out));		//copy(������, ������, ����) copy �Լ��� ����
//}

#include <iostream>
#include <random>
#include "save.h"

using namespace std;

// {1, 3, 5, 7, 9, 2, 4, 6, 8, 10 };   �̴ϼȶ����� ����Ʈ


//a�� ���� �����̴� = ��� (���� ������ ���) ������ �Ǵ°�?
//���������� �������� �����ΰ�?
//a�� �������Ͽ��� ��� ��ϵǴ°�?


//int a[1000'0000];
//int a[1000'0000] = {1};
//�� �� ��쿡 ��������(*exe)�� ũ��� �ſ� �ٸ���. �� �׷��� �˾ƺ���


//���� ������ ũ�� ����� ������ ��

int main()
{
	// ���� 10000000���� �����Ͽ� ������ ����
	//int a[] { 1, 3, 5, 7, 9, 2, 4, 6, 8, 10 }; // �ϰ��� �ʱ�ȭ
	
	int * a;
	int num;

	cout << "���ϴ� ��ŭ ������ �����϶��Ͽ� ���� �� �տ��� 100�Ը� ����մϴ�." << endl;
	cout << "1000 �̻� ������ �Է��ϼ��� : ";
	cin >> num;

	a = new int[num];

	uniform_int_distribution<> uid;
	default_random_engine dre;

	for (int i = 0; i < num; i++)
		a[i] = uid(dre);


	// sort(������, ������, ���);	��� = �Լ��� ���۹���	�˰��� �Լ��ϱ� �˰��� ������� �߰�����
	sort(a, a + num, [](int a, int b) {
		return a < b;
	});
	//	begin(a) = &a[0]   end(a) = &a[10], end�� ������ ���� ����������

	for (int i = 0; i<1000; i++)
		cout << a[i] << ' ';
	cout << endl;

	//save("�ҽ�.cpp");
}