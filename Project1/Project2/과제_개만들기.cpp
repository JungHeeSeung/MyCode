#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
#include<cstring>
#include"save.h"


//using namespace std;


#define NUM_OF_DOG 10
//constexpr int NUM_OF_DOG {100};


class Dog
{
public:
	char name[11];	//�̸��� 10���ڱ��� ���
	int age;

	friend std::ostream& operator<<(std::ostream& os, const Dog& x);

private:
	
};


std::ostream& operator<<(std::ostream& os, const Dog& x)
{
	os << x.name << ", " << x.age << std::endl;
	return os;
}

void printInfo(Dog * dogs);

int main()
{
	// Dog 1000���� ��������
	Dog *dogs = new Dog[NUM_OF_DOG];

	std::uniform_int_distribution<> name_uid('A', 'Z');
	std::uniform_int_distribution<> age_uid(0, 20);
	std::default_random_engine dre;

	// �̸��� ������ ���ĺ� 10���� ä����
	// ���̴� 0~20����� ������ uid(dre) �̿��Ͽ� ä����
	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		for (size_t j = 0; j < 11; j++)
		{
			dogs[i].name[j] = name_uid(dre);
		}
		dogs[i].age = age_uid(dre);
	}
	
	// �̸� ������������ ��������
	std::sort(dogs, dogs + NUM_OF_DOG, [](const Dog& a, const Dog& b) { return strcmp(a.name, b.name) < 0; });


	//printInfo(dogs);

	std::cout << "size: " << sizeof(dogs->name) * NUM_OF_DOG + sizeof(dogs->age) * NUM_OF_DOG;		//1500



	// ����� "DogNameAscend.dat", ���̳ʸ� ���� ��������
	
	std::ofstream out("DogNameAscend.dat", std::ios::binary);

	out.write((char*)dogs	, NUM_OF_DOG * sizeof(Dog));
	//out.write((char*)dogs->age	, NUM_OF_DOG * sizeof(Dog));
	delete[] dogs;
	// 16����Ʈ�̴� ��????

	//out.close();

	// ������ ũ�Ⱑ sizeof(Dog) * 1000 ����Ʈ ���� Ȯ������
	//	--> �׷��� �ʴٸ� �� ���� ������!!


	// DogNameAscend.dat�� �о� ȭ�鿡 �� ����.

	Dog *a = new Dog;
	std::ifstream in("DogNameAscend.dat", std::ios::binary);
	//for (size_t i = 0; i < NUM_OF_DOG; i++)
	//{
	//	in.read((char*)&a, sizeof(Dog));// a�����Ϳ� sizeof(Dog) ��ŭ ������ ��������. (16kb)
	//	std::cout << 
	//}

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		if (i % 5 == 0)
			std::cout << std::endl;
		in.read((char*)&a, sizeof(Dog));// a�����Ϳ� sizeof(Dog) ��ŭ ������ ��������. (16kb)
		std::cout << &dogs;
		//std::cout << a[i];
	}

	delete[] a;


	//for (size_t i = 0; i < NUM_OF_DAG; ++i)
	//	std::cout << dogs[i] << std::endl;		//"�̸�: asdfkn, ����: 17"
}

void printInfo(Dog * dogs)
{

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		std::cout << "�̸�: ";
		for (size_t j = 0; j < 11; j++)
		{
			std::cout << dogs[i].name[j];
		}
		std::cout << "	����: " << dogs[i].age;
		std::cout << std::endl;
	}
}
