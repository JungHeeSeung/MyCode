//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <iterator>
//#include <forward_list>
//#include <list>
//#include "MemoryMonster.h"
//
//using namespace std;
//
//template <class Iter>
//void f(Iter i);
//
//class MyIter : public iterator<input_iterator_tag, int, int*>
//{							// 사용자 정의 반복자
//
//};
//
//template <>
//struct iterator_traits<MyIter> {
//	typedef random_access_iterator_tag iterator_category;
//};
//
//int main()
//{
//	vector<int> v;
//	f(v.begin());	 // 랜덤 억세스
//
//	forward_list<int> fl;
//	f(fl.begin());	// 전진 반복자
//
//	ostream_iterator<int> oi(cout);
//	f(oi);			// 출력 반복자
//
//	f(istream_iterator<int>());		// 입력 반복자
//
//	f(MyIter());
//}
//
//template<class Iter>
//void f(Iter i)
//{
//	cout << typeid(iterator_traits<Iter>::iterator_category).name() << endl;
//}

#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <iterator>
#include <vector>
#include "MemoryMonster.h"

using namespace std;

template <typename Src, typename Des>
void myCopy(Src, Src, Des);

// 키보드에서 단어를 읽어와 역순으로 출력하라
// [예] 안녕 하세요
//   --> 하세요 안녕
// 해보자

int main()
{
	vector<string> v;

	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		back_inserter(v));

	
	for (auto i = v.crbegin(); i < v.crend(); ++i)
		cout << *i << endl;

	//vector<int> v{ 1, 2, 3, 4, 5 };
	//vector<int> w;
	//myCopy(v.begin(), v.end(), back_inserter(w));		// 이런 식으로 집어넣자
}

template<typename Src, typename Des>
void myCopy(Src b, Src e, Des d)
{
	while (b != e)
		*d++ = *b++;
}
