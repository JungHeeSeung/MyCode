#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

// �Է�: �ҽ�.cpp
// ���: e���¼ҽ�.cpp
// ����: �ҽ�.cpp ���� ������ e�� �����Ѵ�.
//		 remove_if()�� ����Ѵ�.
// ����(white space)���� ó���Ϸ��� istreambuf_iterator, ostreambuf_iterator�� ����ؾ��Ѵ�.
int main()
{
	ifstream in("�ҽ�.cpp");

	vector<char> v { istreambuf_iterator<char>(in), istreambuf_iterator<char>() };	//in ó������ ������ ���������.

	auto p = remove_if(v.begin(), v.end(), [](const char c){
		if (c == 'e')
			return true;
		return false;
	});
	v.erase(p, v.end());
	
	ofstream out("e���¼ҽ�.cpp");
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	in.close();

}