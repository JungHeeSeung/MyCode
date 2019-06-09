//#include <iostream>
//#include <vector>
//#include <list>
//#include <iterator>
//#include "MemoryMonster.h"
//
//using namespace std;
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e);
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e, random_access_iterator_tag);
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e, input_iterator_tag);
//
//
//int main()
//{
//	vector<int> v{ 1,2,3,4,5 };
//	cout << "������ ���� ���� - " << my_distance(v.begin(), v.end()) << endl;
//
//	list<int> l{1, 2, 3, 4, 5};
//	cout << "����Ʈ�� ���� ���� - " << my_distance(l.begin(), l.end()) << endl;
//
//}
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e)
//{
//	return my_distance(b, e, Iter::iterator_category() );
//}
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e, random_access_iterator_tag)
//{
//	return e - b;
//}
//
//template<class Iter>
//typename Iter::difference_type my_distance(Iter b, Iter e, input_iterator_tag)
//{
//	typename Iter::difference_type cnt{ 0 };
//
//	while (b++ != e)
//		cnt++;
//
//	return cnt;
//}


// �а� �ڷ�ǿ��� �ܾ��.zip�� ����
//
// 1. ����ڰ� �Է��� �ܾ �ܾ�鿡 �ִ��� Ȯ���Ѵ�
// 2. �ִٸ�
//		�Է��� �ܾ�� anagram ������ �ܾ ��� ã�� ȭ�鿡 ����Ѵ�.
//
//
// 3. �ܾ��.txt�� �ִ� ��� �ܾ�� ���� angram ������ �ܾ���� �������
// 4. anagram ���� �� ���� �ִ°�
// 5. ���� ������ ���� anagram ���� �����ΰ�

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<string> v;
void readData();

int main()
{
	readData();
	

	string target;
	cout << "--------------------------------------" << endl;
	cout << "�Ƴ��׷� ã�� �����~" << endl;
	cout << "--------------------------------------" << endl << endl; 

	while (true)
	{
		cout << "ã�� �ܾ �Է��Ͻÿ�: ";
		cin >> target;

		bool b = binary_search(v.begin(), v.end(), target);

		if (b) {	//	������ �ִٸ�?
			cout << target << "�� anagram�� ã�� ��..." << endl << endl;
			string cp{ target };

			do {
				next_permutation(cp.begin(), cp.end());

				cout << cp << '\r';

				if (binary_search(v.begin(), v.end(), cp))
					cout << cp << " ";
			} while (target != cp);
			cout << endl << endl;
		}
		else
			cout << target << " �� ����!" << endl << endl;


	}
}

void readData()
{
	ifstream in("�ܾ��.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "��� " << v.size() << "���� �ܾ �о���." << endl << endl;
}