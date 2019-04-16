// 연습문제1 
// p.62
// std::string 객체로 된 배열을 정의하고, 자신이 선택한 단어들로 초기화 한 후
// 반복자를 사용해 배열의 내용을 한 줄에 하나씩 출력하는 프로그램을 작성하라.
//


#include<iostream>
#include<string>


using namespace std;


// 연습문제 1

//int main()
//{
//	string s[5]{"C++","Standard","Template","Library","iostream"};	//RAII
//
//	auto b = begin(s);	//추상화된 타임 
//	
//	while (b != end(s))
//		cout << *b++ <<" ";
//}




// 연습문제2
//
// transform 함수를 이용해서 소문자 모음은 *로 출력
//#include <algorithm>
//#include <iterator>
//
//int main()
//{
//	string s[5]{"C++","Standard","Template","Library","iostream"};
//
//
//	//transform(어디부터, 어디까지, 어디로, 이렇게바꿔서);
//	//ostream_iterator<string> // 화면을 찍는 반복자?
//	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"), 
//		[](string &str){
//		auto b = begin(str);
//		while (b != end(str))
//		{
//			//b가 모음이라면 *로 바꿔라.
//			if(*b == 'a'|| *b == 'e' || *b == 'i' || *b == 'o' || *b == 'u')
//				*b = '*';
//			b++;
//		}
//		return str;
//	});
//
//	auto a = begin(s);	//추상화된 타임 
//	while (a != end(s))
//		cout << *a++ << " ";
//
//	//원본을 바꾸지 않고 *로 출력하려면?
//}


// 연습문제3
// 문자열을 대문자로 바꿔서 출력

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


	//transform 으로 대문자 만들기

	transform(begin(s), end(s), ostream_iterator<string>(cout, "\n"),
		[](string &str) {
			transform(begin(str), end(str), ostream_iterator<char>(cout),
				[](char &b) {
				b = toupper(b);
				return b;
			});
		return str;
	});


	//auto a = begin(s);	//추상화된 타임 
	//while (a != end(s))
	//	cout << *a++ << " ";

	//원본을 바꾸지 않고 *로 출력하려면?
}
