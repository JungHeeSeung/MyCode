// �а� �ڷ�ǿ��� �ܾ��.zip�� ����
//
// 1. ����ڰ� �Է��� �ܾ �ܾ�鿡 �ִ��� Ȯ���Ѵ�
// 2. �ִٸ�
//		�Է��� �ܾ�� anagram ������ �ܾ ��� ã�� ȭ�鿡 ����Ѵ�.
//
//
// 3. �ܾ��.txt�� �ִ� ��� �ܾ�� ���� angram ������ �ܾ���� �������
// 4. anagram ���� �� ���� �ִ°�
// 5. ���� ������ ���� anagram ���� �����ΰ�

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

		// [i, j) �� ���ʱ׷� ���̴�
		list <string> t;



		for (auto k = i; k < j; ++k)
			t.push_back(k->second);
		
		vl.push_back(t);

		i = j;
	}

	sort(vl.begin(), vl.end(), [](const list<string>& a, const list<string>& b) {
		return a.size() > b.size();
	});

	ofstream out("�ֳʱ׷� ���̼���.txt");

	for (const list<string>& d : vl) {
		for (const string& s : d) {
			out << s << " ";
		}
		out << endl;
	}

}

//int main()
//{
//	// ���Ͽ��� �ܾ �д´�
//	readData();
//
//	// ������ ���� ���͸� ���ĵ� ������(first)�� �������� �����Ѵ�.
//	sort(v.begin(), v.end(), [](const PS& a, const PS& b) {
//		return a.first < b.first;
//	});
//
//	//// ���Ͽ� �����Ѵ�
//	//ofstream out("�ܾ�� ��.txt");
//	//for (int i = 0; i < v.size(); ++i)
//	//	out << v[i].first << "\t\t" << v[i].second << endl;
//
//	/*cout << "--------------------------------------" << endl;
//	cout << "\t�Ƴ��׷� ã�� �����~" << endl;
//	cout << "--------------------------------------" << endl << endl;*/
//
//	// �ܾ �Է¹޾� �Ƴ��׷��� ã�ƶ�!
//	// ������ ���ٰ� ����϶�
//
//	/*ofstream out("�ֳʱ׷� ��.txt");
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
//	cout << idx - 1 << " ���� ���� ã�Ҵ�." << endl;*/
//
//
//
//	//while (true)
//	//{
//	//	cout << "ã�� �ܾ �Է��ϼ���: ";
//	//	string s;
//	//	cin >> s;
//
//	//	PS ps{ s };
//
//	//	// ��� Anagram ���� ã�� ���Ͽ� ����϶�
//
//	
//}

void readData()
{
	ifstream in("�ܾ��.txt");

	string s;
	while (in >> s)
		v.push_back(s);

	cout << "��� " << v.size() << "���� �ܾ �о���." << endl << endl;
}