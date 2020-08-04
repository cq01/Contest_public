//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e6);
class Time
{
	int hour, minute, second;
public:
	Time(int hh, int mm, int ss) :hour(hh), minute(mm), second(ss)
	{
	}
	void print()
	{
		cout << hour << ':' << minute << ':' << second;
	}
	int toSec()const
	{
		return hour * 3600 + minute * 60 + second;
	}
};
Time toTime(int t)
{
	return Time(t / 3600, t / 60 % 60, t % 60);
}
bool operator>(const Time& a, const Time& b)
{
	return a.toSec() > b.toSec();
}
bool operator<(const Time& a, const Time& b)
{
	return a.toSec() < b.toSec();
}
Time operator+(const Time& a, const Time& b)
{
	return toTime(a.toSec() + b.toSec());
}
Time operator-(const Time& a, const Time& b)
{
	return toTime(abs(a.toSec() - b.toSec()));
}
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
	int y, m, d;
	int n;
	while (cin >> n)
	{
		while (n--)
		{
			cin >> y >> m >> d;
			Time t1(y, m, d);
			cin >> y >> m >> d;
			Time t2(y, m, d);
			(t1 + t2).print();
			cout << ' ';
			(t1 - t2).print();
			cout << endl;
		}
	}

}
