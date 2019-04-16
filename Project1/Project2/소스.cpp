#include<iostream>
#include<vector>
#include<algorithm>
#include"MemoryMonster.h"
using namespace std;

//벡터의 원소가 중간에 끼워질때
// 벡터의 원소를 지울때
int main()
{
	vector<MemoryMonster> v;
	v.reserve(10);

	v.emplace_back(10);
	v.emplace_back(30);
	v.emplace_back(40);

	//for (int i = 0; i < v.size(); ++i)
	//	cout << v[i] << endl;

	//cout << "중간에 20을 넣기 전" << endl;
	////10과 30 사이에 20을 끼우자.
	//v.emplace(v.begin() + 1, 20);
	//cout << "중간에 20을 넣은 후" << endl;

	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;

	cout << "20글자를 삭제하기 전" << endl;
	//20글자를 삭제하자
	remove(v.begin(), v.end(), 20);		//이 방식으로는 벡터내의 원소만 지우게 되고 메모리는 지울 수 없다.

	//// 이렇게 하면 위의 문제를 해결 가능하다.
	//// erase - remove idiom
	//auto p = remove(v.begin(), v.end(), 20);
	//v.erase(p, v.end()-1);

	cout << "20글자를 삭제하기 후" << endl;


	for (int i = 0; i < v.size(); ++i)
		cout << v[i] << endl;


}