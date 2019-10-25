//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cmath>
#include<iomanip>
using namespace std;


double sum(const int& n, const int& q);
int main()
{
	int m, n, p;
	double s = 0;
	while (cin >> m >> n >> p)
	{
		s += sum(m, 1);
		s += sum(n, 3);
		s /= sum(p, 5);
		cout << fixed << setprecision(4) << s << endl;
		s = 0;
	}
}

double sum(const int& n, const int& q)
{
	double result = 0;
	for (int i = 1; i <= n; ++i)
	{
		result += pow(i, q);
	}
	return result;
}