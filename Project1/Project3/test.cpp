#include <iostream>
#include <deque>
#include <string>
#include <fstream>

using namespace std;

int main()
{
	deque<int> a{ 1, 2, 3, 4, 5 };
	deque<int> b{ 1,2,3 };
	deque<int> c{ 000000 };

	string str = "abcdef";
	string::size_type n;
	n = str.find("def");
	str = str.substr(0, n);
	cout << str << endl;

	

	cout << "a의 size는: " << a.size() << " b의 size는: " << b.size();
}