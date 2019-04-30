#include <iostream>
#include <random>
#include <string>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include <vector>

using namespace std;

class Gamer {
	string name{};
	int score{};
public:
	Gamer() = default;

	Gamer(const string& name, int score) : name{ name }, score{ score } {}

	string getName() const { return name; }

	int getScore() const { return score; }

	void setName(const string& str) { name = str; }

	void show() const {
		cout << "[ " << name << " ] - " << score << endl;
	}

	bool operator< (const Gamer& rhs) const {
		return name < rhs.name;
	}

	friend istream& operator>> (istream&, Gamer&);
};

void makeData();

string file1{ "�÷��̾�1.txt" }, file2{ "�÷��̾�2.txt" };

int main()
{
	// 1�� < ������ �о �����̳ʿ� �������� >
	//ifstream in(file1);
	string name;
	int score;

	// STL ������ ���� ��� 
	// friend ���� ���� ����
	//vector<Gamer> v{ istream_iterator<Gamer>(in), istream_iterator<Gamer>() };

	// ����ϰ� �д� ���
	/*while (in >> name >> score)
		v.emplace_back(name, score);*/
	//----------------------------------------------------------------------------------

	
	// ---------------------------------------------------------------------------------
	// 2�� ��� ���� 
	// int �� ����... ���� �����÷ο��...
	// ��ġ��� �ڷ��� �ٲ����ߴ�

	//double sum = 0;

	//for (int i = 0; i < v.size(); ++i)
	//{
	//	sum += v[i].getScore();
	//}
	//cout << sum / v.size() << endl;

	//----------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	// 3�� ���� ū ��
	// ��ġ�� ��ȯ�ϴϱ� ��ġ�� �����ؼ� ����߾�� �ߴ�...
	/*auto p = max_element(v.begin(), v.end(), [](const Gamer& a, const Gamer& b) {
		return a.getScore() < b.getScore();
	});
	p->show();*/
	//----------------------------------------------------------------------------------------

	//----------------------------------------------------------------------------------------
	// 4�� �������� ����  ( 0�� ���� ��������)
	// 3��° ���ڸ� ���� �ʰ� �ϴ� ����� Ŭ���� ���� operator < �����ε��� ����
	// sort(v.begin(), v.end()) �� �������̵��� �Ǿ� �ִٸ� �����ϴ�

	// ����� ����̴�
	//sort(v.begin(), v.end(), [](const Gamer& a, const Gamer& b) {
	//	return a.getScore() < b.getScore();
	//});
	//v.rbegin()->show();

	//----------------------------------------------------------------------------------------
	// 5�� string ����
	/*string fileName = file1.substr(0, file1.find_first_of(".", 0)) 
		+ " + " + file2.substr(0, file1.find_first_of(".", 0)) + ".txt";

	cout << fileName << endl;*/
	//----------------------------------------------------------------------------------------
	// 6�� �� ���� �����̳� ��ġ�� ( ��ġ�� �ߺ� �����ϱ� )
	ifstream in(file1);
	ifstream in2(file2);
	list<Gamer> l1{ istream_iterator<Gamer>(in), istream_iterator<Gamer>() };
	list<Gamer> l2{ istream_iterator<Gamer>(in2), istream_iterator<Gamer>() };
	
	l1.sort();
	l2.sort();
	l1.merge(l2);
	l1.unique([](const Gamer& a, const Gamer& b) {
		return a.getName() == b.getName();
	});
	cout << l1.size() << endl;
}


//int main()
//{
//	////makeData(); fucking useless
//	list<Gamer> gamers;
//	ifstream in(file1);
//
//
//	string str;
//	string::size_type n;
//
//
//	for (int i = 0; i < 20000; ++i)
//	{
//		getline(in, str);
//		n = str.find("\t");
//		Gamer temp(str.substr(0, n),
//			stoi(str.substr(n + 1, str.size() - n - 1)));
//		gamers.push_back(temp);
//	}
//
//	double sum = 0;
//
//	for (auto i = gamers.begin(); i != gamers.end(); ++i)
//	{
//		sum += i->getScore();
//	}
//	cout << sum / gamers.size();
//
//
//	/*max_element(gamers.begin(), gamers.end(), [](const Gamer& a, const Gamer& b) {
//		return a.getScore() < b.getScore();
//	});*/
//
//	/*gamers.sort( [](const Gamer& a, const Gamer& b) {
//		return a.getScore() < b.getScore();
//	});
//	cout << gamers.rbegin()->getScore();*/
//	/*for (auto i = gamers.begin(); i != gamers.end(); ++i)
//	{
//		
//	}*/
//}

void makeData()
{
	ofstream out1(file1);
	ofstream out2(file2);

	default_random_engine dre;

	uniform_int_distribution<> uiName('a', 'z');

	normal_distribution<> ndScore{ 100'0000.0, 10'0000.0 }; // {���, ǥ������}

	for (int i = 0; i < 20000; ++i)
	{
		string name;
		for (int i = 0; i < 4; ++i)
			name += uiName(dre);

		Gamer g(name, ndScore(dre));
		out1 << g.getName() << "\t" << g.getScore() << endl;
	}

	for (int i = 0; i < 20000; ++i)
	{
		string name;
		for (int i = 0; i < 4; ++i)
			name += uiName(dre);

		Gamer g(name, ndScore(dre));
		out2 << g.getName() << "\t" << g.getScore() << endl;
	}
}

istream& operator>> (istream& is, Gamer& g)
{
	is >> g.name >> g.score;
	return is;
}