//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main()
{
	int n, T;
	while (cin >> T)
	{
		for (int t = 0; t < T; ++t)
		{
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < n; ++j)
				{
					if (i == j || i + j == n - 1)
					{
						cout << 'X';
					}
					else if ((i + j < n - 1) || (j < i))
					{
						cout << ' ';
					}
				}
				cout << endl;
			}
		}
	}
}