//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cmath>
using namespace std;
int fb(const int& n);
int main()
{
	int n;
	while (cin>>n)
	{
		cout << fb(n) << endl;
	}
}

int fb(const int& n)
{
	int a = 1, b = 1,t ;
	for (int i = 0; i < n; ++i)
	{
		t = a;
		a = b;
		b += t;
	}
	return a;
}