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
//{							// ����� ���� �ݺ���
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
//	f(v.begin());	 // ���� �＼��
//
//	forward_list<int> fl;
//	f(fl.begin());	// ���� �ݺ���
//
//	ostream_iterator<int> oi(cout);
//	f(oi);			// ��� �ݺ���
//
//	f(istream_iterator<int>());		// �Է� �ݺ���
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

// Ű���忡�� �ܾ �о�� �������� ����϶�
// [��] �ȳ� �ϼ���
//   --> �ϼ��� �ȳ�
// �غ���

int main()
{
	vector<string> v;

	copy(istream_iterator<string>(cin), istream_iterator<string>(),
		back_inserter(v));

	
	for (auto i = v.crbegin(); i < v.crend(); ++i)
		cout << *i << endl;

	//vector<int> v{ 1, 2, 3, 4, 5 };
	//vector<int> w;
	//myCopy(v.begin(), v.end(), back_inserter(w));		// �̷� ������ �������
}

template<typename Src, typename Des>
void myCopy(Src b, Src e, Des d)
{
	while (b != e)
		*d++ = *b++;
}
