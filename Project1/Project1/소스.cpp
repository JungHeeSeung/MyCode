//---------------------------------------------------------------
//정렬
//	sort			 - 일반 정렬에 사용		n log n
//	stable_sort		 - (정렬 기준으로 보아 동등한) 원소의 순서를 유지하며 정렬, 보다 복잡
//	partial_sort	 - 등수를 매겨 n개를 뽑는다
//	nth_element		 - 위에서 부터 10개를 순서없이 골라낸다
//
//	partition		 - 조건에 맞는 것만 따로 분리한다
//
//	is_sorted		 - 정렬되었나 물어본다
//	merge			 - 두 자료를 합친다. 정렬 순서는 유지
//	binary_serach	 - 정렬된 자료에서 찾는 객체의 존재 유무를 리턴
//	equal_range		 - 정렬된 자료에서 실제 객체를 찾을 때 사용
//---------------------------------------------------------------
//검색
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

	// [문제] 777이 있나 찾아라
	// 있다면 어디에 있는지 위치를 (몇번째 원소인지) 모두 출력하라
	
	auto b = binary_search(v.begin(), v.end(), 777);

	if (b) {
		cout << "777은 있다" << endl;
		auto p = equal_range(v.begin(), v.end(), 777);

		for (auto i = p.first; i < p.second; ++i)
			cout << "위치는 - " << distance(v.begin(), i) + 1 << endl;
	}
	else
		cout << "777은 없다" << endl;
		
}