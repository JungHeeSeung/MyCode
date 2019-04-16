// ��������1 
// p.62
// std::string ��ü�� �� �迭�� �����ϰ�, �ڽ��� ������ �ܾ��� �ʱ�ȭ �� ��
// �ݺ��ڸ� ����� �迭�� ������ �� �ٿ� �ϳ��� ����ϴ� ���α׷��� �ۼ��϶�.
//


#include<iostream>
#include<string>


using namespace std;


// �������� 1

//int main()
//{
//	string s[5]{"C++","Standard","Template","Library","iostream"};	//RAII
//
//	auto b = begin(s);	//�߻�ȭ�� Ÿ�� 
//	
//	while (b != end(s))
//		cout << *b++ <<" ";
//}




// ��������2
//
// transform �Լ��� �̿��ؼ� �ҹ��� ������ *�� ���
//#include <algorithm>
//#include <iterator>
//
//int main()
//{
//	string s[5]{"C++","Standard","Template","Library","iostream"};
//
//
//	//transform(������, ������, ����, �̷��Թٲ㼭);
//	//ostream_iterator<string> // ȭ���� ��� �ݺ���?
//	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"), 
//		[](string &str){
//		auto b = begin(str);
//		while (b != end(str))
//		{
//			//b�� �����̶�� *�� �ٲ��.
//			if(*b == 'a'|| *b == 'e' || *b == 'i' || *b == 'o' || *b == 'u')
//				*b = '*';
//			b++;
//		}
//		return str;
//	});
//
//	auto a = begin(s);	//�߻�ȭ�� Ÿ�� 
//	while (a != end(s))
//		cout << *a++ << " ";
//
//	//������ �ٲ��� �ʰ� *�� ����Ϸ���?
//}


// ��������3
// ���ڿ��� �빮�ڷ� �ٲ㼭 ���

#include <algorithm>
#include <iterator>

int main()
{
	string s[5]{ "C++","Standard","Template","Library","iostream" };

	//transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
	//	[](string &str) {
	//	for(auto b = begin(str); b != end(str); ++b)
	//	{
	//		*b = toupper(*b);
	//	}
	//	return str;
	//});


	//transform ���� �빮�� �����

	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
		[](string &str) {
			transform(begin(str), end(str), ostream_iterator<char>(cout),
				[](char &b) {
				b = toupper(b);
				return b;
			});
		return str;
	});


	//auto a = begin(s);	//�߻�ȭ�� Ÿ�� 
	//while (a != end(s))
	//	cout << *a++ << " ";

	//������ �ٲ��� �ʰ� *�� ����Ϸ���?
}
