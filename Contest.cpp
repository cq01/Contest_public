//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cmath>
using namespace std;
void pr(const int& n);
int main()
{
	int n;
	while (cin>>n)
	{
		pr(n);
	}
}
void pr(const int& n)
{
	if (n == 1)
	{
		cout << "*\n";
	}
	else if (n == 2)
	{
		cout << "**\n**\n";
	}
	else
	{
		for (int i = 0; i < n; ++i)
		{
			cout << '*';
		}
		cout << '\n';
		for (int i = 0; i < n - 2; ++i)
		{
			cout << '*';
			for (int j = 0; j < n - 2; ++j)
			{
				cout << ' ';
			}
			cout << "*\n";
		}
		for (int i = 0; i < n; ++i)
		{
			cout << '*';
		}
		cout << '\n';
	}
	cout<<'\n';
}