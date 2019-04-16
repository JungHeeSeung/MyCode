//===================================

//2019 STL 3.12 ȭ56		(2�� 1��)
//
//		- �����Ͽ� ���Ͽ� ����Ѵ�.
//			? ���� ������ ����Ϸ��� �� ����Ʈ �� �ʿ�����???? (40000 ����Ʈ)
//			? ������ 2���� ���(text, binary)�� �� �� �ִ�. ���� �غ���
//
//
//		- binary I/O 
//
//		��ü�� ���� �����ϰ� �о����
//		smart_�Ӥ�?
//===================================


#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
#include"save.h"

#include<iomanip>	//

//using namespace std;



int main()
{
	// ���� ������ �����Ͽ� ���� �� ���Ͽ� ����϶�

	int* num = new int[1'0000];
	//std::sort(num, num + 10000);

	std::uniform_int_distribution<> uid(0,10000);
	std::default_random_engine dre;

	for (size_t i = 0; i < 10000; i++)
		num[i] = uid(dre);

	std::sort(num, num + 10000);

	//���ĵ� a �� ���Ͽ� �� ����

	std::ofstream out("������������.dat",std::ios::binary);

	//for (int i = 0; i < 10000; i++)
	//{
	//	out<<num[i];
	//}
	//out.close();

	// ������ �������� �ʰ� �����Ѵٸ� 10000�� * sizeof(int) ����Ʈ�� �ʿ��ϴ�
	// ���ӵ� ������ �� ���� �����ϴ� ����� ����Ѵ�.
	//out.write(reinterpret_cast<char*>(num), 10000 * sizeof(int));	//�������δ� �̰�

	out.write((char*)num, 10000 * sizeof(int));
	delete[] num;


	//======================================================
	//binary ���� �о ����ϱ�
	//======================================================



	// ���Ͽ��� ���� 10000���� binary mode�� ���� �Ǿ��ִ�.
	// "���� ���� ����.dat" �� �о� ȭ�鿡 ����϶�.
	int *a = new int[10000];
	std::ifstream in("������������.dat", std::ios::binary);
	//in.read((char*)num, 10000 * sizeof(int));
	in.read((char*)a, 10000 * sizeof(int));

	for (size_t i = 0; i < 10000; i++)
	{
		std::cout <<std::setw(6) << a[i];
		if (i%5 ==0)
			std::cout << std::endl;
	}
	
	delete[] a;

	
	
	//save("�ҽ�3.cpp");	// ���� ���ڿ��� ���������� data ���׸�Ʈ�� ����.


}

