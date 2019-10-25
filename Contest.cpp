//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
void pr(const int& n);
int main()
{
	int n;
	while (cin >> n)
	{
		pr(n);
	}
}
void pr(const int& n)
{
	int res[50][50] = { 0 };
	int j = 0, k = 0;
	for (int i = 1; i <= n; ++i)
	{
		res[j][k] = i;
		if (j == 0)
		{
			j = k + 1;
			k = 0;
		}
		else
		{
			--j;
			++k;
		}
	}
	for (int j = 0; j < 50; ++j)
	{
		if (res[j][0])
		{
			for (int k = 0; k < 50; ++k)
			{

				if (res[j][k])
				{
					if (k)
					{
						cout << ' ';
					}
					cout << res[j][k];
				}
				else
				{
					cout << endl;
					break;
				}
			}
		}
		else
		{
			break;
		}
	}
}