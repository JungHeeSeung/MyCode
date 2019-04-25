#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// �� �ܾ��� ���Ƚ���� �˰�ʹ�
// Ư�� �ܾ �Է��ϸ� �� �� ���Ǿ��°� ����Ѵ�

// �ܾ ������������ �����غ���
// map<string, string>���� �о����
// Ex) map<the, the> ���� �ܾ �� ���� ����

ostream& operator<<(ostream& os, const pair<int, string>& temp)
{
	cout << temp.second << " --> " << temp.first;

	return os;
}

int main()
{
	string fname{ "�ٸ���.txt" };

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

	ofstream out("���ĵ� �ٸ����� �ܾ�");

	for (auto i = words.begin(); i != words.end(); ++i)
		out << i->first << endl;

	// a�� �����ϴ� �ܾ�� �� ����?
	size_t num = count_if(words.begin(), words.end(), [](const pair<string, string>& p) {
		return (p.first)[0] == 'a';
	});

	// a�� �����ϴ� ��ġ��
	// b�� �����ϴ� ��ġ�� ã�� ���̸� ����ص� ���� ����� ���̴�.

	cout << "a�� �����ϴ� �پ��� ���� --> " << num << endl;
	//// ���� ���� ���� �ܾ���� ������� ����϶�
	//// ���͸� �̿��غ���

	//vector< pair<int, string> > v;
	//v.reserve(words.size());

	//for (const auto& d : words) // = for( auto d = words.begin(); i != words.end(); ++i)
	//	v.push_back(pair<int, string>(d.second, d.first));

	//sort(v.begin(), v.end(), [](const pair<int, string> a, const pair<int, string> b) {
	//	return a.first > b.first;
	//});

	///*for (int i = 0; i < 20; ++i)
	//	cout << v[i].first << " --> " << v[i].second << endl;*/

	//	// ���� for ���� �Ʒ� ó�� �غ���
	//for (int i = 0; i < 20; ++i)
	//	cout << v[i] << endl;

	///*for (auto i = v.rbegin(); i != v.rend(); ++i)
	//	cout << "[" << i->second << "] -- > " << i->first << endl;*/


	//	// map�� Ű ������ ���ĵǾ� �ִ�. value ������ ������ �Ұ���
	//	// ���� ���ο� �����̳ʸ� �ϳ� ������

	//	//multimap< int, string, greater<int> > isMap;

	//	//for (const auto& d : words)
	//	//	isMap.insert( make_pair(d.second, d.first) );

	//	///*for (const pair<string, int>& d : words)
	//	//	isMap[d.second] = d.first;*/

	//	//for (const pair<int, string>& d : isMap)
	//	//	cout << "[" << d.second << "] -- > " << d.first << endl;

	//	//cout << "�ܾ� ��: " << isMap.size() << endl;


	//cout << "�ܾ� ��: " << words.size() << endl;

	//cout << endl;

	// words<�ܾ�� ���� Ƚ��>
	// �ܾ �Է¹޾� ���� Ƚ���� ���������
	
}

//	array vector deque			--> [i] sort()
//	list forward_list			 --> .sort
//
//	�׻� �������� ģ����
//	map multimap (key, value)	
//	set multiset (key)			// sort X
//
//	unordered_map unordered_muulitmap	//sort �� ����