//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
#include<cstring>
using namespace std;
int test(char str[]);
int main()
{
	char str[1024];
	while (cin >> str)
	{
		if (test(str))
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
}

int test(char str[])
{
	int n = strlen(str);
	int s = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		s += (str[i] != str[n - i - 1]);
	}
	return s;
}