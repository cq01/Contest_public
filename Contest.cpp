﻿//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG

class Integer
{
public:
	int x;
	friend int operator+(const Integer& a, const Integer& b);
	friend int operator-(const Integer& a, const Integer& b);
	friend int operator*(const Integer& a, const Integer& b);
	friend int operator/(const Integer& a, const Integer& b);
};
int operator+(const Integer& a, const Integer& b) { return a.x + b.x; }
int operator-(const Integer& a, const Integer& b) { return a.x - b.x; }
int operator*(const Integer& a, const Integer& b) { return a.x * b.x; }
int operator/(const Integer& a, const Integer& b) { return a.x / b.x; }

int main()
{
#ifdef DEBUG
	fstream in, out;
	in.open("C:\\Users\\qi010\\Desktop\\cin.txt", ios::in);
	out.open("C:\\Users\\qi010\\Desktop\\cout.txt", ios::app);
	streambuf* stream_buffer_cout = cout.rdbuf();
	streambuf* stream_buffer_cin = cin.rdbuf();
	streambuf* stream_buffer_in = in.rdbuf();
	streambuf* stream_buffer_out = out.rdbuf();
	cin.rdbuf(stream_buffer_in);
	cout.rdbuf(stream_buffer_out);
#endif // DEBUG

	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	char op;
	Integer a, b;
	while (cin >> op >> a.x >> b.x)
	{
		switch (op)
		{
		case '+':cout << a + b << endl; break;
		case '-':cout << a - b << endl; break;
		case '*':cout << a * b << endl; break;
		case '/':cout << a / b << endl; break;
		default:
			break;
		}
	}
}