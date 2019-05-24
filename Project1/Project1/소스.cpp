//---------------------------------------------------------------
//����
//	sort			 - �Ϲ� ���Ŀ� ���		n log n
//	stable_sort		 - (���� �������� ���� ������) ������ ������ �����ϸ� ����, ���� ����
//	partial_sort	 - ����� �Ű� n���� �̴´�
//	nth_element		 - ������ ���� 10���� �������� ��󳽴�
//
//	partition		 - ���ǿ� �´� �͸� ���� �и��Ѵ�
//
//	is_sorted		 - ���ĵǾ��� �����
//	merge			 - �� �ڷḦ ��ģ��. ���� ������ ����
//	binary_serach	 - ���ĵ� �ڷῡ�� ã�� ��ü�� ���� ������ ����
//	equal_range		 - ���ĵ� �ڷῡ�� ���� ��ü�� ã�� �� ���
//---------------------------------------------------------------
//�˻�
// find
// find_if
// find_if_not
// find_first_of_all
// adjacent_find
// find_end
//-------------------------
// search
// search_n

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <random>
#include "MemoryMonster.h"

using namespace std;

int main()
{
	string s;
	
	vector<int> v;

	default_random_engine dre;
	uniform_int_distribution<> uid(1, 1000);

	for (int i = 0; i < 10000; ++i)
	{
		v.push_back(uid(dre));
	}

	sort(v.begin(), v.end());

	// [����] 777�� �ֳ� ã�ƶ�
	// �ִٸ� ��� �ִ��� ��ġ�� (���° ��������) ��� ����϶�
	
	auto b = binary_search(v.begin(), v.end(), 777);

	if (b) {
		cout << "777�� �ִ�" << endl;
		auto p = equal_range(v.begin(), v.end(), 777);

		for (auto i = p.first; i < p.second; ++i)
			cout << "��ġ�� - " << distance(v.begin(), i) + 1 << endl;
	}
	else
		cout << "777�� ����" << endl;
		
}