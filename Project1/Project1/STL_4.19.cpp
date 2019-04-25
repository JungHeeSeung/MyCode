//-----------------------------------------------------------------------------------
// �����̳��� ����
// �ݺ����� ����
// ���� 3���� �� ������ �ſ� �߿��ϴ�
// �� �о��
// 
// Associative Containner (���� �����̳�)
//		map - dictionary <ket, value> ���� ����
//		set - <key>�� ����
//
// Unordered Associative Container (�������� ���� �����̳�, Hash)
//		unordered_map
//		unordered_set
//		�޸𸮸� ����ϰ� ã�� �ð��� �ش������� ���̷��� �����
//-----------------------------------------------------------------------------------

//#include <iostream>
//#include <map>
//#include <algorithm>
//#include <iterator>
//#include <string>
//#include "MemoryMonster.h"
//
//using namespace std;
//
//// ���̵��׷��� �̸��� ��� ��
//// �ʿ� �Է��ϰ� ����غ���
//int main()
//{
//	map<string, int> idols;		// map�� tree �̱� ������ push_back ���� ��ġ��
//	// operator<() �� 3��° ���ڷ� ���� ���� // ���Ҹ� �ִ� ������ ������� ����
//	idols.insert(pair<string, int>("��ũ���̵�", 5));
//	idols.insert(make_pair("����", 5));
//	idols.insert(make_pair("�������", 12));
//	idols.insert(make_pair("���ʿ�", 11));
//	idols.insert(make_pair("��𷣵�", 9));
//	idols.insert(make_pair("����ũ", 4));
//	idols.insert(make_pair("Ʈ���̽�", 9));
//	idols.insert(make_pair("����ƾ", 13));
//	idols.insert(make_pair("��ź�ҳ��", 7));
//
//	// ���� ���Ҹ� ���� ã��  ( O(log n)) ���� �����̳��̴�
//	// ����ڰ� ���ϴ��� �׷��� �ο����� ����ϴ� ���α׷��� �ۼ��϶�
//
//	cout << idols["��ź�ҳ��"];		// Associative Array ó�� ��� ����
//	idols["��ź�ҳ��"] = 10;
//}
//


// �ҽ�.cpp�� �� ���ĺ��� �� �� ���Ǿ��� ����϶�
// ���� �ð����� �Ҽ�å�� �о��

#include <iostream>
#include <map>
#include <fstream>
#include <iterator>
#include "MemoryMonster.h"

using namespace std;

int main()
{
	map<char, int> cb;

	ifstream in("STL_4.19.cpp");
	
	for (auto i = istream_iterator<char>(in); i != istream_iterator<char>(); ++i)
		if (isalpha(*i))
			cb[tolower(*i)]++;

	auto p = cb.cbegin();
	for (int i = 0; i < cb.size(); ++i, ++p)
		cout << "[" << p->first << "] --> " << p->second << endl;
}