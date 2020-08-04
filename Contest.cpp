//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e5);

class STR
{
	char* s;
public:
	STR(const char* str)
	{
		size_t len = strlen(str) + 1;
		s = new char[len];
		memcpy(s, str, len);
	}

	~STR()
	{
		delete[] s;
		s = nullptr;
	}
	void move(char& t1, char& t2)
	{
		swap(t1, t2);
	}
	void print()
	{
		cout << s;
	}
	void fun()
	{
		int n = strlen(s);
		int i = 0, j = n - 1;
		while (i < j)
		{
			while (i < n && !isdigit(s[i]))++i;
			while (j >= 0 && isdigit(s[j]))--j;
			if (i >= j)break;
			swap(s[i], s[j]);
		}
	}
};


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
	string s;
	while (cin >> s)
	{
		STR str(s.c_str());
		str.fun();
		str.print();
		cout << endl;
	}
}
