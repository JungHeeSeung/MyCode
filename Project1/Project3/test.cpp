#include<iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include<algorithm>
#include <list>
#include<random>

using namespace std;

enum Nation { KOREA, JAPAN, CHINA, USA };
string NameOfNation[4]{ "대한민국", "일본", "중국", "미국" };

default_random_engine dre{ 2015182038 };
uniform_int_distribution<> uiName('a', 'z');
uniform_int_distribution<> uiNation{ KOREA, USA };
uniform_int_distribution<> uiNameLength{ 5, 15 };

normal_distribution<> ndScore{ 100'0000.0, 20'0000.0 };

class Player {
	string name;
	Nation nation;
	int score;

public:
	Player() {
		for (int i = 0; i < uiNameLength(dre); ++i)
			name += uiName(dre);
		nation = Nation(uiNation(dre));
		score = 0;
	}

	void Show() const {
		cout << "플레이어: " << setw(15) << left 
			<< name + "," << setw(8) << NameOfNation[nation] << ", 점수: " << score << endl;
	}

	void getScore(int num) {
		score = num;
	}

	int getScore() const {
		return score;
	}

	Nation getNation() const {
		return nation;
	}

	string Info() const {
				return  name + ' ' + NameOfNation[nation] + ' ' + to_string(score);
	}

	friend ofstream& operator<<(ofstream& o, Player& d);
};

ofstream& operator<<(ofstream& o, Player& d)
{
	o << d.Info();
	return o;
}

int main()
{
	string name;
	Nation nation;
	int score;
	string::size_type n;

	list<Player> l_Player{ 30 };
	string s;
	ifstream in("Player_Info.txt");
	
	for (int i = 0; i < 30000; ++i)
	{
		in >> s;
		n = s.find(' ');
	}

	

	/*for (auto i = l_Player.cbegin(); i != l_Player.cend(); ++i)
		i->Show();*/

	/*ofstream out("Player_Info.txt");
	for (auto i = l_Player.cbegin(); i != l_Player.cend(); ++i)
		out << i->Info() << endl;*/
		
}