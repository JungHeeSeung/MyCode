#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

// �ܾ�� ������ ����� ����ϱ�

int main()
{
	string a{ "abcdefghijklmnopqrstubwxyz asdf qwer zxcv" };

	copy(a.begin(), a.end(), ostreambuf_iterator<char>(cout));
	cout << endl;
	copy(a.rbegin(), a.rend(), ostreambuf_iterator<char>(cout));
	cout << endl;
}