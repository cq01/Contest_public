﻿//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
// there is a bug that the oj system does not support any chinese char in cpp(only support ascii)
#include <iostream>
#include<cmath>
using namespace std;
inline int sgnInt(int x)
{
	return(x > 0 ? 1 : -1);
}
inline int min(const int& x, const int& y)
{
	return x < y ? x : y;
}
inline int max(const int& x, const int& y)
{
	return x > y ? x : y;
}
inline void swapInt(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
inline void span(int& a, int& b, int& c, int& d, const int& m, const int& n)
{
	int ix = sgnInt(c - a), iy = sgnInt(d - b);
	if (ix == -1 && iy == -1)
	{
		swapInt(a, c);
		swapInt(b, d);
	}
	if (ix == 1 && iy == -1)
	{
		b = n + 1 - b;
		d = n + 1 - d;
	}
	if (ix == -1 && iy == 1)
	{
		a = m + 1 - a;
		c = m + 1 - c;
	}
}
inline void reduce(const int& a, const int& b, const int& c, const int& d, int& m, int& n)
{
	if (m - max(a, c) > 6)
	{
		m = max(a, c) + 6;
	}
	if (n - max(b, d) > 6)
	{
		n = max(b, d) + 6;
	}
}

inline int minNotZero(const int& x, const int& y)// select the min but not zero one,else both are zero then return 0
{
	if (x)
	{
		if (y)
		{
			return min(x, y);
		}
		return x;
	}
	return y;
}

inline bool inBoard(const int& a, const int& b, const int& m, const int& n)//check if in board
{
	if (a >= 1 && a <= m && b >= 1 && b <= n)
	{
		return true;
	}
	return false;
}
int tests(const int& i, int s, int a, int b, const int& c, const int& d, const int& m, const int& n, int success)
{

	if (success && s >= success - 1)//over
	{
		return 0;
	}
	int r = 0;

	switch (i)
	{
	case 0:a += 1; b += 2;  break;
	case 1:a += 2; b += 1; break;
	case 2:a += 1; b += -2; break;
	case 3:a += 2; b += -1; break;
	case 4:a += -1; b += 2; break;
	case 5:a += -2; b += 1; break;
	case 6:a += -1; b += -2; break;
	case 7:a += -2; b += -1; break;
	}
	if (inBoard(a, b, m, n))
	{
		++s;
	}
	else
	{
		return 0;
	}

	if (a != c || b != d)
	{
		for (int j = 0; j < 8; ++j)
		{
			success = minNotZero(r, success);
			r = tests(j, s, a, b, c, d, m, n, success);
		}

		s = minNotZero(r, success);

	}
	return s;
}
int beginTest(int a, int b, int& c, int& d, int& m, int& n)//begin test
{
	reduce(a, b, c, d, m, n);
	span(a, b, c, d, m, n);//after,a<c,b<d
	reduce(a, b, c, d, m, n);
	int sx = 1, sy = 1;
	int r = 0, s = 0;//set search deep
	int t,ax,ay;
	ax = abs(c - a);
	ay = abs(d - b);
	t = min(ax, ay) * 2 / 3 - 4;
	if (t > 0)
	{
		s += 2 * t;
		a += sx * 3 * t;
		b += sy * 3 * t;
	}
	ax = abs(c - a);
	ay = abs(d - b);
	if ((ax - ay) > 4)
	{
		t = ax / 4 - 1;
		s += 2 * t;
		a += sx * 4 * t;
	}
	if ((ay - ax) > 4)
	{
		t = ay / 4 - 1;
		s += 2 * t;
		b += sy * 4 * t;
	}
	int max = s + min(abs(c - a) * abs(d - a) / 2 + 3, m * n - 1);
	int success = max;
	for (int j = 0; j < 8; ++j)
	{
		success = minNotZero(r, success);
		r = tests(j, s, a, b, c, d, m, n, success);
	}
	success = minNotZero(r, success);
	if (success <= max)
	{
		return success;
	}
	else
	{
		return 0;
	}
}
int main()
{
	int a, b, c, d, m, n, k;
	while (cin >> k)
	{
		for (int i = 0; i < k; ++i)
		{
			cin >> m >> n;
			cin >> a >> b >> c >> d;
			int s = beginTest(a, b, c, d, m, n);
			cout << s << endl;
		}
	}
}