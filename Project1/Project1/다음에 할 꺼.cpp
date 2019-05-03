//	set 
//	��� �� ��ü�� ������ ������ set�� �˷��ִ°�?
//	multimap�� multiset���� equal_range�� ������ �˾ƺ���
//
//�ݺ��ڸ����
//�����̳� �����
//�˰��� �Լ� �����

#include <iostream>
#include <set>
#include <map>
#include <iterator>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>							
#include"MemoryMonster.h"

using namespace std;

// set�� ������ �� �� �־� ���� ������ ����
// set �� �ݺ��ڴ� ��� const ��
// cbegin �̳� begin �̳� ���̰� ����
// auto i = s.begin();
// *i = 100 �� �Ұ����ϴ�

struct X
{
	bool operator() (int a, int b)
	{
		return a > b;
	}
};

//template <> // template specialization�� �ϸ� �����ϴ�
//struct less<MemoryMonster> {
//	bool operator() (const MemoryMonster& a, const MemoryMonster& b)
//	{
//		return a.getNum() < b.getNum();
//	}
//};



int main()
{
	// �ٸ���.txt�� ��� �ܾ multiset�� �о��.

	ifstream in("�ٸ���.txt");
	multiset<string> words {istream_iterator<string>(in), istream_iterator<string>()};
	multimap<int, string, greater<int>> mm;
	// �ܾ�� ������ ����϶�

	vector<pair<string, int>> v;
	v.reserve(words.size());

	for (auto i = words.begin(); i != words.end(); i = words.upper_bound(*i))
		mm.emplace( words.count(*i), *i);

	auto p = mm.begin();
	for (int i = 0; i < 20; ++i, ++p)
	{
		cout << p->second << " -- > " << p->first << endl;
	}
	
	/*sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	for (int i = 0; i < 20; ++i)
	{
		cout << v[i].first << " - " << v[i].second << endl;
	}*/
	// ������ ���� ���� �ܾ���� 20�� ����غ���
}
