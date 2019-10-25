//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
int main()
{
	int s[10] = { 0 };
	for (int i = 0; i < 10; ++i)
	{
		cin >> s[i];
	}
	int a;
	while (cin >> a)
	{
		int j;
		for (j = 0; j < 10; ++j)
		{
			if (a < s[j])
			{
				break;
			}
		}
		if (j < 10)
		{

			for (int k = 9; k > j; --k)
			{
				s[k] = s[k - 1];
			}
			s[j] = a;
		}
		for (int l = 0; l < 10; ++l)
		{
			if (l)
			{
				cout << ' ';
			}
			cout << s[l];
		}
		cout << endl;
	}
}
