//===================================
//
//2019 STL 4.02 ȭ56		(5�� 1��)
//
//	2�� ���� �����̳� (sequence container, (homogeneous data type �� ��´�.))
//	  array : smart �� �迭, []�� �Ϻ��ϰ� ��ġ�Ѵ�.
//	- vector : dinamic array (STL ���Ǽ���)
//	  deque
//	  list
//	  forward_list
//
//===================================

// ���� �����̳����� ������ �ִ� �����̳ʰ� �ƴϴ�.
// ���� include �ؾ� ��� ����

#include<iostream>
#include<vector>
#include<array>

#include"MemoryMonster.h"

using namespace std;



#include<random>
#include<algorithm>

//int main()
//{
//
//	vector<MemoryMonster> v;
//	v.reserve(2);	// ������ �̸� �����ϴ� �Լ� *******************
//
//	uniform_int_distribution<> uid(10, 70);
//	default_random_engine dre;
//
//	cout << "push_back ��" << endl << endl;
//	for (size_t i = 0; i < 2; ++i)
//		v.emplace_back(uid(dre));
//	cout << "push_back ��" << endl << endl;
//
//
//	array<MemoryMonster, 10> a{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//	vector<MemoryMonster> v (a.begin(), a.end());
//
//	for (auto i = v.begin(); i < v.end(); ++i)
//	{
//
//	}
//
//}





// �Է��ڷᱸ�� - Ű����
// ����ڷᱸ�� - ȭ��

// Ű���忡�� string�� �о� ������������ �����Ͽ� ����϶�.
// �ҽ�.cpp ���� char�� �о� ������������ �����Ͽ� ����϶�.
#include<string>
//#include<iterator>
#include<algorithm>
#include<fstream>
int main()
{
	//vector<string> v (Ű���� �Է� ����, �Է� ��);
	ifstream in("�ҽ�.cpp");
	vector<char> v{ istream_iterator<char>(in), istream_iterator<char>() }; //{} �� () �� ǥ���ϸ� �Լ��� �ν��Ѵ�.
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<char>(cout, "\t"));


	////2�� ���� ==============
	//vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() }; //{} �� () �� ǥ���ϸ� �Լ��� �ν��Ѵ�.
	//sort(v.begin(), v.end());
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	////2�� ���� ==============


	// for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;
}

// ���Ϳ� ���Ҹ� �߰��� �߰�������
// ������ ���Ұ� ���� �Ǿ�����
// MemoryMonster �� ����Ͽ� ����




//=====================================================================
//=====================================================================



// uid(dre) ���� �ӽ� ��ü�� �����
// push_back ���� �־��ְ�
// �̵������ڰ� �Ҹ��鼭 vector�� �ְ�??
// �ӽð�ü ���� ���� ��������
// ���� ������ �ӽð�ü�� �������.

// push �� ���ؿ� ������ٰ� ������ �Ѱ������� 
// emplace �� ���� �ٷ� ����� ������. (�ξ� ����)

// vector�� �޸� ũ�Ⱑ �������� ���� ��Ȳ�� �������� �ִ°��̰�
// ũ�Ⱑ ������ �ִٸ� array�� ���°� �´�.



//=====================================================================
//=====================================================================
