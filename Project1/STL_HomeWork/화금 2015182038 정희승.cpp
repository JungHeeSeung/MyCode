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
		cout << "���� ���� ���α׷��Դϴ�." << endl;
		cout << "1�� 2�� ��带 �Է��ϼ���." << endl;
		cout << "1: ����ڷκ��� ���� �Է�" << endl;
		cout << "2: ���Ϸκ��� ���� �Է�" << endl;
		cin >> mode;
		switch (mode)
		{
		case 1:
			cout << endl << "������ �Է��ϼ���" << endl;
			cout << '\t';
			cin >> temp;
			op1 = insert(temp, step);

			cout << '+' << '\t';
			cin >> temp;
			op2 = insert(temp, step);

			// op1 �� op2 �� ���� ����� result �� ����ִ´�.
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
			cout << "ù��° ������ ����ִ� ������ �Է��ϼ���" << endl;
			getline(cin, remainder);
			getline(cin, fname);
			temp = fopen_insert(fname);
			if (temp == "fail")
			{
				break;
			}
			op1 = insert(temp, step);
			
			cout << "�ι�° ������ ����ִ� ������ �Է��ϼ���" << endl;
			getline(cin, fname2);
			temp = fopen_insert(fname2);
			if (temp == "fail")
			{
				break;
			}
			op2 = insert(temp, step);

			// op1 �� op2 �� ���� ����� result �� ����ִ´�.
			if (op1.size() < op2.size())
			{
				result = calc(op2, op1, step);
			}
			else
			{
				result = calc(op1, op2, step);
			}


			// ������ ���� �̸��� op1+op2.txt �� ����
			out.open(fname + " + " + fname2 + ".txt");
			for (auto i : result) // result ������ ���� �ȿ� �ְ�
			{
				out << i;
			}
			out.close();
			cout << "������ �Ϸ� �Ǿ����ϴ�." << endl << endl;
			break;
		default:
			cout << "1�� 2�θ� �Է��ϼ���" << endl;
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
	// �� �Լ��� op1�� Size�� op2 ���� ũ�ų� ���� ���� �����ϰ� ����Ѵ�
	deque<int> m_result;
	auto op1_pos = op1.begin();
	auto op2_pos = op2.begin();
	int input = 0;
	int carry = 0;
		
	// �� deque �� Size�� ���� �ʴٸ� op1�� ū�ɷ� ����
	if (op1.size() != op2.size())	
	{
		for (int count = 0; /* ���� ������ �Լ� �ȿ���*/; ++count)
		{
			if (op2.size() <= m_result.size()) // op2�� ���ڸ� �� �о��ٸ�
			{
				if ((op1_pos + count) < op1.end() ) // op1 ������
				{
					input = *(op1_pos + count) + carry; // op1�� �ִ´�
					carry = 0;							// carry�� �ְ� �ٽ� 0����
					if (100'000 <= input) // �� ���� ���� 5�ڸ��� �Ѿ��
					{
						input -= 100'000; // 5�ڸ��� ���� �ִ´�
						carry = 1;	      // �׸��� carry�� 1��
					}
				}
				else // ������ ������ �ݺ����� ����
				{
					if (carry == 1)
					{
						m_result.push_front(carry);
					}
					break;
				}
			}
			else // op2�� ���ڸ� �� ���� �ʾҴٸ� ���ؼ� �ִ´�
			{
				input = *(op1_pos + count) + *(op2_pos + count) + carry;
				if (100'000 <= input) // �� ���� ���� 5�ڸ��� �Ѿ��
				{
					input -= 100'000; // 5�ڸ��� ���� �ִ´�
					carry = 1;	      // �׸��� carry�� 1��
				}
				else //  �� ���� ���� 5�ڸ��� �� �ȴٸ� carry�� 0����
				{
					carry = 0;
				}
			}
			m_result.push_front(input);
		}
	}
	else // �� deque�� Size�� ���ٸ�
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
		if (carry == 1) // ���� n���� ��尡 �ִµ� carry�� ���� n + 1��° ��尡 �߻����� ��
		{
			m_result.push_front(carry);
		}
	}
	return m_result;
}

deque<int> insert(const string & in, const int& step)
{
	// �Է¹��� ���ڿ��� ���������� step ���� �߶� int������ ���� �����մϴ�.
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
		else // ���Ұ� 0�̶�� 
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
		cout << endl <<"���� ���� ����!" << endl;
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
