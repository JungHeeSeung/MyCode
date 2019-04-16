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
	char name[11];	//이름을 10글자까지 허용
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
	// Dog 1000마리 생성하자
	Dog *dogs = new Dog[NUM_OF_DOG];

	std::uniform_int_distribution<> name_uid('A', 'Z');
	std::uniform_int_distribution<> age_uid(0, 20);
	std::default_random_engine dre;

	// 이름은 임의의 알파벳 10글자 채우자
	// 나이는 0~20살까지 값으로 uid(dre) 이용하여 채우자
	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		for (size_t j = 0; j < 11; j++)
		{
			dogs[i].name[j] = name_uid(dre);
		}
		dogs[i].age = age_uid(dre);
	}
	
	// 이름 오름차순으로 정렬하자
	std::sort(dogs, dogs + NUM_OF_DOG, [](const Dog& a, const Dog& b) { return strcmp(a.name, b.name) < 0; });


	//printInfo(dogs);

	std::cout << "size: " << sizeof(dogs->name) * NUM_OF_DOG + sizeof(dogs->age) * NUM_OF_DOG;		//1500



	// 결과를 "DogNameAscend.dat", 바이너리 모드로 저장하자
	
	std::ofstream out("DogNameAscend.dat", std::ios::binary);

	out.write((char*)dogs	, NUM_OF_DOG * sizeof(Dog));
	//out.write((char*)dogs->age	, NUM_OF_DOG * sizeof(Dog));
	delete[] dogs;
	// 16바이트이다 왜????

	//out.close();

	// 파일의 크기가 sizeof(Dog) * 1000 바이트 임을 확인하자
	//	--> 그렇지 않다면 내 컴을 버리자!!


	// DogNameAscend.dat를 읽어 화면에 써 보자.

	Dog *a = new Dog;
	std::ifstream in("DogNameAscend.dat", std::ios::binary);
	//for (size_t i = 0; i < NUM_OF_DOG; i++)
	//{
	//	in.read((char*)&a, sizeof(Dog));// a포인터에 sizeof(Dog) 만큼 공간을 연결해줌. (16kb)
	//	std::cout << 
	//}

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		if (i % 5 == 0)
			std::cout << std::endl;
		in.read((char*)&a, sizeof(Dog));// a포인터에 sizeof(Dog) 만큼 공간을 연결해줌. (16kb)
		std::cout << &dogs;
		//std::cout << a[i];
	}

	delete[] a;


	//for (size_t i = 0; i < NUM_OF_DAG; ++i)
	//	std::cout << dogs[i] << std::endl;		//"이름: asdfkn, 나이: 17"
}

void printInfo(Dog * dogs)
{

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		std::cout << "이름: ";
		for (size_t j = 0; j < 11; j++)
		{
			std::cout << dogs[i].name[j];
		}
		std::cout << "	나이: " << dogs[i].age;
		std::cout << std::endl;
	}
}
