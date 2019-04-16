//===================================
//
//2019 STL 4.02 화56		(5주 1일)
//
//	2장 순차 컨테이너 (sequence container, (homogeneous data type 만 담는다.))
//	  array : smart 한 배열, []를 완벽하게 대치한다.
//	- vector : dinamic array (STL 간판선수)
//	  deque
//	  list
//	  forward_list
//
//===================================

// 순차 컨테이너지만 순서가 있는 컨테이너가 아니다.
// 각각 include 해야 사용 가능

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
//	v.reserve(2);	// 공간을 미리 예약하는 함수 *******************
//
//	uniform_int_distribution<> uid(10, 70);
//	default_random_engine dre;
//
//	cout << "push_back 전" << endl << endl;
//	for (size_t i = 0; i < 2; ++i)
//		v.emplace_back(uid(dre));
//	cout << "push_back 끝" << endl << endl;
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





// 입력자료구조 - 키보드
// 출력자료구조 - 화면

// 키보드에서 string을 읽어 오름차순으로 정렬하여 출력하라.
// 소스.cpp 에서 char를 읽어 오름차순으로 정렬하여 출력하라.
#include<string>
//#include<iterator>
#include<algorithm>
#include<fstream>
int main()
{
	//vector<string> v (키보드 입력 시작, 입력 끝);
	ifstream in("소스.cpp");
	vector<char> v{ istream_iterator<char>(in), istream_iterator<char>() }; //{} 를 () 로 표시하면 함수로 인식한다.
	sort(v.begin(), v.end());
	copy(v.begin(), v.end(), ostream_iterator<char>(cout, "\t"));


	////2번 문제 ==============
	//vector<string> v{ istream_iterator<string>(cin), istream_iterator<string>() }; //{} 를 () 로 표시하면 함수로 인식한다.
	//sort(v.begin(), v.end());
	//copy(v.begin(), v.end(), ostream_iterator<string>(cout, "\t"));
	////2번 문제 ==============


	// for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;
}

// 벡터에 원소를 중간에 추가했을떄
// 벡터의 원소가 삭제 되었을때
// MemoryMonster 를 사용하여 관찰




//=====================================================================
//=====================================================================



// uid(dre) 에서 임시 객체를 만들고
// push_back 으로 넣어주고
// 이동생성자가 불리면서 vector에 넣고??
// 임시객체 안의 값을 가져오고
// 쓸모 없어진 임시객체는 사라진다.

// push 는 스텍에 만들었다가 힙으로 넘겨주지만 
// emplace 는 힙에 바로 만들어 버린다. (훨씬 좋음)

// vector는 메모리 크기가 정해지지 않은 상황에 쓰기위해 있는것이고
// 크기가 정해져 있다면 array를 쓰는게 맞다.



//=====================================================================
//=====================================================================
