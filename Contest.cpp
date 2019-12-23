//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;
#define DEBUG
#define clr(x) memset((x),0,sizeof(x))

const int horizontal[8] = { 2,1,-1,-2,-2,-1,1,2 };
const int vertical[8] = { -1,-2,-2,-1,1,2,2,1 };

bool S[500][500] = {};
unsigned int L[500][500] = {};

struct Point
{
	int x, y;
	unsigned int step;
	bool inS()
	{
		return S[x][y];
	}
	void setS()
	{
		S[x][y] = true;
	}
	void setL()
	{
		step = min(step, L[x][y]);
		L[x][y] = step;
	}
	Point& equals(Point& current, int i)
	{
		x = current.x + horizontal[i];
		y = current.y + vertical[i];
		step = current.step + 1;
		setL();
		return *this;
	}

	Point(int x = 0, int y = 0, int step = 65535) :x(x), y(y), step(step)
	{
		setL();
	}
	Point(Point& current, int i)
	{
		this->equals(current, i);
	}
	Point& operator =(Point& current)
	{
		x = current.x;
		y = current.y;
		step = current.step;
		return *this;
	}
	Point& operator =(const Point& current)
	{
		x = current.x;
		y = current.y;
		step = current.step;
		return *this;
	}
};
bool operator ==(Point A, Point B)
{
	return (A.x == B.x) && (A.y == B.y);
}
bool operator !=(Point A, Point B)
{
	return !(A == B);
}
bool operator < (Point A, Point B)
{
	return A.step < B.step;
}
bool operator > (Point A, Point B)
{
	return A.step > B.step;
}
void p(Point& current)
{
	cout << setw(4) << current.x << setw(4) << current.y << setw(4) << current.step << endl;
}
void span(int& m, int& n, int& a, int& b, int& c, int& d);
void reduce(int& m, int& n, int& a, int& b, int& c, int& d);
int search(int m, int n, int a, int b, int c, int d);
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
	int k;
	while (cin >> k)
	{
		while (k--)
		{
			int m, n, a, b, c, d;
			cin >> m >> n >> a >> b >> c >> d;
#ifdef DEBUG
			//cout << m << ' ' << n << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
			span(m, n, a, b, c, d);
			//cout << m << ' ' << n << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
			reduce(m, n, a, b, c, d);
			//cout << m << ' ' << n << ' ' << a << ' ' << b << ' ' << c << ' ' << d << endl;
			double start = clock();
			cout << search(m, n, a, b, c, d) << '\t';
			cout << (clock() - start) / CLOCKS_PER_SEC << endl;
#else
			span(m, n, a, b, c, d);
			reduce(m, n, a, b, c, d);
			cout << search(m, n, a, b, c, d) << endl;
#endif // DEBUG


		}
	}
#ifdef DEBUG
	in.close();
	out.close();
#endif // DEBUG

}
void span(int& m, int& n, int& a, int& b, int& c, int& d)
{
	auto dx = [&]()->int {return c - a; };
	auto dy = [&]()->int {return d - b; };
	if (dx() < 0)
	{
		if (dy() < 0)
		{
			a = m - 1 - a;
			c = m - 1 - c;
			b = n - 1 - b;
			d = n - 1 - d;
		}
		else
		{
			a = m - 1 - a;
			c = m - 1 - c;
		}
	}
	else
	{
		if (dy() < 0)
		{
			b = n - 1 - b;
			d = n - 1 - d;
		}
	}
	if (dx())
	{
		;
		if (dy() * 1.0 / dx() < 0.5)
		{
			swap(a, b);
			swap(c, d);
			swap(m, n);
		}
	}
}
void reduce(int& m, int& n, int& a, int& b, int& c, int& d)
{
	int max_size;
	auto dx = [&]()->int {return c - a; };
	auto dy = [&]()->int {return d - b; };
	if (m > 10 && n > 10&&dx()>4)
	{
		max_size = 1;//>=1;
	}
	else
	{
		max_size = 3;
	}
	if (m > c + max_size&&dy()>4)
	{
		m = c + max_size;
	}
	if (n > d + max_size)
	{
		n = d + max_size;
	}

	if (a > max_size)
	{
		m -= a - max_size;
		c -= a - max_size;
		a = max_size;
	}
	if (b > max_size)
	{
		n -= b - max_size;
		d -= b - max_size;
		b = max_size;
	}
}
int search(int m, int n, int a, int b, int c, int d)
{
	auto isCheck = [&](int x, int y)->bool {return ((x >= 0) && (x < m) && (y >= 0) && (y < n)); };
	clr(S);
	memset(L, UINT8_MAX, sizeof L);
	Point Begin(a, b, 0), End(c, d, UINT_MAX);
	priority_queue<Point, deque<Point>, greater<Point>> que;
	que.push(Begin);
	while ((!(que.empty())) && (que.top() != End))
	{

		Point t = que.top();
		//p(t);
		que.pop();

		if (t.inS())
		//if (S[t.x][t.y])
		{
			continue;
		}
		t.setS();
		for (int i = 0; i < 8; ++i)
		{
			int x = t.x + horizontal[i];
			int y = t.y + vertical[i];
			unsigned step = t.step + 1;
			if (S[x][y] || (L[x][y] <= step) || !(isCheck(x, y)))
			{
				continue;
			}
			Point temp(t, i);
			//p(temp);
			que.push(temp);
		}
	}
	if (L[c][d] == 65535)
	{
		return 0;
	}
	else
	{
		return L[c][d];
	}
}
