// ���� �� ���� ����Ϸ��� �� ����Ʈ�� �ʿ�����? (40000 ����Ʈ)
// ������ 2���� ���� �� �� �ִ�(text, binary) �����غ���
// 
// ��ü�� ���� �����ϰ� �о����
// smart_pointer
//
//
//
//
//
//
//
//

/* ������ �������� �ʰ� �����Ѵٸ� 10000 * sizeof(int) �� �ʿ��ϴ�
	   ���ӵ� ������ �� ���� �����ϴ� ����� ����Ѵ�*/

#include <iostream>
#include <random>
#include <algorithm>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Dog
{
	char name[11];			//�̸��� 10���ڱ��� ����ϰڴ�
	int age;
};

//		�ƽ�Ű �ڵ� ��
//		97 ~ 122   a ~ z
//		65 ~ 90    A ~ Z

int main()
{
	// Dog 1000������ ��������
	// �̸��� ������ ���ĺ����� 10���� ä���
	// ���̴� (0 ~ 20) ���� ������ uid(dre) �̿��Ͽ� ä���

	// �̸��� ������������ �����ϱ�
	// ����� "DogNameAscend.dat", ���̳ʸ� ��� �� ��������
	// ������ ũ�Ⱑ sizeof(Dog) * 1000 ���� Ȯ������
	//		--> �׷��� �ʴٸ� ��ǻ�� ���� ������

	//{
	//	// DogNameAscend.dat �� �о� ȭ�鿡 �Ẹ��
	//	//for (int i = 0; i < 1000)
	//	//{
	//	//	cout << dog[i] << end;				// "�̸� : wefdascx ���� : 17"
	//	//}
	//}
}

//int main(void)
//{
//	// ���Ͽ��� ������ 10000���� binary mode�� ����Ǿ� �ִ�.
//	// "������������.dat"�� �о� ȭ�鿡 ����϶�
//	ifstream in("������������.dat", ios::binary);
//
//	int * a = new int[10000];
//
//	in.read((char*)a, sizeof(int) * 10000);
//
//	for (int i = 0; i < 10000; i++)
//	{
//		cout << a[i] << ' ';
//	}
//	
//	delete[] a;
//}