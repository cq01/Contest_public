//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG
constexpr int maxn = int(1e5);

class Circle
{
public:
	double r;
	Circle(double R) :r(R)
	{
	}
};
class Table
{
public:
	double height;
	Table(double h) :height(h)
	{
	}
};

class Roundtable :public Circle, public Table
{
public:
	char* color;
	Roundtable(double r, double h, const char* str) :Circle(r), Table(h)
	{
		size_t len = strlen(str) + 1;
		color = new char[len];
		memcpy(color, str, len);
	}

	~Roundtable()
	{
		delete[] color;
		color = nullptr;
	}
	double fun()
	{
		return 3.14 * r * r;
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
	double r, h;
	string s;
	cout << "please input the data of round table:" << endl;
	cout << "radius:" << endl;
	cin >> r;
	cout << "height:" << endl;
	cin >> h;
	cout << "color:" << endl;
	cin >> s;
	Roundtable tab(r, h, s.c_str());
	cout << "height:" << (ll(tab.height * 100) / 100.0) << endl;
	cout << "area:" << (ll(tab.fun() * 100) / 100.0) << endl;
	cout << "color:" << tab.color << endl;
}
