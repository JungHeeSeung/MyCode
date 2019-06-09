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
#include <list>
#include <algorithm>

using namespace std;

struct PS : pair<string, string> {
	PS(string s) : pair(s, s) {
		sort(first.begin(), first.end());
	}
};

vector<PS> v;
void readData();

int main()
{
	readData();

	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
				return a.first < b.first;
	});


	vector<list<string>> vl;
	vl.reserve(31000);

	auto i = v.begin();
	while (true)
	{
		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) {
			return a.first == b.first;
		});

		if (i == v.end())
			break;

		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) {
			return i->first == a.first;
		});

		// [i, j) 는 에너그램 쌍이다
		list <string> t;



		for (auto k = i; k < j; ++k)
			t.push_back(k->second);
		
		vl.push_back(t);

		i = j;
	}

	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b) {
		return a.size() > b.size();
	});

	ofstream out("애너그램 길이순서.txt");

	for (const list<string>& d : vl) {
		for (const string& s : d) {
			out << s << " ";
		}
		out << endl;
	}

}

//int main()
//{
//	// 파일에서 단어를 읽는다
//	readData();
//
//	// 쌍으로 만든 벡터를 정렬된 데이터(first)를 기준으로 정렬한다.
//	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
//		return a.first < b.first;
//	});
//
//	//// 파일에 저장한다
//	//ofstream out("단어들 쌍.txt");
//	//for (int i = 0; i < v.size(); ++i)
//	//	out << v[i].first << "\t\t" << v[i].second << endl;
//
//	/*cout << "--------------------------------------" << endl;
//	cout << "\t아나그램 찾아 드려용~" << endl;
//	cout << "--------------------------------------" << endl << endl;*/
//
//	// 단어를 입력받아 아나그램을 찾아라!
//	// 없으면 없다고 출력하라
//
//	/*ofstream out("애너그램 쌍.txt");
//	int idx{ 1 };
//
//	auto i = v.begin();
//	while (true)
//	{
//		i = adjacent_find(i, v.end(), [](const PS& a, const PS& b) {
//			return a.first == b.first;
//		});
//
//		if (i == v.end())
//			break;
//
//		auto j = find_if_not(i + 1, v.end(), [i](const PS& a) {
//			return i->first == a.first;
//		});
//
//
//		out << "[" << idx++ << "] ";
//		for (auto k = i; k < j; ++k)
//		{
//			out << k->second << " ";
//		}
//		out << endl;
//
//		i = j;
//	}
//	
//	cout << idx - 1 << " 개의 쌍을 찾았다." << endl;*/
//
//
//
//	//while (true)
//	//{
//	//	cout << "찾을 단어를 입력하세요: ";
//	//	string s;
//	//	cin >> s;
//
//	//	PS ps{ s };
//
//	//	// 모든 Anagram 쌍을 찾아 파일에 기록하라
//
//	
//}

void readData()
{
	ifstream in("단어들.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "모두 " << v.size() << "개의 단어를 읽었다." << endl << endl;
}