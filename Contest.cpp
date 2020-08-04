//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e5);
bool isRun(int y)
{
	return y % 4 ? false : y % 100 ? true : y % 400 ? false : true;
}
int days(int y, int m)
{
	switch (m)
	{
	case 2:return 28 + isRun(y);
	case 4:case 6: case 9: case 11:return 30;
	default:return 31;
	}
}
class Date
{
	int year, month, day;
public:
	Date(const Date&) = default;
	Date(int y, int m, int d) :year(y), month(m), day(d)
	{
	}
	int nth()const
	{
		int m = 1, sum = day;
		while (m < month)
		{
			sum += days(year, m);
			++m;
		}
		return sum;
	}
	friend Date operator+(Date d, int n);
	friend ostream& operator<<(ostream& out, const Date& d);
};
ostream& operator<<(ostream& out, const Date& d)
{
	out << d.year << ' ' << d.month << ' ' << d.day;
	return out;
}
Date operator+(Date d, int n)
{
	d.day += n;
	while (days(d.year, d.month) < d.day)
	{
		d.day -= days(d.year, d.month);
		d.month++;
		if (d.month > 12)
		{
			d.month -= 12;
			d.year++;
		}
	}
	return d;
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
	while (cin >> y >> m >> d)
	{
		Date t(y, m, d);
		cout << t.nth() << endl;
		cout << t + 1039 << endl;
	}
}
