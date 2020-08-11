//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <bits/stdc++.h>
using namespace std;

void Rome(int n);
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int n;
	while (cin >> n)
	{
		Rome(n);
		cout << endl;
	}
}

void Rome(int n)
{
	while (n)
	{
		if (n >= 1000)
		{
			cout << 'M';
			n -= 1000;
			continue;
		}
		if (n >= 900)
		{
			cout << "CM";
			n -= 900;
			continue;
		}
		if (n >= 500)
		{
			cout << 'D';
			n -= 500;
			continue;
		}
		if (n >= 400)
		{
			cout << "CD";
			n -= 400;
			continue;
		}
		if (n >= 100)
		{
			cout << 'C';
			n -= 100;
			continue;
		}
		if (n >= 90)
		{
			cout << "XC";
			n -= 90;
			continue;
		}
		if (n >= 50)
		{
			cout << 'L';
			n -= 50;
			continue;
		}
		if (n >= 40)
		{
			cout << "XL";
			n -= 40;
			continue;
		}
		if (n >= 10)
		{
			cout << 'X';
			n -= 10;
			continue;
		}
		if (n >= 9)
		{
			cout << "IX";
			n -= 9;
			continue;
		}
		if (n >= 5)
		{
			cout << 'V';
			n -= 5;
			continue;
		}
		if (n >= 4)
		{
			cout << "IV";
			n -= 4;
			continue;
		}
		if (n)
		{
			cout << 'I';
			--n;
			continue;
		}
	}

}
