#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 각 단어의 사용횟수를 알고싶다
// 특정 단어를 입력하면 몇 번 사용되었는가 출력한다

// 단어를 오름차순으로 정렬해보자
// map<string, string>으로 읽어오자
// Ex) map<the, the> 읽은 단어를 한 번더 저장

ostream& operator<<(ostream& os, const pair<int, string>& temp)
{
	cout << temp.second << " --> " << temp.first;

	return os;
}

int main()
{
	string fname{ "앨리스.txt" };

	ifstream in(fname);

	istream_iterator<string> beg{ in };
	istream_iterator<string> end{};

	map<string, string> words;

	string str;
	int cnt{};
	while (beg != end)
	{
		str = *beg++;;
		words.insert(make_pair(str, str));
	}

	ofstream out("정렬된 앨리스의 단어");

	for (auto i = words.begin(); i != words.end(); ++i)
		out << i->first << endl;

	// a로 시작하는 단어는 몇 개니?
	size_t num = count_if(words.begin(), words.end(), [](const pair<string, string>& p) {
		return (p.first)[0] == 'a';
	});

	// a로 시작하는 위치와
	// b로 시작하는 위치를 찾아 차이를 계산해도 같은 결과일 것이다.

	cout << "a로 시작하는 다어의 수는 --> " << num << endl;
	//// 가장 많이 사용된 단어부터 순서대로 출력하라
	//// 벡터를 이용해보자

	//vector< pair<int, string> > v;
	//v.reserve(words.size());

	//for (const auto& d : words) // = for( auto d = words.begin(); i != words.end(); ++i)
	//	v.push_back(pair<int, string>(d.second, d.first));

	//sort(v.begin(), v.end(), [](const pair<int, string> a, const pair<int, string> b) {
	//	return a.first > b.first;
	//});

	///*for (int i = 0; i < 20; ++i)
	//	cout << v[i].first << " --> " << v[i].second << endl;*/

	//	// 위의 for 문을 아래 처럼 해보자
	//for (int i = 0; i < 20; ++i)
	//	cout << v[i] << endl;

	///*for (auto i = v.rbegin(); i != v.rend(); ++i)
	//	cout << "[" << i->second << "] -- > " << i->first << endl;*/


	//	// map은 키 값으로 정렬되어 있다. value 값으로 정렬은 불가능
	//	// 차라리 새로운 컨테이너를 하나 만들자

	//	//multimap< int, string, greater<int> > isMap;

	//	//for (const auto& d : words)
	//	//	isMap.insert( make_pair(d.second, d.first) );

	//	///*for (const pair<string, int>& d : words)
	//	//	isMap[d.second] = d.first;*/

	//	//for (const pair<int, string>& d : isMap)
	//	//	cout << "[" << d.second << "] -- > " << d.first << endl;

	//	//cout << "단어 수: " << isMap.size() << endl;


	//cout << "단어 수: " << words.size() << endl;

	//cout << endl;

	// words<단어와 출현 횟수>
	// 단어를 입력받아 출현 횟수를 출력해주자
	
}

//	array vector deque			--> [i] sort()
//	list forward_list			 --> .sort
//
//	항상 정렬중인 친구들
//	map multimap (key, value)	
//	set multiset (key)			// sort X
//
//	unordered_map unordered_muulitmap	//sort 와 무관