//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
void fillmartix(const int& n, int p[]);
void printmartix(const int& n, int p[]);
int atr(const int& n);
inline int op(const int& a, const int& b, const int& n);
inline int value(const int& n);
inline int sum2(const int& n);
int main()
{
	int n;
	while (cin >> n)
	{
		int* p = new int[n * n]();
		fillmartix(n, p);
		printmartix(n, p);
		cout << atr(n) << endl;
	}
}
inline int value(const int& n)
{
	return n > 1 ? n : 1;
}
int op(const int& a, const int& b, const int& n)
{
	return a * n + b;
}

void fillmartix(const int& n, int p[])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			p[op(i, j, n)] = value(i + 1 - j);
		}
	}
}

void printmartix(const int& n, int p[])
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (j)
			{
				cout << ' ';
			}
			cout << p[op(i, j, n)];
		}
		cout << endl;
	}
}
int atr(const int& n)
{
	int s = 0;
	for (int i = 2; i <= n; ++i)
	{
		s += sum2(i);
	}
	return s;
}
int sum2(const int& n)
{
	return (n - 1) * (n + 2) / 2;
}