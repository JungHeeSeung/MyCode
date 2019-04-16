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
	char name[11];	//이름을 10글자까지 허용
	int age;
	// 16바이트이다 왜????
	//		-메모리를 4바이트 단위로 읽어서(2**n 으로 가는것 같다.)
};

ostream& operator<<(ostream& os, const Dog& dog)
{
	os << "이름: " << dog.name << ", 나이: " << dog.age;
	return os;
}


int main()
{
	// Dog 1000마리 생성하자
	Dog dogs[1000];


	// 이름 오름차순으로 정렬하자
	std::sort(begin(dogs), end(dogs), [](const Dog& a, const Dog& b) { 
		return a.getName() < b.getName();
	});


	// 결과를 "DogNameAscend.dat", 바이너리 모드로 저장하자

	std::ofstream out("DogNameAscend_2.dat", std::ios::binary);

	out.write((char*)dogs, NUM_OF_DOG * sizeof(Dog));

	out.close();




	// DogNameAscend.dat를 읽어 화면에 써 보자.


	std::ifstream in("DogNameAscend_2.dat", std::ios::binary);

	//Dog 1 마리만 읽어오자.
	//in.read((char*)&dogs, sizeof(Dog));
	//cout << "이름: " << (char*)&dogs << endl;

	for (size_t i = 0; i < NUM_OF_DOG; i++)
	{
		in.read((char*)dogs, sizeof(Dog));		//dogs 앞 &는???
		cout << "이름: " << (char*)&dogs << endl;
	}
	
	//in.read((char*)dogs, sizeof(Dog) * NUM_OF_DOG);
	//for (size_t i = 0; i < NUM_OF_DOG; i++)
	//	cout << dogs[i] << endl;

}


