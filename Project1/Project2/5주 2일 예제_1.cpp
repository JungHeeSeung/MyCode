#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;

// 입력: 소스.cpp
// 출력: e없는소스.cpp
// 변신: 소스.cpp 에서 영문자 e를 제거한다.
//		 remove_if()를 사용한다.
// 공백(white space)까지 처리하려면 istreambuf_iterator, ostreambuf_iterator를 사용해야한다.
int main()
{
	ifstream in("소스.cpp");

	vector<char> v { istreambuf_iterator<char>(in), istreambuf_iterator<char>() };	//in 처음부터 마지막 빈공간까지.

	auto p = remove_if(v.begin(), v.end(), [](const char c){
		if (c == 'e')
			return true;
		return false;
	});
	v.erase(p, v.end());
	
	ofstream out("e없는소스.cpp");
	copy(v.begin(), v.end(), ostreambuf_iterator<char>(out));

	in.close();

}