//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
// there is a bug that the oj system does not support any chinese char in cpp(only support ascii)
#include <iostream>
#include<cmath>
using namespace std;
struct dot
{
	int x, y;
};
inline double min(const double& a, const double& b)
{
	return a < b ? a : b;
}


inline bool equal(const double& a, const double& b)
{
	return (fabs(a - b) < 1e-6);
}

inline double length(dot p1, dot p2)
{
	return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

inline void fill(dot p[4])
{
	for (int i = 0; i < 4; ++i)
	{
		cin >> p[i].x >> p[i].y;
	}
}

bool isthis(dot p[4])
{
	int s= -4;

	double n = min(length(p[0], p[1]), length(p[0], p[2]));

	for (int i = 0; i < 3; ++i)
	{
		for (int j = i + 1; j < 4; ++j)
		{
			s += (length(p[i], p[j]) == n);
		}
	}
	if (s != 0)
	{
		return false;
	}
	for (int i = 0; i < 3; ++i)
	{
		s += equal(length(p[3], p[i]) / sqrt(2), n);
	}
	return s;
}


int main()
{
	dot point[4];
	for (int i = 0; i < 3; ++i)
	{

		fill(point);
		if (isthis(point))
		{
			cout << "yes" << endl;
		}
		else
		{
			cout << "no" << endl;
		}
	}
}