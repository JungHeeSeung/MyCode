#include <iostream>
#include <string>
#include <iterator>
#include <fstream>
#include <deque>

using namespace std;

deque<int> calc(const deque<int>&, const deque<int>&, const int);
deque<int> insert(const string&, const int&);
void print_number(const deque<int>&);
string fopen_insert(string&);

int main()
{
	string temp;
	string fname;
	string fname2;
	string remainder;
	
	deque<int> op1;
	deque<int> op2;
	deque<int> result;
	
	ofstream out;
	
	int mode = 0;
	const int step = 5;

	while (1)
	{
		cout << "정수 덧셈 프로그램입니다." << endl;
		cout << "1과 2로 모드를 입력하세요." << endl;
		cout << "1: 사용자로부터 정수 입력" << endl;
		cout << "2: 파일로부터 정수 입력" << endl;
		cin >> mode;
		switch (mode)
		{
		case 1:
			cout << endl << "정수를 입력하세요" << endl;
			cout << '\t';
			cin >> temp;
			op1 = insert(temp, step);

			cout << '+' << '\t';
			cin >> temp;
			op2 = insert(temp, step);

			// op1 과 op2 의 덧셈 결과를 result 에 집어넣는다.
			if (op1.size() < op2.size())
			{
				result = calc(op2, op1, step);
			}
			else
			{
				result = calc(op1, op2, step);
			}
			print_number(result);
			break;
		case 2:
			cout << "첫번째 정수가 들어있는 파일을 입력하세요" << endl;
			getline(cin, remainder);
			getline(cin, fname);
			temp = fopen_insert(fname);
			if (temp == "fail")
			{
				break;
			}
			op1 = insert(temp, step);
			
			cout << "두번째 정수가 들어있는 파일을 입력하세요" << endl;
			getline(cin, fname2);
			temp = fopen_insert(fname2);
			if (temp == "fail")
			{
				break;
			}
			op2 = insert(temp, step);

			// op1 과 op2 의 덧셈 결과를 result 에 집어넣는다.
			if (op1.size() < op2.size())
			{
				result = calc(op2, op1, step);
			}
			else
			{
				result = calc(op1, op2, step);
			}


			// 저장할 파일 이름을 op1+op2.txt 로 열고
			out.open(fname + " + " + fname2 + ".txt");
			for (auto i : result) // result 값들을 파일 안에 넣고
			{
				out << i;
			}
			out.close();
			cout << "저장이 완료 되었습니다." << endl << endl;
			break;
		default:
			cout << "1과 2로만 입력하세요" << endl;
			break;
		}
	
		cout << endl << endl;
		result.clear();
		op1.clear();
		op2.clear();
	}
}

deque<int> calc(const deque<int> &op1, const deque<int> &op2, const int step)
{
	// 이 함수는 op1의 Size가 op2 보다 크거나 같은 것을 가정하고 계산한다
	deque<int> m_result;
	auto op1_pos = op1.begin();
	auto op2_pos = op2.begin();
	int input = 0;
	int carry = 0;
		
	// 두 deque 의 Size가 같지 않다면 op1이 큰걸로 간주
	if (op1.size() != op2.size())	
	{
		for (int count = 0; /* 종료 조건은 함수 안에서*/; ++count)
		{
			if (op2.size() <= m_result.size()) // op2의 숫자를 다 읽었다면
			{
				if ((op1_pos + count) < op1.end() ) // op1 끝까지
				{
					input = *(op1_pos + count) + carry; // op1만 넣는다
					carry = 0;							// carry를 넣고 다시 0으로
					if (100'000 <= input) // 두 수의 합이 5자리가 넘어가면
					{
						input -= 100'000; // 5자리로 만들어서 넣는다
						carry = 1;	      // 그리고 carry를 1로
					}
				}
				else // 끝까지 왔으면 반복문을 종료
				{
					if (carry == 1)
					{
						m_result.push_front(carry);
					}
					break;
				}
			}
			else // op2의 숫자를 다 읽지 않았다면 더해서 넣는다
			{
				input = *(op1_pos + count) + *(op2_pos + count) + carry;
				if (100'000 <= input) // 두 수의 합이 5자리가 넘어가면
				{
					input -= 100'000; // 5자리로 만들어서 넣는다
					carry = 1;	      // 그리고 carry를 1로
				}
				else //  두 수의 합이 5자리가 안 된다면 carry를 0으로
				{
					carry = 0;
				}
			}
			m_result.push_front(input);
		}
	}
	else // 두 deque의 Size가 같다면
	{
		for (int count = 0; (op1_pos + count) != op1.end(); count++)
		{
			input = *(op1_pos + count) + *(op2_pos + count) + carry;
			if (100'000 <= input)
			{
				input -= 100'000;
				carry = 1;
			}
			else
			{
				carry = 0;
			}
			m_result.push_front(input);
		}
		if (carry == 1) // 각각 n개의 노드가 있는데 carry로 인해 n + 1번째 노드가 발생했을 때
		{
			m_result.push_front(carry);
		}
	}
	return m_result;
}

deque<int> insert(const string & in, const int& step)
{
	// 입력받은 문자열을 끝에서부터 step 개씩 잘라서 int형으로 덱에 저장합니다.
	deque<int> temp;

	for (int i = in.size(); 0 < i; i -= step)
	{
		if (0 < (i - step))
		{
			temp.push_back(stoi(in.substr((i - step), step)));
		}
		else
		{
			temp.push_back(stoi(in.substr(0, i)));
		}
	}
	return temp;
}

void print_number(const deque<int>& result)
{
	cout << '=' << '\t';
	for (auto d : result)
	{
		if (d != 0)
		{
			cout << d;
		}
		else // 원소가 0이라면 
		{
			cout << "00000";
		}
	}
	cout << endl << endl;
}

string fopen_insert(string& fname)
{
	ifstream in(fname);
	string temp;
	string::size_type n;

	if (!in.is_open())
	{
		cout << endl <<"파일 열기 실패!" << endl;
		return "fail";
	}
	else
	{
		in >> temp;
		in.close();
		n = fname.find(".txt");
		fname = fname.substr(0, n);
	}
	return temp;
}
