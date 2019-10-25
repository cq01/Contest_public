//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cmath>
using namespace std;
bool able(const double& a, const double& b, const double& c, const double& d);
bool sort(const double& a, const double& b, const double& c, const double& d);
inline bool is24(const double& s);
double op(int& mode, const double& a, const double& b);
int main()
{
	double a, b, c, d;
	while (cin >> a >> b >> c >> d)
	{
		if (sort(a, b, c, d))
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NOT" << endl;
		}
	}

}
bool is24(const double& s)
{
	return (fabs(s - 24) < 1e-6);
}
double op(int& mode, const double& a, const double& b)
{
	if (mode == 3 || b == 0)
	{
		return a;
	}
	switch (mode)
	{
	case 0:return a + b; break;
	case 1:return a - b; break;
	case 2:return a * b; break;
	case 3:return a / b; break;
	}
}
bool able(const double& a, const double& b, const double& c, const double& d)
{
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			for (int k = 0; k < 4; ++k)
			{
				//((a#b)#c)#d
				if (is24(op(i, op(j, op(k, a, b), c), d)))
				{
					return true;
				}
				//(a#b)#(c#d)
				if (is24(op(i, op(j,a,b),op(k,c,d))))
				{
					return true;
				}
			}
		}
	}
	return false;
}
bool sort(const double& a, const double& b, const double& c, const double& d)
{
	double set[4] = { a,b,c,d };
	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (j == i)
			{
				continue;
			}
			for (int k = 0; k < 4; ++k)
			{
				if (k == j || k == i)
				{
					continue;
				}
				int l = 6 - i - j - k;
				if (able(set[i], set[j], set[k], set[l]))
				{
					return true;
				}

			}
		}
	}
	return false;
}