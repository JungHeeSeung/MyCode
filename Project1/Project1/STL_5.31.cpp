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
//	cout << "벡터의 원소 갯수 - " << my_distance(v.begin(), v.end()) << endl;
//
//	list<int> l{1, 2, 3, 4, 5};
//	cout << "리스트의 원소 갯수 - " << my_distance(l.begin(), l.end()) << endl;
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


// 학과 자료실에서 단어들.zip을 받자
//
// 1. 사용자가 입력한 단어가 단어들에 있는지 확인한다
// 2. 있다면
//		입력한 단어와 anagram 관계인 단어를 모두 찾아 화면에 출력한다.
//
//
// 3. 단어들.txt에 있는 모든 단어에서 서로 angram 관계인 단어들을 출력하자
// 4. anagram 쌍은 몇 개가 있는가
// 5. 가장 갯수가 많은 anagram 쌍은 무엇인가

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
	cout << "아나그램 찾아 드려용~" << endl;
	cout << "--------------------------------------" << endl << endl; 

	while (true)
	{
		cout << "찾을 단어를 입력하시오: ";
		cin >> target;

		bool b = binary_search(v.begin(), v.end(), target);

		if (b) {	//	사전에 있다면?
			cout << target << "의 anagram을 찾는 중..." << endl << endl;
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
			cout << target << " 는 없다!" << endl << endl;


	}
}

void readData()
{
	ifstream in("단어들.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "모두 " << v.size() << "개의 단어를 읽었다." << endl << endl;
}