#include<iostream>
#include<random>
#include<algorithm>
#include<fstream>
#include<cstring>
#include"save.h"


using namespace std;


#define NUM_OF_DOG 1000
//constexpr int NUM_OF_DOG {100};


std::uniform_int_distribution<> uid_name('A', 'Z');
std::uniform_int_distribution<> uid_age(0, 20);
std::default_random_engine dre;

class Dog
{
public:
	Dog(){
		for (size_t i = 0; i < 10; i++)
			name[i] = uid_name(dre);
		name[10] = '\0';
		age = uid_age(dre);
	}

	string getName() const {
		return string(name);
	}
	
	friend ostream& operator<<(ostream&, const Dog&);

private:
	char name[11];	//�̸��� 10���ڱ��� ���
	int age;
	// 16����Ʈ�̴� ��????
	//		-�޸𸮸� 4����Ʈ ������ �о(2**n ���� ���°� ����.)
};

ostream& operator<<(ostream& os, const Dog& dog)
{
	os << "�̸�: " << dog.name << ", ����: " << dog.age;
	return os;
}


int main()
{
	// Dog 1000���� ��������
	Dog dogs[1000];


	// �̸� ������������ ��������
	std::sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) { 
		return a.getName() < b.getName();
	});


	// ����� "DogNameAscend.dat", ���̳ʸ� ���� ��������

	std::ofstream out("DogNameAscend_2.dat", std::ios::binary);

	out.write((char*)dogs, NUM_OF_DOG * sizeof(Dog));

	out.close();




	// DogNameAscend.dat�� �о� ȭ�鿡 �� ����.


	std::ifstream in("DogNameAscend_2.dat", std::ios::binary);

	//Dog 1 ������ �о����.
	//in.read((char*)&dogs, sizeof(Dog));
	//cout << "�̸�: " << (char*)&dogs << endl;

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		in.read((char*)dogs, sizeof(Dog));		//dogs �� &��???
		cout << "�̸�: " << (char*)&dogs << endl;
	}
	
	//in.read((char*)dogs, sizeof(Dog) * NUM_OF_DOG);
	//for (size_t i = 0; i < NUM_OF_DOG; i++)
	//	cout << dogs[i] << endl;

}


