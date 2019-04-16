#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// 단어별로 순서를 뒤집어서 출력하기

int main()
{
	string a{ "abcdefghijklmnopqrstubwxyz asdf qwer zxcv" };

	copy(a.begin(), a.end(), ostreambuf_iterator<char>(cout));
	cout << endl;
	copy(a.rbegin(), a.rend(), ostreambuf_iterator<char>(cout));
	cout << endl;
}