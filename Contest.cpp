//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define clr_0(A) memset((A),0,sizeof(A))
//#define DEBUG

class Circle
{
public:
	virtual int area() = 0;
	virtual int volume() = 0;
	int radius;
protected:
	static constexpr int pi = 3;
};

class Sphere :public Circle
{
public:
	int hight;
	int area();
	int volume();
};
class Column :public Circle
{
public:
	int hight;
	Column() = default;
	int area();
	int volume();
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
	int r, h;
	Circle* p;
	Sphere s;
	Column c;
	while (cin >> r >> h)
	{
		s.radius = c.radius = r;
		s.hight = h;
		p = &c;
		cout << p->volume() << ' ' << p->area() << ' ';
		p = &s;
		cout << p->volume() << ' ' << p->area() << ' ' << endl;
	}
}

int Sphere::area()
{
	return 2 * pi * radius * (radius + hight);
}

int Sphere::volume()
{
	return pi * radius * radius * hight;
}

int Column::area()
{
	return 4 * pi * radius * radius;
}

int Column::volume()
{
	return pi * 4 / 3 * radius * radius * radius;
}
