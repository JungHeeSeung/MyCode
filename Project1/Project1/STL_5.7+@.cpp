#include <iostream>
#include <unordered_map>
#include <string>
#include <map>
#include <vector>
#include "MemoryMonster.h"

using namespace std;

//-----------------------------------------------------------------------------------
// �����̳��� ����
// �ݺ����� ����
// ���� 3���� �� ������ �ſ� �߿��ϴ�
// �� �о��
// 
// Associative Containner (���� �����̳�)
//		map - dictionary <ket, value> ���� ����
//		set - <key>�� ����
//
// Unordered Associative Container (�������� ���� �����̳�, Hash)
//		unordered_map
//		unordered_set
//		�޸𸮸� ����ϰ� ã�� �ð��� �ش������� ���̷��� �����
//-----------------------------------------------------------------------------------

class Dog {
	string name;

public:
	Dog(string f_name) : name(f_name)
	{
	}

	string getName() const
	{
		return name;
	}

	bool operator==(const Dog& rhs) const
	{
		return name == rhs.name;
	}
};

class X {

public:
	size_t operator()(const Dog& a) const {
		return hash<string>()(a.getName());
	}
};

template<>
struct hash<Dog>
{
	int operator()(const Dog& d)const {
		return hash<string>() (d.getName());
	}
};

int main()
{
	// ��ȭ��ȣ�� ������ ����
	// map�� �ٸ� ���� ����?

	// hash �Լ��� ����ϴµ�
	// �⺻ �ڷ��� �ۿ� �غ� �� �Ǿ� ����
	// ���� ���� �ؽ��� ��������

	unordered_map<Dog, int> dogs;

	dogs.emplace("�۸���", 3);
	dogs.emplace("�����", 5);
	dogs.emplace("ůů��", 8);
	dogs.emplace("�̻�", 1);

	for (int i = 0; i < dogs.bucket_count(); ++i)
	{
		cout << " [ " << i << " ] --- ";

		if (dogs.bucket_size(i))
		{
			for (auto b = dogs.begin(i); b != dogs.end(i); ++b)
				cout << b->second << " ";
		}
		cout << endl;
	}

	// ã��
	// �� ������ �� �� �Ǵ°�?
	//dogs["�۸���"];

	cout << dogs[string("�۸���")] << endl;

}

// Key ���� ���� ��ġ�� �����
// �� ��ġ�� Value ���� �ִ´�
