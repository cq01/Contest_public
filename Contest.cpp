//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<iomanip>
#include <bitset>
using namespace std;
void apart(int& n);
int main()
{
	int n;
	while (cin >> n)
	{
		apart(n);
	}
}

void apart(int& n)
{
	while (n>1)
	{
		for (int i = 2; i < 136; ++i)
		{
			if (n%i)
			{
				continue;
			}
			cout << ' ' << i;
			n /= i;
			break;
		}
	}
	cout << endl;
}