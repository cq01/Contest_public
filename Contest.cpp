//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<iomanip>
using namespace std;
//如果写double Pfunc(double x, int n); OJ会报编译错误
double Pfunc(double x, int n)
{
	if (!n)//n==0
	{
		return 1;
	}
	if (n == 1)
	{
		return x;
	}
	return ((2l * n - 1) * Pfunc(x, n - 1) - (n - 1l) * Pfunc(x, n - 2)) / n;
}
int main()
{
	int n;
	double x;
	float xf;
	while (cin>>xf>>n)
	{
		x = double(xf);
		cout << fixed << setprecision(2) << Pfunc(x, n) << endl;
	}
}
//P[n](x)
//{1, n = 0；
//{ x ,n = 1；
//{((2n - 1)P[n - 1](x)) - (n - 1)P[n - 2](x)) / n ,n > 1；
