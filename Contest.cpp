//Copyright by cq01, 2019 Licensed under the MIT license : http://www.opensource.org/licenses/mit-license.php
#include <iostream>
using namespace std;
int main()
{
	int s[10] = { 0 };
	int a;
	for (int i = 0; i < 10; ++i)
	{
		cin >> a;
		s[a] = i;
	}
	for (int i = 9; i >=0; --i)
	{
		cout << i << ' ' << s[i] << endl;
	}
}
